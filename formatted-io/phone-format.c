#include <stdio.h>
#include <stdlib.h>

/*
 * Program that prompts the user to enter a telephone number
 * in the form (xxx) xxx-xxxx and then displays the number
 * in the form xxx.xxx.xxxx
 */
int main (void)
{
	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	int n1, n2, n3;
	scanf("(%d) %d-%d", &n1, &n2, &n3);

	printf("You entered %d.%d.%d\n", n1, n2, n3);

	return EXIT_SUCCESS;
}
