#include "square.h"

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

        case ONE_ROOT:       printf("x = %lg\n", x1);
                             break;

        case TWO_ROOTS:      printf("x1 = %lg\nx2 = %lg\n", x1, x2);
                             break;

        case INFINITY_ROOTS: printf("x = any number");
                             break;

        default:             printf("unreachable");
                             break;
    }
}

void CheckFile(FILE* file)
{
    if (file == NULL)
    {
        printf("file not opened\n");
    }
}

void CheckFclose(FILE* file_ptr)
{
    assert(file_ptr);

    int fclose_return = fclose(file_ptr);

    if (fclose_return != 0)
    {
        printf("file closed wrong, fclose_return = %d\n", fclose_return);
    }
}
