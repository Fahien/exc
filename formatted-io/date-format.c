#include <stdio.h>
#include <stdlib.h>

/*
 * Program that accepts a date from the user in the form mm/dd/yyyy
 * and then displays it in the form yyyymmdd
 */
int main (void)
{
	printf("Enter a date (mm/dd/yyyy): ");

	int mm;
	int dd;
	int yyyy;
	scanf("%d/%d/%d", &mm, &dd, &yyyy);

	printf("You entered the date %4.4d%2.2d%2.2d\n", yyyy, mm, dd);

	return EXIT_SUCCESS;
}
