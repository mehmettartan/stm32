
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"

#define GPIODEN        		(1U<<3)
#define GPIOD15         	(1U<<15)

#define LED_PIN             (GPIOD15)

uint32_t dma_ty;

static void uart_callback(void);

int main(void)
{
	char message[31] = "Hello from Stm32 DMA transfer\n\r";

	RCC->AHB1ENR |= GPIODEN;

	GPIOD->MODER |= (1U<<30);
	GPIOD->MODER &=~ (1U<<31);

	uart2_tx_init();
	dma1_stream6_init((uint32_t)message, (uint32_t) &USART2->DR, 31);

	while(1)
	{

	}
}

static void dma_callback(void)
{
	GPIOD->ODR |= LED_PIN;
}

void DMA1_Stream6_IRQHandler(void)
{
	/*Check for transfer complate interrupt*/
	if(DMA1->HISR & HISR_TCIF)
	{
		/*Clear flag*/
		DMA1->HIFCR |= HIFCR_CTCIF6;
	    dma_ty = DMA1->HIFCR;
		/*do something*/
		dma_callback();
	}
}



















