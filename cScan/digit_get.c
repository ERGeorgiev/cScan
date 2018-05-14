#include <math.h>

#include "digit.h"

//Digit is given in a right-to-left order.
int digit_get64(int64_t number, int place)
{
	int64_t target = number;
	int digit = 0;

	target /= (int64_t)pow(10, place);
	digit = target % 10;

	return digit;
}

int digit_get32(int32_t number, int place)
{
	int32_t target = number;
	int digit = 0;

	target /= (int32_t)pow(10, place);
	digit = target % 10;

	return digit;
}

int digit_get16(int16_t number, int place)
{
	int16_t target = number;
	int digit = 0;

	target /= (int16_t)pow(10, place);
	digit = target % 10;

	return digit;
}

int digit_getshort(short number, int place)
{
	int target = number;
	int digit = 0;

	target /= (int)pow(10, place);
	digit = target % 10;

	return digit;
}

int digit_getint(int number, int place)
{
	int target = number;
	int digit = 0;

	target /= (int)pow(10, place);
	digit = target % 10;

	return digit;
}

int digit_getlong(long number, int place)
{
	int target = number;
	int digit = 0;

	target /= (int)pow(10, place);
	digit = target % 10;

	return digit;
}

int digit_getlonglong(long long number, int place)
{
	int target = (int)number;
	int digit = 0;

	target /= (int)pow(10, place);
	digit = target % 10;

	return digit;
}