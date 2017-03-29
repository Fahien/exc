#include "stack.h"

#define CAPACITY 64

struct stack
{
	Item *contents;
	int top;
	int capacity;
	bool error;
};


struct stack *create()
{
	struct stack *s = malloc(sizeof(struct stack));
	if (s == NULL)
		return NULL;

	s->contents = malloc(CAPACITY * sizeof(Item));
	if (s->contents == NULL)
	{
		free(s);
		return NULL;
	}

	s->top = 0;
	s->capacity = CAPACITY;
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


bool is_error(struct stack *s)
{
	return s->error;
}


bool push(struct stack *s, Item i)
{
	if (is_full(s))
		return false;
	s->contents[(s->top)++] = i;
	return true;
}


Item pop(struct stack *s)
{
	Item data;
	if (is_empty(s))
	{
		s->error = true;
		return data;
	}

	return s->contents[--(s->top)];
}
