#include <iostream>
#include <complex>
#include <iomanip> 
#include "mandelbrot.h"

int main(int argc, char **argv)
{
	if (argc != 9) {
		fprintf(stderr, "expecting 8 arguments: xmin, xmax, ymin, "
                        "ymax, xpoints, ypoints, zreal, and zimag\n");
		return EXIT_FAILURE;
	}

	ZValue xmin = std::stold( argv[1]);
	ZValue xmax = std::stold( argv[2]);
	ZValue ymin = std::stold( argv[3]);
	ZValue ymax = std::stold( argv[4]);
	int xpoints = std::stoi(  argv[5]);
	int ypoints = std::stoi(  argv[6]);

	ZValue zreal = std::stold(argv[7]);
	ZValue zimag = std::stold(argv[8]);
	MValue z0(zreal, zimag);

	ZValue xstep = (xmax - xmin)/(xpoints - 1);
	ZValue ystep = (ymax - ymin)/(ypoints - 1);

	ZValue x = xmin;
	ZValue y = ymin;
	unsigned int n;
	for (int i=0; i < xpoints; ++i) {
		x = xmin + i * xstep;
		for (int j=0; j < ypoints; ++j) {
			y = ymin + j * ystep;
			n = iterate(x, y, z0);
			std::cout << std::setprecision(12) << x << ", " << y << ", " << n << std::endl;
		}
	}

    return 0;
}

MValue julia(MValue z0, MValue c)
{
	/* Applies the Julia function {z -> z^2 c} to complex z0 */
	return (z0 * z0 + c);
}

unsigned int iterate(ZValue x, ZValue y, MValue z0)
{
	/* Creates complex number z=x+iy and iterates the julia function until |z| > 2 or we reach max iterations */
	MValue c(x,y);

	unsigned int iters = 0;
	MValue z = z0;
	while (std::abs(z) <= 2 && iters < MAXITER)
	{
		z = julia(z,c);
		iters++;
	}

	return iters;
}
