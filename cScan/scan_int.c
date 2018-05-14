#include <conio.h>

#include "scan.h"
#include "digit.h"

int scan_int(int limit, int allowMinus)
{
	int total, input = 0, allowminus = allowMinus;

	char ch;

	total = 0;
	ch = 0;

	while (input_int(&ch, &input, &total, limit, &allowminus))
	{
		print_int(&ch, &input, &total, limit);
	}
	if (ch != KEY_ESC)
	{
		if (allowminus == 2)
		{
			input *= -1;
		}
		return input;
	}
	else return 0;
}

int input_int(char *ch, int *input, int *total, int limit, int *allowminus)
{
	*ch = (char)_getch();

	switch (*ch)
	{
	case KEY_ENTER:
		return 0;
		break;
	case KEY_ESC:
		erase_int(input, total, limit+1, allowminus);
		return 0;
		break;
	case KEY_BACKSPACE:
		erase_int(input, total, 1, allowminus);
		break;
	case KEY_MINUS:
		if (*allowminus == 1)
		{
			*allowminus = 2;
			scan_erase(*total);
			printf("-");
			if (*input != 0)
			{
				printf("%d", *input);
			}
		}
		else if (*allowminus == 2)
		{
			*allowminus = 1;
			scan_erase(*total);
			printf("\b \b");
			if (*input != 0)
			{
				printf("%d", *input);
			}
		}
		break;
	}
	return 1;
}

void print_int(char *ch, int *input, int *total, int limit)
{
	int toint;

	toint = *ch - '0';
	if (*total < limit && *ch >= KEY_0 && *ch <= KEY_9)
	{
		*input *= 10;
		*input += toint;
		printf("%c", *ch);
		*total += 1;
	}
}

void erase_int(int *input, int *total, int times, int *allowminus)
{
	int count;

	for (count = 0; count < times; (count)++)
	{
		if (*total == 0 && *allowminus == 2)
		{
			printf("\b \b");
			*allowminus = 1;
		}
		else if (*total > 0)
		{
			printf("\b \b");
			*total -= 1;
			*input /= 10;
		}
	}
}