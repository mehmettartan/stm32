
#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stm32f407xx.h"
#include "stdint.h"

void SPI_Gpio_init();
void Spi_config();
void spi1_transmit(uint8_t *data, uint32_t size);
void spi1_receive(uint8_t *data, uint32_t size);
void cs_enable();
void cs_disable();


#endif /* INC_SPI_H_ */
