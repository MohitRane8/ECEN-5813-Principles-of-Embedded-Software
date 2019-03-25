#include "report.h"
#include "uart.h"
#include "buffer.h"

void printnum(uint8_t conv)
{
	UART_transmit((conv/100)+48);
	conv = conv%100;
	UART_transmit((conv/10)+48);
	conv = conv%10;
	UART_transmit(conv + 48);
}

void report(uint8_t data)
{
	for(uint8_t k=0;k<uniq_char_cnt;k++)
	{
		uniq_flag = 1;
		//increase count of unique char which already occured earlier
		if(data == app_char[k])
		{
			app_cnt[k] = (app_cnt[k] + 1);
			uniq_flag = 0;
			break;
		}
	}

	if(uniq_flag == 1)
	{
		app_char[uniq_char_cnt] = data;
		app_cnt[uniq_char_cnt] = 1;
		uniq_char_cnt = uniq_char_cnt + 1;
	}

	UART_transmit('\r');
	UART_transmit('\n');
	UART_transmit('>');
	UART_transmit('\r');
	UART_transmit('\n');

	//printing report
	for(uint8_t i=0;i<uniq_char_cnt;i++)
	{
		UART_transmit(app_char[i]);
		UART_transmit(' ');
		UART_transmit(45);
		UART_transmit(' ');
		if(app_cnt[i] > 9)
		{
			printnum(app_cnt[i]);
		}

		else
			UART_transmit(app_cnt[i] + 48);

		UART_transmit('\r');
		UART_transmit('\n');
	}
}

