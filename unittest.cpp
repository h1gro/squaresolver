#include "prototype.h"

int Tester(struct Tests struct_test, int nTest)
{
    double x1 = 0, x2 = 0;

    int nRoots = SolveSquare(struct_test.a, struct_test.b, struct_test.c, &x1, &x2);

    if (nRoots != struct_test.nRootsExp
        || !IsEqual(x1, struct_test.x1exp)
        || !IsEqual(x2, struct_test.x2exp))
    {
        printf("\n" "error test = %d, a = %lg, b = %lg, c = %lg\n"
               " x1 = %lg, x2 = %lg, nRoots = %d\n"
               "expected, x1exp = %lg, x2exp = %lg, nRootsExp = %d\n"
               "x1-x1exp = %lg, x2-x2exp= %lg\n\n",
               nTest, struct_test.a, struct_test.b, struct_test.c,
               x1, x2, nRoots,
               struct_test.x1exp, struct_test.x2exp, struct_test.nRootsExp,
               x1-struct_test.x1exp, x2-struct_test.x2exp);

        return TEST_FAILED;
    }
    else
    {
        printf("Successfully\n");

        return TEST_DONE;
    }
}

int ScanTestsFile()
{
    struct Tests struct_test = {};
    int nTest = 0;

    FILE * file = fopen("tests.txt", "r");
    if (file == NULL)
    {
        printf("file not opened");
        return FILE_NOT_OPENED;
    }

    while( fscanf(file,
                  "%lg %lg %lg %lg %lg %d",
                    &struct_test.a, &struct_test.b, &struct_test.c,
                    &struct_test.x1exp, &struct_test.x2exp, &struct_test.nRootsExp) == 6)
    {
        int check = 0;

        check = Tester(struct_test, nTest);

        if (check == TEST_FAILED)
        {
            fclose(file);
            return INCORRECT_TEST;
        }

        nTest++;
    }
    fclose(file);
    return ALL_TESTS_DONE;
}
