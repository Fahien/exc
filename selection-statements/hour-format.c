#include <stdio.h>
#include <stdlib.h>

/*
 * Program that take a 24-hour time and
 * displays the time in 12-hour form
 */
int main (int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./hour-format <hh:mm>\n");
		return EXIT_FAILURE;
	}

	int hours;
	int minutes;

	sscanf(argv[1], "%d:%d", &hours, &minutes);
	
	// Check for hours boundaries
	if (hours < 0 || 24 < hours) {
		fprintf(stderr, "Hours could not be %d\n", hours);
		return EXIT_FAILURE;
	}

	// Check for minutes boundaries
	if (minutes < 0 || 59 < minutes) {
		fprintf(stderr, "Minutes could not be %d\n", minutes);
		return EXIT_FAILURE;
	}

	// Check for 24:(XX>00)
	if (hours == 24 && minutes != 0) {
		fprintf(stderr, "%.2d:%.2d is not a valid 24-hour time\n", hours, minutes);
		return EXIT_FAILURE;
	}

	printf("24-hour time %.2d:%.2d\n", hours, minutes);
    printf("Equivalent 12-hour time: "); 	
	
	if (hours == 24) {
		printf("00:%.2d AM\n", minutes);
	}
	else if (hours > 12) {
		printf("%.2d:%.2d PM\n", hours - 12, minutes);
	}
	else {
		printf("%.2d:%.2d AM\n", hours, minutes);
	}

	return EXIT_SUCCESS;
}
