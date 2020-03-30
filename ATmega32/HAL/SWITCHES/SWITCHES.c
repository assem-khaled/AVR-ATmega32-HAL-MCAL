/*
 * MOTOR.c
 *
 *  Created on: Sep 5, 2019
 *      Author: Assem
 */

#include "../../STD_Types.h"
#include "../../macros.h"
#include "../../MCAL/DIO/DIO.h"
#include "../SWITCHES/SWITCHES.h"
#include "../SWITCHES/SWITCHES_CFG.h"
#define F_CPU	8000000UL
#include "avr/delay.h"

void SWTCH_vidH_BRIDGE(u8 FirstPinPWR , u8 SecPinPWR )
{
	/*HIGH & HIGH ==> BOOM */
	if (FirstPinPWR == HIGH && SecPinPWR == HIGH)
	{
		FirstPinPWR=LOW;
	    SecPinPWR=LOW;
	}

	if (FirstPinPWR == HIGH && SecPinPWR == HIGH)
		{return;}

	DIO_vidSetPinDir(Hbridge_PORT,Hbridge_PIN1,OUTPUT);
	DIO_vidSetPinDir(Hbridge_PORT,Hbridge_PIN2,OUTPUT);

	DIO_vidSetPinValue(Hbridge_PORT,Hbridge_PIN1,FirstPinPWR);
	DIO_vidSetPinValue(Hbridge_PORT,Hbridge_PIN2,SecPinPWR);
}

void SWTCH_vidOPTOCOUPLER(u8 PWR)
{
	DIO_vidSetPinDir(OptoCoupler_PORT,OptoCoupler_PIN,OUTPUT);

	DIO_vidSetPinValue(OptoCoupler_PORT,OptoCoupler_PIN,PWR);
}

void SWTCH_vidRELAY(u8 PWR)
{
	DIO_vidSetPinDir(Relay_PORT,Relay_PIN,OUTPUT);

	DIO_vidSetPinValue(Relay_PORT,Relay_PIN,PWR);
}
