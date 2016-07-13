#include <stdbool.h>

#define EXT_MAX 8

/// @brief This function stores the extension on the file name in the string pointed to by extension
char *get_extension(const char *file_name, char *extension);

/// @brief This function returns true if the file's extension matches the string pointed to by extension
bool test_extension(const char *file_name, const char *extension);
