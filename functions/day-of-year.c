#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * This function tests whether an year is a leap year
 */
bool is_leap(int year)
{
    // 1. If the year is evenly divisible by 4, go to step 2.
    //    Otherwise, go to step 5.
    if (year % 4 == 0) {
        // 2. If the year is evenly divisible by 100, go to step 3.
        //    Otherwise, go to step 4.
        if (year % 100 == 0) {
            // 3. If the year is evenly divisible by 400, go to step 4.
            //    Otherwise, go to step 5.
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

/*
 * This function returns the number of days of a month
 */
int number_of_days(int month, int year)
{
    // Check for input error
    if (month < 1 || 12 < month) {
        fprintf(stderr, "Month must be comprised between 1 and 12, inclusive\n");
        return -1;
    }

    // Logic
    switch (month) {
        case 2: return is_leap(year) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

/*
 * This function returns the day of the year specified by the three arguments
 */
int day_of_year(int month, int day, int year)
{
    // Check for input error
    int dayCount = number_of_days(month, year);
    // Check for month error
    if (dayCount < 0) return -1;
    // Check for day error
    if (day < 1 || dayCount < day) {
        fprintf(stderr, "Day must be comprised between 1 and %d, inclusive\n", dayCount);
        return -1;
    }

    // To return
    int ret = 0;
   
    // Sum
    for (int i = 1; i < month; i++) {
        dayCount = number_of_days(i, year);
        ret += dayCount;
    }
    // Last sum
    ret += day;

    return ret;
}

/*
 * Test day of year
 */
int main(int argc, char** argv)
{
    if (argc != 4) {
        fprintf(stderr, "Usage: ./day-of-year month day year\n");
        return EXIT_FAILURE;
    }

    int month = atoi(argv[1]);
    int day = atoi(argv[2]);
    int year = atoi(argv[3]);

    printf("day_of_year(%d, %d, %d) = %d\n", month, day, year, day_of_year(month, day, year));
    return EXIT_SUCCESS;
}
