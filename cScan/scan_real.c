#include <math.h>
#include <conio.h>

#include "scan.h"
#include "digit.h"

uint64_t scan_real(char limit, char allowminus) 
{
	uint64_t input = 1000000000000000000;

	digit_get64(2, 2);

	char total[2] = { 0, 0 }, ch = 0, decimal = 0, negative = 0;

	while (input_real(&ch, &input, total, &decimal, limit, allowminus, &negative))
	{
		print_real(&ch, &input, total, &decimal, limit);
	}

	if (ch != KEY_ESC)
	{
		if (negative == 2)
		{
			input *= -1;
		}
		return input;
	}
	else
	{
		return 0;
	}
}

uint32_t real_whole(uint64_t number)
{
	uint64_t whole = number;

	if (whole <= 1000000000000000000)
	{
		return 0;
	}
	else
	{
		whole -= 1000000000000000000;
		whole /= (uint32_t)pow(10, 9);
		return (uint32_t)whole;
	}
}

uint32_t real_decimal(uint64_t number) //Returns decimal without the zeros on its left, so be careful.
{
	uint64_t decimal = number;

	if (number <= 1000000000000000000)
	{
		return 0;
	}
	else
	{
		decimal -= 1000000000000000000;
		decimal %= (uint32_t)pow(10, 9);
		return (uint32_t)decimal;
	}
}

char input_real(char *ch, uint64_t *input, char *total, char *decimal, char limit, char allowminus, char *negative)
{
	*ch = (char)_getch();

	switch (*ch)
	{
	case KEY_ARROW:
		_getch();
		break;
	case KEY_ENTER:
		if (*negative)
		{
			*input *= -1;
		}
		return 0;
		break;
	case KEY_ESC:
		*input = 0;
		return 0;
		break;
	case KEY_BACKSPACE:
		erase_real(input, total, decimal, negative, 1);
		break;
	case KEY_MINUS:
		if (allowminus)
		{
			scan_erase(total[0]+total[1]);
			if (*negative)
			{
				*negative = 0;
				if (*decimal != 0)
				{
					printf("\b \b");
					printf("\b \b");
					printf("%d.%d", real_whole(*input), real_decimal(*input));
				}
				else
				{
					printf("\b \b");
					printf("%d", real_whole(*input));
				}
			}
			else
			{
				*negative = 1;
				if (*decimal != 0)
				{
					printf("\b \b");
					printf("-");
					printf("%d.%d", real_whole(*input), real_decimal(*input));
				}
				else
				{
					printf("-");
					printf("%d", real_whole(*input));
				}
			}
		}
		break;

	case KEY_DOT:
		if ((*decimal == 0) && ((limit*2) > (total[0] + total[1])))
		{
			if ((*input == 0) && (total[0] == 0))
			{
				printf("0");
			}
			*decimal = 1;
			printf("%c", *ch);
		}
		break;
	}
	return 1;
}

void print_real(char *ch, uint64_t *input, char *total, char *decimal, char limit)
{
	int toInt, i;

	if (*decimal == 0) //If no decimal
	{
		if ((limit > total[0]) && ((*ch) >= KEY_0 && (*ch) <= KEY_9))
		{
			if ((*ch != KEY_0) || (total[0] != 0))
			{
				toInt = (*ch) - '0';
				for (i = ((limit - 1) + total[0]); i >= limit; i--)
				{
					*input = digit_put64(*input, i + 1, digit_get64(*input, i));
				}
				*input = digit_put64(*input, limit, toInt);
				printf("%d", toInt);
				total[0]++;
			}
		}
	}
	else
	{
		if ((limit > total[1]) && ((*ch) >= KEY_0 && (*ch) <= KEY_9))
		{
			toInt = (*ch) - '0';
			for (i = (total[1] - 1); i >= 0; i--)
			{
				*input = digit_put64(*input, i + 1, digit_get64(*input, i));
			}
			*input = digit_put64(*input, 0, toInt);
			printf("%d", toInt);
			total[1]++;
		}
	}
}

void erase_real(uint64_t *input, char *total, char *decimal, char *negative, int times)
{
	int count, i;

	for (count = 0; count < times; count++)
	{
		if (*decimal)
		{
			if (total[1] > 0)
			{
				for (i = 1; i < (total[0]); i++)
				{
					*input = digit_put64(*input, i, digit_get64(*input, i + 1));
				}
				printf("\b \b");
				*input = digit_put64(*input, 9 - total[1], 0);
				total[1]--;
			}
			else
			{
				printf("\b \b");
				*decimal = 0;
				if (*input == 0)
				{
					printf("\b \b");
				}
			}
		}
		else if (total[0] > 0)
		{
			for (i = 9; i < ((9-1) + total[0]); i++)
			{
				*input = digit_put64(*input, i, digit_get64(*input, i + 1));
			}
			printf("\b \b");
			*input = digit_put64(*input, ((9 - 1) + total[0]), 0);
			total[0]--;
		}
		else if (*negative)
		{
			printf("\b \b");
			*negative = 0;
		}
	}
}