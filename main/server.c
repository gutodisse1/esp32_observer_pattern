/** @file server.c
 * 
 * @brief This module builds a queue to decouple sensors from their consumer.  
 *
 * @par       
 * COPYRIGHT NOTICE: (c) 2020 Gustavo Marques. 
 */ 
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#include "server.h"

/*!
 * @brief Set queue as global
 */
static QueueHandle_t xQueue = 0;

/*!
 * @brief Create a queue capable of containg 10 pointer to message
 *
 * @return nothing
 */
void vServerInit(void)
{

    xQueue = xQueueCreate(10, sizeof(struct AMessage *));
    if (xQueue == 0)
    {
        // TODO: ADD FAIL HANDLER.
        printf("ERROR");
    }
}

/*!
 * @brief Create a message and after enqueue this
 *
 * @return nothing
 */
void vServerSend(int id, int value)
{
    struct AMessage *pxMessage;

    pxMessage = malloc(sizeof(struct AMessage));

    pxMessage->sMessageID       = id;
    pxMessage->sMessageValue    = value;

    if (!xQueueSend(xQueue, (void *)&pxMessage, (TickType_t)0))
    {
        // TODO: ADD FAIL HANDLER.
        printf("ERROR");
    }
}

/*!
 * @brief Peek and return the last item from the queue
 *
 * @return nothing
 */
struct AMessage * pxServerGet(void)
{
    struct AMessage *pxRxedMessage;

    if (xQueue != 0)
    {
        // Peek a message on the created queue.  Don't block.
        if (xQueuePeek(xQueue, &(pxRxedMessage), (TickType_t)0))
        {  
            return pxRxedMessage;
        }
    }
    return 0;
}

/*!
 * @brief Pop and return the last item from the queue
 *
 * @return nothing
 */
struct AMessage * pxServerRemove(void)
{
    struct AMessage *pxRxedMessage;

    if (xQueue != 0)
    {
        // Pop a message on the created queue.  Don't block.
        if (xQueueReceive(xQueue, &(pxRxedMessage), (TickType_t)0))
        {
            return pxRxedMessage;
        }
    }
    return 0;
}
/*** end of file ***/