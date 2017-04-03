#include <stdio.h>
#include <stdlib.h>


/// Show the output produced by each of the following program fragments.
/// Assume that i, j, and k are unsigned short variables.
int main()
{
	unsigned short i, j, k;

	i = 8;
	j = 9;
	printf("%d\n", i >> 1 + i >> 1); // 0

	i = 1;
	printf("%d\n", i & ~i); // 0

	i = 2;
	j = 1;
	k = 0;
	printf("%d\n", ~i & j ^ k); // 1

	i = 7;
	j = 8;
	k = 9;
	printf("%d\n", i ^ j & k); // 15
	return EXIT_SUCCESS;
}
