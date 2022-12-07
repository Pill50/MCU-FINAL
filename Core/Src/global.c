/*
 * global.c
 *
 *  Created on: Dec 7, 2022
 *      Author: Hoang
 */


#include "global.h"
char traffic_light_num[50];

//HAL_UART_Transmit(huart, info,
//					sprintf(info,"Toggle red led start at %d\r",HAL_GetTick()), 100);
int pwm = 0;
