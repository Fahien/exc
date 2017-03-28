#include "queue.h"

struct queue
{
	Item *contents;
	size_t tail;
	size_t head;
	size_t capacity;
	size_t size;
};


struct queue *create(size_t capacity)
{
	struct queue *q = malloc(sizeof(struct queue));
	if (q == NULL)
		return NULL;

	q->contents = malloc(capacity * sizeof(Item));
	if (q->contents == NULL)
	{
		free(q);
		return NULL;
	}

	q->tail = 0;
	q->head = 0;
	q->capacity = capacity;
	q->size = 0;
	return q;
}

void destroy(struct queue *q)
{
	free(q->contents);
	free(q);
}

void clear(struct queue *q)
{
	q->tail = q->head;
	q->size = 0;
}

bool is_empty(struct queue *q)
{
	return q->size == 0;
}

bool is_full(struct queue *q)
{
	return q->size == q->capacity;
}

size_t size(struct queue *q)
{
	return q->size;
}

bool enqueue(struct queue *q, Item i)
{
	if (is_full(q))
		return false;

	q->contents[q->tail++] = i;
	if (q->tail == q->capacity)
		q->tail = 0;
	++q->size;
	return true;
}

Item *dequeue(struct queue *q)
{
	if (is_empty(q))
		return NULL;

	Item *i = &q->contents[q->head++];
	if (q->head == q->capacity)
		q->head = 0;
	--q->size;
	return i;
}

Item *head(struct queue *q)
{
	if (is_empty(q))
		return NULL;

	return &q->contents[q->head];
}

Item *tail(struct queue *q)
{
	if (is_empty(q))
		return NULL;

	if (q->tail == 0)
		return &q->contents[q->capacity - 1];
	else
		return &q->contents[q->tail - 1];
}
