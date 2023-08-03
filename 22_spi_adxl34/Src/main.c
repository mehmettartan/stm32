
#include <stdio.h>
#include <stdint.h>
#include "adxl345.h"

int16_t x, y,z;
float xq, yq, zq;

uint8_t data_rec[6];

const float FOUR_G_SCALE_FACT = 0.0078;

int main(void)
{
	adxl_init();

	while(1)
	{
		adxl_read(DATA_START_ADDR,data_rec);

		x = ((data_rec[1]<<8) | data_rec[0]);
		y = ((data_rec[3]<<8) | data_rec[2]);
		z = ((data_rec[5]<<8) | data_rec[4]);

		xq = x * FOUR_G_SCALE_FACT;
		yq = y * FOUR_G_SCALE_FACT;
		zq = z * FOUR_G_SCALE_FACT;
	}
}




















