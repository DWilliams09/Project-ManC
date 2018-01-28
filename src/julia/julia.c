#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

int main(int argc, char **argv)
{
	if (argc != 9) {
		fprintf(stderr, "expecting 8 arguments: xmin, xmax, ymin, "
                        "ymax, xpoints, ypoints, creal, and cimag\n");
		return EXIT_FAILURE;
	}

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

			printf("%Lf, %Lf, %d\n", x, y, n);
		}
	}

	return 0;
}

COMPLEX julia(COMPLEX z, COMPLEX c)
{
	/* Returns a single iteration of the julia function, (z -> z^2 + c) */
	return add_complex(square_complex(z), c);
}

unsigned int iterate(long double x, long double y, COMPLEX c)
{
	/* Creates complex number z=x+iy and iterates the julia function until |z| > 2 or we reach max iterations */
	COMPLEX z = {x,y};
	unsigned int iters = 0;

	while (abs_complex(z) < 2 && iters < MAXITER) {
		z = julia(z, c);
		iters++;
	}
	return iters;
}
