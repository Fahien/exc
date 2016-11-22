#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/// When passed a function pointer f, prints a table showing the values of f
void tabulate(double (*f)(double), double first, double last, double incr);

/// This program prints tables showing the values of the cos, sin and tan functions
int main()
{
	double final;
	double increment;
	double initial;

	printf("Enter initial value: ");
	scanf("%lf", &initial);
	printf("Enter final value: ");
	scanf("%lf", &final);
	printf("Enter increment value: ");
	scanf("%lf", &increment);

	printf( "\n      x       cos(x)"
	        "\n   -------    -------\n");
	tabulate(cos, initial, final, increment);

	printf( "\n      x       sin(x)"
	        "\n   -------    -------\n");
	tabulate(sin, initial, final, increment);

	printf( "\n      x       tan(x)"
	        "\n   -------    -------\n");
	tabulate(tan, initial, final, increment);

	return EXIT_SUCCESS;
}


void tabulate(double (*f)(double), double first, double last, double incr)
{
	double x;
	int num_intervals = ceil((last - first) / incr);

	for (int i = 0; i <= num_intervals; ++i) {
		x = first + i * incr;
		printf("%10.5f %10.5f\n", x, (*f)(x));
	}
}

