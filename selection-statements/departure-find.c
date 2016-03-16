#include <stdio.h>
#include <stdlib.h>

#define FLIGHTS_COUNT 8

/*
 * This program takes a time (expressed in hours and minutes,
 * using the 24-hour clock) and displays the departure and
 * arrival times for the flight whose departure time is
 * closest to that entered by the user
 */
struct time
{
	int hours;
	int minutes;
};

void create_flights(struct time* departures, struct time* arrivals);

int find_closest_time(const struct time t, const struct time* times, const unsigned times_size);

int main (int argc, char** argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./departure-find hh:mm\n");
		return EXIT_FAILURE;
	}

	struct time input_time;

	sscanf(argv[1], "%d:%d", &input_time.hours, &input_time.minutes);

	if (input_time.hours < 0 || 23 < input_time.hours) {
		fprintf(stderr, "Hours not valid: %.2d\n", input_time.hours);
		return EXIT_FAILURE;
	}

	if (input_time.minutes < 0 || 59 < input_time.minutes) {
		fprintf(stderr, "Minutes not valid: %.2d\n", input_time.minutes);
		return EXIT_FAILURE;
	}

	printf("Input time: %.2d:%.2d\n", input_time.hours, input_time.minutes);

	struct time departures[FLIGHTS_COUNT];
	struct time arrivals[FLIGHTS_COUNT];

	create_flights(departures, arrivals);

	printf("Departures\tArrivals\n");
	for (int i = 0; i < FLIGHTS_COUNT; i++) {
		printf("%.2d:%.2d\t\t%.2d:%.2d\n",
				departures[i].hours, departures[i].minutes,
				arrivals[i].hours, arrivals[i].minutes);
	}

	int i = find_closest_time(input_time, departures, FLIGHTS_COUNT);
	printf("Closest departure time is %.2d:%.2d, "
			"arriving at %.2d:%.2d\n",
			departures[i].hours, departures[i].minutes,
			arrivals[i].hours, arrivals[i].minutes);
	
	return EXIT_SUCCESS;
}

void create_flights(struct time* departures, struct time* arrivals)
{
	departures[0].hours = 8; departures[0].minutes = 0;
	departures[1].hours = 9; departures[1].minutes = 43;
	departures[2].hours = 11; departures[2].minutes = 19;
	departures[3].hours = 12; departures[3].minutes = 47;
	departures[4].hours = 14; departures[4].minutes = 0;
	departures[5].hours = 15; departures[5].minutes = 45;
	departures[6].hours = 19; departures[6].minutes = 0;
	departures[7].hours = 21; departures[7].minutes = 45;
	
	arrivals[0].hours = 10; arrivals[0].minutes = 16;
	arrivals[1].hours = 11; arrivals[1].minutes = 52;
	arrivals[2].hours = 13; arrivals[2].minutes = 31;
	arrivals[3].hours = 15; arrivals[3].minutes = 0;
	arrivals[4].hours = 16; arrivals[4].minutes = 8;
	arrivals[5].hours = 17; arrivals[5].minutes = 55;
	arrivals[6].hours = 19; arrivals[6].minutes = 20;
	arrivals[7].hours = 23; arrivals[7].minutes = 58;
}

int find_closest_time(const struct time t, const struct time* times, const unsigned times_size)
{
	int index = 0;

	// Convert input time in minutes
	int t_minutes = t.hours * 60 + t.minutes;

	int minutes_diff = 999999;

	int c_minutes;
	int c_diff;
	for (unsigned i = 0; i < times_size; i++) {
		// Convert current time in minutes
		c_minutes = times[i].hours * 60 + times[i].minutes;
		// Compute difference
		if (c_minutes > t_minutes) {
			c_diff = c_minutes - t_minutes;
		} else {
			c_diff = t_minutes - c_minutes;
		}
		// Update return value
		if (c_diff < minutes_diff) {
			minutes_diff = c_diff;
			index = i;
		}
	}

	return index;
}
