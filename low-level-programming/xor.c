#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'


int main()
{
	int orig_char, new_char;

	while ((orig_char = getchar()) != EOF)
	{
		new_char = orig_char ^ KEY;
		if (isprint(orig_char) && isprint(new_char))
			putchar(new_char);
		else
			putchar(orig_char);
	}

	return EXIT_SUCCESS;
}
