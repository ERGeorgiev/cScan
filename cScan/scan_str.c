#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "scan.h"
#include "digit.h"

int scan_str(char *output, int limit)
{
	int total = 0;
	
	char *input;

	input = malloc((limit + 1) * sizeof(char));
	clrstr(input);

	while (input_str(input, &total))
	{
		print_str(input, &total, limit);
	}
	if (input[total] != KEY_ESC)
	{
		clrstr(output);
		strcpy_s(output, (limit + 1) * sizeof(char), input);
		free(input);
		return 1;
	}
	else
	{
		free(input);
		return 0;
	}
}

int input_str(char *input, int *total)
{
	input[*total] = (char)_getch();

	switch (input[*total])
	{
	case -32:
		_getch();
		break;
	case KEY_BACKSPACE:
		input[*total] = 0;
		erase_str(input, total, 1);
		break;
	case KEY_ENTER:
		input[*total] = 0;
		return 0;
		break;
	case KEY_ESC:
		return 0;
		break;
	}
	return 1;
}

void print_str(char *input, int *total, int limit)
{
	if (input[*total] > 31 && input[*total] < 127 && limit > *total)
	{
		printf("%c", input[*total]);
		*total += 1;
	}
}

void erase_str(char *input, int *total, int times)
{
	int count;

	for (count = 0; count < times; count++)
	{
		if (*total > 0)
		{
			printf("\b \b");
			*total -= 1;
			input[*total] = 0;
		}
	}
}
