/*
 * 002LedButton.c
 *
 *  Created on: 04-Apr-2020
 *      Author: Selva Kumar
 */



#include "stm32f4xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
	GPIO_handle_t GpioLed1,GpioLed2,GpioLed3,GpioLed4,GpioBt;

	/*
	GpioLed1.pGPIOx = GPIOD;
	GpioLed1.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed1.GPIO_pinconfig.GPIO_PinMode   = GPIO_MODE_OUT;
	GpioLed1.GPIO_pinconfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	GpioLed1.GPIO_pinconfig.GPIO_PinOPType = GPIO_TYPE_OD;
	GpioLed1.GPIO_pinconfig.GPIO_PinOPType = GPIO_PIN_PU;

	GpioLed2.pGPIOx = GPIOD;
	GpioLed2.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GpioLed2.GPIO_pinconfig.GPIO_PinMode   = GPIO_MODE_OUT;
	GpioLed2.GPIO_pinconfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	GpioLed2.GPIO_pinconfig.GPIO_PinOPType = GPIO_TYPE_PP;
	GpioLed2.GPIO_pinconfig.GPIO_PinOPType = GPIO_NO_PUPD;

	GpioLed3.pGPIOx = GPIOD;
	GpioLed3.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed3.GPIO_pinconfig.GPIO_PinMode   = GPIO_MODE_OUT;
	GpioLed3.GPIO_pinconfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	GpioLed3.GPIO_pinconfig.GPIO_PinOPType = GPIO_TYPE_PP;
	GpioLed3.GPIO_pinconfig.GPIO_PinOPType = GPIO_NO_PUPD;

	GpioLed4.pGPIOx = GPIOD;
	GpioLed4.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GpioLed4.GPIO_pinconfig.GPIO_PinMode   = GPIO_MODE_OUT;
	GpioLed4.GPIO_pinconfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	GpioLed4.GPIO_pinconfig.GPIO_PinOPType = GPIO_TYPE_PP;
	GpioLed4.GPIO_pinconfig.GPIO_PinOPType = GPIO_NO_PUPD;
*/

	GpioLed2.pGPIOx = GPIOB;
	GpioLed2.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GpioLed2.GPIO_pinconfig.GPIO_PinMode   = GPIO_MODE_OUT;
	GpioLed2.GPIO_pinconfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	GpioLed2.GPIO_pinconfig.GPIO_PinOPType = GPIO_TYPE_PP;



	//GPIO_PeriClockControl(GPIOB,ENABLE);
	//GPIO_Init(&GpioLed1);
	GPIO_Init(&GpioLed2);
	//GPIO_Init(&GpioLed3);
	//GPIO_Init(&GpioLed4);

	    GpioBt.pGPIOx = GPIOA;
		GpioBt.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_0;
		GpioBt.GPIO_pinconfig.GPIO_PinMode   = GPIO_MODE_IN;
		GpioBt.GPIO_pinconfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
		GpioBt.GPIO_pinconfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

		GPIO_Init(&GpioBt);
	    //GPIO_PeriClockControl(GPIOA,ENABLE);

	while(1)
	{
		if(GPIO_ReadInputPin(GPIOA,GPIO_PIN_NO_0) == 1)
		{
		delay();
		GPIO_ToggleOutputPin(GPIOB,GPIO_PIN_NO_15);
		//GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
		//GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_15);
		}
	}
	return 0;
}

void EXTI_IRQHandler(void)
{
	//handle the interrupt
	GPIO_IRQHandling(0);
}

