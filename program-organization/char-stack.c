#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 64

/* External variables */
char contents[STACK_SIZE];
int top = 0;

void stack_overflow();
void stack_underflow();

void clear();
bool is_empty();
bool is_full();
void push(char i);
char pop();

int main()
{
    printf("Enter parentheses and/or braces: ");

    bool nested_properly = true;
    
    char c;
    while ((c = getchar()) != '\n' && nested_properly) {
        // Push each left
        if (c == '(' || c == '{') {
            push(c);
        }

        if (c == ')') {
            nested_properly = pop() == '(';
        }

        if (c == '}') {
            nested_properly = pop() == '{';
        }
    }

    if (is_empty() && nested_properly) {
        printf("Parenthesis/braces are nested properly\n");
    }
    else {
        printf("Parenthesis/braces are not nested properly\n");
    }

    return EXIT_SUCCESS;
}

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
 * Put a char on top of the stack
 */
void push(char c)
{
    if (is_full()) {
        stack_overflow();
    }
    else {
        contents[top++] = c;
    }
}

/*
 * Remove an char at top of the stack and return it
 */
char pop()
{
    if (is_empty()) {
        stack_underflow();
        return 0;
    }
    else {
        return contents[--top];
    }
}
