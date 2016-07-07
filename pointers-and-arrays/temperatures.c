#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "find-largest.h"

#define DAYS 7
#define HOURS 24

#define TEMPERATURE_MAX 42

void print_day(int temperatures[DAYS][HOURS], unsigned int day)
{
    int *begin = *temperatures + day * HOURS;
    int *end = begin + HOURS;
    while (begin < end) {
        printf("%2d ", *begin++);
    }
    printf("\b\n");
}


int main(void)
{
    // Randomize seed
    srand(time(NULL));

    // Declare and initialize temperatures array
    int temperatures[DAYS][HOURS];
    int *p = temperatures[0];
    int *limit = p + DAYS*HOURS;
    while(p < limit) {
        *p++ = rand() % TEMPERATURE_MAX;
    }

    // Print temperatures header
    for (int i = 0; i < HOURS; ++i) {
        printf("%2d ", i);
    }
    printf("\b\n");
    // Print temperatures
    for (int i = 0; i < DAYS; ++i) {
        print_day(temperatures, i);
    }

    // Search for value 32
    bool found = search(temperatures[0], DAYS*HOURS, 32);
    if (found) { printf("32 found!\n"); }
    else { printf("32 not found\n"); }

    // Find highest temperature
    int *highest = find_largest(temperatures[0], DAYS*HOURS);
    printf("Highest: %d\n", *highest);

    return EXIT_SUCCESS;
}
