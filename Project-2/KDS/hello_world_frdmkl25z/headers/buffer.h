#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void cir_buff_init();
void char_in(uint8_t data);
uint8_t char_out();

uint8_t buff_size = 9;		//fixed
uint8_t buff_char_count = 0;
int32_t *base_addr, *head, *tail;
