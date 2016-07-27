#ifndef WORD_H
#define WORD_H

#include "string.h"

/// Reads the next word from the input and stores it in word.
/// Makes word empty if no word could be read because of end-of-line.
/// Truncates the word if its length exceeds len.
/// Returns the numbers of characters stored.
size_t read_word(char *word, size_t len);

#endif // WORD_H
