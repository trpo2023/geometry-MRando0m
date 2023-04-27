#include "ctest.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "libgeometry/area.h"
#include "libgeometry/lexer.h"
#include "libgeometry/parser.h"
#include "libgeometry/perimetr.h"

CTEST(name, failname)
{
    char* str = "circlee(1.0 2.0, 3)";
    int expected = 1;
    int result = checker(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(name, correctname)
{
    char* str = "circle(1.0 2.0, 3.0)";
    int expected = 0;
    int result = checker(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(arguments, failof_x)
{
    char* str = "circle(1x 2, 3.0)";
    int expected = 2;
    int result = checkarg(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(arguments, failof_y)
{
    char* str = "circle(1 2x, 3.0)";
    int expected = 2;
    int result = checkarg(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(arguments, failof_rad)
{
    char* str = "circle(1 2, 3.0x)";
    int expected = 4;
    int result = checkarg(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(brace, failbrace)
{
    char* str = "circle(1 2, 3.1(";
    int expected = 5;
    int result = checkarguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(unexp_tok, failtok)
{
    char* str = "circle(1.0 2.1, 3) 123";
    int expected = 5;
    int result = checkarguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(area, correct)
{
    char* str = "circlee(1 2, 3)";
    double expected = 9 * M_PI;
    double result = scoreArea(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0.00000000001);
}

CTEST(area, fail)
{
    char* str = "circle(1 2, x)";
    double expected = -1;
    double result = scoreArea(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0);
}

CTEST(perimetr, correct)
{
    char* str = "circle(1 2, 3)";
    double expected = 2 * M_PI * 3;
    double result = scorePer(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0.00000000001);
}

CTEST(perimetr, fail)
{
    char* str = "circle(1 2, x)";
    double expected = -1;
    double result = scorePer(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0);
}