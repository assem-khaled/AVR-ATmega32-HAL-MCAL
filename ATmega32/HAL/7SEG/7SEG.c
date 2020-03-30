/*
 * 7SEG.c
 *
 *  Created on: Sep 5, 2019
 *      Author: Assem
 */

#include "../../STD_Types.h"
#include "../../macros.h"
#include "../../MCAL/DIO/DIO.h"
#include "7SEG.h"
#include "7SEG_CFG.h"
#define F_CPU	8000000UL
#include "avr/delay.h"



static u8 Numbers[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};


void SEG_vidDisplaySeg1(u8 Number)
{
	DIO_vidSetPortDir(SEG1_PORT,OUTPUT);
	DIO_vidSetPortValue(SEG1_PORT,Number);
}

void SEG_vidDisplaySeg2(u8 Number)
{
	DIO_vidSetPortDir(SEG2_PORT,OUTPUT);
	DIO_vidSetPortValue(SEG2_PORT,Number);
}

void SEG_vidDisplayTwoSeg(u8 Number1 , u8 Number2)
{
	/*First 7-seg*/
	DIO_vidSetPortDir(SEG1_PORT,OUTPUT);
	DIO_vidSetPortValue(SEG1_PORT,Number1);
	/*Second 7-seg*/
	DIO_vidSetPortDir(SEG2_PORT,OUTPUT);
	DIO_vidSetPortValue(SEG2_PORT,Number2);
}

void SEG_vidCountSeg1(u16 u16Time)
{
	u8 i ;

	DIO_vidSetPortDir(SEG1_PORT,OUTPUT);

	for (i=0;i<10;i++)
	{
		DIO_vidSetPortValue(SEG1_PORT,Numbers[i]);
		_delay_ms(u16Time);
	}
}

void SEG_vidCountSeg2(u16 u16Time)
{
	u8 i ;

	DIO_vidSetPortDir(SEG2_PORT,OUTPUT);

	for (i=0;i<10;i++)
	{
		DIO_vidSetPortValue(SEG2_PORT,Numbers[i]);
		_delay_ms(u16Time);
	}
}

void SEG_vidCountTwoSeg(u16 u16Time)
{
	u8 c1 ,c2 ;
	DIO_vidSetPortDir(SEG1_PORT,OUTPUT);
	DIO_vidSetPortDir(SEG2_PORT,OUTPUT);

	for (c1=0;c1<10;c1++)
	{
		DIO_vidSetPortValue(SEG1_PORT,Numbers[c1]);

		for (c2=0;c2<10;c2++)
		{
			DIO_vidSetPortValue(SEG2_PORT,Numbers[c2]);
			_delay_ms(u16Time);
		}

	}


}

