#include <stdio.h>
#include <stdlib.h>


/// Returns the result of shifting the bits in i to the left by n places,
/// where bits that were "shifted off" moved to the right end of i.
unsigned int rotate_left(unsigned int i, unsigned int n)
{
	size_t bit_count = sizeof(i) * 8;
	unsigned int bit_saved = i >> (bit_count - n);
	i = (i << n) | bit_saved;
	return i;
}

/// Similar to "rotate_right", but it rotates bits to the right instead of the left.
unsigned int rotate_right(unsigned int i, unsigned int n)
{
	size_t bit_count = sizeof(i) * 8;
	unsigned int bit_saved = i << (bit_count - n);
	i = (i >> n) | bit_saved;
	return i;
}


/// Tests the two functions
int main()
{
	unsigned int a = 0x12345678;
	for (unsigned int i = 0; i < 8; ++i)
	{
		printf("rotate_left(0x%x, %u) = 0x%x\n", a, i * 4, rotate_left(a, i * 4));
		printf("rotate_right(0x%x, %u) = 0x%x\n", a, i * 4, rotate_right(a, i * 4));
	}
	return EXIT_SUCCESS;
}
