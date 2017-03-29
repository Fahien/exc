#include "queue.h"

#define CAPACITY 64

struct queue
{
	Item *contents;
	size_t tail;
	size_t head;
	size_t capacity;
	size_t size;
	bool error;
};


struct queue *create()
{
	struct queue *q = malloc(sizeof(struct queue));
	if (q == NULL)
		return NULL;

	q->contents = malloc(CAPACITY * sizeof(Item));
	if (q->contents == NULL)
	{
		free(q);
		return NULL;
	}

	q->tail = 0;
	q->head = 0;
	q->capacity = CAPACITY;
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


bool is_error(struct queue *q)
{
	return q->error;
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


Item dequeue(struct queue *q)
{
	Item data;
	if (is_empty(q))
		q->error = true;
	else
	{
		data = q->contents[q->head++];
		if (q->head == q->capacity)
			q->head = 0;
		--q->size;
	}
	return data;
}


Item head(struct queue *q)
{
	Item data;
	if (is_empty(q))
		q->error = true;
	else
		data = q->contents[q->head];
	return data;
}


Item tail(struct queue *q)
{
	Item data;
	if (is_empty(q))
		q->error = true;
	else
	{
		if (q->tail == 0)
			data = q->contents[q->capacity - 1];
		else
			data = q->contents[q->tail - 1];
	}
	return data;
}
