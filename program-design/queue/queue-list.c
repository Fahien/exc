#include "queue.h"

struct node
{
	Item data;
	struct node *next;
};

struct queue
{
	struct node *head;
	struct node *tail;
	size_t size;
	bool error;
};


struct queue *create()
{
	struct queue *q = malloc(sizeof(struct queue));
	if (q == NULL)
		return NULL;

	q->tail = NULL;
	q->head = NULL;
	q->size = 0;
	return q;
}


void destroy(struct queue *q)
{
	clear(q);
	free(q);
}


void clear(struct queue *q)
{
	while (!is_empty(q))
		dequeue(q);
}


bool is_empty(struct queue *q)
{
	return q->size == 0;
}


bool is_full(struct queue *q)
{
	return false;
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
	struct node *new_tail = malloc(sizeof(struct node));
	if (new_tail == NULL)
		return false;

	new_tail->data = i;
	if (is_empty(q)) // base case
		q->head = q->tail = new_tail;
	else
	{
		q->tail->next = new_tail;
		q->tail = new_tail;
	}
	++q->size;
	return true;
}


Item dequeue(struct queue *q)
{
	Item data;
	if (is_empty(q)) // return uninizialized data
		q->error = true;
	else
	{
		struct node *head = q->head;
		data = head->data;
		if (q->head == q->tail) // one element
			q->head = q->tail = NULL;
		else
			q->head = head->next;
		free(head);
		--q->size;
	}
	return data;
}


Item head(struct queue *q)
{
	Item data;
	if (is_empty(q)) // return uninitialized data
		q->error = true;
	else
		data = q->head->data;
	return data;
}


Item tail(struct queue *q)
{
	Item data;
	if (is_empty(q)) // return uninizialized data
		q->error = true;
	else
		data = q->tail->data;
	return data;
}
