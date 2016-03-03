#include <stdio.h>
#include <stdlib.h>

/*
 * Program that calculates the remaining balance on a loan
 * after the first, second, and third monthly payments
 */

int main (void)
{
	printf("Enter amount of loan: ");
	float loan;
	int scanf_result = scanf("%f", &loan);

	if (scanf_result == EOF) {
		perror("scanf");
		return EXIT_FAILURE;
	}

	printf("Enter interest rate: ");
	float interest_rate;
	scanf_result = scanf("%f", &interest_rate);

	if (scanf_result == EOF) {
		perror("scanf");
		return EXIT_FAILURE;
	}

	interest_rate = interest_rate / 100.0f / 12.0f;

	printf("Enter monthly payment ");
	float monthly_payment;
	scanf_result = scanf("%f", &monthly_payment);

	if (scanf_result == EOF) {
		perror("scanf");
		return EXIT_FAILURE;
	}

	float first_balance = loan - monthly_payment;
	first_balance += loan * interest_rate;
	printf("Balance remaining after first payment: $%.2f\n", first_balance);

	float second_balance = first_balance - monthly_payment;
	second_balance += first_balance * interest_rate;
	printf("Balance remaining after second payment: $%.2f\n", second_balance);

	float third_balance = second_balance - monthly_payment;
	third_balance += second_balance * interest_rate;
	printf("Balance remaining after third payment: $%.2f\n", third_balance);

	return EXIT_SUCCESS;
}
