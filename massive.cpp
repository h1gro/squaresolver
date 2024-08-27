#include <stdio.h>
#include <TXLib.h>
#include <math.h>

void Print_Massive(int data[][2], size_t sizeX, size_t sizeY);

int main()
{
    int data[2][2] = {{1, 2}, {3, 4}};

    size_t sizeY = sizeof (data)/ sizeof (data[0]);

    size_t sizeX = sizeof (data[0])/ sizeof (data[0][0]);

    int num_elements = sizeof (data)/ sizeof (data[0][0]);

    printf("num_line = %d num_column = %d num_elements = %d\n", sizeY, sizeX, num_elements);

    Print_Massive(data, sizeX, sizeY);
}


void Print_Massive(int data[][2], size_t sizeX, size_t sizeY)
{
    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            printf("data[%d][%d] = %d\n", x, y, data[x][y]);
        }
        printf("\n");
    }
}
