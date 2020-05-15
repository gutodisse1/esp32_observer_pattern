/** @file serial.h
 * 
 * @brief This module read from the server and send to primary serial  
 *
 * @par       
 * COPYRIGHT NOTICE: (c) 2020 Gustavo Marques. 
 */ 
#ifndef SERIAL_H
#define SERIAL_H

// Dimensions the buffer that the task being created will use as its stack.
// NOTE:  This is the number of bytes the stack will hold, not the number of
// words as found in vanilla FreeRTOS.
#define SERIAL_STACK_SIZE 2000

//
#define DELAY_IN_MS 1000

void vSerialInit(void);
void vSerialConfig(void);
void vSerialRefresh(void);


#endif // !SERIAL_H
/*** end of file ***/