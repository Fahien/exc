#include "censor.h"
#include <ctype.h>
#include <string.h>

char *censor(char *str, char *token)
{
    char *p = str;
    size_t tokenl = strlen(token);
    while (*p) {
        // If an occurrence is found
        if (strncmp(p, token, tokenl) == 0) {
            for (size_t i = 0; i < tokenl; ++i) {
                *(p+i) = 'x';
            }
        }
        ++p;
    }
    return str;
}
