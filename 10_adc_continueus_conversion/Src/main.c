#include "stm32f4xx.h"
#include "adc.h"
#include "uart.h"

uint32_t sensor_value;

int main(void)
{
	pa1_adc_init();
	start_conversion();

	uart2_tx_init();

	while(1)
	{
		sensor_value = adc_read();
		printf("Sensor value: %d \n\r", (int)sensor_value);
	}
}
