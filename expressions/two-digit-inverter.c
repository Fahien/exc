#include <stdio.h>
#include <stdlib.h>

/*
 * Program that asks the user to enter a two-digit number,
 * then prints the number with its digits reversed
 */
int main (void)
{
	printf("Enter a two-digit number: ");
	int number;
	scanf("%d", &number);

	int ones = number % 10;
	int tens = number / 10;
	int reversal = ones * 10 + tens;

	printf("The reversal is: %d\n", reversal);

	return EXIT_SUCCESS;
}
