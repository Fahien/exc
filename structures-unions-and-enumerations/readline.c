#include <ctype.h>
#include <stdio.h>
#include "readline.h"

/// Skips leading white-space characters, then reads the remainder of the input line and stores it in str.
// Truncates the line if its length exceeds n. Returns the number of characters stored.
int read_line(char str[], int n)
{
	int ch, i = 0;

	while (isspace(ch = getchar()));
	
	while (ch != '\n' && ch != EOF) {
		if (i < n) {
			str[i++] = ch;
		}
		ch = getchar();
	}

	str[i] = 0;
	return i;
}
