/*
 * UART.c
 *
 *  Created on: Oct 4, 2019
 *      Author: mr_ta
 */

#include "../../STD_Types.h"
#include "../../macros.h"
#include "../DIO/DIO.h"
#include "UART.h"

/*USART I/O Data Register*/
#define UDR_REGISTER *((volatile u8*) 0x2C)
/*USART Control and Status Register A*/
#define UCSRA_REGISTER *((volatile u8*) 0x2B)
#define MPCM_REG 0
#define U2X_REG  1
#define PE_REG   2
#define DOR_REG  3
#define FE_REG   4
#define UDRE_REG 5
#define TXC_REG  6
#define RXC_REG  7
/*USART Control and Status Register B*/
#define UCSRB_REGISTER *((volatile u8*) 0x2A)
#define TXB8_REG  0
#define RXB8_REG  1
#define UCSZ2_RE  2
#define TXEN_REG  3
#define RXEN_REG  4
#define UDRIE_REG 5
#define TXCIE_REG 6
#define RXCIE_REG 7
/*USART Control and Status Register C*/
#define UCSRC_REGISTER *((volatile u8*) 0x40)
#define UCPOL_REG 0
#define UCSZ0_REG 1
#define UCSZ1_REG  2
#define USBS_REG  3
#define UPM0_REG  4
#define UPM1_REG  5
#define UMSEL_REG 6
#define URSEL_REG 7
/*USART Baud Rate Registers*/
#define UBRRH_REGISTER *((volatile u8*) 0x40)
#define UBRRL_REGISTER *((volatile u8*) 0x29)


void UART_vidInit(void)
{
	// Set BaudRate -> 9600/8MhZ
	UBRRL_REGISTER = 51 ;

	// Set Frame Format -> 8 data, 1 stop, No Parity
	//set_bit(UCSRC_REGISTER,URSEL_REG);
	//set_bit(UCSRC_REGISTER,UCSZ0_REG);
	//set_bit(UCSRC_REGISTER,UCSZ1_REG);
	UCSRC_REGISTER = 0x86;

	// Enable RX and TX
	//set_bit(UCSRB_REGISTER,TXCIE_REG);
	//set_bit(UCSRB_REGISTER,RXCIE_REG);
	UCSRB_REGISTER=0x18;

}

void UART_vidSendChar(u8 data)
{
	// Wait until transmission Register Empty
	while (get_bit(UCSRA_REGISTER,UDRE_REG)==0);

	UDR_REGISTER = data;
}

u8 UART_u8GetChar (void)
{
	u8 result;
	// Wait until Reception Complete
	while(get_bit(UCSRA_REGISTER,RXC_REG)==0);

	result = UDR_REGISTER;

	//Clear flag
	set_bit(UCSRA_REGISTER,RXC_REG);

	return result;

}
