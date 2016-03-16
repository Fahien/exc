#include <stdio.h>
#include <stdlib.h>

/*
 * Program that converts a numerical grade into a letter grade
 */
int main (int argc, char** argv)
{
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: ./grade-convert grade\n");
        return EXIT_FAILURE;
    }

    // Convert input string to int
    int numerical_grade = atoi(argv[1]);

    // Check for input error
    if (numerical_grade < 0 || 100 < numerical_grade) {
        fprintf(stderr, "The numerical grade must be comprised between 0 and 100\n");
        return EXIT_FAILURE;
    }

    // Simplify computation
    numerical_grade /= 10;

    // Initialize letter grade
    char letter_grade = 'F';

    // Compute conversion
    switch (numerical_grade) {
      case 6: letter_grade = 'D'; break;
      case 7: letter_grade = 'C'; break;
      case 8: letter_grade = 'D'; break;
      case 9: case 10: letter_grade = 'A'; break;
      default: break;
    }

    // Print out the letter grade
    printf("%c\n", letter_grade);

    return EXIT_SUCCESS;
}
