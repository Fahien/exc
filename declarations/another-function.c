#include <stdio.h>
#include <stdlib.h>


typedef int FuncToReturn(double);

int returnFunction(double d)
{
	return (int)d;
}

FuncToReturn *anotherFunction(float (*d)(long), char *c)
{
	d((long)*c);
	return returnFunction;
}

float paramFunction(long l)
{
	return (float)l;
}

typedef int(*MindBlowingFunction(float(*)(long), char*))(double);

int main()
{
	char aChar = 'a';
	MindBlowingFunction *f = anotherFunction;
	printf("Int returned from computation = %d\n", f(paramFunction, &aChar)(1.0));
	return EXIT_SUCCESS;
}
