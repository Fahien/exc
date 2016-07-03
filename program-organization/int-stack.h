#ifndef INT_STACK_H
#define INT_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 64

void stack_overflow();
void stack_underflow();

void clear();
bool is_empty();
bool is_full();
void push(int i);
int pop();

#endif // INT_STACK_H
