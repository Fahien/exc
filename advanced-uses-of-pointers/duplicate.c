#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/// Uses dynamic storage allocation to create a copy of a string
// Returns a null pointer if the memory allocation fails
char *duplicate(const char *string)
{
	size_t length = strlen(string) + 1;
	char *copy = malloc(length);
	if (copy == NULL) {
		fprintf(stderr, "Could not allocate memory of size %lu\n", length);
		return NULL;
	}
	memcpy(copy, string, length);
	return copy;
}


int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s string\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *copy = duplicate(argv[1]);
	printf("Duplicate [%s]\n", copy);

	free(copy);
	return EXIT_SUCCESS;
}

