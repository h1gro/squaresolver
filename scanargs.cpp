#include "square.h"

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
