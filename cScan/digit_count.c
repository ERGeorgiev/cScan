#include <math.h>

#include "digit.h"

int digit_count64(int64_t number)
{
	int64_t target = (int64_t)llabs(number);
	int digits = 0;

	while (target)
	{
		target /= 10;
		digits++;
	}

	return digits;
}

int digit_count32(int32_t number)
{
	int32_t target = (int32_t)llabs(number);
	int digits = 0;

	while (target)
	{
		target /= 10;
		digits++;
	}

	return digits;
}

int digit_count16(int16_t number)
{
	int16_t target = (int16_t)llabs(number);
	int digits = 0;

	while (target)
	{
		target /= 10;
		digits++;
	}

	return digits;
}

int digit_countshort(short number)
{
	short target = (short)llabs(number);
	int digits = 0;

	while (target)
	{
		target /= 10;
		digits++;
	}

	return digits;
}

int digit_countint(int number)
{
	int target = (int)llabs(number);
	int digits = 0;

	while (target)
	{
		target /= 10;
		digits++;
	}

	return digits;
}

int digit_countlong(long number)
{
	long target = (long)llabs(number);
	int digits = 0;

	while (target)
	{
		target /= 10;
		digits++;
	}

	return digits;
}

int digit_countlonglong(long long number)
{
	long long target = (long long)llabs(number);
	int digits = 0;

	while (target)
	{
		target /= 10;
		digits++;
	}

	return digits;
}