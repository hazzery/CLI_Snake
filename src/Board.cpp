#include "../include/Coords.h"
#include "../include/Symbol.h"
#include "../include/Board.h"
#include <iostream>
using std::cout;
using std::endl;

template <int X, int Y>
Board<X, Y>::Board()
{
    for (int y = 0; y < Height; y++)
    {
        for (int x = 0; x < Width; x++)
        {
            pixelArray[x][y] = '0';
        }
    }
//    cout << "constructed board of dimension " << width << " by " << height << endl;
}

template <int X, int Y>
void Board<X, Y>::Print() const
{
    for (int y = 0; y < Height; y++)
    {
        for (int x = 0; x < Width; x++)
        {
            cout << pixelArray[x][y];
        }
        cout << endl;
    }
}

template <int X, int Y>
void Board<X, Y>::Set(const Coords& pos, const Symbol& sym)
{
    char chr = sym.Get();
    pixelArray[pos.Get(Axis::x)][pos.Get(Axis::y)] = chr;

//    cout << "set called: " << pos << " to " << str << endl;
}

template <int X, int Y>
int Board<X, Y>::Get(const Coords& pos) const
{
    char chr = pixelArray[pos.Get(Axis::x)][pos.Get(Axis::y)];
    
    if (chr == '^' || chr == '<' || chr == '>' || chr == 'V')
        return 1;
    
    else if (chr == '"')
        return 2;
    
    else if (chr == '@')
        return 3;
    
    else
        return 0;
}

template <int X, int Y>
void Board<X, Y>::Clear(const Coords& pos)
{
    pixelArray[pos.Get(Axis::x)][pos.Get(Axis::y)] = '0';
    
    //    cout << "Cleared: " << pos << endl;
}
