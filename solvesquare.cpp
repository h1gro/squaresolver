#include "prototype.h"

int SolveSquare ( double a, double b, double c, double* x1, double* x2)
{
    assert(x1);
    assert(x2);

    double D = b * b - 4 * a * c;

    if (IsEqual(a, 0))
    {
        return SolveLinear(b, c, x1);
    }

    else
    {
        if (D >= 0)
        {
            double sqrt_D = sqrt(D);

            *x1 = (-b + sqrt_D) / (2 * a);
            *x2 = (-b - sqrt_D) / (2 * a);

            if (IsEqual(*x1, *x2))
            {
                return ONE_ROOT;
            }

            else
            {
                return TWO_ROOTS;
            }
        }

        else
        {
            return NO_ROOTS;
        }
    }
}
