/*
 * WDT.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Assem
 */

#ifndef MCAL_WDT_WDT_H_
#define MCAL_WDT_WDT_H_

void WDT_Init(void);
void WDT_Disable(void);


#define WDT_Refresh()   __asm__ volatile ("WDR");

#endif /* MCAL_WDT_WDT_H_ */
