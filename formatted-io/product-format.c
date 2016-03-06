#include <stdio.h>
#include <stdlib.h>

#define AMOUNT_MAX 9999.99

/*
 * Program that formats product information entered by the user
 */
int main (void)
{
	printf("Enter item number: ");
	int id = 0;
	scanf("%d", &id);

	printf("Enter unit price: ");
	float price = 0.0f;
	scanf("%f", &price);

	if (price > AMOUNT_MAX) {
		fprintf(stderr, "Price could not be greater than %7.2f\n", AMOUNT_MAX);
		return EXIT_FAILURE;
	}

	printf("Enter purchase date (mm/dd/yyyy): ");
	int mm = 0;
	int dd = 0;
	int yyyy = 0;
	scanf("%d/%d/%d", &mm, &dd, &yyyy);
	printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
	printf("%-d\t\t$%7.2f\t%-2.2d/%-2.2d/%-4.4d\n", id, price, mm, dd, yyyy);

	return EXIT_SUCCESS;
}
