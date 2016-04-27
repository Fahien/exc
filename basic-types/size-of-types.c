#include <stdio.h>
#include <stdlib.h>

/*
 * Program that prints the size of c types
 */
int main (void)
{
    printf("Type\t\tSize\n");
    printf("int\t\t%lu\n", sizeof(int));
    printf("short\t\t%lu\n", sizeof(short));
    printf("long\t\t%lu\n", sizeof(long));
    printf("float\t\t%lu\n", sizeof(float));
    printf("double\t\t%lu\n", sizeof(double));
    printf("long double\t%lu\n", sizeof(long double));
    return EXIT_SUCCESS;
}
