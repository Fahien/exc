#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct color
{
	int red;
	int green;
	int blue;
} Color;


const Color MAGENTA1 = {255, 0, 255};
const Color MAGENTA2 = {.red = 255, .green = 0, .blue = 255};
const Color MAGENTA3 = {.red = 255, .blue = 255};


Color make_color(int red, int green, int blue)
{
	red = (red < 0) ? 0 : red;
	green = (green < 0) ? 0 : green;
	blue = (blue < 0) ? 0 : blue;
	red = (red > 255) ? 255 : red;
	green = (green > 255) ? 255 : green;
	blue = (blue > 255) ? 255 : blue;

	return (Color) {red, green, blue};
}


Color darker(Color c)
{
	c.red *= 0.7;
	c.green *= 0.7;
	c.blue *= 0.7;
	return c;
}


Color brighter(Color c)
{
	// Special case 1
	if (c.red == 0 && c.green == 0 && c.blue == 0) {
		c.red = c.green = c.blue = 3;
		return c;
	}

	// Special case 2
	if (c.red < 3) { c.red = 3; }
	c.red /= 0.7;
	if (c.green < 3) { c.green = 3; }
	c.green /= 0.7;
	if (c.blue < 3) { c.blue = 3; }
	c.blue /= 0.7;

	// Special case 3
	if (c.red > 255) { c.red = 255; }
	if (c.green > 255) { c.green = 255; }
	if (c.blue > 255) { c.blue = 255; }

	return c;
}


int main(int argc, char **argv)
{
	if (argc < 4)
	{
		fprintf(stderr, "Usage: ./color red green blue\n");
		return EXIT_FAILURE;
	}

	Color c = make_color(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	printf("Color[%d, %d, %d]\n", c.red, c.green, c.blue);

	Color d = darker(c);
	printf("Darker[%d, %d, %d]\n", d.red, d.green, d.blue);
	
	Color b = brighter(c);
	printf("Brigher[%d, %d, %d]\n", b.red, b.green, b.blue);

	return EXIT_SUCCESS;
}
