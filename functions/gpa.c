#include <stdio.h>
#include <stdlib.h>

#define GRADE_COUNT 12

/*
 * This function computes and returns the average of a set of grades
 */
float computeGPA(char grades[], unsigned int size)
{
    float avg = 0.0f;
    for (unsigned int i = 0; i < size; ++i) {
        switch (grades[i]) {
          case 'A': avg += 4.0f; break;
          case 'B': avg += 3.0f; break;
          case 'C': avg += 2.0f; break;
          case 'D': avg += 1.0f; break;
          case 'F': avg += 0.0f; break;
          default:
            fprintf(stderr, "Invalid grade %c\n", grades[i]);
            return -1.0f;
        }
    }
    return avg / (float) size;
}

int main()
{
    // Create grades
    char grades[GRADE_COUNT];

    printf("Grades: ");
    for (unsigned int i = 0; i < GRADE_COUNT; ++i) {
        grades[i] = 'A' + i % 4;
        printf("%c ", grades[i]);
    }
    printf("\b\n");

    printf("computeGPA(grades, %d) = %f\n", GRADE_COUNT, computeGPA(grades, GRADE_COUNT));

    return EXIT_SUCCESS;    
}
