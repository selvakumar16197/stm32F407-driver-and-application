/*
 * 004_spi_tx_test.c
 *
 *  Created on: 04-Jun-2020
 *      Author: Selva Kumar
 */
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"


/*
 * PB14 --> SPI2_MISO
 * PB15 --> SPI2_MOSI
 * PB13 --> SPI2_SCLK
 * PB12 --> SPI2_NSS
 */

void SPI2_GPIOInits(void)
{
	GPIO_handle_t SPIPins;

	SPIPins.pGPIOx = GPIOB;
	SPIPins.GPIO_pinconfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.GPIO_pinconfig.GPIO_PinAltFunMode = 5;
	SPIPins.GPIO_pinconfig.GPIO_PinOPType = GPIO_TYPE_PP;
	SPIPins.GPIO_pinconfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	SPIPins.GPIO_pinconfig.GPIO_PinSpeed = GPIO_SPEED_FAST;


	//SCLK
	SPIPins.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_Init(&SPIPins);

	//MOSI
	SPIPins.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GPIO_Init(&SPIPins);

	//MISO

	//SPIPins.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	//GPIO_Init(&SPIPins);

	//NSS
	//SPIPins.GPIO_pinconfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	//GPIO_Init(&SPIPins);
}

void SPI2_Inits(void)
{

	SPI_Handle_t SPI2handle;

	SPI2handle.pSPIx = SPI2;
	SPI2handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI2handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI2handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV2;  //generates sclk of 8Mhz
	SPI2handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI2handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI2handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI2handle.SPIConfig.SPI_SSM = SPI_SSM_EN;                 //software slave management enabled for NSS pin

	SPI_Init(&SPI2handle);
}

int main(void)
{

   char user_data[] = "S";

   //this function is used to initialize the GPIO pins to behave as SPI2 pins
   SPI2_GPIOInits();

   //this function is used to initialize the SPI2 peripheral parameters
   SPI2_Inits();

   //this makes NSS high which avoids restting master mode
   SPI_SSIConfig(SPI2,ENABLE);

   //enable the SPI2 peripheral
   SPI_PeripheralControl(SPI2,ENABLE);

   //to send data
   SPI_SendData(SPI2,(uint8_t*)user_data,strlen(user_data));
   while(1);
}
