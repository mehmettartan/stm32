#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

int timestamp = 0;

int main(void)
{

	tim4_pd12_output_compare();
	tim3_pa6_input_capture();

	while(1)
	{
		/*Wait until edge is captured*/
		while(! (TIM3->SR & SR_CC1IF)) { }
		/*Read captured Value */
		timestamp = TIM3->CCR1;
	}
}












