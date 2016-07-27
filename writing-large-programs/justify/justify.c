#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main()
{
	char word[MAX_WORD_LEN + 2];
	int word_len;

	clear_line();

	while (true) {
		word_len = read_word(word, MAX_WORD_LEN + 1); // read word

		if (word_len == 0) { // cant read word
			flush_line(); // write contents of line buffer without justification
			return EXIT_FAILURE; // terminate program
		}

		if (word_len > MAX_WORD_LEN) {
			word[MAX_WORD_LEN] = '*'; // ignore all characters after the first 20
		}

		if (word_len + 1 > space_remaining()) { // word doesn't fit in line buffer
			write_line(); // write contents of line buffer with justification
			clear_line(); // clear line buffer
		}

		add_word(word); // add word to line buffer
	}

	return EXIT_SUCCESS;
}
