#include "../include/Board.h"

template <int X, int Y>
Board<X, Y>::Board()
{
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            pixelArray[x][y] = '0';
        }
    }
}