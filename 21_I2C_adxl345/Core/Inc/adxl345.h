/*
 * adxl345.h
 *
 *  Created on: 1 May 2023
 *      Author: mehmet.tartan
 */

#ifndef INC_ADXL345_H_
#define INC_ADXL345_H_


#include "i2c.h"
#include <stdint.h>

#define   DEVID_R					(0x00)
#define   DEVICE_ADDR    			(0x53)
#define   DATA_FORMAT_R   			(0x31)
#define   POWER_CTL_R 				(0x2D)
#define   DATA_START_ADDR			(0x32)

#define		FOUR_G					(0x01)
#define		RESET					(0x00)
#define     SET_MEASURE_B		    (0x08) //0b 1000

void adxl_init (void);
void adxl_read_values (uint8_t reg);

#endif /* INC_ADXL345_H_ */
