#include <stdio.h>
#include <stdlib.h>

#define ROW_COUNT 5

/*
 * Program that reads a 5x5 array of integers and
 * then prints the row sums and the column sums.
 */
int main (void)
{
    // Declare a matrix
    int matrix[5][5] = {0};

    // Read the rows
    for (int i = 0; i < ROW_COUNT; i++) {
        printf("Enter row %d: ", i);
        scanf("%d %d %d %d %d", matrix[i], matrix[i] + 1,
                matrix[i] + 2, matrix[i] + 3, matrix[i] + 4);
    }

    // Print row totals 
    printf("Row totals:");
    for (int i = 0; i < ROW_COUNT; i++) {
        int sum = 0;
        for (int j = 0; j < ROW_COUNT; j++) {
            sum += matrix[i][j];
        }
        printf(" %d", sum);
    }
    printf("\n");

    // Print column totals
    printf("Column totals:");
    for (int i = 0; i < ROW_COUNT; i++) {
        int sum = 0;
        for (int j = 0; j < ROW_COUNT; j++) {
            sum += matrix[j][i];
        }
        printf(" %d", sum);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
