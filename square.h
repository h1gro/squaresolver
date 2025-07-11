#ifndef IFDEF_CONST
#define IFDEF_CONST

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

const double EPSILON          = 0.0001;
const int    NUMBER_TEST_ARGS = 6;
const int    MAX_BUF_SIZE     = 50;
const int    WORD_SIZE        = 10;
const int    NEG_SQRT_LEN     = 5;

static const char* TESTS = "tests.txt";

struct Tests
{
    double a, b, c;
    double x1exp, x2exp;
    int nRootsExp;
};

enum Number_of_roots
{
    NO_ROOTS       = 0,
    ONE_ROOT       = 1,
    TWO_ROOTS      = 2,
    INFINITY_ROOTS = 3,
};

enum Tests_results
{
    TEST_DONE       = 4,
    TEST_FAILED     = 5,
    ALL_TESTS_DONE  = 6,
    INCORRECT_TEST  = 7,
    FILE_NOT_OPENED = 8,
};

enum ptr_shifts
{
    INT  = 1,
    SQRT = 2,
};

bool IsNumber      (char symbol);
bool IsEqual       (double elem1, double elem2);

char* GetArg       (double* coef, char* buffer);

int  ScanTestsFile ();
int  SolveLinear   (double b, double c, double* x1);
int  Tester        (struct Tests struct_test, int nTest);
int  SolveSquare   (double a, double b, double c, double* x1, double* x2);

void ClearBuffer   ();
void CheckFile     (FILE* file);
void CheckFclose   (FILE* file_ptr);
void ScanCoeffs    (double* a, double* b, double* c);
void PrintResult   (int nRoots, double x1, double x2);

#endif
