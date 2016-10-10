#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct fraction
{
	int numerator;
	int denominator;
} Fraction;


int gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a;
		a = b % a;
		b = c;
	}
	return b;
}


Fraction add_fraction(Fraction a, Fraction b)
{
	Fraction c;
	c.denominator = a.denominator * b.denominator;
	c.numerator = a.numerator * c.denominator / a.denominator + b.numerator * c.denominator / b.denominator;
	int g = gcd(c.numerator, c.denominator);
	c.numerator /= g;
	c.denominator /= g;
	return c;
}


Fraction sub_fraction(Fraction a, Fraction b)
{
	Fraction c;
	c.denominator = a.denominator * b.denominator;
	c.numerator = a.numerator * c.denominator / a.denominator - b.numerator * c.denominator / b.denominator;
	int g = gcd(c.numerator, c.denominator);
	c.numerator /= g;
	c.denominator /= g;
	return c;
}


Fraction mul_fraction(Fraction a, Fraction b)
{
	Fraction c;
	c.denominator = a.denominator * b.denominator;
	c.numerator = a.numerator * b.numerator;
	int g = gcd(c.numerator, c.denominator);
	c.numerator /= g;
	c.denominator /= g;
	return c;
}


Fraction div_fraction(Fraction a, Fraction b)
{
	Fraction c;
	c.denominator = a.denominator * b.numerator;
	c.numerator = a.numerator * b.denominator;
	int g = gcd(c.numerator, c.denominator);
	c.numerator /= g;
	c.denominator /= g;
	return c;
}


int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage: ./fraction numerator/denominator\n");
		return EXIT_FAILURE;
	}

	Fraction f1;
	sscanf(argv[1], "%d/%d", &f1.numerator, &f1.denominator);

	int g = gcd(f1.numerator, f1.denominator);
	printf("Lowest term = %d/%d\n", f1.numerator / g, f1.denominator / g);

	Fraction f2 = {1, 2};
	Fraction f3 = add_fraction(f1, f2);
	printf("%d/%d + %d/%d = %d/%d\n",
		f1.numerator, f1.denominator,
		f2.numerator, f2.denominator,
		f3.numerator, f3.denominator);
	f3 = sub_fraction(f1, f2);
	printf("%d/%d - %d/%d = %d/%d\n",
		f1.numerator, f1.denominator,
		f2.numerator, f2.denominator,
		f3.numerator, f3.denominator);
	f3 = mul_fraction(f1, f2);
	printf("%d/%d * %d/%d = %d/%d\n",
		f1.numerator, f1.denominator,
		f2.numerator, f2.denominator,
		f3.numerator, f3.denominator);
	f3 = div_fraction(f1, f2);
	printf("%d/%d / %d/%d = %d/%d\n",
		f1.numerator, f1.denominator,
		f2.numerator, f2.denominator,
		f3.numerator, f3.denominator);

	return EXIT_SUCCESS;
}
