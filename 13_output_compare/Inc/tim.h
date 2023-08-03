/*
 * tim.h
 *
 *  Created on: Apr 19, 2023
 *      Author: ubuntu
 */

#ifndef TIM_H_
#define TIM_H_

void tim4_1hz_init(void);
void tim4_pd12_output_compare(void);

#define SR_UIF   (1U<<0)

#endif /* TIM_H_ */
