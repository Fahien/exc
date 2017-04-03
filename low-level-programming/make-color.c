#include <stdio.h>
#include <stdlib.h>

/// This macro takes three parameters (the red, green, and blue intensities)
/// and returns a long in which the last three bytes contain the red, green,
/// and blue intensities, with the red value as the last byte and the green
/// value as the next-to-last byte.
#define MK_COLOR(r,g,b) (((r) << 16) | ((g) << 8) | (b))

#define GET_BLUE(c) ((c) & ~(255 << 16) & ~(255 << 8))

#define GET_GREEN(c) ((c) & ~(255 << 16) & ~(255))

#define GET_RED(c) ((c) & ~(255 << 8) & ~(255))


int main()
{
	unsigned long color = MK_COLOR(255, 255, 255);
	printf("%ld\n", color);
	printf("%.6lx (%.6lx, %.6lx, %.6lx)\n",
			color,
			GET_RED(color),
			GET_GREEN(color),
			GET_BLUE(color));
	return EXIT_SUCCESS;
}
