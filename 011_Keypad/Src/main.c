/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdio.h>
#include <stdint.h>

#include "main.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


void splash()
{
	printf( "******************************\n" );
	printf( "*  010_LED Toggle Bit Fields *\n" );
	printf( "******************************\n" );
	printf("\n");

	return;
}

void delay( uint64_t cycles )
{
	for ( uint32_t volatile i=0; i<cycles; i++ )
	{
		// empty loop - do nothing
	}

	return;
}

int main(void)
{
	RCC_AHB1ENR_t volatile *const pRCC_AHB1EnrReg	= (RCC_AHB1ENR_t*) RCC_AHB1ENR;

	GPIOx_MODER_t volatile *const pGPIOD_ModeReg 	= (GPIOx_MODER_t*) GPIOD_MODER;
	GPIOx_IDR_t   volatile *const pGPIOD_InDataReg 	= (GPIOx_IDR_t*) GPIOD_IDR;
	GPIOx_ODR_t   volatile *const pGPIOD_OutDataReg = (GPIOx_ODR_t*) GPIOD_ODR;
	GPIOx_PUPDR_t volatile *const pGPIOD_PuPdReg	= (GPIOx_PUPDR_t*) GPIOD_PUPDR;

	// each cycle is ~0.0625 uS, loop is 7 ins
	// 1000 uS = 1m ~ 2000 iterations; 150ms = 300K.
	uint64_t delayCycles = 300000;

	splash();

	// turn on clock for GPIOD
	pRCC_AHB1EnrReg->gpiod_en = 1;

	// all rows as Output
	pGPIOD_ModeReg->mode_r0 = 0x01;
	pGPIOD_ModeReg->mode_r1 = 0x01;
	pGPIOD_ModeReg->mode_r2 = 0x01;
	pGPIOD_ModeReg->mode_r3 = 0x01;

	// all columns as Input
	pGPIOD_ModeReg->mode_r8  = 0x00;
	pGPIOD_ModeReg->mode_r9  = 0x00;
	pGPIOD_ModeReg->mode_r10 = 0x00;
	pGPIOD_ModeReg->mode_r11 = 0x00;

	// all column inputs using pull up resistors
	pGPIOD_PuPdReg->pupd_r8  = 0x01;
	pGPIOD_PuPdReg->pupd_r9  = 0x01;
	pGPIOD_PuPdReg->pupd_r10 = 0x01;
	pGPIOD_PuPdReg->pupd_r11 = 0x01;

    /* Loop forever */
	while (1)
	{

		// turn off row 1
		pGPIOD_OutDataReg->od_r0 = 0;
		pGPIOD_OutDataReg->od_r1 = 1;
		pGPIOD_OutDataReg->od_r2 = 1;
		pGPIOD_OutDataReg->od_r3 = 1;

		if ( !( pGPIOD_InDataReg->id_r8 ) )
		{
			delay( delayCycles );
			printf("1\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r9 ) )
		{
			delay( delayCycles );
			printf("2\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r10 ) )
		{
			delay( delayCycles );
			printf("3\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r11 ) )
		{
			delay( delayCycles );
			printf("A\n" );
		}

		// turn off row 2
		pGPIOD_OutDataReg->od_r0 = 1;
		pGPIOD_OutDataReg->od_r1 = 0;
		pGPIOD_OutDataReg->od_r2 = 1;
		pGPIOD_OutDataReg->od_r3 = 1;

		if ( !( pGPIOD_InDataReg->id_r8 ) )
		{
			delay( delayCycles );
			printf("4\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r9 ) )
		{
			delay( delayCycles );
			printf("5\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r10 ) )
		{
			delay( delayCycles );
			printf("6\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r11 ) )
		{
			delay( delayCycles );
			printf("B\n" );
		}

		// turn off row 3
		pGPIOD_OutDataReg->od_r0 = 1;
		pGPIOD_OutDataReg->od_r1 = 1;
		pGPIOD_OutDataReg->od_r2 = 0;
		pGPIOD_OutDataReg->od_r3 = 1;

		if ( !( pGPIOD_InDataReg->id_r8 ) )
		{
			delay( delayCycles );
			printf("7\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r9 ) )
		{
			delay( delayCycles );
			printf("8\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r10 ) )
		{
			delay( delayCycles );
			printf("9\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r11 ) )
		{
			delay( delayCycles );
			printf("C\n" );
		}

		// turn off row 4
		pGPIOD_OutDataReg->od_r0 = 1;
		pGPIOD_OutDataReg->od_r1 = 1;
		pGPIOD_OutDataReg->od_r2 = 1;
		pGPIOD_OutDataReg->od_r3 = 0;

		if ( !( pGPIOD_InDataReg->id_r8 ) )
		{
			delay( delayCycles );
			printf("*\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r9 ) )
		{
			delay( delayCycles );
			printf("0\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r10 ) )
		{
			delay( delayCycles );
			printf("#\n" );
		}

		if ( !( pGPIOD_InDataReg->id_r11 ) )
		{
			delay( delayCycles );
			printf("D\n" );
		}

		// Reset all the rows back to HIGH
		pGPIOD_OutDataReg->od_r0 = 1;
		pGPIOD_OutDataReg->od_r1 = 1;
		pGPIOD_OutDataReg->od_r2 = 1;
		pGPIOD_OutDataReg->od_r3 = 1;
	}
}
