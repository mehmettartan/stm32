/*
 * systick.c
 *
 *  Created on: Apr 18, 2023
 *      Author: ubuntu
 */


#include "stm32f4xx.h"

#define SYSTICK_LOAD_VAL     16000
#define CTRL_ENABLE          (1U<<0)
#define CTRL_CLKSRC          (1U<<2)
#define CTRL_COUNTFLG        (1U<<16)
#define CTRL_TICKINT         (1U<<1)

#define ONE_SEC_LOAD         16000000

void systickDelayMs(int delay)
{
	/*Reload with number of clock per milisecond */
	SysTick->LOAD = SYSTICK_LOAD_VAL;

	/*Clear SysTick current value register */
	SysTick->VAL = 0;

	/*Enable systick and select internal clk_src */
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	for(int i = 0; i < delay; i++)
	{
		//Wait until the COUNTFLAG is set*/

		while(SysTick->CTRL & CTRL_COUNTFLG == 0) { }
	}

	SysTick->CTRL = 0;
}

void systick_1hz_interrupt(void)
{
	/*Reload with number of clock per milisecond */
	SysTick->LOAD = ONE_SEC_LOAD - 1;

	/*Clear SysTick current value register */
	SysTick->VAL = 0;

	/*Enable systick and select internal clk_src */
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	/*Enable Systick interrupt	 */

	SysTick->CTRL |= CTRL_TICKINT;
}











