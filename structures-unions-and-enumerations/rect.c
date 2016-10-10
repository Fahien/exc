#include <stdio.h>
#include "rect.h"


int main(void)
{
	Point a = {2, 9};
	Point b = {9, 2};
	Rect r = {a, b};

	printf("Area = %d\n", area_rect(r));

	Point c = center_rect(r);
	printf("Center = (%d, %d)\n", c.x, c.y);

	r = move_rect(r, 1, 3);
	c = center_rect(r);
	printf("Center = (%d, %d)\n", c.x, c.y);

	Point s = {5, 4};
	printf("Point s is %sinside the rectangle\n", rect_contains_point(r, s) ? "" : "not ");
	printf("Point c is %sinside the rectangle\n", rect_contains_point(r, c) ? "" : "not ");

	return EXIT_SUCCESS;
}
