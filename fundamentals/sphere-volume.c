#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

/*
 * Program that computes the volume of a sphere with
 * an X-meter radius, using the formula v = 4/3 * PI * r^3
 */
int main (void)
{
	float radius;
	printf("Radius of the sphere? ");
	int scanf_result = scanf("%f", &radius);
	if (scanf_result == EOF) {
		perror("scanf");
		return EXIT_FAILURE;
	}

	float volume = 4.0f / 3.0f * PI * radius * radius * radius;
	
	printf("The volume of a sphere with a %.1f-meter radius is %.1f m³\n", radius, volume);
	
	return EXIT_SUCCESS;
}
