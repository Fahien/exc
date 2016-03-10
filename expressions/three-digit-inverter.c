#include <stdio.h>
#include <stdlib.h>

/*
 * Write a program that asks the user to enter a three-digit number,
 * then prints the number with its digits reversed
 */
int main (void)
{
	printf("Enter a three-digit number: ");
	int number;
	scanf("%d", &number);

	int ones = number % 10;
	int tens = number / 10 % 10;
	int hundreds = number / 100;
	int reversal = ones * 100 + tens * 10 + hundreds;
	
	printf("The reversal is: %d\n", reversal);

	return EXIT_SUCCESS;
}
