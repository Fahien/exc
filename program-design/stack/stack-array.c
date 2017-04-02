#include <string.h>
#include "stack.h"

#define CAPACITY 4

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


void scale(struct stack *s)
{
	// Double capacity
	size_t new_capacity = s->capacity * 2;
	// Allocate memory
	Item *new_contents = malloc(new_capacity * sizeof(Item));
	// Move contents
	memmove(new_contents, s->contents, s->capacity * sizeof(Item));
	// Update struct
	free(s->contents);
	s->contents = new_contents;
	s->capacity = new_capacity;
}


bool push(struct stack *s, Item i)
{
	if (is_full(s))
		scale(s);
	s->contents[(s->top)++] = i;
	return true;
}


Item pop(struct stack *s)
{
	Item data;
	if (is_empty(s))
		s->error = true;
	else
		data = s->contents[--(s->top)];
	return data;
}


Item peek(struct stack *s)
{
	Item data;
	if (is_empty(s))
		s->error = true;
	else
		data = s->contents[s->top - 1];
	return data;
}
