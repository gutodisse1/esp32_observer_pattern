/** @file server.h
 * 
 * @brief This module builds a queue to decouple sensors from their consumer.  
 *
 * @par       
 * COPYRIGHT NOTICE: (c) 2020 Gustavo Marques. 
 */ 

#ifndef SERVER_H
#define SERVER_H

#import "message.h"


void vServerInit(void);
void vServerSend(int, int);
struct AMessage * pxServerGet(void);
struct AMessage * pxServerRemove(void);

#endif // !SERVER_H

/*** end of file ***/