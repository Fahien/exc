#include <stdbool.h>

/// @brief This function returns true if key matches some elements of a, and false if it doesn't.
/// @param a is the array to be searched
/// @param size is the number of elements in the array
/// @param key is the search key
bool search(const int *a, const unsigned int size, const int key)
{
    const int *limit = a + size;
    while (a < limit) {
        if (*a++ == key) return true;
    }
    return false;
}
