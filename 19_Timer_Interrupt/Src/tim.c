#include "stm32f4xx.h"

#define TIM4EN       (1U<<2)
#define CR1_CEN      (1U<<0)

#define DIER_UIE     (1U<<0)

void tim4_1hz_init(void)
{
	/*Enable clock access */
	RCC->APB1ENR |= TIM4EN;
	/*Set Prescaler value*/
	TIM4->PSC = 1600 - 1; //16 000 000 / 1600 = 10 000
	/*Set auto-reload value */
	TIM4->ARR = 10000 - 1; // 10000 / 10000 = 1
	/*clear counter */
	TIM4->CNT = 0;
	/*Enable Timer */
	TIM4->CR1 = CR1_CEN;
}


void tim4_1hz_interrupt_init(void)
{
	/*Enable clock access */
	RCC->APB1ENR |= TIM4EN;
	/*Set Prescaler value*/
	TIM4->PSC = 1600 - 1; //16 000 000 / 1600 = 10 000
	/*Set auto-reload value */
	TIM4->ARR = 10000 - 1; // 10000 / 10000 = 1
	/*clear counter */
	TIM4->CNT = 0;
	/*Enable Timer */
	TIM4->CR1 = CR1_CEN;

	/* Enable TIM interrupt */
	TIM4->DIER |= DIER_UIE;

	/*Enable TIM interrupt in NVIC */
	NVIC_EnableIRQ(TIM4_IRQn);

}
