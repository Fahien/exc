#include <stdlib.h>
#include <stdio.h>


/// Wraps malloc and terminate the program if malloc returns a null pointer
void *checked_malloc(size_t n)
{
	void *memory = malloc(n);
	if (memory == NULL) {
		fprintf(stderr, "Could not allocate memory of size %lu\n", n);
		exit(EXIT_FAILURE);
	}
	return memory;
}
