#include <stdio.h>
#include <stdlib.h>

/*
 * Program that gets a number of days of a month and
 * the day of the week on which the month begins,
 * then prints that month calendar
 */
int main (int argc, char** argv)
{
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: ./one-month-calendar n d\n"
                "\tn - number of days of a month\n"
                "\td - day of the week on which the month begins\n");
        return EXIT_FAILURE;
    }

    // Convert string input
    int days_num = atoi(argv[1]);
    int day = atoi(argv[2]);

    // Check input
    if (day < 1 || day > 7) {
        fprintf(stderr, "The day of the week must be comprised between 1 (Sunday) and 7 (Saturday)\n");
        return EXIT_FAILURE;
    }  
    // Print header
    printf("SUN MON TUE WED THU FRI SAT\n");

    // Leave space
    for (int i = 1; i < day; i++) printf("    ");

    // Print calendar
    int i = 0;
    for (i = 1; i <= days_num; i++) {
        printf("%3d ", i);
        if ((i - 1 + day) % 7 == 0) printf("\n");
    }
    if ((i - 2 + day ) % 7 != 0) printf("\n");

    return EXIT_SUCCESS;
}
