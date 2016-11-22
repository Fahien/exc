/// sum(g, i, j) returns g(i) + ... + g(j)
int sum(int (*f)(int), int i, int j)
{
	if (i > j) { // Swap if i is greater than j
		int temp = i;
		i = j;
		j = temp;
	}
	int sum = 0;
	for (; i <= j; ++i) { sum += (*f)(i); }
	return sum;
}

