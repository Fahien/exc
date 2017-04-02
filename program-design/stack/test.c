#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void)
{
	struct stack *s = create();
	push(s, 1);
	push(s, 2);

	printf("The stack size is %lu\n", size(s));

	Item n = pop(s);
	printf("Popped from the stack: %d\n", n);
	n = pop(s);
	printf("Popped from the stack: %d\n", n);
	n = pop(s);

	if (is_empty(s))
		printf("The stack is empty\n");

	for (int i = 0; i < 16; ++i)
		push(s, i);
	while (!is_empty(s))
		printf("Popped from the stack: %d\n", pop(s));

	destroy(s);

	return EXIT_SUCCESS;
}
