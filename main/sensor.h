/** @file sensor.h
 * 
 * @brief This module simulate a sensor, sending data to the server.
 *
 * @par       
 * COPYRIGHT NOTICE: (c) 2020 Gustavo Marques. 
 */ 
#ifndef SENSOR_H
#define SENSOR_H

// Dimensions the buffer that the task being created will use as its stack.
// NOTE:  This is the number of bytes the stack will hold, not the number of
// words as found in vanilla FreeRTOS.
#define SERIAL_STACK_SIZE 2000

//
#define DELAY_IN_MS 1000

void vSensorInit(void);
void vSensorConfig(void);
void vSensorRead(void);


#endif // !SENSOR_H
/*** end of file ***/