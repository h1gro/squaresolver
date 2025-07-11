#include "square.h"

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    int identificator = ScanTestsFile();

    if (identificator == ALL_TESTS_DONE)
    {
        printf("Enter your coefficients a, b, c \nof square equation a*x^2 + b*x + c = 0:\n");

        ScanCoeffs(&a, &b, &c);
        //printf("%lg, %lg, %lg\n", a, b, c);

        int nRoots = SolveSquare(a, b, c, &x1, &x2);
        PrintResult(nRoots, x1, x2);
    }

    return 0;
}


