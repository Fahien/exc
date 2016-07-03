#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MONTHS 12

static int days_of_month[] = {
    31, // January
    28, // February
    31, // March
    30, // April
    31, // May
    30, // June
    31, // July
    31, // August
    30, // September
    31, // October
    30, // November
    31 // December
};

/// @brief This function tests whether an year is a leap year
bool is_leap(int year)
{
    // 1. If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
    if (year % 4 == 0) {
        // 2. If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
        if (year % 100 == 0) {
            // 3. If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
                if (year % 400 == 0) {
                // 4. The year is a leap year (it has 366 days).
                return true;
            }
        } else {
            // 4. The year is a leap year (it has 366 days).
            return true;
        }
    }
    // 5. The year is not a leap year (it has 365 days).
    return false;
}


/// @param date_of_year is an integer between 1 and 366,
/// specifying a particular day within the year designated by year.
/// @params month and day point to variables in which the function
/// will store the equivalent month (1-12) and day within month (1-31).
void split_date(int day_of_year, int year, int *month, int *day)
{
    // Check input error
    if (day_of_year < 1) {
        fprintf(stderr, "day_of_year cannot be less than 1\n");
        return;
    }

    // Check whether year is a leap year
    if (is_leap(year)) {
        days_of_month[1] = 29;

        // Check input error
        if (day_of_year > 366) {
            fprintf(stderr, "day_of_year cannot be greater than 366\n");
            return;
        }
    }
    else if (day_of_year > 365) {
        fprintf(stderr, "day_of_year cannot be greater than 365\n");
        return;
    }

    // Perform logic
    *month = 1;
    for (int i = 0; i < MONTHS; ++i) {
        if (day_of_year - days_of_month[i] > 0) {
            day_of_year -= days_of_month[i];
            ++(*month);
        }
        else {
            *day = day_of_year;
            return;
        }
    }
}


int main(int argc, char **argv)
{
    // Check for command line error
    if (argc < 3) {
        fprintf(stderr, "Usage: ./split-date day-of-year year\n");
        return EXIT_FAILURE;
    }

    // Initialize variables
    int day_of_year = atoi(argv[1]);
    int year = atoi(argv[2]);
    int month = 0;
    int day;

    // Test split_date function
    split_date(day_of_year, year, &month, &day);
    printf("Day[%d] - Month[%d]\n", day, month);

    return EXIT_SUCCESS;
}
