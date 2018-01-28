/*###
# Name: Tim Frenzel
# Student ID: 002267120
# Email: frenz102@mail.chapman.edu
# Course: CS510 Fall 2017
###

####### START: COMPLEX FUNCTIONS #######
#import packages */
#include <stdio.h>
#include <math.h>
#include "complex.h"

long double complex_abs(COMPLEX a) {
        rsq = a.x * a.x + a.y * a.y;
        rsq = lround(rsq)
    return sqrtl(rsq);
}

COMPLEX complex_add(COMPLEX a, COMPLEX b) {
    COMPLEX z;
        z.x = a.x + b.x;
        z.y = a.y + b.y;
    return z;
}

COMPLEX complex_multi(COMPLEX a, COMPLEX b) {
    COMPLEX z;
        z.x = a.x * b.x - a.y * b.y;
        z.y = a.x * b.y + a.y * b.x;
    return z;
}

COMPLEX complex_2(COMPLEX a) {
        z = complex_multi(a, a);
    return z;
}

*/ ####### END: COMPLEX FUNCTIONS ####### */
