#include "stm32f4xx.h"
#include "adc.h"
#include "uart.h"

uint32_t sensor_value;

static void adc_callback(void);

int main(void)
{
	uart2_tx_init();
	pa1_adc_interrupt_init();
	start_conversion();

	while(1)
	{

	}
}

static void adc_callback(void)
{
	sensor_value = adc_read();
	printf("Sensor value: %d \n\r", sensor_value);
}

void ADC_IRQHandler(void)
{
	/*Check for eoc in SR */
	if ((ADC1->SR & SR_EOC) != 0)
	{
		/*Clear EOC */
		ADC1->SR &=~ SR_EOC;
		adc_callback();
	}
}
