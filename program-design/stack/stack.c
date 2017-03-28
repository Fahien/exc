#include "stack.h"

struct stack
{
	Item *contents;
	int top;
	int capacity;
};


struct stack *create(int capacity)
{
	struct stack *s = malloc(sizeof(struct stack));
	if (s == NULL)
		return NULL;

	s->contents = malloc(capacity * sizeof(Item));
	if (s->contents == NULL)
	{
		free(s);
		return NULL;
	}

	s->top = 0;
	s->capacity = capacity;
	return s;
}


void destroy(struct stack *s)
{
	free(s->contents);
	free(s);
}


void clear(struct stack *s)
{
	s->top = 0;
}


bool is_empty(struct stack *s)
{
	return s->top == 0;
}


bool is_full(struct stack *s)
{
	return s->top == s->capacity;
}


size_t size(struct stack *s)
{
	return s->top;
}


bool push(struct stack *s, Item i)
{
	if (is_full(s))
		return false;
	s->contents[(s->top)++] = i;
	return true;
}


Item *pop(struct stack *s)
{
	if (is_empty(s))
		return NULL;

	return &(s->contents[--(s->top)]);
}
