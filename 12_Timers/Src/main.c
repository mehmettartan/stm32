#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

#define GPIODEN				   (1U<<3)
#define PIN14				   (1U<<14)

#define LED				   		PIN14


int main(void)
{
	/*1.Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIODEN;

	/*2.Set PD12 as output pin*/
	GPIOD->MODER |= (1U<<28);
	GPIOD->MODER &=~(1U<<29);

	uart2_tx_init();
	tim4_1hz_init();

	while(1)
	{
		/*wait for UIF */
		while(!(TIM4->SR & SR_UIF)) { }

		/*Clear UIF*/
		TIM4->SR &=~SR_UIF;

		GPIOD->ODR ^= LED;

		printf("A second passed !! \n\r");


	}
}












