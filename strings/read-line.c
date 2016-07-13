#include "read-line.h"
#include <stdio.h>
#include <ctype.h>

int read_line(char *str, size_t n)
{
    int ch = 0;
    size_t i = 0;

    while ((ch = getchar()) != '\n') {
        if (isspace(ch)) {
            // Skip initial white spaces
            if (i == 0) { continue; }
            // Stop reading otherwise
            else { break; }
        }

        // Read the char
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = 0;
    return i;
}
