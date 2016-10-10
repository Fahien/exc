#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct time
{
	int hours;
	int minutes;
	int seconds;
} Time;

/// Returns a structure containing the equivalent time of total_seconds in hours, minutes and seconds
Time split_time(int total_seconds)
{
	Time t;
	t.seconds = total_seconds % 60;
	total_seconds -= t.seconds;
	int minutes = total_seconds / 60;
	t.minutes = minutes % 60;
	minutes -= t.minutes;
	t.hours = minutes / 60;
	return t;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage: ./time total_seconds\n");
		return EXIT_FAILURE;
	}

	Time t = split_time(atoi(argv[1]));
	printf("%.2d:%.2d:%.2d\n", t.hours, t.minutes, t.seconds);
	return EXIT_SUCCESS;
}
