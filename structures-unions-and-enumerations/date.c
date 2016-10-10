#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct date
{
	int month;
	int day;
	int year;
} Date;

bool is_leap(int year)
{
	if (year % 400 == 0) { return true; }
	else if (year % 100 == 0) { return false; }
	else if (year % 4 == 0) { return true; }
	else { return false; }
}

int days_in(int month, int year)
{
	if (month < 0 || month > 11) { return 0; }
	if (month == 1) {
		if (is_leap(year)) { return 29; }
		else { return 28; }
	}
	else if (month == 3 || month == 5 || month == 8 || month == 10) { return 30; }
	else { return 31; }
}

/// Returns the day of the year (an integer between 1 and 366) that corresponds to the date d
int day_of_year(Date d)
{
	int day = 0;
	for (int i = 0; i < d.month; ++i) {
		day += days_in(i, d.year);
	}
	return day + d.day;
}

/// Returns -1 if d1 is an earlier date than d2,
// +1 if d1 is a later date than d2,
// and 0 if d1 and d2 are the same
int compare_dates(Date d1, Date d2)
{
	if (d1.year < d2.year) { return -1; }
	else if (d1.year > d2.year) { return 1; }
	else if (d1.month < d2.month) { return -1; }
	else if (d1.month > d2.month) { return 1; }
	else if (d1.day < d2.day) { return -1; }
	else if (d1.day > d2.day) { return 1; }
	else { return 0; }
}

int main(int argc, char **argv)
{
	if (argc < 4) {
		fprintf(stderr, "Usage: ./date month day year\n");
		return EXIT_FAILURE;
	}

	Date date = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};
	printf("Day of year = %d\n", day_of_year(date));

	Date d2 = {0, 1, 1970};
	printf("Compare date with 1/1/1970 = %d\n", compare_dates(date, d2));

	return EXIT_SUCCESS;
}
