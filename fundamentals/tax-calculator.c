#include <stdio.h>
#include <stdlib.h>

/*
 * Program that asks the user to enter a dollars-and-cents amount,
 * then displays the amount with 5% tax added
 */
int main (void)
{
	printf("Enter an amount: ");
	float amount;
	int scanf_result = scanf("%f", &amount);

	if (scanf_result == EOF) {
		perror("scanf");
		return EXIT_FAILURE;
	}

	float with_tax = amount * 1.05f;
	printf("With tax added: $%.2f\n", with_tax);

	return EXIT_SUCCESS;
}
