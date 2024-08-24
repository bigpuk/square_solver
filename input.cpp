#include <TXLib.h>
#include <math.h>

#include "input.h"

int input(double* a, double* b, double* c)
{
    printf("Enter a b c: \n");

    assert(a);
    assert(b);
    assert(c);

    if (scanf("%lg %lg %lg", a, b, c) != COEFF_COUNT)
    {
        printf("Incorrect number!!!\n");

        return 1;
    }

    return 0;
}