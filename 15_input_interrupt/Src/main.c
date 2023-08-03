#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

#define GPIODEN				   (1U<<3)
#define PIN12				   (1U<<12)

#define LED				   		PIN12

int timestamp = 0;

static void exti_callback(void);

int main(void)
{

	/*1.Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIODEN;

	/*2.Set PD12 as output pin*/
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &=~(1U<<25);

	pa0_exti_init();
	uart2_tx_init();

	while(1)
	{

	}
}

static void exti_callback(void)
{
	printf("BTN Pressed...\n\r");
	GPIOD->ODR ^= LED;
}

void EXTI0_IRQHandler(void)
{
	if ((EXTI->PR & LINE0) != 0)
	{
		/*Clear PR Flag */
		EXTI->PR |= LINE0;

		exti_callback();

	}
}












