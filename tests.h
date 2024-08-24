#ifndef TESTS_H
#define TESTS_H

struct TestData
{
    int n;
    double a, b, c;
    double x1_expected, x2_expected;
    int nRoots_expected;
};

int Tests(TestData* data);

#endif