#include "stm32f4xx.h"


#define GPIODEN		 (1U<<3)
#define GPIOAEN		 (1U<<0)

#define TIM4EN       (1U<<2)
#define TIM3EN       (1U<<1)

#define CR1_CEN      (1U<<0)
#define OC_TOGGLE    ((1U<<4) | (1U<<5))
#define OC_TOGGLE2   ((1U<<13) | (1U<<12))
#define CCER_CCR1E   (1U<<0)
#define CCER_CCR2E   (1U<<4)
#define CCER_CCR3E   (1U<<8)
#define CCER_CCR4E   (1U<<12)

#define CCER_CC1S    (1U<<0)


void tim4_1hz_init(void)
{
	/*Enable clock access */
	RCC->APB1ENR |= TIM4EN;
	/*Set Prescaler value*/
	TIM4->PSC = 1600 - 1; //16 000 000 / 1600 = 10 000
	/*Set auto-reload value */
	TIM4->ARR = 1000 - 1; // 10000 / 10000 = 1
	/*clear counter */
	TIM4->CNT = 0;
	/*Enable Timer */
	TIM4->CR1 = CR1_CEN;
}

void tim4_pd12_output_compare(void)
{
	/* Enable clock access to GPIOD */
	RCC->AHB1ENR |= GPIODEN;
	/*Set GPIOD pins 12 - 15 to alternate mode */
	GPIOD->MODER &=~ (1U<<24);
	GPIOD->MODER |= (1U<<25);

	GPIOD->MODER &=~ (1U<<26);
	GPIOD->MODER |= (1U<<27);

	GPIOD->MODER &=~ (1U<<28);
	GPIOD->MODER |= (1U<<29);

	GPIOD->MODER &=~ (1U<<30);
	GPIOD->MODER |= (1U<<31);

	/* Set alternate function to AF2 (TIM4) */
	GPIOD->AFR[1] |= (1U<<17);
	GPIOD->AFR[1] |= (1U<<21);
	GPIOD->AFR[1] |= (1U<<25);
	GPIOD->AFR[1] |= (1U<<29);

	/*Enable clock access */
	RCC->APB1ENR |= TIM4EN;
	/*Set Prescaler value*/
	TIM4->PSC = 1600 - 1; //16 000 000 / 1600 = 10 000
	/*Set auto-reload value */
	TIM4->ARR = 10000 - 1; // 10000 / 10000 = 1
	/*Set output compare toggle mode	 */
	TIM4->CCMR1 |= OC_TOGGLE;
	TIM4->CCMR1 |= OC_TOGGLE2;
	TIM4->CCMR2 |= OC_TOGGLE;
	TIM4->CCMR2 |= OC_TOGGLE2;
	/*Enable tim4 ch1 in compare mode */
	TIM4->CCER |= CCER_CCR1E;
	TIM4->CCER |= CCER_CCR2E;
	TIM4->CCER |= CCER_CCR3E;
	TIM4->CCER |= CCER_CCR4E;

	/*clear counter */
	TIM4->CNT = 0;
	/*Enable Timer */
	TIM4->CR1 = CR1_CEN;
}

void tim3_pa6_input_capture(void)
{
	/* Enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;
	/* Set PA6 mode to alternate function */
	GPIOA->MODER &=~ (1U<<12);
	GPIOA->MODER |= (1U<<13);
	/* Set PA6 alternate function type to TIM3_CH1(AF01) */
	GPIOA->AFR[0] |= (1U<<25);
	/* Enable clock access to tim3 */
	RCC->APB1ENR |= TIM3EN;
	/* Set prescaler */
	TIM3->PSC = 16000 - 1;
	/* Set CH1 to input capture */
	TIM3->CCMR1 = CCER_CC1S;
	/* Set CH1 to capture at rising edge */
	TIM3->CCER = CCER_CCR1E;
	/* Enable TIM3 */
	TIM3->CR1 = CR1_CEN;
}

