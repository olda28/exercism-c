#include "complex_numbers.h"
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
    complex_t z = { a.real + b.real, a.imag + b.imag };
    return z;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t z = { a.real - b.real, a.imag - b.imag };
   return z;
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t z = { a.real * b.real - a.imag * b.imag, a.imag * b.real + a.real * b.imag };
   return z;
}

complex_t c_div(complex_t a, complex_t b)
{
    int divisor = pow(c_abs(b), 2);
    complex_t z = c_mul(a, c_conjugate(b));
    z.real /= divisor;
    z.imag /= divisor;
    return z;
}

double c_abs(complex_t x)
{
    return sqrt(pow(x.real, 2) + pow(x.imag, 2));
}

complex_t c_conjugate(complex_t x)
{
    complex_t z = { x.real, -x.imag };
    return z;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    double e = exp(1);
    double ea = pow(e, x.real);
    complex_t z = { ea * cos(x.imag), ea * sin(x.imag) };
    return z;
}
