#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>


/// Type of data to be stored in the stack
typedef int Item;

/// Encapsulation using incomplete type
struct stack;


/// Dynamically allocates memory for a stack
struct stack *create();

/// Releases the stack's dynamically allocated memory
void destroy(struct stack *s);

/// Clears the stack
void clear(struct stack *s);

/// Tests whether the stack is empty
bool is_empty(struct stack *s);

/// Tests whether the stack is full
bool is_full(struct stack *s);

/// Returns the size of the stack
size_t size(struct stack *s);

/// Pushes an item on top of the stack
bool push(struct stack *s, Item i);

/// Pops an item from the top of the stack
Item pop(struct stack *s);


#endif // STACK_H
