#include <MKL25Z4.h>
#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#include "report.h"
#include "buffer.h"

void UART_config()
{
	//Clock settings
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
	SIM_SOPT2 |= 0x4000000u; //clock source selection

	//Disable Tx and Rx before setting baud rates
	UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);

	//baud rate settings - 57600
	UART0_BDH &= 0x00;
	UART0_BDL = 0x1A;
	UART0_C4 |= 0x0F;
	UART0_C1 &= 0x00;

	//Enable clock of Port A
	//SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

	//UART0 RX/TX is connected to pins 27/28, PTA1/PTA2 (ALT2)
	PORTA_PCR1 = PORT_PCR_MUX(2);
	PORTA_PCR2 = PORT_PCR_MUX(2);

	//Enabling Tx and Rx for polling
	UART0_C2 |= (UART0_C2_TE_MASK | UART0_C2_RE_MASK);

	//enable receiver transmitter interrupt
	UART0_C2 |= UART0_C2_RIE_MASK;

	__enable_irq();

	NVIC_EnableIRQ(UART0_IRQn);
}

void UART_transmit(uint8_t data)
{
	while(!(UART0_S1 & UART_S1_TDRE_MASK));
	UART0_D = data;
}

uint8_t UART_receive()
{
	//while(!(UART0_S1 & UART_S1_RDRF_MASK));
	uint8_t data = UART0_D;
	return data;
}

//ISR handler
void UART0_IRQHandler(void)
{
	__disable_irq();

	if ((UART0_C2 & UART0_C2_TIE_MASK) == UART0_C2_TIE_MASK) 		//for transmit interrupt
	{
		UART0_C2 &= ~UART0_C2_TIE_MASK;		//disabling TX interrupt

		uint8_t temp[buff_size - 1], i=0, j;

		while(tail != head)
		{
			temp[i] = char_out();
			i++;
		}

		for(j = 0; j<i; j++)
			report(temp[j]);

		UART0_C2 |= UART0_C2_RIE_MASK;		//enabling RX interrupt

//		__enable_irq();
//		return;
	}

	else if((UART0_C2 & UART0_C2_RIE_MASK) == UART0_C2_RIE_MASK)	//for receiver interrupt
	{
		//scan data until data register keeps on being filled
		do
		{
			rec_data = UART_receive();
			char_in(rec_data);			//adds rx'd data to CB
			NVIC_EnableIRQ(UART0_IRQn);
		}
		while(UART0_S1 & UART_S1_RDRF_MASK);

		UART0_C2 &= ~UART0_C2_RIE_MASK;		//disabling RX interrupt
		UART0_C2 |= UART0_C2_TIE_MASK;		//enabling TX interrupt

//		__enable_irq();
//		return;
	}
//	else
//	{
//		__enable_irq();
//		return;
//	}
	NVIC_EnableIRQ(UART0_IRQn);

	__enable_irq();
}
