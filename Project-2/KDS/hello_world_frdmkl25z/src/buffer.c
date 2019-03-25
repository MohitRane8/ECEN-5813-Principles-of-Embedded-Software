#include "buffer.h"
#include "uart.h"
//will run once
void cir_buff_init()
{
	base_addr = (int32_t*) malloc(buff_size);
	head = base_addr;
	tail = base_addr;
}

//when buffer receives a character, it adds to the buffer
void char_in(uint8_t data)
{
	*head = data;
	head = (head + 1) >= (base_addr + buff_size) ? base_addr : head + 1;
}

uint8_t char_out()
{
	uint8_t tail_ret;
	tail_ret = *tail;
	tail = (tail + 1) >= (base_addr + buff_size) ? base_addr : (tail + 1);
	return tail_ret;
}
