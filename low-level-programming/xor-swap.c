#include <stdio.h>
#include <stdlib.h>

/// Explain what effect the following macro has on its argument.
#define M(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))


void callM(unsigned short i, unsigned short j)
{
	printf("M(i=%d, j=%d) -> ", i, j);
	M(i, j);
	printf("(i=%d, j=%d)\n", i, j);
}


int main()
{
	// Actually, the macro swaps the two values
	for (unsigned short i = 0; i < 8; ++i)
		for (unsigned short j = 0; j < 8; ++j)
			callM(i, j);

	return EXIT_SUCCESS;
}
