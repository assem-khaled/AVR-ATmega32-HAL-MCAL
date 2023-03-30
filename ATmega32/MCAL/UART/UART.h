/*
 * UART.h
 *
 *  Created on: Oct 4, 2019
 *      Author: mr_ta
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

void UART_vidInit(void);
void UART_vidSendChar(u8 data);
u8 UART_u8GetChar (void);



#endif /* MCAL_UART_UART_H_ */
