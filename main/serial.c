/** @file serial.c
 * 
 * @brief This module read from the server and send to primary serial  
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
void vSerialTask(void *pvParameters)
{
    struct AMessage *xReadMessage = 0;
    int sTmp = 0;
    for (;;)
    {
        xReadMessage = pxServerRemove();
        if(xReadMessage)
        {
            printf("ID: %d\nVALUE: %d\n", 
                xReadMessage->sMessageID, 
                xReadMessage->sMessageValue);

            free(xReadMessage);
        }

        vTaskDelay(DELAY_IN_MS / portTICK_PERIOD_MS);
    }
}

void vSerialInit(void)
{
    xTaskCreate(
        vSerialTask,
        "INPUT",
        SERIAL_STACK_SIZE,
        &ucParameterToPass,
        tskIDLE_PRIORITY,
        &xHandleInput);
        
    configASSERT(xHandleInput);
}

void vSerialConfig(void)
{
}

void vSerialRefresh(void)
{
}
/*** end of file ***/