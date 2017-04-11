#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


/// Prints the sizes and offsets of the a, b, and c members of the s structure.
/// Have the program print the size of the entire structure as well.
/// From this information, determine whether or not the structure has any holes.
/// If it does, describe the location and size of each.
int main()
{
	struct s {
		char a;
		int b[2];
		float c;
	};

	printf("Size of struct s = %lu\n", sizeof(struct s));

	size_t a_offset = offsetof(struct s, a);
	size_t b_offset = offsetof(struct s, b);
	size_t c_offset = offsetof(struct s, c);

	printf("char a\n\toffset: %lu\n\tsize: %lu\n\thole: %lu\n",
			a_offset,
			sizeof(char),
			b_offset - a_offset - sizeof(char));
	printf("int b[2]\n\toffset: %lu\n\tsize: %lu\n\thole: %lu\n",
			b_offset,
			sizeof(int[2]),
			c_offset - b_offset - sizeof(int[2]));
	printf("float c\n\toffset: %lu\n\tsize: %lu\n\thole: %lu\n",
			c_offset,
			sizeof(float),
			sizeof(struct s) - c_offset - sizeof(float));

	return EXIT_SUCCESS;
}
