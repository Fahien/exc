#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rect.h"

#define M_PI 3.14159265358979323846

#define RECTANGLE 0
#define CIRCLE 1

typedef struct shape
{
	int shape_kind; // RECTANGLE or CIRCLE
	Point center;
	union {
		struct {
			int width;
			int height;
		} rectangle;
		struct {
			int radius;
		} circle;
	} u;
} Shape;


/// Compute the area of a shape
double area_shape(Shape s)
{
	switch(s.shape_kind) {
	  case RECTANGLE:
		return s.u.rectangle.width * s.u.rectangle.height;
	  case CIRCLE:
		return s.u.circle.radius * s.u.circle.radius * M_PI;
	  default:
		fprintf(stderr, "Invalid shape kind\n");
		return -1;
	}
}


/// Move a shape by x units in the x direction and y units in the y direction,
// returning the modified version of the shape
Shape move_shape(Shape s, int x, int y)
{
	s.center.x += x;
	s.center.y += y;
	return s;
}


/// Scale a shape by a factor of c, returning the modified version of the shape
Shape scale_shape(Shape s, double c)
{
	switch (s.shape_kind) {
	  case RECTANGLE:
		s.u.rectangle.width *= c;
		s.u.rectangle.height *= c;
		return s;
	  case CIRCLE:
		s.u.circle.radius *= c;
		return s;
	  default:
		fprintf(stderr, "Invalid shape kind\n");
		return s;
	}
}
