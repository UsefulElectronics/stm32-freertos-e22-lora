/**
 ******************************************************************************
 *							USEFUL ELECTRONICS
 ******************************************************************************/
/**
 ******************************************************************************
 * @file    :  circ_buffer.c
 * @author  :  WARD ALMASARANI
 * @version :  v.1.0
 * @date    :  Mar 2, 2023
 * @link    :  https://www.youtube.com/@usefulelectronics
 *			   Hold Ctrl button and click on the link to be directed to
			   Useful Electronics YouTube channel	
 ******************************************************************************/


/* INCLUDES ------------------------------------------------------------------*/
#include "circ_buffer.h"

/* PRIVATE STRUCTRES ---------------------------------------------------------*/

/* VARIABLES -----------------------------------------------------------------*/

/* DEFINITIONS ---------------------------------------------------------------*/

/* MACROS --------------------------------------------------------------------*/

/* PRIVATE FUNCTIONS DECLARATION ---------------------------------------------*/

/* FUNCTION PROTOTYPES -------------------------------------------------------*/
void circ_buffer_enqueue(circ_buffer_t *cb, uint8_t* data, uint8_t size)
{
	if ((cb->end + 1) % BUFFER_SIZE == cb->start)
	{
		// Buffer is full, do not add new element
		return;
	}
	memcpy(cb->buffer[cb->end], data, size * sizeof(int));
	cb->elementSizes[cb->end] = size;
	cb->end = (cb->end + 1) % BUFFER_SIZE;
}

uint8_t* circ_buffer_dequeue(circ_buffer_t *cb, uint8_t *size)
{
	uint8_t *element = cb->buffer[cb->start];
	if (size)
	{
		*size = cb->elementSizes[cb->start];
	}
	cb->start = (cb->start + 1) % BUFFER_SIZE;
	return element;
}

uint8_t* circ_buffer_peek(circ_buffer_t *cb, uint8_t *size)
{
	uint8_t *element = cb->buffer[cb->start];

	if (size)
	{
		*size = cb->elementSizes[cb->start];
	}
	return element;
}

void circ_buffer_clear(circ_buffer_t *cb)
{
	cb->start = 0;
	cb->end = 0;
}

uint8_t circ_buffer_getNextSize(circ_buffer_t *cb)
{
	if (cb->start == cb->end)
	{
		return 0;
	}
	else
	{
		return cb->elementSizes[cb->start];
	}
}

uint8_t circ_buffer_getNumArrays(circ_buffer_t *cb)
{
	if (cb->end >= cb->start)
	{
		return cb->end - cb->start;
	}
	return BUFFER_SIZE - cb->start + cb->end;
}
/*************************************** USEFUL ELECTRONICS*****END OF FILE****/
