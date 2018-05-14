#include <math.h>

#include "digit.h"

int64_t digit_switch64(int64_t number, int placeA, int placeB)
{
	int64_t result = number;
	int remainder = 0;

	remainder = digit_get64(number, placeA);
	result = digit_put64(result, placeA, digit_get64(result, placeB));
	result = digit_put64(result, placeB, remainder);

	return result;
}

int32_t digit_switch32(int32_t number, int placeA, int placeB)
{
	int32_t result = number;
	int remainder = 0;

	remainder = digit_get32(number, placeA);
	result = digit_put32(result, placeA, digit_get32(result, placeB));
	result = digit_put32(result, placeB, remainder);

	return result;
}

int16_t digit_switch16(int16_t number, int placeA, int placeB)
{
	int16_t result = number;
	int remainder = 0;

	remainder = digit_get16(number, placeA);
	result = digit_put16(result, placeA, digit_get16(result, placeB));
	result = digit_put16(result, placeB, remainder);

	return result;
}

short digit_switchshort(short number, int placeA, int placeB)
{
	short result = number;
	int remainder = 0;

	remainder = digit_getshort(number, placeA);
	result = digit_putshort(result, placeA, digit_getshort(result, placeB));
	result = digit_putshort(result, placeB, remainder);

	return result;
}

int digit_switchint(int number, int placeA, int placeB)
{
	int result = number;
	int remainder = 0;

	remainder = digit_getint(number, placeA);
	result = digit_putint(result, placeA, digit_getint(result, placeB));
	result = digit_putint(result, placeB, remainder);

	return result;
}

long digit_switchlong(long number, int placeA, int placeB)
{
	long result = number;
	int remainder = 0;

	remainder = digit_getlong(number, placeA);
	result = digit_putlong(result, placeA, digit_getlong(result, placeB));
	result = digit_putlong(result, placeB, remainder);

	return result;
}

long long digit_switchlonglong(long long number, int placeA, int placeB)
{
	long long result = number;
	int remainder = 0;

	remainder = digit_getlonglong(number, placeA);
	result = digit_putlonglong(result, placeA, digit_getlonglong(result, placeB));
	result = digit_putlonglong(result, placeB, remainder);

	return result;
}