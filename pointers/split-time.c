#include <stdio.h>
#include <stdlib.h>


/// @param total_sec is a time represented as the number of seconds since midnight
/// @params hr, min and sec are pointers to variables in which the function will store the equivalent time
/// in hours, minutes and seconds, respectively
void split_time(long total_sec, int *hour, int *min, int *sec)
{
    *hour = total_sec / 60 / 60;
    *min = total_sec / 60 - *hour * 60;
    *sec = total_sec % 60;
}


int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./split-time n\n");
        return EXIT_FAILURE;
    }

    // Declare variables
    long total_sec = atol(argv[1]);
    int hour, min, sec;

    split_time(total_sec, &hour, &min, &sec);
    printf("split_time = %.2d:%.2d:%.2d\n", hour, min, sec);

    return EXIT_SUCCESS;
}
