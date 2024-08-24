#include <math.h>
#include <TXLib.h>

#include "SolveSquare.h"
#include "compare.h"

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    assert(x1);
    assert(x2);
    double d = b * b - 4 * a * c;

    if(Compare(a, 0) && Compare(b, 0))
    {
        *x1 = INFINITY;
        *x2 = INFINITY;

        return -1;
    }
    else
    {
        if((Compare(b, 0) && Compare(c, 0)) || (Compare(a, 0) && Compare(c, 0)))
        {
            *x1 = 0;
            *x2 = NAN;

            return 1;
        }
        else if(Compare(a, 0))
        {
            *x1 = -c / b;
            *x2 = *x1;

            return 1;
        }
    }

    if(d < 0)
    {
        *x1 = NAN;
        *x2 = NAN;

        return 0;
    }

    double part1 = -b / (2 * a);
    double part2 = sqrt(d) / (2 * a);

    *x1 = part1 + part2;
    *x2 = part1 - part2;

    if(isnan(*x1) || isnan(*x2)) return 0;
    else
    {
        if(Compare(*x1, *x2))
        {
            *x2 = NAN;

            return 1;
        }

            if(x1 > x2)
        {
            double sort_x = *x1;
            *x1 = *x2;
            *x2 = sort_x;
        }

        return 2;
    }
}