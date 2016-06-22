#include "int-stack.h"

int main()
{
    push(1);
    printf("Should print 1: %d\n", pop());
    printf("Should exit with stack underflow error\n");
    pop();
    return EXIT_SUCCESS;
}

