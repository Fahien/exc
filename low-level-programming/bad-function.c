#include <stdio.h>
#include <stdlib.h>


// What is the value of ~(~0 << n)?
// This expression sets the first n bits to 1
// What does this function do?
// This function shifts a number of bits to the right and applies a mask.
// It's overcomplicated.
unsigned int f(unsigned int i, int m, int n)
{
	return (i >> (m + 1 - n)) & ~(~0 << n);
}


int main()
{
	unsigned int a = 0x12345678;
	for (int m = 0; m < 8; ++m)
		for (int n = 0; n < 8; ++n)
			printf("f(0x%x, %u, %u) = 0x%x\n",
					a,
					m * 4 - 1,
					n * 4,
					f(a, m * 4 - 1, n * 4));
	return EXIT_SUCCESS;
}
