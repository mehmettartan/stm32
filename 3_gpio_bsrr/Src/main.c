#include "stm32f4xx.h"








#define GPIODEN                 (1U<<3)
#define PIN13                    (1U<<13)
#define LED_PIN                 PIN13

int main(void)
{
	RCC->AHB1ENR |= GPIODEN;

	GPIOD->MODER |= (1U<<26);
	GPIOD->MODER &=~(1U<<27);

	while(1)
	{
		GPIOD->ODR ^= LED_PIN;
		for(int i = 0; i<1000000; i++)
		{

		}
	}
}
