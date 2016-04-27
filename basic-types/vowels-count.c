#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * Program that counts the number of vowels (a, e, i, o and u)
 */
int main (void)
{
    char c;
    int vowels = 0;

    // Read next char from standard input
    while ((c = getchar()) != EOF) {
        c = toupper(c);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            ++vowels;
        }
    }

    // Print out the number of vowels and exit
    printf("%d\n", vowels);
    return EXIT_SUCCESS;
}
