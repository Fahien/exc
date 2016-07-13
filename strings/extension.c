#include "extension.h"
#include "capitalize.h"
#include <ctype.h>
#include <string.h>

char *get_extension(const char *file_name, char *extension)
{
    // Get the name length
    size_t namel = strlen(file_name);

    // Find the point
    const char *p = file_name;
    while (*p != '.' && *p != 0) {
        ++p;
    }
    // Skip point
    ++p;

    return strncat(extension, p, namel - (p - file_name));
}


bool test_extension(const char *file_name, const char *extension)
{
    // Capitalize the test extension
    char test_ext[EXT_MAX] = {0};
    strcpy(test_ext, extension);
    capitalize(test_ext);
    // Get the extension
    char ext[EXT_MAX] = {0};
    get_extension(file_name, ext);
    // Compare and return result
    return strcmp(capitalize(ext), test_ext) == 0;
}
