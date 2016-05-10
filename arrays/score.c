#include <stdio.h>
#include <stdlib.h>

#define STUDENT_COUNT 5
#define QUIZ_COUNT 5

/*
 * Program that prompts for 5 quiz grades for 5 students,
 * then computes the total score and average score for each student,
 * and the average score, high score and low score for each quiz.
 */
int main (void)
{
    // Declare a matrix
    int matrix[STUDENT_COUNT][QUIZ_COUNT] = {0};
    // And a help pointer
    int* pointer = 0;

    // Read the rows
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter grades for student %d: ", i);
        pointer = *(matrix + i);
        scanf("%d %d %d %d %d",
                pointer, pointer + 1, pointer + 2, pointer + 3, pointer + 4);
    }

    // Print out the table
    for (int i = 0; i < STUDENT_COUNT; i++) {
        for (int j = 0; j < QUIZ_COUNT; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\b\n");
    }

    // Loop variable
    int sum;
    // Print student total and average
    for (int i = 0; i < STUDENT_COUNT; i++) {
        // First element
        sum = **(matrix + i);
        for (int j = 1; j < QUIZ_COUNT; j++) {
            sum += *(*(matrix + i) + j);
        }
        printf("Student [%d] - total [%d] - average [%d]\n", i, sum, sum / QUIZ_COUNT);
    }

    // Loop variable
    int value = 0;
    int low = 0;
    int high = 0;
    // Print quiz average, high and low
    for (int i = 0; i < QUIZ_COUNT; i++) {
        value = *(*(matrix) + i);
        sum = value;
        low = value;
        high = value;
        for (int j = 1; j < STUDENT_COUNT; j++) {
            value = *(*(matrix + j) + i);
            sum += value;
            if (value < low) low = value;
            if (value > high) high = value;
        }
        printf("Quiz [%d] - average [%d] - high [%d] - low [%d]\n", i, sum / STUDENT_COUNT, high, low);
    }

    return EXIT_SUCCESS;
}
