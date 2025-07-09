#include "square.h"

int SolveSquare (double a, double b, double c, double* x1, double* x2)
{
    assert(x1);
    assert(x2);

    if (IsEqual(a, 0))
    {
        return SolveLinear(b, c, x1);
    }

    else
    {
        double D = b * b - 4 * a * c;

        if (D > 0)
        {
            double sqrt_D = sqrt(D);

            *x1 = (-b + sqrt_D) / (2 * a);
            *x2 = (-b - sqrt_D) / (2 * a);

            return TWO_ROOTS;
        }

        else if (IsEqual(D, 0))
        {
            *x1 = -b / (2 * a);
            *x2 = *x1;

            return ONE_ROOT;
        }

        else
        {
            return NO_ROOTS;
        }
    }
}

int SolveLinear(double b, double c, double* x1)
{
    assert(x1);

    if (IsEqual(b, 0))
    {
        if (IsEqual(c, 0))
        {
            return INFINITY_ROOTS;
        }

        else
        {
            return NO_ROOTS;
        }
    }

    else
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }
}
