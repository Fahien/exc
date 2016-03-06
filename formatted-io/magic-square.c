#include <stdio.h>
#include <stdlib.h>

/*
 * Program that asks the user to enter the numbers from 1 to 16
 * (in any order) and then displays the numbers in a 4 by 4 arrangement,
 * followed by the sums of the rows, columns and diagonals
 */
int main (void)
{
	printf("Enter the numbers from 1 to 16 in any order:\n");
	
	int numbers[16];
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
			numbers, numbers+1, numbers+2, numbers+3,
			numbers+4, numbers+5, numbers+6, numbers+7,
			numbers+8, numbers+9, numbers+10, numbers+11,
			numbers+12, numbers+13, numbers+14, numbers+15);

	int rowsums[4];
	int colsums[4];
	for (int i = 0; i < 4; i++) {
		int row = i*4;
		printf("%2d%3d%3d%3d\n",
				numbers[row], numbers[row+1], numbers[row+2], numbers[row+3]);
		rowsums[i] = numbers[row] + numbers[row+1] + numbers[row+2] + numbers[row+3];
		colsums[i] = numbers[i] + numbers[i+4] + numbers[i+8] + numbers[i+12];
	}
	
	int diagsums[2];
	diagsums[0] = numbers[0] + numbers[5] + numbers[10] + numbers[15];
	diagsums[1] = numbers[3] + numbers[6] + numbers[9] + numbers[12];

	printf("Row sums: %d %d %d %d\n",
			rowsums[0], rowsums[1], rowsums[2], rowsums[3]);
	printf("Column sums: %d %d %d %d\n",
			colsums[0], colsums[1], colsums[2], colsums[3]);
	printf("Diagonal sums: %d %d\n", diagsums[0], diagsums[1]);

	return EXIT_SUCCESS;
}
