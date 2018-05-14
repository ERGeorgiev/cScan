#include <math.h>

#include "digit.h"

int64_t digit_put64(int64_t number, int place, int digit)
{
	int64_t result = number;

	result -= digit_get64(number, place)*(int64_t)pow(10, (place));
	result += digit*(int64_t)pow(10, (place));

	return result;
}

int32_t digit_put32(int32_t number, int place, int digit)
{
	int32_t result = number;

	result -= digit_get32(number, place)*(int32_t)pow(10, (place));
	result += digit*(int32_t)pow(10, (place));

	return result;
}

int16_t digit_put16(int16_t number, int place, int digit)
{
	int16_t result = number;

	result -= digit_get16(number, place)*(int16_t)pow(10, (place));
	result += digit*(int16_t)pow(10, (place));

	return result;
}

short digit_putshort(short number, int place, int digit)
{
	int result = number;

	result -= digit_getint(number, place)*(short)pow(10, (place));
	result += digit*(short)pow(10, (place));

	return result;
}

int digit_putint(int number, int place, int digit)
{
	int result = number;

	result -= digit_getint(number, place)*(int)pow(10, (place));
	result += digit*(int)pow(10, (place));

	return result;
}

long digit_putlong(long number, int place, int digit)
{
	long result = number;

	result -= digit_getlong(number, place)*(long)pow(10, (place));
	result += digit*(long)pow(10, (place));

	return result;
}

long long digit_putlonglong(long long number, int place, int digit)
{
	long long result = number;

	result -= digit_getlonglong(number, place)*(long long)pow(10, (place));
	result += digit*(long long)pow(10, (place));

	return result;
}