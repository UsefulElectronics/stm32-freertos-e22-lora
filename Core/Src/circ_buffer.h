/**
 ******************************************************************************
 *							USEFUL ELECTRONICS
 ******************************************************************************/
/**
 ******************************************************************************
 * @file    :  circ_buffer.h
 * @author  :  WARD ALMASARANI
 * @version :  v.1.0
 * @date    :  Mar 2, 2023
 * @link    :  https://www.youtube.com/@usefulelectronics
 *			   Hold Ctrl button and click on the link to be directed to
			   Useful Electronics YouTube channel	
 ******************************************************************************/

#ifndef SRC_CIRC_BUFFER_H_
#define SRC_CIRC_BUFFER_H_


/* INCLUDES ------------------------------------------------------------------*/
#include "stdlib.h"
#include "stdint.h"

/* MACROS --------------------------------------------------------------------*/
#define BUFFER_SIZE 		5
#define MAX_DATA_SIZE		245
/* ENUMORATIONS --------------------------------------------------------------*/

/* STRUCTURES & TYPEDEFS -----------------------------------------------------*/
typedef struct
{
	uint8_t buffer[BUFFER_SIZE][MAX_DATA_SIZE];
	uint8_t start;
	uint8_t end;
	uint8_t elementSizes[BUFFER_SIZE];
} circ_buffer_t;
/* VARIABLES -----------------------------------------------------------------*/

/* FUNCTIONS DECLARATION -----------------------------------------------------*/
void circ_buffer_enqueue(circ_buffer_t *cb, uint8_t* data, uint8_t size);

uint8_t* circ_buffer_dequeue(circ_buffer_t *cb, uint8_t *size);

uint8_t* circ_buffer_peek(circ_buffer_t *cb, uint8_t *size);

void circ_buffer_clear(circ_buffer_t *cb);

uint8_t circ_buffer_getNextSize(circ_buffer_t *cb);

uint8_t circ_buffer_getNumArrays(circ_buffer_t *cb);

#endif /* SRC_CIRC_BUFFER_H_ */

/*************************************** USEFUL ELECTRONICS*****END OF FILE****/
