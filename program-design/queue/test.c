#include <stdio.h>
#include "queue.h"


int main()
{
	struct queue *q = create();

	for (int i = 0; i < 64; ++i)
		enqueue(q, i);

	if (enqueue(q, 64) == false)
		printf("Cannot enqueue 64th element\n");
	if (is_full(q))
		printf("Queue is full\n");
	printf("Queue size is %lu\n", size(q));

	while(!is_empty(q))
		printf("Dequeued element is %d\n", dequeue(q));

	destroy(q);
	return EXIT_SUCCESS;
}
