#include <stdlib.h>

#include "command.h"


int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s command\n", argv[0]);
		return EXIT_FAILURE;
	}

	invoke(argv[1]);
	return EXIT_SUCCESS;
}

