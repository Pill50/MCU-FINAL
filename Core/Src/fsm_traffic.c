/*
 * fsm_manual.c
 *
 *  Created on: Dec 2, 2022
 *      Author: DELL
 */

#include "fsm_traffic.h"
#include "button.h"
#include "global.h"
#include "software_timer.h"
#include "main.h"

void fsm_automatic_run() {
	switch(status) {
	case INIT:
		status = AUTO_RED;
		break;
	case AUTO_RED:
		if(timer1_flag == 1) {
//			HAL_GPIO_WritePin(GPIOA, Led_red_Pin, SET);
//			HAL_GPIO_WritePin(GPIOA, Led_green_Pin, SET);
			status = AUTO_GREEN;
			setTimer1(3000);
		}
		break;
	case AUTO_YELLOW:
		if(timer1_flag == 1) {
			status = AUTO_RED;
			setTimer1(5000);
//		    HAL_GPIO_WritePin(Led_red_GPIO_Port, Led_red_Pin, SET);
//			HAL_GPIO_WritePin(Led_green_GPIO_Port, Led_green_Pin, SET);
		}
		break;
	case AUTO_GREEN:
		if(timer1_flag == 1) {
			status = AUTO_YELLOW;
			setTimer1(2000);
		}
		break;
	default:
		break;
	}
}

