#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "prototype.h"

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    int identificator = ScanTestsFile();

    if (identificator == ALL_TESTS_DONE)
    {
        while (scanf("%lg %lg %lg", &a, &b, &c) != 3)
        {
            printf("wrong input");
            ClearBuffer();
        }

        int nRoots = SolveSquare (a, b, c, &x1, &x2);
        PrintResult(nRoots, x1, x2);
    }
}
