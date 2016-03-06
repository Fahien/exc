#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	printf("%%6d displays an integer in decimal form using a minimum of 6 characters\n");
	printf("printf(\"%%6d, %%4d\", 86, 1040);\n");
	printf("%6d, %4d\n", 86, 1040);

	printf("%%12.5e displays a floating-point number in exponential form, using 12 characters overall, with 5 digits after the decimal point\n");
	printf("printf(\"%%12.5e\", 30.253);\n");
	printf("%12.5e\n", 30.253);

	printf("%%.4f displays a floating-point number with four digits after the decimal point\n");
	printf("printf(\"%%.4f\", 83.162);\n");
	printf("%.4f\n", 83.162);

	printf("%%-6.2g displays a floating-point number using 6 characters overall with left justification and a maximum of 2 significant digits\n");
	printf("printf(\"%%-6.2g\", .0000009979);\n");
	printf("%-6.2g\n", .0000009979);

	return EXIT_SUCCESS;
}
