/*
 * button.c
 *
 *  Created on: Dec 2, 2022
 *      Author: DELL
 */

#include "input_reading.h"
#include "main.h"
#define NO_OF_BUTTONS 4
#define BUTTON_IS_PRESSED  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS]={BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[NO_OF_BUTTONS];

static uint16_t buttonPin[NO_OF_BUTTONS]={BUTTON_1_Pin,BUTTON_2_Pin,BUTTON_3_Pin,BUTTON_4_Pin};
static GPIO_TypeDef* buttonPort[NO_OF_BUTTONS]={BUTTON_1_GPIO_Port,BUTTON_2_GPIO_Port,BUTTON_3_GPIO_Port,BUTTON_4_GPIO_Port};

int duration_for_buttons;

void button_reading()
{
	for(uint8_t i=0;i<NO_OF_BUTTONS;i++)
	{
		debounceButtonBuffer2[i]=debounceButtonBuffer1[i];
		debounceButtonBuffer1[i]=HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
		if(debounceButtonBuffer1[i]==debounceButtonBuffer2[i])
		{
			if(debounceButtonBuffer3[i]!=debounceButtonBuffer1[i])
			{
				debounceButtonBuffer3[i]=debounceButtonBuffer1[i];
				if(debounceButtonBuffer1[i]==BUTTON_IS_PRESSED)
				{
					buttonBuffer[i]=BUTTON_IS_PRESSED;
					duration_for_buttons=100;
				}
			}
			else
			{
				duration_for_buttons--;
				if(duration_for_buttons<=0)
				{
					debounceButtonBuffer3[i]=BUTTON_IS_RELEASED;
				}
			}
		}
	}
}

int is_button_pressed(uint8_t index)
{
	if(buttonBuffer[index]==BUTTON_IS_PRESSED)
	{
		buttonBuffer[index]=BUTTON_IS_RELEASED;
		return 1;
	}
	else return 0;
}
