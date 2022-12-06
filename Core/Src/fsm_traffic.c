/*
 * fsm_manual.c
 *
 *  Created on: Dec 2, 2022
 *      Author: DELL
 */

#include "input_reading.h"
#include "fsm_traffic.h"
#include "global.h"
#include "software_timer.h"
#include "main.h"

void fsm_horizontal_automatic_run() {
	switch(status_horizontal) {
	case INIT:
		status_horizontal = AUTO_RED;
		setTimer1(5000);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		if(timer1_flag == 1) {
			status_horizontal = AUTO_GREEN;
			setTimer1(3000);
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
		if(timer1_flag == 1) {
			status_horizontal = AUTO_RED;
			setTimer1(5000);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
		if(timer1_flag == 1) {
			status_horizontal = AUTO_YELLOW;
			setTimer1(2000);
		}
		break;
	default:
		break;
	}
}

void fsm_vertical_automatic_run() {
	switch(status_vertical) {
		case INIT:
			status_vertical = AUTO_GREEN;
			setTimer2(3000);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			if(timer2_flag == 1) {
				status_vertical = AUTO_GREEN;
				setTimer2(3000);
			}
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
			if(timer2_flag == 1) {
				status_vertical = AUTO_RED;
				setTimer2(5000);
			}
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			if(timer2_flag == 1) {
				status_vertical = AUTO_YELLOW;
				setTimer2(2000);
			}
			break;
		default:
			break;
		}
}
