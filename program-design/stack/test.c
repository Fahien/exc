#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void)
{
	struct stack *s1 = create(8);
	push(s1, 1);
	push(s1, 2);

	Item *n = pop(s1);
	printf("Popped from s1: %d\n", *n);
	n = pop(s1);
	printf("Popped from s1: %d\n", *n);
	n = pop(s1);
	if (n == NULL)
		printf("s1 is empty\n");
	destroy(s1);

	return EXIT_SUCCESS;
}
