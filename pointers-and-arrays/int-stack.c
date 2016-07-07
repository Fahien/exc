#include "int-stack.h"

/* External variables */
int contents[STACK_SIZE];
int top = 0;

/*
 * Handle stack overflow error
 */
void stack_overflow()
{
    fprintf(stderr, "Stack overflow\n");
    exit(EXIT_FAILURE);
}

/*
 * Handle stack underflow error
 */
void stack_underflow()
{
    fprintf(stderr, "Stack underflow\n");
    exit(EXIT_FAILURE);
}

/*
 * Clear the stack
 */
void clear()
{
    top = 0;
}

/*
 * Test whether the stack is empty
 */
bool is_empty()
{
    return top == 0;
}

/*
 * Test whether the stack is full
 */
bool is_full()
{
    return top == STACK_SIZE;
}

/*
 * Put an integer on top of the stack
 */
void push(int i)
{
    if (is_full()) {
        stack_overflow();
    }
    else {
        contents[top++] = i;
    }
}

/*
 * Remove an integer at top of the stack and return it
 */
int pop()
{
    if (is_empty()) {
        stack_underflow();
        return 0;
    }
    else {
        return contents[--top];
    }
}
