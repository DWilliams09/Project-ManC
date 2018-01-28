/*###
# Name: Tim Frenzel
# Student ID: 002267120
# Email: frenz102@mail.chapman.edu
# Course: CS510 Fall 2017
###

#import packages */
#ifndef FINAL_MANDELBROT_H_
#define FINAL_MANDELBROT_H_
#include <complex>

  typedef long double z_val;
  typedef std::complex<z_val> my_val;
  my_val julia(my_val, my_val);
  unsigned int iterate(z_val, z_val, my_val);

#endif
