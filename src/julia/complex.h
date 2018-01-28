/*###
# Name: Tim Frenzel
# Student ID: 002267120
# Email: frenz102@mail.chapman.edu
# Course: CS510 Fall 2017
###

####### START: COMPLEX #######
#import packages */
#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#define MAXITER 256

struct complex {
    long double x;
    long double y;
};
typedef struct complex COMPLEX;

long double complex_abs(COMPLEX a);
COMPLEX complex_add(COMPLEX a, COMPLEX b);
COMPLEX complex_multi(COMPLEX a, COMPLEX b);
COMPLEX complex_2(COMPLEX a);

    COMPLEX julia(COMPLEX, COMPLEX);
    unsigned int iterate(long double, long double, COMPLEX);

#endif

/* ####### END: COMPLEX ####### */
