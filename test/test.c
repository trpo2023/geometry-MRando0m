#include "ctest.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "libgeometry/area.h"
#include "libgeometry/lexer.h"
#include "libgeometry/parser.h"
#include "libgeometry/perimetr.h"

CTEST(ckecktest, test1)
{
    char* str = "circlee(1.0 2.0, 3)";
    int expected = 1;
    int result = checker(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(ckeckerrors, test2)
{
    char* str = "circle(1.0 2.0, 3.0)";
    int expected = 0;
    int result = checker(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(ckeckfail, test3)
{
    char* str = "circle(1x 2, 3.0)";
    int expected = 2;
    int result = checkarg(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(ckeckfail1, test4)
{
    char* str = "circle(1 2x, 3.0)";
    int expected = 2;
    int result = checkarg(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(ckeckfail2, test5)
{
    char* str = "circle(1 2, 3.0x)";
    int expected = 4;
    int result = checkarg(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(ckeckout, test6)
{
    char* str = "circle(1 2, 3.1(";
    int expected = 5;
    int result = checkarguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(ckeckstr, test7)
{
    char* str = "circle(1.0 2.1, 3) 123";
    int expected = 5;
    int result = checkarguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(ckec_area_result, test8)
{
    char* str = "circlee(1 2, 3)";
    double expected = 9 * M_PI;
    double result = scoreArea(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0.00000000001);
}

CTEST(check_area_res, test9)
{
    char* str = "circle(1 2, x)";
    double expected = -1;
    double result = scoreArea(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0);
}

CTEST(check_perimetr_result, test10)
{
    char* str = "circle(1 2, 3)";
    double expected = 2 * M_PI * 3;
    double result = scorePer(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0.00000000001);
}

CTEST(check_perimetr_res, test11)
{
    char* str = "circle(1 2, x)";
    double expected = -1;
    double result = scorePer(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0);
}