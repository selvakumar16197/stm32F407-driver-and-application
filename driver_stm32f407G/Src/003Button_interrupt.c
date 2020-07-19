/*
 * 003Button_interrupt.c
 *
 *  Created on: 07-Apr-2020
 *      Author: Selva Kumar
 */
#include <string.h>
//#include "stm32f4xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
	GPIO_handle_t GpioLed1,GpioBt;

	//settting the members in structure to zero
	memset(&GpioLed1,0,sizeof(GpioLed1));
	memset(&GpioBt,0,sizeof(GpioBt));

	//
	GpioLed1.pGPIOx = GPIOD;
	GpioLed1.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed1.GPIO_pinconfig.GPIO_PinMode   = GPIO_MODE_OUT;
	GpioLed1.GPIO_pinconfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
	GpioLed1.GPIO_pinconfig.GPIO_PinOPType = GPIO_TYPE_PP;
	GpioLed1.GPIO_pinconfig.GPIO_PinOPType = GPIO_NO_PUPD;


	GPIO_PeriClockControl(GPIOD,ENABLE);
	GPIO_Init(&GpioLed1);


	    GpioBt.pGPIOx = GPIOA;
		GpioBt.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_0;
		GpioBt.GPIO_pinconfig.GPIO_PinMode   = GPIO_MODE_IT_RT;
		GpioBt.GPIO_pinconfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
		GpioBt.GPIO_pinconfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

		GPIO_Init(&GpioBt);
	    GPIO_PeriClockControl(GPIOA,ENABLE);

	    //IRQ_configuration
	    GPIO_IRQPriorityConfig(IRQ_NO_EXTI0,NVIC_IRQ_PRI0);
	    GPIO_IRQConfig(IRQ_NO_EXTI0,ENABLE);

	    while(1);

	return 0;
}

void EXTI0_IRQHandler(void)
{
	GPIO_IRQHandling(GPIO_PIN_NO_0);
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_13);
}
