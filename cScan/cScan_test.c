#include <conio.h>
#include <stdlib.h>

#include "scan.h"

int main(void)
{
	uint32_t date;
	uint64_t real;
	
	printf("Arrow Scan demonstration. Use up and down arrow to navigate and enter to choose. \nPress any key to engage.");
	_getch();
	system("CLS");
	printf("Scanned %d\nPress any key to continue.", scan_arrowy(3, 0, 0));
	_getch();
	system("CLS");
	printf("Date Scan demonstration. Enter a valid date and click enter to proceed. Use backspace to delete. Invalid dates shouldn't allow you to proceed. \nPress any key to engage.");
	_getch();
	system("CLS");
	date = scan_date();
	system("CLS");
	printf("Scanned %d/%d/%d.\nPress any key to continue.", date_day(date), date_month(date), date_year(date));
	_getch();
	system("CLS");
	printf("Real Scan demonstration. Enter a valid real number and separate decimal with a dot. Click enter to proceed or backspace to delete.\nPress any key to engage.");
	_getch();
	system("CLS");
	real = scan_real(18, 1);
	system("CLS");
	printf("Scanned %d,%d\nPress any key to continue.", real_whole(real), real_decimal(real));
	_getch();
	system("CLS");

	return 0;
}