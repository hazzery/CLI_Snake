#include "../include/Coords.h"
#include "../include/Symbol.h"
#include "../include/Board.h"
#include <iostream>
using std::cout;
using std::endl;

template <int X, int Y>
Board<X, Y>::Board()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelArray[x][y] = "0";
        }
    }
    cout << "constructed board of dimension " << width << " by " << height << endl;
}

template <int X, int Y>
void Board<X, Y>::print()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cout << pixelArray[x][y];
        }
        cout << endl;
    }
}

template <int X, int Y>
void Board<X, Y>::set(Coords pos, Head_Symbol sym)
{
    const char* str = GetSymbol(sym);
    pixelArray[pos.get(Axis::x)][pos.get(Axis::y)] = str;

    cout << "set called: (" << pos.get(Axis::x) << ", " << pos.get(Axis::y) << ") to " << str << endl;
}

template <int X, int Y>
void Board<X, Y>::set(Coords pos, Body_Symbol sym)
{
    const char* str = GetSymbol(sym);
    pixelArray[pos.get(Axis::x)][pos.get(Axis::y)] = str;
    
    cout << "set called: (" << pos.get(Axis::x) << ", " << pos.get(Axis::y) << ") to " << str << endl;
}
