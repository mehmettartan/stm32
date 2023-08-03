#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"
#include "uart.h"

#define GPIODEN				   (1U<<3)
#define PIN15				   (1U<<15)

#define LED				   		PIN15



int main(void)
{
	/*1.Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIODEN;

	/*2.Set PA5 as output pin*/
	GPIOD->MODER |= (1U<<30);
	GPIOD->MODER &=~(1U<<31);

	uart2_tx_init();

	while(1)
	{
		printf("A second passed !! \n\r");
		GPIOD->ODR ^= LED;
		systickDelayMs(1000000);
	}
}
