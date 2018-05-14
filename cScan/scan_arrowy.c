#include <conio.h>

#include "scan.h"
#include "digit.h"

int scan_arrowy(int limit, int _x, int _y)
{
	int place = 0, x = _x, y = _y;
	unsigned char ch;

	if (limit > 0)
	{
		gotoxy(x,y);
		printf("*");
		gotoxy(x,y);
		do
		{
			ch = (char)_getch();
			if (ch == 0 || ch == 0xE0)
			{
				ch = (char)_getch();
				switch (ch)
				{
				case KEY_UP:
					if (place > 0)
					{
						printf(" \b");
						y--;
						gotoxy(x,y);
						printf("*");
						gotoxy(x,y);
						place--;
					}
					else if (place == 0)
					{
						printf(" \b");
						y += limit - 1;
						gotoxy(x,y);
						printf("*");
						gotoxy(x,y);
						place = limit - 1;
					}
					break;
				case KEY_DOWN:
					if (place + 1 < limit)
					{
						printf(" \b");
						y++;
						gotoxy(x,y);
						printf("*");
						gotoxy(x,y);
						place++;
					}
					else if (place + 1 == limit)
					{
						printf(" \b");
						y = _y;
						gotoxy(x,y);
						printf("*");
						gotoxy(x,y);
						place = 0;
					}
					break;
				}
			}
		} while (ch != KEY_ENTER && ch != KEY_ESC);
		if (ch == KEY_ESC) return ch;
		return place+1;
	}
	else
	{
		return place;
	}
}