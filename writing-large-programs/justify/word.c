#include <stdio.h>
#include "word.h"


int read_char()
{
	int ch = getchar();
	if (ch == '\n' || ch == '\t') { return ' '; }
	else { return ch; }
}


size_t read_word(char *word, size_t len)
{
	int ch;
	size_t pos = 0;

	while ((ch = read_char()) == ' ') { ; }

	while (ch != ' ' && ch != EOF) {
		if (pos < len) { word[pos++] = ch; }
		ch = read_char();
	}
	word[pos] = 0;
	return pos;
}
