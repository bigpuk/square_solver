#include <math.h>
#include <TXLib.h>

#include "tests.h"
#include "compare.h"
#include "SolveSquare.h"

int Tests(TestData* data)
{
    assert(data);

    double x1 = NAN, x2 = NAN;

    int nRoots = SolveSquare(data->a, data->b, data->c, &x1, &x2);

    if((Compare(x1, x2) == 1 && (Compare(x1, data->x1_expected) == 0 || Compare(x2, data->x2_expected) == 0)) || Compare(nRoots, data->nRoots_expected) == 0)
    {
        printf("ERROR!!! (TEST %d) \n RESULT: a = %lg, b = %lg, c = %lg, x = %lg, nRoots = %d \n",data->n, data->a, data->b, data->c, x1, nRoots);
        printf("EXPECTED: a = %lg, b = %lg, c = %lg, x = %lg, nRoots = %d \n", data-> a, data->b, data->c, data->x1_expected, data->nRoots_expected);
        
        return 1;
    }
    else if(!Compare(nRoots, data->nRoots_expected) || !Compare(x1, data->x1_expected) || !Compare(x2, data->x2_expected))
    {
        printf("ERROR!!! (TEST %d) \n RESULT: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nRoots = %d \n",data->n, data->a, data->b, data->c, x1, x2, nRoots);
        printf("EXPECTED: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, nRoots = %d \n", data->a, data->b, data->c, data->x1_expected, data->x2_expected, data->nRoots_expected);
    
        return 1;
    }

    return 0;
}