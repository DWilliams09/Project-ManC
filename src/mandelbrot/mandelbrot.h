#ifndef FINAL_MANDELBROT_H_
#define FINAL_MANDELBROT_H_

#include <complex>

typedef long double ZValue;
typedef std::complex<ZValue> MValue;

#define MAXITER 256

MValue julia(MValue, MValue);
unsigned int iterate(ZValue, ZValue, MValue);

#endif