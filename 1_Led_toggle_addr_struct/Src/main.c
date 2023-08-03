#include <stdint.h>

#define PERIPH_BASE				(0x40000000UL)
#define AHB1PERIPH_OFFSET		(0x00020000UL)
#define AHB1PERIPH_BASE	        (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOD_OFFSET			(0x0000UL)

#define GPIOD_BASE				(AHB1PERIPH_BASE + GPIOD_OFFSET)

#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)




#define  GPIODEN				(1U<<3) //   0b 0000 0000 0000 0000 0000 0000 0000 0001

#define PIN12					(1U<<12)
#define LED_PIN					 PIN12

#define __IO  volatile


typedef struct
{
  volatile uint32_t DUMMY[12];
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */

} RCC_TypeDef;



typedef struct
{
	volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */

} GPIO_TypeDef;



#define RCC		    ((RCC_TypeDef*) RCC_BASE)
#define GPIOD		((GPIO_TypeDef*)GPIOD_BASE)


int main(void)
{
	/*1. Enable clock access to GPIOA*/

	 RCC->AHB1ENR |=  GPIODEN;

	/*2.Set PA5 as output pin*/


	 GPIOD->MODER |= (1U<<24);  // Set bit 10 to 1
	 GPIOD->MODER &=~(1U<<25); //  Set bit 11 to 0


	while(1)
	{



		GPIOD->ODR^= LED_PIN;

		for(int i=0;i<10000;i++){}

	}
}



