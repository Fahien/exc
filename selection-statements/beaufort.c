#include <stdio.h>
#include <stdlib.h>

#define CALM "Calm"				// less than 1
#define LIGHT "Light air"		// 1 - 3
#define BREEZE "Breeze"			// 4 - 27
#define GALE "Gale"				// 28 - 47
#define STORM "Storm"			// 48 - 63
#define HURRICANE "Hurricane"	// Above 63

#define CALM_LIM 1
#define LIGHT_LIM 4
#define BREEZE_LIM 28
#define GALE_LIM 48
#define STORM_LIM 64

/*
 * Program that takes a wind speed (in knots), then
 * displays the corresponding description
 */
int main (int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./beaufort <WIND SPEED (in knots)>\n");
		return EXIT_FAILURE;
	}

	int speed = atoi(argv[1]);

	if (speed < CALM_LIM) {
		printf(CALM"\n"); // string concatenation
	}
	else if (speed < LIGHT_LIM) {
		printf(LIGHT"\n");
	}
	else if (speed < BREEZE_LIM) {
		printf(BREEZE"\n");
	}
	else if (speed < GALE_LIM) {
		printf(GALE"\n");
	}
	else if (speed < STORM_LIM) {
		printf(STORM"\n");
	}
	else {
		printf(HURRICANE"\n");
	}

	return EXIT_SUCCESS;
}