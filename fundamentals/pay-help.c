#include <stdio.h>
#include <stdlib.h>

/*
 * Program that asks the user to enter a U.S. dollar amount and then shows how
 * to pay that amount using the smallest number of $20, $10, $5 and $1 bills
 */
int main (void)
{
	printf("Enter a dollar amount: ");
	int amount;
	int scanf_result = scanf("%d", &amount);
	
	if (scanf_result == EOF) {
		perror("scanf");
		return EXIT_FAILURE;
	}

	int bills20 = amount / 20;
	
	int mod20 = amount % 20;
	int bills10 = mod20 / 10;

	int mod10 = mod20 % 10;
	int bills5 = mod10 / 5;

	int bills1 = mod10 % 5;

	printf("\n$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d\n",
		bills20, bills10, bills5, bills1);

	return EXIT_SUCCESS;
}
