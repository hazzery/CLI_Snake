#include "../include/Board.h"
#include <iostream>
using std::cout;
using std::endl;

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

template <int X, int Y>
void Board<X, Y>::print()
{
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            cout << pixelArray[x][y];
        }
        cout << endl;
    }
}

template <int X, int Y>
void Board<X, Y>::set(Coords pos, unsigned char symbol)
{
    pixelArray[pos.get(Axis::x)][pos.get(Axis::y)] = symbol;
}
