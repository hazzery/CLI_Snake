#include "../include/Snake.h"
#include "../include/Direction.h"
#include "../include/Axis.h"
#include <iostream>
using std::cout;
using std::endl;

Snake::Snake()
    :headSymbol('^'), headCoords(Coords(0, 0)), oldHeadCoords(Coords(0, 0))
{
    cout << "constructed empty snake" << endl;
}

Snake::Snake(int x, int y)
    : headSymbol('^'), headCoords(Coords(((x+1)/2)-1, ((y + 1) / 2) - 1)), oldHeadCoords(Coords(0, 0))
{
    cout << "constructed snake at pos (" << ((x + 1) / 2) - 1 << ", " << ((y + 1) / 2) - 1 << ")" << endl;
}

void Snake::move(Direction dir)
{
    oldHeadCoords = headCoords;
    
    cout << "move snake ";

    switch(dir)
    {
        case Up:
            headCoords.decrement(Axis::y);
            cout << "up" << endl;
            break;
            
        case Down:
            headCoords.increment(Axis::y);
            cout << "down" << endl;
            break;
            
        case Left:
            headCoords.decrement(Axis::x);
            cout << "left" << endl;
            break;
            
        case Right:
            headCoords.increment(Axis::x);
            cout << "right" << endl;
            break;
    }
}

Coords Snake::HeadCoords() const
{ return headCoords; }

Coords Snake::OldHeadCoords() const
{ return oldHeadCoords; }

int Snake::HeadCoord(Axis ax) const
{ return headCoords.get(ax); }

int Snake::OldHeadCoord(Axis ax) const
{ return oldHeadCoords.get(ax); }

char Snake::HeadSymbol() const
{ return headSymbol; }