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
            pixelArray[x][y] = BlankSym.Get();
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
    if (pos.Get(Axis::x) < 0 || pos.Get(Axis::y) < 0)//Wall
        return -1;

    char chr = pixelArray[pos.Get(Axis::x)][pos.Get(Axis::y)];
    
    if (chr == HeadUpSym.Get() || chr == HeadLeftSym.Get() || chr == HeadRightSym.Get() || chr == HeadDownSym.Get())//Snake head
        return 1;
    
    else if (chr == BodySym.Get())//Snake body
        return 2;
    
    else if (chr == AppleSym.Get())//Apple
        return 3;
    
    else //Empty space
        return 0;
}

template <int X, int Y>
void Board<X, Y>::Clear(const Coords& pos)
{
    pixelArray[pos.Get(Axis::x)][pos.Get(Axis::y)] = BlankSym.Get();
    
    //    cout << "Cleared: " << pos << endl;
}
