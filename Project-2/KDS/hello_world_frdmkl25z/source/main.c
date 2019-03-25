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
#include "uart.h"
#include "buffer.h"
#include <stdint.h>
#include <stdio.h>
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

    // Print the initial banner
    //PRINTF("\r\nHello World!\r\n\r\n");

    //-----------------------our addition starts

    UART_config();
    cir_buff_init();

    void fibprint(uint16_t conv)
    {
    	UART_transmit((conv/100)+48);
    	conv = conv%100;
    	UART_transmit((conv/10)+48);
    	conv = conv%10;
    	UART_transmit(conv + 48);
    }

    while(1)
    {
    	unsigned long long factorial = 1;
    	uint16_t fib1 = 0, fib2 = 1, fib3;

		//compute factorial for delay
    	for(uint8_t k = 0; k<10;k++)
    	{
			for(uint16_t i=0; i<254; i++)
			{
				for(uint8_t j = 1; j<=i; ++j)
				{
					factorial *= i;
				}
			}
    	}

    	//UART_config();

		//section for fibonacci series
		for(uint8_t k=0;k<17;k++)
		{

			if(fib1 > 9)
			{
				fibprint(fib1);
				UART_transmit('\t');;
			}

			else
			{
				UART_transmit(fib1 + 48);
				UART_transmit('\t');

			}
			fib3 = fib1 + fib2;
			fib1 = fib2;
			fib2 = fib3;
		}
		UART_transmit('\n');
		UART_transmit('\r');
   	}
    return 0;
}
