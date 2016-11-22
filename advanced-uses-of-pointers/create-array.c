#include <stdlib.h>
#include <stdio.h>


/// Returns a pointer to a dynamically allocated int array with n members, each of
// which is initialized to initial_value. Returns NULL if the rray can't be allocated
int *create_array(int n, int initial_value)
{
	int *array = malloc(n * sizeof(int));
	if (array == NULL) {
		fprintf(stderr, "Could not allocate memory of size %d\n", n);
		return NULL;
	}
	while (--n >= 0) {
		array[n] = initial_value;
	}
	return array;
}


int main()
{
	int *array = create_array(8, 2);
	if (array == NULL) { return EXIT_FAILURE; }
	for(int i = 0; i < 8; ++i) { printf("%d ", array[i]); }
	printf("\b\n");

	free(array);
	return EXIT_SUCCESS;
}

