#ifndef IFDEF_CONST
#define IFDEF_CONST

#include <stdio.h>
#include <math.h>
#include <assert.h>

/**
 * @param EPSILON the minimum difference between two
 * elements in which that two elements can be equal
 */
const double EPSILON          = 0.0001;
const int    NUMBER_TEST_ARGS = 6;

static const char* TESTS = "tests.txt";

/**
 * @brief Tests Structure for tests
 * @param a square equation coefficient
 * @param b square equation coefficient
 * @param � square equation coefficient
 * @param x1exp the first expected root
 * @param x2exp the second expected root
 * @param nRootsExp the expected number of roots
 */
struct Tests
{
    double a, b, c;
    double x1exp, x2exp;
    int nRootsExp;
};

/**
 * @brief Find roots of square equation with
 * coefficients a, b, c and the number of roots
 * @return Return the number of roots
 * @param a square equation coefficient
 * @param b square equation coefficient
 * @param � square equation coefficient
 * @param x1 the first root
 * @param x2 the second root
 */
int SolveSquare(double a, double b, double c, double* x1, double* x2);

/**
 * @brief Open the test from file and scan tests from it
 * @return Return results of all tests
 */
int ScanTestsFile();

/**
 * @brief Compare roots from functions SolveSquare and SolveLinear with expected roots
 * @return Return the result of the test
 * @param nTest the number of the test
 * @param struct_test structure where keeps coefficients
 * a, b, c, roots x1exp, x2exp and nRootsExp
 */
int Tester(struct Tests struct_test, int nTest);

/**
 * @brief Find roots of linear equation with
 * coefficients b, c and number of roots
 * @return Return the number of roots
 * @param b linear equation coefficient
 * @param � linear equation coefficient
 * @param x1 first root
 */
int SolveLinear(double b, double c, double* x1);

/**
 * @brief Print the result of the programm
 * @param nRoots the number of roots
 * @param x1 first root
 * @param x2 second root
 */
void PrintResult(int nRoots, double x1, double x2);

/**
 * @brief Clear buffer from wrong coefficients
 */
void ClearBuffer();

/**
 * @brief Compare abs difference between two elements and epsilon
 * @return Return True or False
 * @param elem1 the first element
 * @param elem2 the second element
 */
bool IsEqual(double elem1, double elem2);

void CheckFile(FILE* file);
void CheckFclose(FILE* file_ptr);

/**
 * @brief Number_of_roots enumeration of constants that mean number of roots
 * @param NO_ROOTS the number of roots is zero
 * @param ONE_ROOT the number of roots is one
 * @param TWO_ROOTS the number of roots is two
 * @param INFINITY_ROOTS the number of roots is infinity
 */
enum Number_of_roots
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITY_ROOTS = 3,
};

/**
 * @brief Tests_results enumeration of constants that mean results of tests
 * @param TEST_DONE the test has gone successfully
 * @param TEST_FAILED the test has gone unsuccessfully
 * @param ALL_TESTS_DONE all test have gone successfully
 * @param INCORRECT_TEST the test is not correct
 * @param FILE_NOT_OPENED the file is not opened
 */
enum Tests_results
{
    TEST_DONE = 4,
    TEST_FAILED = 5,
    ALL_TESTS_DONE = 6,
    INCORRECT_TEST = 7,
    FILE_NOT_OPENED = 8,
};

#endif
