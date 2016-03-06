#include <stdio.h>
#include <stdlib.h>

/*
 * Program that breaks down an International Standard Book Number (ISBN)
 */
int main (int argc, char** argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./isbn-format <ISBN>\n");
		return EXIT_FAILURE;
	}

	int gs1, group, publisher, item, check;
	sscanf(argv[1], "%d-%d-%d-%d-%d", &gs1, &group, &publisher, &item, &check);

	printf("GS1 prefix: %d\n", gs1);
	printf("Group identifier: %d\n", group);
	printf("Publisher code: %d\n", publisher);
	printf("Item number: %d\n", item);
	printf("Check digit: %d\n", check);

	return EXIT_SUCCESS;
}
