/*
 * WDT.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Assem
 */

#include "../../STD_Types.h"
#include "../../macros.h"
#include "../DIO/DIO.h"
#include "WDT.h"
#define F_CPU 8000000UL
#include "avr/delay.h"

/*Watchdog Timer Control Register*/
#define WDTCR_REGISTER *((volatile u8*) 0x41)
#define WDP0_REG 0
#define WDP1_REG 1
#define WDP2_REG 2
#define WDE_REG  3
#define WDTOE_REG 4

void WDT_Init(void)
{
	set_bit(WDTCR_REGISTER,WDP1_REG);
	set_bit(WDTCR_REGISTER,WDP2_REG);
	set_bit(WDTCR_REGISTER,WDE_REG);

}

void WDT_Disable(void)
{
	//Write logical one to WDTOE and WDE
	WDTCR_REGISTER = (1<<WDTOE_REG) | (1<< WDE_REG);

	//Turn off WDT
	WDTCR_REGISTER=0x00;
}
