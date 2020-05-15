/** @file sensor.c
 * 
 * @brief This module simulate a sensor, sending data to the server.
 *
 * @par       
 * COPYRIGHT NOTICE: (c) 2020 Gustavo Marques. 
 */ 
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#import <stdio.h>
#import "serial.h"
#import "server.h"

// 
static uint8_t ucParameterToPass;
static TaskHandle_t xHandleInput = NULL;

// 
void vSensorTask(void *pvParameters)
{
    struct AMessage *xReadMessage = 0;
    int sTmp = 0;
    for (;;)
    {
        printf("Readind inputs now.\n");
        
        sTmp = sTmp + 1;
        vServerSend(0,sTmp);

        vTaskDelay(DELAY_IN_MS / portTICK_PERIOD_MS);
    }
}

void vSensorInit(void)
{
    xTaskCreate(
        vSensorTask,
        "SENSOR",
        SERIAL_STACK_SIZE,
        &ucParameterToPass,
        tskIDLE_PRIORITY,
        &xHandleInput);
        
    configASSERT(xHandleInput);
}

void vSensorConfig(void)
{
}

void vSensorRead(void)
{
}
/*** end of file ***/