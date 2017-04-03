#include <stdio.h>
#include <stdlib.h>

/// Toggles bit j
unsigned short toggle(unsigned short i, unsigned short j)
{
	if (i & 1 << j) // test bit j
		i &= ~(1 << j); // clear bit j
	else
		i |= 1 << j; // set bit j
	return i;
}

/// Describe a simple way to "toggle" a bit. Illustrate the technique
/// by writing a statement that toggles bit 4 of the variable i.
int main()
{
	unsigned short i = 0;

	printf("%d\n", toggle(i, 0)); // 1
	printf("%d\n", toggle(i, 1)); // 2
	printf("%d\n", toggle(toggle(i, 3), 3)); // 0
	printf("%d\n", toggle(i, 4)); // 16

	return EXIT_SUCCESS;
}
