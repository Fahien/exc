#include <stdio.h>
#include <stdlib.h>

/*
 * Program that takes a two-digit number and
 * prints the English word for the number
 */
int main (int argc, char** argv)
{
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./number-to-word two-digit-number\n");
        return EXIT_FAILURE;
    }

    // Convert input string to int
    int number = atoi(argv[1]);

    // Check for range error
    if (number < 10 || 99 < number) {
        fprintf(stderr, "The number must be comprised between 10 and 99\n");
        return EXIT_FAILURE;
    }

    // Get the digits
    int r_digit = number % 10;
    int l_digit = number / 10;

    // Print out left digit
    switch (l_digit) {
        case 1: { // Handle special cases
            switch (r_digit) {
                case 0: printf("ten\n"); goto EXIT;
                case 1: printf("eleven\n"); goto EXIT;
                case 2: printf("twelve\n"); goto EXIT;
                case 3: printf("thirteen\n"); goto EXIT;
                case 4: printf("fourteen\n"); goto EXIT;
                case 5: printf("fifteen\n"); goto EXIT;
                case 6: printf("sixteen\n"); goto EXIT;
                case 7: printf("seventeen\n"); goto EXIT;
                case 8: printf("eighteen\n"); goto EXIT;
                case 9: printf("nineteen\n"); goto EXIT;
                default: { // Error case
                    fprintf(stderr, "Invalid right digit: %d\n", r_digit);
                    return EXIT_FAILURE;
                }
            }
        }
        case 2: printf("twenty"); break;
        case 3: printf("thirty"); break;
        case 4: printf("forty"); break;
        case 5: printf("fifty"); break;
        case 6: printf("sixty"); break;
        case 7: printf("seventy"); break;
        case 8: printf("eighty"); break;
        case 9: printf("ninety"); break;
        default: { // Error case
            fprintf(stderr, "Invalid left digit: %d\n", l_digit);
            return EXIT_FAILURE;
        }
    }
    
    switch (r_digit) {
        case 0: printf("\n"); break;
        case 1: printf("-one\n"); break;
        case 2: printf("-two\n"); break;
        case 3: printf("-three\n"); break;
        case 4: printf("-four\n"); break;
        case 5: printf("-five\n"); break;
        case 6: printf("-six\n"); break;
        case 7: printf("-seven\n"); break;
        case 8: printf("-eight\n"); break;
        case 9: printf("-nine\n"); break;
        default: { // Error case
            fprintf(stderr, "Invalid right digit: %d\n", r_digit); 
            return EXIT_FAILURE;
        }
    }

    EXIT:
    return EXIT_SUCCESS;
}
