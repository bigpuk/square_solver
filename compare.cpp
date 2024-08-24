#include <math.h>

#include "compare.h"

int Compare(double num1, double num2)
{
    if(isnan(num1) && isnan(num2)) return 1;
    else if(isnan(num1) || isnan(num2)) return 0;

    if(isinf(num1) && isinf(num2)) return 1;
    else if(isinf(num1) || isinf(num2)) return 0;

    if(fabs(num1 - num2) < EPS) return 1;

    return 0;
}