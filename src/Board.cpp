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
    int x = pos.Get(Axis::x);
    int y = pos.Get(Axis::y);

    if (x < 0 || x > Width - 1 || y < 0 || y > Height - 1)//Wall
        return -1;

    char chr = pixelArray[x][y];//Gets symbol at given coords
    
    if (chr == BlankSym.Get())//Empty space
        return 0;
    
    else if (chr == BodySym.Get())//Snake body
        return 1;
    
    else if (chr == AppleSym.Get())//Apple
        return 2;
    
    else if (chr == HeadUpSym.Get() || chr == HeadLeftSym.Get() || chr == HeadRightSym.Get() || chr == HeadDownSym.Get())//Snake head
        return 3;
    
    else//Error, there is somthing in pixelArray that shouldn't be there
        return chr;
}

template <int X, int Y>
void Board<X, Y>::Clear(const Coords& pos)
{
    pixelArray[pos.Get(Axis::x)][pos.Get(Axis::y)] = BlankSym.Get();
    
    //    cout << "Cleared: " << pos << endl;
}
