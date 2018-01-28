/*###
# Name: Tim Frenzel
# Student ID: 002267120
# Email: frenz102@mail.chapman.edu
# Course: CS510 Fall 2017
###

####### START: CREATE MANDELBROT #######
#import packages */
#include <iostream>
#include <complex>
#include <iomanip> 
#include "mandelbrot.h"
#define MAXITER 256

int main(int argc, char **argv)
{
	if (argc != 9) {
		fprintf(stderr, "Incorrect numbers. Expecting 8 arguments\n");
		return 0;
	}

	/*determine parameter*/
		z_val xmin = std::stold(argv[1]);
		z_val xmax = std::stold(argv[2]);
		z_val ymin = std::stold(argv[3]);
		z_val ymax = std::stold(argv[4]);
		int xpoints = std::stoi(argv[5]);
		int ypoints = std::stoi(argv[6]);
		z_val zreal = std::stold(argv[7]);
		z_val zimag = std::stold(argv[8]);
		my_val z0(zreal, zimag);
		z_val xstep = (xmax - xmin)/(xpoints - 1);
		z_val ystep = (ymax - ymin)/(ypoints - 1);
		z_val x = xmin;
		z_val y = ymin;
	
	unsigned int n;
	for (int i=0; i < xpoints; ++i) {
		x = xmin + i * xstep;
		for (int j=0; j < ypoints; ++j) {
			y = ymin + j * ystep;
			n = iterate(x, y, z0);
			std::cout << std::setprecision(8) << x << ", " << y << ", " << n << std::endl;
		}
	}
    return 0;
}

/* complex julia function */
	my_val julia(my_val z0, my_val c)
	{
		return (z0 * z0 + c);
	}

/* iterate julia function until z = max iterations or z > 2  */
	unsigned int iterate(z_val x, z_val y, my_val z0)
	{
		my_val c(x,y);

		unsigned int iterations = 0;
		my_val z = z0;
		while (std::abs(z) <= 2 && iterations < MAXITER)
		{
			z = julia(z,c);
			iterations++;
		}

		return iterations;
	}

/* ####### END: CREATE MANDELBROT ####### */
