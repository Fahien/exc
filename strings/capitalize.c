#include "capitalize.h"
#include <ctype.h>

char *capitalize(char *str)
{
    char *p = str;
    while (*p) {
        *p = toupper(*p);
        p++;
    }
    return str;
}
