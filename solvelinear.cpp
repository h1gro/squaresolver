#include "prototype.h"

int SolveLinear(double b, double c, double* x1)
{
        assert(x1);

        if ( IsEqual(b, 0) )
        {
            if ( IsEqual(c, 0) )
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
