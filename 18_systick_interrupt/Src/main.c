#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"

#define GPIODEN				   (1U<<3)
#define PIN13				   (1U<<13)

#define LED				   		PIN13

void systick_callback(void);

int main(void)
{
	/*1.Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIODEN;

	/*2.Set PA5 as output pin*/
	GPIOD->MODER |= (1U<<26);
	GPIOD->MODER &=~(1U<<27);

	uart2_tx_init();
	systick_1hz_interrupt();

	while(1)
	{

	}
}

void systick_callback(void)
{
	printf("A second passed !! \n\r");
	GPIOD->ODR ^= LED;
}

void SysTick_Handler(void)
{
	systick_callback();
}







