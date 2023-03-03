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
	uint16_t	address;
	uint8_t 	chanel;
	uint8_t 	dataBuffer[MAX_DATA_PACKET_SIZE];
}e22_packet_t;

typedef struct
{
	void*		 huart;
	void		(*loraTransmit) 		(void *huart, const uint8_t *pData, uint16_t Size);
	void 		(*loraReceive) 			(void *huart, uint8_t *pData, uint16_t Size);
	void 		(*loraReceiveCallback) 	(uint8_t *pData, uint16_t Size);
	e22_packet_t packet;
	uint8_t 	 packetLength;
	bool 		 txPortReady;

	circ_buffer_t txBuffer;
	circ_buffer_t rxBuffer;

}e22_handler_t;
/* VARIABLES -----------------------------------------------------------------*/
e22_handler_t hE22 = {0};
/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

/* FUNCTION PROTOTYPES -------------------------------------------------------*/
void e22_lora_init(void* huart,
					void* transmissionFunc,
					void* receptionFunc)
{
	hE22.huart 			= huart;
	hE22.loraTransmit 	= transmissionFunc;
	hE22.loraReceive 	= receptionFunc;
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

	hE22.packet.address = address;

	hE22.packet.chanel = channel;

	memcpy(&hE22.packet.dataBuffer, pData, size);

	circ_buffer_enqueue(&hE22.txBuffer, &hE22.packet, size + overheadSize);
}
/**
 * @brief Start data reception over DMA
 *
 * @param pData	:	DMA buffer pointer
 */
void e22_lora_startReception(uint8_t *pData)
{
	hE22.loraReceive(hE22.huart, pData, MAX_DATA_PACKET_SIZE);
}
/**
 * @brief Store received data in the RX reception buffer.
 *
 * @param pData : data received to be stored in the corresponding circular buffer
 *
 * @param size 	: number of bytes received
 */
void e22_lora_receive(uint8_t *pData, uint16_t size)
{
	circ_buffer_enqueue(&hE22.rxBuffer, pData, size );
}
/**
 * @brief
 *
 */
void e22_lora_manager(void)
{

}
/*************************************** USEFUL ELECTRONICS*****END OF FILE****/
