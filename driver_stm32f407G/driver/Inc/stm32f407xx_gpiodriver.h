/*
 * stm32f407xx_gpiodriver.h
 *
 *  Created on: 27-Mar-2020
 *      Author: Selva Kumar
 */



#ifndef INC_STM32F407XX_GPIODRIVER_H_

#define INC_STM32F407XX_GPIODRIVER_H_

#include "stm32f4xx.h"

//configuration structure for GPIO

typedef struct
{
    uint8_t GPIO_PinNumber;        //POSSIBLE VALUES FROM @GPIO PIN NUMBERS
    uint8_t GPIO_PinMode;          //possible values from @GPIO PIN MODES
    uint8_t GPIO_PinSpeed;         //possible values from @GPIO SPEED MODES
    uint8_t GPIO_PinPuPdControl;   //possible values from @GPIO PUSHPULL CONTROL
    uint8_t GPIO_PinOPType;        //possible values from @GPIO PIN OP TYPE
    uint8_t GPIO_PinAltFunMode;

}GPIO_pinconfig_t;



//handle structure for GPIO

typedef struct
{
	GPIO_regdef_t *pGPIOx;      //hold base address of GPIO pin
	GPIO_pinconfig_t GPIO_pinconfig;     //hold GPIO pin configuration settings

}GPIO_handle_t;


//GPIO pin modes
//@GPIO PIN MODES

#define GPIO_MODE_IN      0
#define GPIO_MODE_OUT     1
#define GPIO_MODE_ALTFN   2
#define GPIO_MODE_ANALOG  3
#define GPIO_MODE_IT_FT   4
#define GPIO_MODE_IT_RT   5
#define GPIO_MODE_IT_RFT  6

//GPIO pin output types
//@GPIO PIN OP TYPE

#define GPIO_TYPE_PP   0       //push pull
#define GPIO_TYPE_OD   1       //open drain

//GPIO pin possible output speed
//@GPIO SPEED MODES

#define GPIO_SPEED_LOW     0
#define GPIO_SPEED_MEDIUM  1
#define GPIO_SPEED_FAST    2
#define GPIO_SPEED_HIGH    3

//GPIO pin pull up and pull down configuration macros
//@GPIO PUSHPULL CONTROL

#define GPIO_NO_PUPD  0
#define GPIO_PIN_PU   1
#define GPIO_PIN_PD   2

//GPIO pin number
//GPIO PIN NUMBERS

#define GPIO_PIN_NO_0   0
#define GPIO_PIN_NO_1   1
#define GPIO_PIN_NO_2   2
#define GPIO_PIN_NO_3   3
#define GPIO_PIN_NO_4   4
#define GPIO_PIN_NO_5   5
#define GPIO_PIN_NO_6   6
#define GPIO_PIN_NO_7   7
#define GPIO_PIN_NO_8   8
#define GPIO_PIN_NO_9   9
#define GPIO_PIN_NO_10   10
#define GPIO_PIN_NO_11   11
#define GPIO_PIN_NO_12   12
#define GPIO_PIN_NO_13   13
#define GPIO_PIN_NO_14   14
#define GPIO_PIN_NO_15   15

//NVIC IRQ interrupt priority number
#define NVIC_IRQ_PRI0   0
#define NVIC_IRQ_PRI1   1
#define NVIC_IRQ_PRI2   2
#define NVIC_IRQ_PRI3   3
#define NVIC_IRQ_PRI4   4
#define NVIC_IRQ_PRI5   5


void GPIO_PeriClockControl(GPIO_regdef_t *pGPIOx,uint8_t EnorDi);


void GPIO_Init(GPIO_handle_t *pGPIOHandle);



void GPIO_DeInit(GPIO_regdef_t *pGPIOx);




uint8_t GPIO_ReadInputPin(GPIO_regdef_t *pGPIOx, uint8_t PinNumber);


uint16_t GPIO_ReadInputPort(GPIO_regdef_t *pGPIOx);




void GPIO_WriteOutputPin(GPIO_regdef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);




void GPIO_WriteOutputPort(GPIO_regdef_t *pGPIOx, uint16_t Value);



void GPIO_ToggleOutputPin(GPIO_regdef_t *pGPIOx, uint8_t PinNumber);


void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t EnorDi);



void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);


void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_STM32F407XX_GPIODRIVER_H_ */
