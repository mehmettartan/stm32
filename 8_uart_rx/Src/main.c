#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"

#define GPIODEN        		(1U<<3)
#define GPIOD_15         	(1U<<15)
#define GPIOD_14         	(1U<<14)
#define GPIOD_13         	(1U<<13)
#define GPIOD_12         	(1U<<12)

#define LED_PIN1             (GPIOD_15)
#define LED_PIN2             (GPIOD_14)
#define LED_PIN3             (GPIOD_13)
#define LED_PIN4             (GPIOD_12)

char key;

int main(void)
{
	RCC->AHB1ENR |= GPIODEN;

	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &=~ (1U<<25);

	GPIOD->MODER |= (1U<<26);
	GPIOD->MODER &=~ (1U<<27);

	GPIOD->MODER |= (1U<<28);
	GPIOD->MODER &=~ (1U<<29);

	GPIOD->MODER |= (1U<<30);
	GPIOD->MODER &=~ (1U<<31);


	uart2_rxtx_init();

	while(1)
	{

		key = uart2_read();

		switch(key)
		{
		case '1' :
			GPIOD->ODR |= LED_PIN1;
			GPIOD->ODR &=~ LED_PIN2;
			GPIOD->ODR &=~ LED_PIN3;
			GPIOD->ODR &=~ LED_PIN4;
			uart2_write(key);
			break;
		case '2' :
			GPIOD->ODR |= LED_PIN1;
			GPIOD->ODR |= LED_PIN2;
			GPIOD->ODR &=~ LED_PIN3;
			GPIOD->ODR &=~ LED_PIN4;
			uart2_write(key);
			break;
		case '3' :
			GPIOD->ODR |= LED_PIN1;
			GPIOD->ODR |= LED_PIN2;
			GPIOD->ODR |= LED_PIN3;
			GPIOD->ODR &=~ LED_PIN4;
			uart2_write(key);
			break;
		case '4' :
			GPIOD->ODR |= LED_PIN1;
			GPIOD->ODR |= LED_PIN2;
			GPIOD->ODR |= LED_PIN3;
			GPIOD->ODR |= LED_PIN4;
			uart2_write(key);
			break;

		case '0' :
			GPIOD->ODR &=~ LED_PIN1;
			GPIOD->ODR &=~ LED_PIN2;
			GPIOD->ODR &=~ LED_PIN3;
			GPIOD->ODR &=~ LED_PIN4;
			break;

		}
	}
}
