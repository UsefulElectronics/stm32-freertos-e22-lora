/**
 ******************************************************************************
 *							USEFUL ELECTRONICS
 ******************************************************************************/
/**
 ******************************************************************************
 * @file    :  e22900t22d.c
 * @author  :  WARD ALMASARANI
 * @version :  v.1.0
 * @date    :  Mar 2, 2023
 * @link    :  https://www.youtube.com/@usefulelectronics
 *			   Hold Ctrl button and click on the link to be directed to
			   Useful Electronics YouTube channel	
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/
#include "e22900t22d.h"
#include "circ_buffer.h"
/* PRIVATE STRUCTRES ---------------------------------------------------------*/

typedef struct
{
	void*		 huart;
	void		(*loraTransmit) 		(void *huart, const uint8_t *pData, uint16_t Size);
	void 		(*loraStartReception)	(void *huart, uint8_t *pData, uint16_t Size);
	void 		(*loraReceive) 			(uint8_t *pData, uint8_t Size);
	void 		(*loraTransceiverMode)	(void);
	void 		(*loraConfigurationMode)(void);
	e22_packet_t packet;
	uint8_t 	 packetLength;
	bool 		 txPortReady;

	circ_buffer_t txBuffer;
	circ_buffer_t rxBuffer;

	uint8_t* 	 pRxDmaBuffer;
	uint8_t* 	 pTxDmaBuffer;

}e22_handler_t;
/* VARIABLES -----------------------------------------------------------------*/
e22_handler_t hE22 = {0};
uint8_t rxDmaBuffer[MAX_DATA_PACKET_SIZE] = {0};
uint8_t txDmaBuffer[MAX_DATA_PACKET_SIZE] = {0};
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

/* FUNCTION PROTOTYPES -------------------------------------------------------*/
/**
 * @brief	Initializes the E22 LoRa module
 * 			This function initializes the E22 LoRa module by assigning the UART handle, transmission function, reception function,
 * 			configuration mode function, and transceiver mode function. It also assigns DMA buffer pointers and sets the transceiver
 * 			mode as the default mode.
 *
 * @param huart					: Pointer to the UART handle used for communication with the E22 module.
 *
 * @param transmissionFunc		: Pointer to the function used for transmitting data via the E22 module.
 *
 * @param receptionFunc			: Pointer to the function used for receiving data via the E22 module.
 *
 * @param receptionCallbackFunc : Pointer to the function used to send the received packet and its size to the main layer.
 *
 * @param configModeFunc		: Pointer to the function used to configure the E22 module.
 *
 * @param TransceiverModeFunc	: Pointer to the function used to set the E22 module to transceiver mode.
 */
void e22_lora_init( void* huart,
					void* transmissionFunc,
					void* receptionFunc,
					void* receptionCallbackFunc,
					void* configModeFunc,
					void* TransceiverModeFunc)
{
	hE22.huart 						= huart;
	hE22.loraTransmit 				= transmissionFunc;
	hE22.loraStartReception 		= receptionFunc;
	hE22.loraReceive		 		= receptionCallbackFunc;
	hE22.loraConfigurationMode 		= configModeFunc;
	hE22.loraTransceiverMode		= TransceiverModeFunc;

	//Assign DMA buffer pointers.
	hE22.pRxDmaBuffer = rxDmaBuffer;
	hE22.pTxDmaBuffer = txDmaBuffer;
	//transceiver mode as default
	hE22.loraTransceiverMode();

	hE22.loraStartReception(hE22.huart, hE22.pRxDmaBuffer, MAX_DATA_PACKET_SIZE);
}
/**
 * @brief Get data to be transmitted to the LoRa module and form the necessary packet including the target address and the communication channel
 * 		  and store the formed packet in the circular buffer.
 *
 * @param pData
 *
 * @param size		:	number of bytes to be transmitted
 *
 * @param address	:	LoRa target device address.
 *
 * @param channel	:	RF channel to send data over
 *
 */
void e22_lora_transnit(uint8_t *pData, uint16_t size, uint16_t address, uint8_t channel)
{
	const uint8_t overheadSize = 3;

	memset(&hE22.packet, 0, sizeof(e22_packet_t));
	//Address 2 bytes swap
	hE22.packet.address = (address >> 8) | (address << 8);

	hE22.packet.chanel = channel;

	hE22.txPortReady = true;

	memcpy(&hE22.packet.dataBuffer, pData, size);

	circ_buffer_enqueue(&hE22.txBuffer, (uint8_t*)&hE22.packet, size + overheadSize);
}

/**
 * @brief 	Store received data in the RX reception buffer.
 *
 * @param 	pData : data received to be stored in the corresponding circular buffer
 *
 * @param	size : number of bytes received
 */
void e22_lora_receive(uint8_t *pData, uint16_t size)
{
	circ_buffer_enqueue(&hE22.rxBuffer, pData, size );

}
/**
 * @brief 	Manages the E22 LoRa module
 * 			This function manages the E22 LoRa module by checking for packets in the TX circular buffer, dequeuing them, and transmitting
 * 			them via the E22 module.
 *
 */
void e22_lora_manager(void)
{
	uint8_t packetSize = 0;
	uint8_t* pPacket = NULL;
	//check for packet in TX circular buffer
	if(circ_buffer_getNextSize(&hE22.txBuffer))
	{
//		uint8_t packetSize = 0;
//		uint8_t* pPacket = NULL;
		if(hE22.txPortReady)
		{
			hE22.txPortReady = false;
			// Dequeue packet from circular buffer
			pPacket = circ_buffer_dequeue(&hE22.txBuffer, &packetSize);
			// Copy packet to DMA buffer
			memcpy(hE22.pTxDmaBuffer ,pPacket, packetSize);
			// Transmit packet via the E22 module
			hE22.loraTransmit(hE22.huart, hE22.pTxDmaBuffer, packetSize);
		}
	}
	//check for packet in RX circular buffer
	if(circ_buffer_getNextSize(&hE22.rxBuffer))
	{
		pPacket = circ_buffer_dequeue(&hE22.rxBuffer, &packetSize);
		hE22.loraReceive(pPacket, packetSize);
	}
}
/**
 * @brief 	Make transmission line status ready at TX complete callback
 *
 */
void e22_lora_make_ready(void)
{
	hE22.txPortReady = true;
}
/**
 * @brief 	this function should be called at the UART RX complete callback.
 *
 */
void e22_lora_reception_complete(uint8_t size)
{
	circ_buffer_enqueue(&hE22.rxBuffer, (uint8_t*)hE22.pRxDmaBuffer, size);
	//Activate UART reception again
	hE22.loraStartReception(hE22.huart, hE22.pRxDmaBuffer, MAX_DATA_PACKET_SIZE);
}
/*************************************** USEFUL ELECTRONICS*****END OF FILE****/
