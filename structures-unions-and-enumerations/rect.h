#include <stdlib.h>
#include <stdbool.h>

typedef struct point
{
	int x;
	int y;
} Point;


typedef struct rect
{
	Point upper_left;
	Point lower_right;
} Rect;


int area_rect(Rect r)
{
	int base = abs(r.upper_left.x - r.lower_right.x);
	int height = abs(r.upper_left.y - r.lower_right.y);
	return base * height;
}


Point center_rect(Rect r)
{
	return (Point) {(r.upper_left.x + r.lower_right.x) / 2, (r.upper_left.y + r.lower_right.y) / 2};
}


Rect move_rect(Rect r, int x, int y)
{
	r.upper_left.x += x;
	r.upper_left.y += y;
	r.lower_right.x += x;
	r.lower_right.y += y;
	return r;
}


bool rect_contains_point(Rect r, Point p)
{
	return (p.x >= r.upper_left.x && p.x <= r.lower_right.x) && (p.y >= r.lower_right.y && p.y <= r.upper_left.y);
}
