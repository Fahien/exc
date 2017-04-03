#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;


int main()
{
	unsigned int address;

	printf("Address of main function: %x\n", (unsigned int) main);
	printf("Address of address variable: %x\n", (unsigned int) &address);

	printf("\nEnter a (hex) address: ");
	scanf("%x", &address);
	printf("Enter number of bytes to view: ");
	int n;
	scanf("%d", &n);

	printf("\n Address              Bytes              Characters\n");
	printf(  " -------  -----------------------------  ----------\n");

	BYTE *ptr = (BYTE *) address;
	for(; n > 0; n -= 10)
	{
		printf("%8X  ", (unsigned int) ptr);
		int i;
		for (i = 0; i < 10 && i < n; ++i)
			printf("%.2X ", *(ptr + i));
		for (; i < 10; ++i)
			printf("   ");
		printf(" ");
		for (i = 0; i < 10 && i < n; ++i)
		{
			BYTE ch = *(ptr + i);
			if (!isprint(ch))
				ch = '.';
			printf("%c", ch);
		}
		printf("\n");
		ptr += 10;
	}

	return EXIT_SUCCESS;
}
