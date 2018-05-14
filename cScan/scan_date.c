#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <conio.h>

#include "scan.h"
#include "digit.h"

uint32_t scan_date()
{
	uint32_t input = 0;
	int total = 0;
	char ch = 0;

	printf("DD.MM.YYYY\b\b\b\b\b\b\b\b\b\b");
	while (input_date(&input, &total, &ch))
	{
		if (total < 8)
		{
			print_date(&input, &total, &ch);
		}
	}

	if (ch != KEY_ESC)
	{
		return input;
	}
	else
	{
		return 0;
	}
}

int date_day(uint32_t date)
{
	return ((digit_get32(date, 1) * 10) + (digit_get32(date, 0) * 1));
}

int date_month(uint32_t date)
{
	return ((digit_get32(date, 3) * 10) + (digit_get32(date, 2) * 1));
}

int date_year(uint32_t date)
{
	return ((digit_get32(date, 7) * 1000) + (digit_get32(date, 6) * 100) + (digit_get32(date, 5) * 10) + (digit_get32(date, 4) * 1));
}

int check_date(uint32_t date)
{
	int day = date_day(date);
	int month = date_month(date);
	int year = date_year(date);

	time_t rawtime;
	struct tm timeinfo;

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	(&timeinfo)->tm_mon++;
	(&timeinfo)->tm_year += 1900;

	if (year > (&timeinfo)->tm_year || month > 12)	return 0;
	else if (year == (&timeinfo)->tm_year)
	{
		if (month > (&timeinfo)->tm_mon) return 0;
		else if (((int)month == (&timeinfo)->tm_mon) && (day > (&timeinfo)->tm_mday)) return 0;
	}
	if ((month % 2) == 0)
	{
		if (month == 2)
		{
			if ((year % 4) == 0)
			{
				if (day > 29) return 0;
			}
			else if (day > 28) return 0;
		}
		else if ((month <= 7 && day > 31) || (month >= 8 && day > 30)) return 0;
	}
	else if ((month <= 7 && day > 30) || (month >= 8 && day > 31)) return 0;

	return 1;
}

int input_date(uint32_t *input, int *total, char *ch)
{
	*ch = (char)_getch();

	switch (*ch)
	{
	case KEY_ARROW:
		_getch();
		break;
	case KEY_ESC:
		erase_date(input, total, *total);
		return 0;
		break;
	case KEY_BACKSPACE:
		erase_date(input, total, 1);
		break;
	case KEY_ENTER:
	case KEY_DOT:
	case KEY_RSLASH:
		switch (*total)
		{
		case 0:
			printf("00.");
			*total = 2;
			break;
		case 1:
			printf("\b0%d.", date_day(*input));
			*total = 2;
			break;
		case 2:
			printf("00.");
			*total = 4;
			break;
		case 3:
			printf("\b0%d.", date_month(*input));
			*total = 4;
			break;
		case 4:
			printf("0000\b");
			*total = 8;
			break;
		case 5:
			printf("\b000%d\b", date_year(*input));
			*total = 8;
			break;
		case 6:
			printf("\b\b00%d\b", date_year(*input));
			*total = 8;
			break;
		case 7:
			printf("\b\b\b0%d\b", date_year(*input));
			*total = 8;
			break;
		case 8:
			if (check_date(*input))
			{
				return 0;
			}
			break;
		}
		break;
	}
	return 1;
}

void print_date(uint32_t *input, int *total, char *ch)
{
	int toInt = 0;

	if (((*ch) >= KEY_0) && ((*ch) <= KEY_9))
	{
		toInt = (*ch) - '0';
		*input = digit_put32(*input, *total, toInt);
		switch (*total)
		{
		case 0:
			printf("  \b\b");
			printf("%d", toInt);
			break;
		case 1:
			printf("%d", toInt);
			printf(".");
			*input = digit_switch32(*input, 0, 1);
			break;
		case 2:
			printf("%d", toInt);
			printf(" \b");
			break;
		case 3:
			printf("%d", toInt);
			printf(".");
			*input = digit_switch32(*input, 2, 3);
			break;
		case 4:
			printf("%d", toInt);
			printf("    \b\b\b\b");
			break;
		case 5:
			printf("%d", toInt);
			*input = digit_switch32(*input, 4, 5);
			break;
		case 6:
			printf("%d", toInt);
			*input = digit_switch32(*input, 5, 6);
			*input = digit_switch32(*input, 4, 5);
			break;
		case 7:
			printf("%d\b", toInt);
			*input = digit_switch32(*input, 6, 7);
			*input = digit_switch32(*input, 5, 6);
			*input = digit_switch32(*input, 4, 5);
			break;
		}
		(*total)++;
	}
}

void erase_date(uint32_t *input, int *total, int times)
{
	int count;

	if (*total > 0)
	{
		for (count = 0; count < times; count++)
		{
			if (total > 0)
			{
				switch (*total)
				{
				case 1:
					printf("\bDD\b\b");
					*input = digit_put32(*input, 0, 0);
					break;
				case 2:
					printf("\b\b \b");
					*input = digit_put32(*input, 0, 0);
					*input = digit_switch32(*input, 0, 1);
					break;
				case 3:
					printf("\bMM\b\b");
					*input = digit_put32(*input, 2, 0);
					break;
				case 4:
					printf("\b\b \b");
					*input = digit_put32(*input, 2, 0);
					*input = digit_switch32(*input, 2, 3);
					break;
				case 5:
					printf("\bYYYY\b\b\b\b");
					*input = digit_put32(*input, 4, 0);
					break;
				case 6:
					printf("\b \b");
					*input = digit_put32(*input, 4, 0);
					*input = digit_switch32(*input, 4, 5);
					break;
				case 7:
					printf("\b \b");
					*input = digit_put32(*input, 4, 0);
					*input = digit_switch32(*input, 4, 5);
					*input = digit_switch32(*input, 5, 6);
					break;
				case 8:
					printf(" \b");
					*input = digit_put32(*input, 4, 0);
					*input = digit_switch32(*input, 4, 5);
					*input = digit_switch32(*input, 5, 6);
					*input = digit_switch32(*input, 6, 7);
					break;
				}
				(*total)--;
			}
			else
			{
				break;
			}
		}
	}
}