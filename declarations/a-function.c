#include <stdio.h>
#include <stdlib.h>

#define ITERATION_MAX 11


int f(int i)
{
	static int j = 0;
	return i * j++;
}


int main(void)
{
	for(int i = 0; i < ITERATION_MAX; ++i)
		printf("f(%d) = %d\n", i, f(i));

	return EXIT_SUCCESS;
}
