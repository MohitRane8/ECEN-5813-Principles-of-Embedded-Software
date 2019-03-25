/*
 * Copyright (c) 2013 - 2014, Freescale Semiconductor, Inc.
 */


///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////
// SDK Included Files
#include "board.h"
#include "fsl_lptmr_driver.h"
#include "fsl_debug_console.h"

//--------------------our addition starts
#include <MKL25Z4.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "uart.h"
#include "adc.h"
#include "dma.h"
#include "gpio.h"
#include "app.h"

extern int16_t* base_addr;
extern int16_t* head;
extern int16_t adc_value;

//--------------------our addition ends

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////
// Timer period: 500000uS
#define TMR_PERIOD         500000U
#if defined(TWR_KV46F150M)
#define LPTMR0_IDX LPTMR_IDX
#endif


////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
/*!
 * @brief LPTMR interrupt call back function.
 * The function is used to toggle LED1.
 */
void lptmr_call_back(void)
{
    // Toggle LED1
    LED1_TOGGLE;
}

/*!
 * @brief Main function
 */
int main (void)
{
    // RX buffers
    //! @param receiveBuff Buffer used to hold received data

    // LPTMR configurations
 	lptmr_user_config_t lptmrConfig =
    {
        .timerMode = kLptmrTimerModeTimeCounter,
        .freeRunningEnable = false,
        .prescalerEnable = true,
        .prescalerClockSource = kClockLptmrSrcLpoClk,
        .prescalerValue = kLptmrPrescalerDivide2,
        .isInterruptEnabled = true,
    };
    // LPTMR driver state information
    lptmr_state_t lptmrState;

    // Initialize standard SDK demo application pins
    hardware_init();

    // Initialize LPTMR
    LPTMR_DRV_Init(LPTMR0_IDX, &lptmrState, &lptmrConfig);
    // Set timer period for TMR_PERIOD seconds
    LPTMR_DRV_SetTimerPeriodUs(LPTMR0_IDX, TMR_PERIOD);
    // Install interrupt call back function for LPTMR
    LPTMR_DRV_InstallCallback(LPTMR0_IDX, lptmr_call_back);
    // Start LPTMR
    LPTMR_DRV_Start(LPTMR0_IDX);

    // Initialize LED1
    LED1_EN;

//############################################################## our code starts here ###########################################################################

    // Configuring UART and ADC
    UART_config();
	ADC_config();

	char buffer1[6], buffer2[6], buffer3[6];
	float valueDBFS;

	// Creating a buffer
	base_addr = (int16_t*) malloc(128);
	head = base_addr;

	// Configuring DMA and GPIO
	DMA_config();
	gpio_config();

	while(1)
	{
		ADC0_SC1A = (0 & ADC_SC1_ADCH_MASK) | (ADC0_SC1A & ADC_SC1_DIFF_MASK);

		// Storing ADC value from RA register in a variable
		adc_value = ADC0_RA;

		// Printing ADC value
		memset(buffer1, 0,sizeof(buffer1));
		sprintf(buffer1, "%d", adc_value);
		for(int i=0; i<6; i++)
		{
			UART_transmit(buffer1[i]);
		}

		UART_transmit('\t');

		// Printing DMA values stored in buffer
		memset(buffer2, 0,sizeof(buffer2));
		sprintf(buffer2, "%d", *head);
		for(int i=0; i<6; i++)
		{
			UART_transmit(buffer2[i]);
		}

		UART_transmit('\t');

		// Calculating peak value
		app();

		head++;

		// Calculating dBFS value of sample
		valueDBFS = (fabs(adc_value))/32768;
		valueDBFS = log10(valueDBFS);
		valueDBFS = 20*valueDBFS;

		// Printing dBFS value on UART
		sprintf(buffer3, "%f", valueDBFS);
		for(int i=0; i<6; i++)
		{
			UART_transmit(buffer3[i]);
		}

		UART_transmit('\r');
		UART_transmit('\n');


		if(head == (base_addr + 32))
		{
			DMA_DCR0 |= DMA_DCR_EINT_MASK;
		}

		if(head == (base_addr + 64))
		{
			DMA_DCR0 |= DMA_DCR_EINT_MASK;
		}
	}

//############################################################## our code ends here ###########################################################################
    return 0;
}
