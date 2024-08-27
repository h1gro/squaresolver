#include "prototype.h"

void ClearBuffer()
{
    int ch = getchar();
    while (ch != EOF && ch != '\n' )
    {
        ch = getchar();
    }
}

bool IsEqual(double elem1, double elem2)
{
    return (fabs(elem1 - elem2) <= EPSILON);
}

void PrintResult(int nRoots, double x1, double x2)
{
    switch(nRoots)
    {
        case NO_ROOTS:       printf("no roots\n");
                             break;

        case ONE_ROOT:       printf("%lg\n", x1);
                             break;

        case TWO_ROOTS:      printf("%lg %lg\n", x1, x2);
                             break;

        case INFINITY_ROOTS: printf("any number");
                             break;

        default:             printf("unreachable");
                             break;

    }

}
