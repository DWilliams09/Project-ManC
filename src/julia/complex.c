#include <stdio.h>
#include <math.h>
#include "complex.h"

COMPLEX mult_complex(COMPLEX a, COMPLEX b) {
    COMPLEX z;
    z.x = a.x * b.x - a.y * b.y;
    z.y = a.x * b.y + a.y * b.x;
    return z;
}

COMPLEX square_complex(COMPLEX a) {
    return mult_complex(a, a);
}

COMPLEX add_complex(COMPLEX a, COMPLEX b) {
    COMPLEX z;
    z.x = a.x + b.x;
    z.y = a.y + b.y;
    return z;
}

long double abs_complex(COMPLEX a) {
    long double rsq = a.x * a.x + a.y * a.y;
    return sqrtl(rsq);
}

void print_complex(COMPLEX a){
    printf("%Lf + %LF i", a.x, a.y);
}