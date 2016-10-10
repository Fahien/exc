#include "shape.h"


int main(void)
{
	Shape rect;
	rect.shape_kind = RECTANGLE;
	rect.center = (Point) {0, 0};
	rect.u.rectangle.width = 3;
	rect.u.rectangle.height = 4;

	Shape circle;
	circle.shape_kind = CIRCLE;
	circle.center = (Point) {0, 0};
	circle.u.circle.radius = 5;

	printf("Area of rect = %f\n", area_shape(rect));
	printf("Area of circle = %f\n", area_shape(circle));

	rect = move_shape(rect, 4, 1);
	printf("Center of rect = (%d, %d)\n", rect.center.x, rect.center.y);

	circle = scale_shape(circle, 2);
	printf("Area of circle = %f\n", area_shape(circle));

	return EXIT_SUCCESS;
}
