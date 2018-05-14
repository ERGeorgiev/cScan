#pragma once

#include <stdint.h>

int digit_get64(int64_t number, int place);
int digit_get32(int32_t number, int place);
int digit_get16(int16_t number, int place);
int digit_getshort(short number, int place);
int digit_getint(int number, int place);
int digit_getlong(long number, int place);
int digit_getlonglong(long long number, int place);