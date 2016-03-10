#include <stdio.h>
#include <stdlib.h>

/*
 * Program that reads an integer entered by the user
 * and displays it in octal (base 8) 
 */
int main (void)
{
	printf("Enter a number between 0 and 32767: ");
	int number;
	scanf("%d", &number);

	printf("In octal, your number is %o\n", number);	

	return EXIT_SUCCESS;
}
