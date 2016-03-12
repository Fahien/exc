#include <stdio.h>
#include <stdlib.h>

#define CLASS1_LIM 750.0f
#define CLASS2_LIM 2250.0f
#define CLASS3_LIM 3750.0f
#define CLASS4_LIM 5250.0f
#define CLASS5_LIM 7000.0f

#define CLASS1_TAX 0.01f
#define CLASS2_TAX 0.02f
#define CLASS3_TAX 0.03f
#define CLASS4_TAX 0.04f
#define CLASS5_TAX 0.05f
#define CLASS6_TAX 0.06f
/*
 * Program that takes an amount of taxable income,
 * then displays the tax due
 */
int main (int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./tax-helper <INCOME>\n");
		return EXIT_FAILURE;
	}

	float amount;
	int sscanf_result = sscanf(argv[1], "%f", &amount);
	if (sscanf_result != 1) {
		perror("sscanf");
		return EXIT_FAILURE;
	}

	printf("Income: $%.2f\nTax due: ", amount);

	if (amount < CLASS1_LIM) {
		printf("$%.2f\n", amount * CLASS1_TAX);
	}
	else if (amount < CLASS2_LIM) {
		printf("$%.2f\n", amount * CLASS2_TAX);
	}
	else if (amount < CLASS3_LIM) {
		printf("$%.2f\n", amount * CLASS3_TAX);
	}
	else if (amount < CLASS4_LIM) {
		printf("$%.2f\n", amount * CLASS4_TAX);
	}
	else if (amount < CLASS5_LIM) {
		printf("$%.2f\n", amount * CLASS5_TAX);
	}
	else {
		printf("$%.2f\n", amount * CLASS6_TAX);
	}

	return EXIT_SUCCESS;
}
