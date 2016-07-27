#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;


void clear_line()
{
	line[0] = 0;
	line_len = 0;
	num_words = 0;
}


void add_word(const char *word)
{
	if (num_words > 0) {
		line[line_len] = ' ';
		line[line_len + 1] = 0;
		++line_len;
	}

	strcat(line, word);
	line_len += strlen(word);
	++num_words;
}


int space_remaining()
{
	return MAX_LINE_LEN - line_len;
}


void write_line()
{
	int extra_spaces = space_remaining();
	int spaces_to_insert;
	int i;
	int j;

	for (i = 0; i < line_len; ++i) {
		if (line[i] != ' ') { putchar(line[i]); }
		else {
			spaces_to_insert = extra_spaces / (num_words - 1);
			for (j = 1; j <= spaces_to_insert + 1; ++j) { putchar(' '); }
			extra_spaces -= spaces_to_insert;
			--num_words;
		}
	}
	putchar('\n');
}


void flush_line()
{
	if (line_len > 0) { puts(line); }
}
