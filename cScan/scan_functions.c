#include <stdio.h>
#include <Windows.h>

void clrstr(char *str) //Clears a string.
{
	memset(str, 0, sizeof(str));
}

void scan_erase(int total) //Erases input
{
	int count;

	for (count = 0; count < total; count++)
	{
		printf("\b \b");
	}
}

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}