#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UPC_LIM 12
/*
 * Program that checks whether a Universal Product Code is valid
 */
int main (int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./upc code\n");
		return EXIT_FAILURE;
	}

	// Get first UPC_LIM digits
	char buff[UPC_LIM];
	memcpy(buff, argv[1], UPC_LIM);
	
	int first_digit;
	int first_group[5];
	int second_group[5];
	int check_digit;

	int sscanf_result = sscanf(buff,
			"%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
			&first_digit, first_group, first_group + 1,
			first_group + 2, first_group + 3, first_group + 4,
			second_group, second_group + 1, second_group + 2,
			second_group + 3, second_group + 4, &check_digit);

	// Check for input error
	if (sscanf_result != UPC_LIM) {
		fprintf(stderr, "Could not read %d digits\n", UPC_LIM);
		return EXIT_FAILURE;
	}

	int first_sum = first_digit + first_group[1] + first_group[3]
			+ second_group[0] + second_group[2] + second_group[4];
	int second_sum = first_group[0] + first_group[2] + first_group[4]
			+ second_group[1] + second_group[3];
	int total = 3 * first_sum + second_sum;
	int check = 9 - ((total - 1) % 10);

	printf("%s: %s\n", buff, check == check_digit ? "VALID" : "NOT VALID");

	return EXIT_SUCCESS;
}
