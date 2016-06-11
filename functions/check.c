#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * This function returns 1 if both x and y fall between
 * 0 and n-1, inclusive. It returns 0 otherwise.
 */
int check(int x, int y, int n)
{
    // Check x
    bool x_check = 0 <= x && x < n;
    // Check y
    bool y_check = 0 <= y && y < n;
    
    if (x_check && y_check) return 1;
    else return 0;
}

int main()
{
    printf("First check should return 1: %d\n", check(1, 2, 3));
    printf("Second check should return 0: %d\n", check(3, 2, 1));

    return EXIT_SUCCESS;
}
