#include "stm32f4xx.h"
#include "tim.h"

void TIM_Config(void);

int main(void)
{
	tim4_pd12_output_compare();

	while(1)
	{

	}
}
