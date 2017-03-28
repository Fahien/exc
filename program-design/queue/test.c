#include <stdio.h>
#include "queue.h"


int main()
{
	struct queue *q = create(4);

	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);

	if (enqueue(q, 5) == false)
		printf("Cannot enqueue fifth element\n");
	if (is_full(q))
		printf("Queue is full\n");
	printf("Queue size is %lu\n", size(q));

	while(!is_empty(q))
		printf("Dequeued element is %d\n", *dequeue(q));

	destroy(q);
	return EXIT_SUCCESS;
}
