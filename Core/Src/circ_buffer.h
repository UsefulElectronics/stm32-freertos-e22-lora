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
	 /**< Buffer to hold the data */
	uint8_t buffer[BUFFER_SIZE][MAX_DATA_SIZE];
	/**< Index of the first element in the buffer */
	uint8_t start;
	/**< Index of the last element in the buffer */
	uint8_t end;
	/**< Array to hold the sizes of each element in the buffer */
	uint8_t elementSizes[BUFFER_SIZE];
} circ_buffer_t;
/* VARIABLES -----------------------------------------------------------------*/

/* FUNCTIONS DECLARATION -----------------------------------------------------*/
/**
 * @brief 	Add an element to the circular buffer
 *
 * @param 	cb 		:	Pointer to the circular buffer
 *
 * @param 	data	: 	Array of bytes to add to the buffer
 *
 * @param 	size 	:	Size of the data array
 */
void circ_buffer_enqueue(circ_buffer_t *cb, uint8_t* data, uint8_t size);

/**
 * @brief 	Remove the first element from the circular buffer and return it
 *
 * @param 	cb		: 	Pointer to the circular buffer
 *
 * @param 	size	:	Pointer to an integer to store the size of the returned array
 *
 * @return 	Pointer to the first element in the buffer
 */
uint8_t* circ_buffer_dequeue(circ_buffer_t *cb, uint8_t *size);


/**
 * @brief Return a pointer to the first element in the buffer without removing it
 *
 * @param 	cb		:	Pointer to the circular buffer
 *
 * @param 	size	:	Pointer to an integer to store the size of the returned array
 *
 * @return 	Pointer	: 	to the first element in the buffer
 */
uint8_t* circ_buffer_peek(circ_buffer_t *cb, uint8_t *size);
/**
 * @brief 	Clear 	:	the circular buffer
 *
 * @param 	cb		: 	Pointer to the circular buffer
 */
void circ_buffer_clear(circ_buffer_t *cb);

/**
 * @brief 	Get the number of arrays currently stored in the buffer
 *
 * @param 	cb		: 	Pointer to the circular buffer
 *
 * @return 	Number	: 	of arrays in the buffer
 */
uint8_t circ_buffer_getNextSize(circ_buffer_t *cb);

/**
 * @brief 	Get the size of the next block of data to read
 *
 * @param 	cb		:	 Pointer to the circular buffer
 *
 * @return 	Size 	:	of the next block of data to read, or 0 if the buffer is empty
 */
uint8_t circ_buffer_getNumArrays(circ_buffer_t *cb);

#endif /* SRC_CIRC_BUFFER_H_ */

/*************************************** USEFUL ELECTRONICS*****END OF FILE****/
