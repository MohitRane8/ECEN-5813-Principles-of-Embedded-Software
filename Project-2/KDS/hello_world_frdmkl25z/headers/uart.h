#include <MKL25Z4.h>
#include <stdint.h>
#include <stdio.h>

void UART_config();
void UART_transmit(uint8_t data);
uint8_t UART_receive();
void UART0_IRQHandler(void);

uint8_t rec_data;
