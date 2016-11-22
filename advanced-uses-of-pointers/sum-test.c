#include <stdio.h>
#include <stdlib.h>

#include "sum.h"


int square(int n)
{
	return n*n;
}


int main()
{
	printf("Sum(square, 0, 3) = %d\n", sum(square, 0, 3));
	return EXIT_SUCCESS;
}

