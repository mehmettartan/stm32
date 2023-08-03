#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

#define GPIODEN				   (1U<<3)
#define PIN15				   (1U<<15)

#define LED				   		PIN15


int main(void)
{
	/*1.Enable clock access to GPIOD*/
	RCC->AHB1ENR |= GPIODEN;

	/*2.Set PD15 as output pin*/
	GPIOD->MODER |= (1U<<30);
	GPIOD->MODER &=~(1U<<31);

	uart2_tx_init();
	tim4_1hz_interrupt_init();

	while(1)
	{


	}
}

static void tim4_callback(void)
{
	printf("A second timer passed !! \n\r");
	GPIOD->ODR ^= LED;
}

void TIM4_IRQHandler(void)
{
	/*Clear update interrupt flag */
	TIM4->SR &=~ SR_UIF;

	tim4_callback();
}
