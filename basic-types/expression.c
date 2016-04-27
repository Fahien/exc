#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Program that evaluates an expression
 */
int main (void)
{
    // Logic variables
    float number;
    char operator;
    float result = 0.0f;

    int conversion;

    // Read a floating number
    conversion = scanf("%f", &result);

    // Read from standard input
    while (conversion) {
        // Read the operator
        conversion = scanf("%c", &operator);
        if (!conversion) break;
        
        // Read the next floating number
        conversion = scanf("%f", &number);
        if (!conversion) break;

        // Apply operator
        switch (operator) {
            case '+':
                result += number;
                break;
            case '-':
                result -= number;
                break;
            case '*':
                result *= number;
                break;
            case '/':
                result /= number;
                break;
            default: // Error case
                goto END;
        }
    }

END:
    // Print out result and exit
    printf("%.2f\n", result);
    return EXIT_SUCCESS;
}
