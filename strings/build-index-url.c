#include "build-index-url.h"
#include <ctype.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url)
{
    strcpy(index_url, "http://www.");
    strcat(index_url, domain);
    strcat(index_url, "/");
}
