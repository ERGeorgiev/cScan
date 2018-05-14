#pragma once

#include <stdint.h>

int64_t digit_put64(int64_t number, int place, int digit);
int32_t digit_put32(int32_t number, int place, int digit);
int16_t digit_put16(int16_t number, int place, int digit);
short digit_putshort(short number, int place, int digit);
int digit_putint(int number, int place, int digit);
long digit_putlong(long number, int place, int digit);
long long digit_putlonglong(long long number, int place, int digit);