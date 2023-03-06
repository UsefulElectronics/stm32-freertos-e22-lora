/**
 ******************************************************************************
 *							USEFUL ELECTRONICS
 ******************************************************************************/
/**
 ******************************************************************************
 * @file    :  e22900t22d.h
 * @author  :  WARD ALMASARANI
 * @version :  v.1.0
 * @date    :  Mar 2, 2023
 * @link    :  https://www.youtube.com/@usefulelectronics
 *			   Hold Ctrl button and click on the link to be directed to
			   Useful Electronics YouTube channel	
 ******************************************************************************/

#ifndef SRC_E22900T22D_H_
#define SRC_E22900T22D_H_


/* INCLUDES ------------------------------------------------------------------*/
#include "stdbool.h"
#include <stdio.h>
#include <string.h>

/* MACROS --------------------------------------------------------------------*/
#define 	MAX_DATA_PACKET_SIZE		240
/* ENUMORATIONS --------------------------------------------------------------*/

/* STRUCTURES & TYPEDEFS -----------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/

/* FUNCTIONS DECLARATION -----------------------------------------------------*/
/**
 * @brief	Initializes the E22 LoRa module
 * 			This function initializes the E22 LoRa module by assigning the UART handle, transmission function, reception function,
 * 			configuration mode function, and transceiver mode function. It also assigns DMA buffer pointers and sets the transceiver
 * 			mode as the default mode.
 *
 * @param huart				: Pointer to the UART handle used for communication with the E22 module.
 *
 * @param transmissionFunc		: Pointer to the function used for transmitting data via the E22 module.
 *
 * @param receptionFunc		: Pointer to the function used for receiving data via the E22 module.
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
					void* TransceiverModeFunc);

/**
 * @brief Get data to be transmitted to the LoRa module and form the necessary packet including the target address and the communication channel
 * 		  and store the formed packet in the circular buffer.
 *
 * @param pData		:	pointer to the data to be transmitted to the module.
 *
 * @param size		:	number of bytes to be transmitted
 *
 * @param address	:	LoRa target device address.
 *
 * @param channel	:	RF channel to send data over
 *
 */
void e22_lora_transnit(uint8_t *pData, uint16_t size, uint16_t address, uint8_t channel);

/**
 * @brief 	Store received data in the RX reception buffer.
 *
 * @param 	pData : data received to be stored in the corresponding circular buffer
 *
 * @param	 size : number of bytes received
 */
void e22_lora_receive(uint8_t *pData, uint16_t size);

/**
 * @brief 	Manages the E22 LoRa module
 * 			This function manages the E22 LoRa module by checking for packets in the TX circular buffer, dequeuing them, and transmitting
 * 			them via the E22 module.
 *
 */
void e22_lora_manager(void);
/**
 * @brief 	Make transmission line status ready at TX complete callback
 *
 */
void e22_lora_make_ready(void);
/**
 * @brief 	this function should be called at the UART RX complete callback.
 *
 */
void e22_lora_reception_complete(uint8_t size);

#endif /* SRC_E22900T22D_H_ */

/*************************************** USEFUL ELECTRONICS*****END OF FILE****/
