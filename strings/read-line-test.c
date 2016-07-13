#include "read-line.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 64

/// @brief Test program for read_line function
int main()
{
    char line[MAXLINE + 1];
    read_line(line, MAXLINE);
    printf("%s\n", line);
    return EXIT_SUCCESS;
}
