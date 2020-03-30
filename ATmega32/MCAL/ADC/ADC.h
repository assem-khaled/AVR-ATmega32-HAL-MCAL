/*
 * ADC.h
 *
 *  Created on: Oct 3, 2019
 *      Author: Assem
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

void ADC_vidInit(void);
u16 ADC_u16Read(u8 channel);

#define ADC0 (u8)0
#define ADC1 (u8)1
#define ADC2 (u8)2
#define ADC3 (u8)3
#define ADC4 (u8)4
#define ADC5 (u8)5
#define ADC6 (u8)6
#define ADC7 (u8)7


#endif /* MCAL_ADC_ADC_H_ */
