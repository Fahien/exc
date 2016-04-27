#include <stdio.h>
#include <stdlib.h>

/*
 * Program that reads two fractions separated by a plus sign
 */
int main (int argc, char** argv)
{
    // Check command line input
    if (argc != 2) {
        fprintf(stderr, "Usage: ./frac-op num/num<OP>num/num\n");
        return EXIT_FAILURE;
    }

    int a, b, c, d;
    char op;
    // Read values;
    int conversions = sscanf(argv[1], "%d/%d%c%d/%d", &a, &b, &op, &c, &d);

    if (conversions != 5) {
        fprintf(stderr, "Invalid argument: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Result variables
    int numerator = 0;
    int denominator = 0;

    switch (op) {
        case '+':
            // Check denominators
            if (b == d) {
                numerator = a + c;
                denominator = b;
            } else {
                denominator = b * d;
                numerator = a * denominator / b + c * denominator / d;
            }
            break;
        case '-':
            // Check denominators
            if (b == d) {
                numerator = a - c;
                denominator = b;
            } else {
                denominator = b * d;
                numerator = a * denominator / b - c * denominator / d;
            }
            break;
        case '*':
            numerator = a * c;
            denominator = b * d;
            break;
        case '/':
            numerator = a * d;
            denominator = b * c;
            break;
        default:
            fprintf(stderr, "Invalid operator: %c\n", op);
            return EXIT_FAILURE;
    }

    // Print result and exit
    printf("%d/%d\n", numerator, denominator);
    return EXIT_SUCCESS;
}
