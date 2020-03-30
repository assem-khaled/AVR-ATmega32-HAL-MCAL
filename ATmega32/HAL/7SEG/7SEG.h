/*
 * 7SEG.h
 *
 *  Created on: Sep 5, 2019
 *      Author: Assem
 */

#ifndef HAL_7SEG_7SEG_H_
#define HAL_7SEG_7SEG_H_

void SEG_vidDisplaySeg1(u8 Number);
void SEG_vidDisplaySeg2(u8 Number);
void SEG_vidDisplayTwoSeg(u8 Number1 , u8 Number2);
void SEG_vidCountSeg1(u16 u16Time);
void SEG_vidCountSeg2(u16 u16Time);
void SEG_vidCountTwoSeg(u16 u16Time);

#define ZERO    0b00111111
#define ONE     0b00000110
#define TWO     0b01011011
#define THREE   0b01001111
#define FOUR    0b01100110
#define FIVE    0b01101101
#define SIX     0b01111101
#define SEVEN   0b00000111
#define EIGHT   0b01111111
#define NINE    0b01101111
#define DOT     0b10000000
#define TEST    0b11111111


#endif /* HAL_7SEG_7SEG_H_ */
