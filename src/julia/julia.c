/*###
# Name: Tim Frenzel
# Student ID: 002267120
# Email: frenz102@mail.chapman.edu
# Course: CS510 Fall 2017
###

#######  START: CREAT JULIA SET #######
#import packages */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

int main(int argc, char **argv)
{
	if (argc != 9) {
		fprintf(stderr, "Incorrect numbers. Expecting 8 arguments\n");
		return 0;
	}

	/*determine parameter*/
		long double xmin = strtold(argv[1], NULL);
		long double xmax = strtold(argv[2], NULL);
		long double ymin = strtold(argv[3], NULL);
		long double ymax = strtold(argv[4], NULL);
		int xpoints = atoi(argv[5]);
		int ypoints = atoi(argv[6]);
		long double creal = strtold(argv[7], NULL);
		long double cimag = strtold(argv[8], NULL);

		COMPLEX c = {creal, cimag};

		long double xstep = (xmax - xmin)/(xpoints - 1);
		long double ystep = (ymax - ymin)/(ypoints - 1);
		long double x = xmin;
		long double y = ymin;
		unsigned int n;

	for (int i=0; i < xpoints; ++i) {
		x = xmin + i * xstep;
		for (int j=0; j < ypoints; ++j) {
			y = ymin + j * ystep;
			n = iterate(x, y, c);
		}
	}

	return 0;
}

COMPLEX julia(COMPLEX z, COMPLEX c)
{
	return complex_add(complex_2(z), c);
}


/* iterate julia function until z = max iterations or z > 2  */
unsigned int iterate(long double x, long double y, COMPLEX c)
{
	COMPLEX z = {x,y};
	unsigned int iterations = 0;

	while (complex_abs(z) < 2 && iterations < MAXITER) {
		z = julia(z, c);
		iterations++;
		if (complex_abs(z) > 2)
			{
			    return iterations;
			}
	}
	return iterations;
}
/*#######  END: CREAT JULIA SET ####### */
