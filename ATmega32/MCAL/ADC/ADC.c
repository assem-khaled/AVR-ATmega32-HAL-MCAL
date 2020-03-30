/*
 * ADC.c
 *
 *  Created on: Oct 3, 2019
 *      Author: Assem
 */

#include "../../STD_Types.h"
#include "../../macros.h"
#include "../DIO/DIO.h"
#include "ADC.h"
#define F_CPU	8000000UL
#include "avr/delay.h"

/*ADC Multiplexer Selection Register*/
#define ADMUX_REGISTER *((volatile u8*) 0x27)
#define MUX0_REG  0
#define MUX1_REG  1
#define MUX2_REG  2
#define MUX3_REG  3
#define MUX4_REG  4
#define ADLAR_REG 5
#define REFS0_REG 6
#define REFS1_REG 7
/*ADC Control and Status Register A*/
#define ADCSRA_REGISTER *((volatile u8*) 0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7
/*The ADC Data Register*/
#define ADCH_REGISTER *((volatile u16*) 0x25)
#define ADCL_REGISTER *((volatile u16*) 0x24)


void ADC_vidInit(void)
{
	//AVCC with external capacitor at AREF pin
	set_bit(ADMUX_REGISTER,REFS0_REG);

	//ADC Enable
	set_bit(ADCSRA_REGISTER,ADEN);

	//ADC Interrupt Enable
	//set_bit(ADCSRA_REGISTER,ADIE);

	//ADC Prescaler
	//set_bit(ADCSRA_REGISTER,ADPS0);
	//set_bit(ADCSRA_REGISTER,ADPS1);
	//set_bit(ADCSRA_REGISTER,ADPS2);


}

u16 ADC_u16Read(u8 channel)
{
	//Input Channel: Single Ended Input
	channel &= 0x07;
	ADMUX_REGISTER  &= 0xE0;
	ADMUX_REGISTER |= channel;


	//ADC Start Conversion
	set_bit(ADCSRA_REGISTER,ADSC);

	//ADC flag : wait for conversion
	while(get_bit(ADCSRA_REGISTER,ADIF)==0);

	//ADC flag clear
	set_bit(ADCSRA_REGISTER,ADIF);

	return ADCL_REGISTER;
}
