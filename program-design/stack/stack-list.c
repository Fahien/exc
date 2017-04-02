#include "stack.h"

struct node
{
	Item data;
	struct node *next;
};

struct stack
{
	struct node *top;
	size_t size;
	bool error;
};


struct stack *create()
{
	struct stack *s = malloc(sizeof(struct stack));
	if (s == NULL)
		return NULL;

	s->top = NULL;
	s->size = 0;
	return s;
}


void destroy(struct stack *s)
{
	clear(s);
	free(s);
}


void clear(struct stack *s)
{
	while (!is_empty(s))
		pop(s);
}


bool is_empty(struct stack *s)
{
	return s->top == NULL;
}


bool is_full(struct stack *s)
{
	return false;
}


size_t size(struct stack *s)
{
	return s->size;
}


bool is_error(struct stack *s)
{
	return s->error;
}


bool push(struct stack *s, Item i)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		return false;

	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
	++s->size;
	return true;
}


Item pop(struct stack *s)
{
	Item data;
	if (is_empty(s))
		s->error = true;
	else
	{
		struct node *top = s->top;
		s->top = top->next;
		data = top->data;
		free(top);
		--s->size;
	}
	return data;
}


Item peek(struct stack *s)
{
	Item data;
	if (is_empty(s))
		s->error = true;
	else
		data = s->top->data;
	return data;
}
