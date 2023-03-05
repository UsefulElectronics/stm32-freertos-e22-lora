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
/**
 * @brief 	Add an element to the circular buffer
 *
 * @param 	cb 		:	Pointer to the circular buffer
 *
 * @param 	data	: 	Array of bytes to add to the buffer
 *
 * @param 	size 	:	Size of the data array
 */
void circ_buffer_enqueue(circ_buffer_t *cb, uint8_t* data, uint8_t size)
{
	if ((cb->end + 1) % BUFFER_SIZE == cb->start)
	{
		// Buffer is full, do not add new element
		return;
	}
	memcpy(cb->buffer[cb->end], data, size * sizeof(uint8_t));
	cb->elementSizes[cb->end] = size;
	cb->end = (cb->end + 1) % BUFFER_SIZE;
}
/**
 * @brief 	Remove the first element from the circular buffer and return it
 *
 * @param 	cb		: 	Pointer to the circular buffer
 *
 * @param 	size	:	Pointer to an integer to store the size of the returned array
 *
 * @return 	Pointer to the first element in the buffer
 */
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
/**
 * @brief Return a pointer to the first element in the buffer without removing it
 *
 * @param 	cb		:	Pointer to the circular buffer
 *
 * @param 	size	:	Pointer to an integer to store the size of the returned array
 *
 * @return 	Pointer	: 	to the first element in the buffer
 */
uint8_t* circ_buffer_peek(circ_buffer_t *cb, uint8_t *size)
{
	uint8_t *element = cb->buffer[cb->start];

	if (size)
	{
		*size = cb->elementSizes[cb->start];
	}
	return element;
}
/**
 * @brief 	Clear 	:	the circular buffer
 *
 * @param 	cb		: 	Pointer to the circular buffer
 */
void circ_buffer_clear(circ_buffer_t *cb)
{
	cb->start = 0;
	cb->end = 0;
}
/**
 * @brief 	Get the number of arrays currently stored in the buffer
 *
 * @param 	cb		: 	Pointer to the circular buffer
 *
 * @return 	Number	: 	of arrays in the buffer
 */
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
/**
 * @brief 	Get the size of the next block of data to read
 *
 * @param 	cb		:	 Pointer to the circular buffer
 *
 * @return 	Size 	:	of the next block of data to read, or 0 if the buffer is empty
 */
uint8_t circ_buffer_getNumArrays(circ_buffer_t *cb)
{
	if (cb->end >= cb->start)
	{
		return cb->end - cb->start;
	}
	return BUFFER_SIZE - cb->start + cb->end;
}
/*************************************** USEFUL ELECTRONICS*****END OF FILE****/
