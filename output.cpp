#include <math.h>
#include <TXLib.h>

#include "output.h"

void output(double x1, double x2, int nRoots)
{
    switch (nRoots)
    {
        case -1: printf("Any number is a root \n");
                break;

        case 0: printf("No roots \n");
                break;

        case 1: printf("Only one root: %lg \n", x1);
                break;

        case 2: printf("Two roots: %lg, %lg \n",x1, x2);
                break;

        default: printf("ERROR \n");

    }
}