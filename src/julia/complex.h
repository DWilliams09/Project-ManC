#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#define MAXITER 256

struct complex {
    long double x;
    long double y;
};
typedef struct complex COMPLEX;

COMPLEX mult_complex(COMPLEX a, COMPLEX b);
COMPLEX square_complex(COMPLEX a);
COMPLEX add_complex(COMPLEX a, COMPLEX b);
void print_complex(COMPLEX a);
long double abs_complex(COMPLEX a);

COMPLEX julia(COMPLEX, COMPLEX);
unsigned int iterate(long double, long double, COMPLEX);

#endif
