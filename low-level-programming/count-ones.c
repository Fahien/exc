#include <stdio.h>
#include <stdlib.h>


/// Returns the number of 1 bits in ch
unsigned int count_ones(unsigned char ch)
{
	unsigned int ones = 0;
	size_t bit_count = sizeof(ch) * 8;
	for (size_t i = 0; i < bit_count; ++i)
	{
		if (ch & 1 << i)
			++ones;
	}
	return ones;
}


int main()
{
	for (unsigned char i = 0; i < 8; ++i)
		printf("Ones in 0x%x = %u\n", i, count_ones(i));
	return EXIT_SUCCESS;
}
