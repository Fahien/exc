#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Program that take a 12-hour time and
 * displays the time in 24-hour form
 */
int main (int argc, char **argv)
{
	if (argc != 2 && argc != 3) {
		fprintf(stderr, "Usage: ./hour-format hh:mm(AM/PM)\n");
		return EXIT_FAILURE;
	}

	int hours;
	int minutes;
    char indicator[3];
    memset(indicator, 0, 3);

	if (argc == 2) sscanf(argv[1], "%d:%d%s", &hours, &minutes, indicator);
    else { // 3 arguments
        sscanf(argv[1], "%d:%d", &hours, &minutes);
        sscanf(argv[2], "%s", indicator);
    }
	
	// Check for hours boundaries
	if (hours < 0 || 12 < hours) {
		fprintf(stderr, "Hours could not be %d\n", hours);
		return EXIT_FAILURE;
	}

	// Check for minutes boundaries
	if (minutes < 0 || 59 < minutes) {
		fprintf(stderr, "Minutes could not be %d\n", minutes);
		return EXIT_FAILURE;
	}

    bool isAM = false;
    bool isPM = false;

    size_t len = strlen(indicator);
    if (len == 1) {
        // Check A
        isAM = memcmp(indicator, "A", 1) == 0;
        
        if (!isAM) //Check a
            isAM = memcmp(indicator, "a", 1) == 0;
        
        if (!isAM) // Check P
            isPM = memcmp(indicator, "P", 1) == 0;
        
        if (!isPM) // Check p
            isPM = memcmp(indicator, "p", 1) == 0;
    }
    else if (len == 2) {
        // Check AM
        isAM = memcmp(indicator, "AM", 2) == 0;
        
        if (!isAM) // Check am
            isAM = memcmp(indicator, "am", 2) == 0;
        
        if (!isAM) // Check PM
            isPM = memcmp(indicator, "PM", 2) == 0;
        
        if (!isPM) // Check pm
            isPM = memcmp(indicator, "pm", 2) == 0;
    } else {
        fprintf(stderr, "%s is not a valid AM/PM indicator\n", indicator);
        return EXIT_FAILURE;
    }

	// Check for 12 AM error
	if (hours == 12 && isAM) {
		fprintf(stderr, "%.2d:%.2d %s is not a valid 12-hour time\n", hours, minutes, indicator);
		return EXIT_FAILURE;
	}
    // Check for 0 PM error
    if (hours == 0 && isPM) {
		fprintf(stderr, "%.2d:%.2d %s is not a valid 12-hour time\n", hours, minutes, indicator);
		return EXIT_FAILURE;
    }

	printf("12-hour time %.2d:%.2d %s\n", hours, minutes, indicator);
    printf("Equivalent 24-hour time: ");
	
	if (isPM) {
        hours = (hours == 12) ? 0 : hours + 12;
    }
	printf("%.2d:%.2d\n", hours, minutes);

	return EXIT_SUCCESS;
}
