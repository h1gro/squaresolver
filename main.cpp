#include <stdio.h>
#include <math.h>

#include "square.h"

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    int identificator = ScanTestsFile();

    if (identificator == ALL_TESTS_DONE)
    {
        printf("Enter your coefficients a, b, c \nof square equation a*x^2 + b*x + c = 0:\n");

        ScanCoeffs(&a, &b, &c);
        printf("%lg, %lg, %lg\n", a, b, c);

        int nRoots = SolveSquare(a, b, c, &x1, &x2);
        PrintResult(nRoots, x1, x2);
    }

    return 0;
}

void ScanCoeffs(double* a, double* b, double* c)
{
    assert(a);
    assert(b);
    assert(c);

    char buffer[MAX_BUF_SIZE] = {};

    fgets(buffer, MAX_BUF_SIZE, stdin);
    char* ptr = buffer;

    ptr = GetArg(a, ptr);

    ptr = GetArg(b, ptr);

    ptr = GetArg(c, ptr);
}

char* GetArg(double* coef, char* buffer)
{
    assert(coef);
    assert(buffer);

    char* current = buffer;

    int i = 0, j = 0, len = 0, len_sqrt = 0;

    char word[WORD_SIZE] = {};

    while ((buffer[i] != ' ') && ((j < WORD_SIZE)))
    {
        if (IsNumber(buffer[i]) || ((buffer[i] == '-') && (IsNumber(buffer[i+1]))))
        {
            sscanf(&(buffer[i]), "%lg%n", coef, &len);

            i += len + INT;

            break;
        }

        else if ((buffer[i] != '(') && ((j < WORD_SIZE)))
        {
            word[j] = buffer[i];

            //printf("word[%d] = %c\n", j, word[j]);

            j++;
        }

        else if (!strcmp((const char*) word, "sqrt") || (!strcmp((const char*) word, "-sqrt")))
        {
            i++;
            sscanf(&(buffer[i]), "%lg%n", coef, &len_sqrt);

            if (*coef >= 0)
            {
                *coef = sqrt(*coef);

                if (strlen(word) == NEG_SQRT_LEN){*coef *= -1;}
            }

            else
            {
                printf("negative root expression!\n");

                *coef    = 0;
                len_sqrt = 1;
            }

            i += len_sqrt + SQRT;
            break;
        }

        else
        {
            printf("wrong input!\n");

            ClearBuffer();
            break;
        }

        i++;
    }

    current += i;

    return current;
}

bool IsNumber(char symbol)
{
    return (('0' <= symbol) && (symbol <= '9'));
}
