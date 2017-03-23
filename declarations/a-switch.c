#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	const int a = 1;

	// the compiler will check that no assignment is made
	const int x;

	switch (argc)
	{
	  case a: // const int can be used in case label
		printf("First case\n");
		break;
	  default:
		break;
	}

	return EXIT_SUCCESS;
}
