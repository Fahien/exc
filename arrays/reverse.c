#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INPUT_LIM 1024
/*
 * Program that reverses the words in a sentence
 */
int main (void)
{
    // Array to store the sentence
    char input[INPUT_LIM] = {0};

    // Loop variable
    char c;
    int i;
    for (i = 0; i < INPUT_LIM - 1; ++i) {
        // Get next char
        c = getchar();

        // Test for EOF, period, question mark or exclamation point
        if (c == '.' || c == '?' || c == '!') break;
        // Workaround
        if (c == EOF) {
            input[i-1] = 0;
            break;
        }

        // Save char
        input[i] = c;
    }

    // Reverse the sentence
    for (int j = i - 1; j > 0; --j) {
        // Print the word next to a space
        if (input[j] == ' ' && input[j+1] != ' ') {
            printf("%s ", input + j + 1);
            // Substitute the space with a '\0'
            input[j] = 0;
        }
    }
    // Print first word
    printf("%s", input);

    // Print punctuation
    if (c != EOF) {
        printf("%c\n", c);
    } else {
        printf("\n");
    }

    return EXIT_SUCCESS;
}
