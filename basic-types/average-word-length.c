#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Program that calculates the average word length for a sentence
 */
int main (void)
{
    // Read the first char from the standard input
    char c = getchar();

    if (c == '\r' || c == '\n' || c == EOF) {
        fprintf(stderr, "No words to count\n");
        return EXIT_FAILURE;
    }

    // Number of words
    int words_count = 1;

    // Average word length
    float avg = 0.0f;

    while (true) {
        // If the next character is not a space
        if (c != ' ') {
            avg++;
        } else {
            // End of a word
            words_count++;
        }
        c = getchar();
        if (c == '\n' || c == EOF) break;
    }

    printf("chars: %.0f, words: %d, avg: %.1f\n", avg, words_count, avg / words_count);
    return EXIT_SUCCESS;
}
