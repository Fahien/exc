#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct date
{
	int month;
	int day;
	int year;
};

bool is_valid(const struct date* d);

bool is_leap_year(const int year);

int compare(const struct date* a, const struct date* b);

/*
 * This program indicates which date comes earlier on the calendar
 */
int main (int argc, char** argv)
{
	// Check arguments
	if (argc != 3) {
		fprintf(stderr, "Usage: ./date-compare mm/dd/yy mm/dd/yy\n");
		return EXIT_FAILURE;
	}

	// Get first date
	struct date date1;
	sscanf(argv[1], "%d/%d/%d", &date1.month, &date1.day, &date1.year);
	if (!is_valid(&date1)) return EXIT_FAILURE;

	// Get second date
	struct date date2;
	sscanf(argv[2], "%d/%d/%d", &date2.month, &date2.day, &date2.year);
	if (!is_valid(&date2)) return EXIT_FAILURE;

	// Compare the dates
	int compare_result = compare(&date1, &date2);

	// Print result
	if (compare_result == 0) {
		printf("The dates are equal\n");
	}
	else if (compare_result < 0) {
		printf("%.2d/%.2d/%.2d is before %.2d/%.2d/%.2d\n",
				date1.month, date1.day, date1.year,
				date2.month, date2.day, date2.year);
	}
	else if (compare_result > 0) {
		printf("%.2d/%.2d/%.2d is before %.2d/%.2d/%.2d\n",
				date2.month, date2.day, date2.year,
				date1.month, date1.day, date1.year);
	}

	return EXIT_SUCCESS;
}

/*
 * Tests whether a date is valid
 */
bool is_valid(const struct date* d)
{
	// Validate month
	if (d->month < 1 || 12 < d->month) {
		fprintf(stderr, "Month could not be %d\n", d->month);
		return false;
	}

	// Validate day
	switch (d->month) {
	  case 2: {
		return is_leap_year(d->year) ?
				(0 < d->day && d->day < 30) :
				(0 < d->day && d->day < 29);
	  }
	  case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
		return (0 < d->day && d->day < 32);
	  }
	  case 4: case 6: case 9: case 11: {
		return (0 < d->day && d->day < 31);
	  }
	  default: return false;
	}

	// Print error message
	fprintf(stderr, "Day of month %d could not be %d\n", d->month, d->day);

	return false;
}

/*
 * Tests whether a year is a leap year
 */
bool is_leap_year(const int year)
{
	// Easy algorithm
	if (year % 4 != 0) return false;
	if (year % 100 != 0) return true;
	if (year % 400 != 0) return false;
	return true;
}

/*
 * Compares two dates
 */
int compare(const struct date* a, const struct date* b)
{
	// Onion test
	if (a->year == b->year) {
		if (a->month == b->month) {
			if (a->day == b->day) {
				return 0;
			}
			else if (a->day < b->day) return -1;
			else return 1;
		}
		else if (a->month < b->month) return -1;
		else return 1;
	}
	else if (a->year < b->year) return -1;
	else return 1;
}
