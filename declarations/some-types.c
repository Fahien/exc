#include <stdio.h>
#include <stdlib.h>


typedef void (*NoArgNoRet)(void);

void sayHello()
{
	printf("Hello\n");
}

struct t
{
	int x;
};

NoArgNoRet f(struct t *q, long n)
{
	printf("Struct with x = %d, and n = %ld\n", q->x, n);
	return sayHello;
}

void insert()
{
	printf("Insert\n");
}

void search()
{
	printf("Search\n");
}

void update()
{
	printf("Update\n");
}

void print()
{
	printf("Print\n");
}

struct t testB(int a, int b)
{
	printf("TestB(%d, %d)\n", a, b);
	return (struct t) {a};
}

int a5[5] = {0, 1, 2, 3, 4};

typedef int FiveInts[5];

FiveInts *funcBlowing(int a)
{
	printf("FuncBlowing with a = %d\n", a);
	return &a5;
}


int main(void)
{
	// p is a pointer to a function with a character pointer
	// argument that returns a character pointer
	char *(*p(char *));

	// f is a function with two arguments: q, a pointer to a structure
	// with tag t, and n, a long integer. f returns a pointer to a
	// function that has no arguments and returns nothing
	struct t oneContainer = {1};
	(f(&oneContainer, 2)());

	// a is an array of four pointers to functions that have no arguments
	// and return nothing. The elements of a initially point to
	// functions named insert, search, update, and print.
	void (*a[4])(void) = {insert, search, update, print};
	for (int i = 0; i < 4; ++i)
		a[i]();

	// b is an array of 10 pointers to functions with two
	// int arguments that return structures with tag t
	struct t (*b[10])(int, int);
	b[0] = testB;
	printf("Returning struct contains %d\n", b[0](2, 3).x);

	/// funcBlowing is a function (int) returning pointer to array of five int
	printf("4th element of returned array = %d\n", (*funcBlowing(4))[4]);

	return EXIT_SUCCESS;
}
