
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"

#define GPIODEN        		(1U<<3)
#define GPIOD_13         	(1U<<13)

#define LED_PIN             (GPIOD_13)

char key;

static void uart_callback(void);

int main(void)
{
	RCC->AHB1ENR |= GPIODEN;

	GPIOD->MODER |= (1U<<26);
	GPIOD->MODER &=~ (1U<<27);

	uart2_rx_interrupt_init();

	while(1)
	{

	}
}

static void uart_callback(void)
{

	key = USART2->DR;
	if(key == '1')
	{
		GPIOD->ODR |= LED_PIN;
	}
	else
	{
		GPIOD->ODR &=~ LED_PIN;
	}
}

void USART2_IRQHandler(void)
{
	if(USART2->SR & SR_RXNE)
	{
		uart_callback();
	}
}



















