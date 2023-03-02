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
	void*		huart;
	void		(*loraTransmit) (void *huart, const uint8_t *pData, uint16_t Size);
	void 		(*loraReceive) (void *huart, uint8_t *pData, uint16_t Size);
	e22_packet_t packet;
	uint8_t 	packetLength;
	circ_buffer_t bufferController;

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

/*************************************** USEFUL ELECTRONICS*****END OF FILE****/
