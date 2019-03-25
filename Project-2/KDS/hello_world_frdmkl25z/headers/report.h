#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t app_char[256];
uint8_t app_cnt[256];
uint8_t uniq_char_cnt = 0, uniq_flag = 1;

void report(uint8_t);
