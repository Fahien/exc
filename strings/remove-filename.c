#include "remove-filename.h"
#include <stdbool.h>

void remove_filename(char *url)
{
    int slashes = 0;
    while (*url++) {
        if (*url == '/') {
            if (++slashes == 3) { *url = 0; }
        }
    }
}
