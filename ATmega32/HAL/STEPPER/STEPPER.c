/*
 * STEPPER.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Assem
 */

#include "../../STD_Types.h"
#include "../../macros.h"
#include "../../MCAL/DIO/DIO.h"
#include "STEPPER.h"
#include "STEPPER_CFG.h"
#define F_CPU	8000000UL
#include "avr/delay.h"

void STEPPER_vidTurn(u16 u16Degree, u16 u16Time)
{
	u16 step;

	/*Set Port as output*/
    DIO_vidSetPinDir(STEP_PORT,STEP_PIN0,OUTPUT);
    DIO_vidSetPinDir(STEP_PORT,STEP_PIN1,OUTPUT);
    DIO_vidSetPinDir(STEP_PORT,STEP_PIN2,OUTPUT);
    DIO_vidSetPinDir(STEP_PORT,STEP_PIN3,OUTPUT);

    /*set PIN -> LOW*/
	DIO_vidSetPinValue(STEP_PORT,STEP_PIN0,LOW);
	DIO_vidSetPinValue(STEP_PORT,STEP_PIN1,LOW);
	DIO_vidSetPinValue(STEP_PORT,STEP_PIN2,LOW);
	DIO_vidSetPinValue(STEP_PORT,STEP_PIN3,LOW);

 for (step=0;step<(u16Degree* OneLap / 360.0);step++)
 {
	DIO_vidSetPinValue(STEP_PORT, STEP_PIN0,HIGH);
	_delay_ms (u16Time);
	DIO_vidSetPinValue(STEP_PORT, STEP_PIN0,LOW);

	DIO_vidSetPinValue(STEP_PORT, STEP_PIN1,HIGH);
	_delay_ms (u16Time);
	DIO_vidSetPinValue(STEP_PORT, STEP_PIN1,LOW);

	DIO_vidSetPinValue(STEP_PORT, STEP_PIN2,HIGH);
	_delay_ms (u16Time);
	DIO_vidSetPinValue(STEP_PORT, STEP_PIN2,LOW);

	DIO_vidSetPinValue(STEP_PORT, STEP_PIN3,HIGH);
	_delay_ms (u16Time);
	DIO_vidSetPinValue(STEP_PORT, STEP_PIN3,LOW);
 }
}
