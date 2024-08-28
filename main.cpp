#include <TXLib.h>
#include <math.h>

#include "compare.h"
#include "input.h"
#include "output.h"
#include "tests.h"
#include "SolveSquare.h"
#include "autotest.h"

const int INPUT_FAIL = 1;

int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int nRoots = -8;

    if (input(&a, &b, &c) == INPUT_FAIL) return 1;

    nRoots = SolveSquare(a, b, c, &x1, &x2);

    output(x1, x2, nRoots);

    autotest();
}