#include <stdio.h>
#include <stdlib.h>

typedef struct complex
{
	double real;
	double imaginary;
} Complex;

Complex make_complex(double real, double imaginary)
{
	return (Complex) {real, imaginary};
}

Complex add_complex(Complex a, Complex b)
{
	return (Complex) {a.real + b.real, a.imaginary + b.imaginary};
}

int main(void)
{
	Complex c1 = make_complex(0.0, 1.0);
	Complex c2 = make_complex(1.0, 0.0);
	Complex c3;

	printf("c1 = {%f, %f}\n", c1.real, c1.imaginary);
	printf("c2 = {%f, %f}\n", c2.real, c2.imaginary);
	printf("c3 = {%f, %f}\n", c3.real, c3.imaginary);

	c1 = c2; // Copy the members of c2 into c1
	c3 = add_complex(c1, c2);

	printf("After some operations\n");
	printf("c1 = {%f, %f}\n", c1.real, c1.imaginary);
	printf("c2 = {%f, %f}\n", c2.real, c2.imaginary);
	printf("c3 = {%f, %f}\n", c3.real, c3.imaginary);

	return EXIT_SUCCESS;
}
