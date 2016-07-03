///
// In the Reverse Polish Notation, operators are placed 
// after their operands instead of between their operands.
// RPN expressions can easily be evaluated using a stack
//

#include "int-stack.h"

int operate(int a, int b, char operator)
{
    switch(operator) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

int main ()
{
    printf("Enter an RPN expression: ");

    char c;
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            push(operate(pop(), pop(), c));
        }
        else if (c == '=') {
            printf("Value of expression: %d\n", pop());
            printf("Enter an RPN expression: ");
        }
        else if (c >= 'a' && c <= 'z') {
            break;
        }
        else continue;
    }

    return EXIT_SUCCESS;
}
