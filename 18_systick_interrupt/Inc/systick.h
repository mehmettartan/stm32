/*
 * systick.h
 *
 *  Created on: Apr 18, 2023
 *      Author: ubuntu
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

void systickDelayMs(int delay);

void systick_1hz_interrupt(void);

#endif /* SYSTICK_H_ */
