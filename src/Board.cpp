#include "../include/Coords.h"
#include "../include/Symbol.h"
#include "../include/Board.h"
#include <iostream>
using std::cout;
using std::endl;

template <uint8_t _width, uint8_t _height>
Board<_width, _height>::Board()
{
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            array[x][y] = Symbols::Blank;
        }
    }
//    cout << "constructed board of dimension " << _width << " by " << _height << endl;
}

template <uint8_t _width, uint8_t _height>
void Board<_width, _height>::Print() const
{
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            cout << array[x][y];
        }
        cout << endl;
    }
}

template <uint8_t _width, uint8_t _height>
void Board<_width, _height>::Set(const Coords& pos, const Symbol& sym)
{
    array[pos.Get(Axis::X)][pos.Get(Axis::Y)] = sym;

//    cout << "set called: " << pos << " to " << str << endl;
}

template <uint8_t _width, uint8_t _height>
int8_t Board<_width, _height>::Get(const Coords& pos) const
{
    int x = pos.Get(Axis::X);
    int y = pos.Get(Axis::Y);

    if (x < 0 || x > _width - 1 || y < 0 || y > _height - 1)//Wall
        return -1;

    Symbol sym = array[x][y];//Gets symbol at given coords
    
    if (sym == Symbols::Blank)//Empty space
        return 0;
    
    else if (sym == Symbols::Apple)//Apple
        return 2;
    
    else if (sym == Symbols::TopLeft || sym == Symbols::TopRight || sym == Symbols::BottomLeft || sym == Symbols::BottomRight || sym == Symbols::Horizontal || sym == Symbols::Vertical)//Snake body
        return 1;
    
    else if (sym == Symbols::HeadUp || sym == Symbols::HeadLeft || sym == Symbols::HeadRight || sym == Symbols::HeadDown)//Snake head
        return 3;
    
    else//Error, there is somthing in array that shouldn't be there
        return (int)sym;
}

template <uint8_t _width, uint8_t _height>
void Board<_width, _height>::Clear(const Coords& pos)
{
    array[pos.Get(Axis::X)][pos.Get(Axis::Y)] = Symbols::Blank;
    
    //    cout << "Cleared: " << pos << endl;
}

template <uint8_t _width, uint8_t _height>
constexpr uint8_t Board<_width, _height>::Width()
{ return _width; }

template <uint8_t _width, uint8_t _height>
constexpr uint8_t Board<_width, _height>::Height()
{ return _height; }
