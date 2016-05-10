#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 2048

/*
 * Program that reads a message and translates it into B1FF-speak
 */
int main (void)
{
    char buffer[MAXLINE];
    unsigned buf_len;

    while (true) {
        // Fill the buffer with zeros
        memset(buffer, 0, MAXLINE);

        // Read a line
        fgets(buffer, MAXLINE, stdin);
        buf_len = strlen(buffer) - 1;
        buffer[buf_len] = 0;

        // Check for error or EOF
        if (buf_len <= 0) break;
        
        for (unsigned i = 0; i < buf_len; i++) {
            // Capitalize
            buffer[i] = toupper(buffer[i]);

            // Filter
            switch (buffer[i]) {
                case 'A': buffer[i] = '4'; break;
                case 'B': buffer[i] = '8'; break;
                case 'E': buffer[i] = '3'; break;
                case 'I': buffer[i] = '1'; break;
                case 'O': buffer[i] = '0'; break;
                case 'S': buffer[i] = '5'; break;
                default: break;
            }
        }

        // Print out the filtered message
        printf("%s\n", buffer);
    }

    return EXIT_SUCCESS;
}
