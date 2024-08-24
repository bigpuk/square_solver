#include <math.h>
#include <TXLib.h>

#include "autotest.h"
#include "tests.h"

void autotest()
{
    const double two_thirds = ((double) 2) / ((double) 3);

    TestData tests[] =
    {
        {.n = 1, .a = 1,   .b = 2,   .c = 1,     .x1_expected = -1,       .x2_expected = NAN,         .nRoots_expected =  1},
        {.n = 2, .a = 0,   .b = 0,   .c = 0,     .x1_expected = INFINITY, .x2_expected = INFINITY,    .nRoots_expected = -1},
        {.n = 3, .a = 1,   .b = 0,   .c = 0,     .x1_expected = 0,        .x2_expected = NAN,         .nRoots_expected =  1},
        {.n = 4, .a = 0,   .b = 1,   .c = 0,     .x1_expected = 0,        .x2_expected = NAN,         .nRoots_expected =  1},
        {.n = 5, .a = 1,   .b = 1,   .c = 100,   .x1_expected = NAN,      .x2_expected = NAN,         .nRoots_expected =  0},
        {.n = 6, .a = 1,   .b = 0,   .c = -1,    .x1_expected = -1,       .x2_expected = 1,           .nRoots_expected =  2},
        {.n = 7, .a = 1,   .b = 2,   .c = 3,     .x1_expected = NAN,      .x2_expected = NAN,         .nRoots_expected =  0},
        {.n = 8, .a = 1,   .b = 4,   .c = 3,     .x1_expected = -3,       .x2_expected = -1,          .nRoots_expected =  2},
        {.n = 9, .a = 1.5, .b = 2.5, .c = 1,     .x1_expected = -1,       .x2_expected = -two_thirds, .nRoots_expected =  2}
    };

    int correct = 0;
    int incorrect = 0;

    for(size_t i = 0; i < sizeof(tests) / sizeof(TestData); i++)
    {
        if(Tests(&(tests[i])))incorrect += 1;
            else correct += 1;
    }

    if(incorrect == 0) printf("\nEverything's OK \n");
    else printf("\nCorrect Tests: %d\nIncorrect Tests: %d \n", correct, incorrect);
}