#include <stdio.h>
#include <stdlib.h>


/// Returns the number that results from swapping the two bytes in i
unsigned short swap_bytes(unsigned short i)
{
	return (i << 8) | ((i & ~255) >> 8);
}


/// Tests swap_byte function
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s n\n", argv[0]);
		return EXIT_SUCCESS;
	}

	unsigned short i = atoi(argv[1]);
	printf("%.4hx -> %.4hx\n", i, swap_bytes(i));

	return EXIT_SUCCESS;
}
