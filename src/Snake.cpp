#include "../include/Snake.h"
#include "../include/Direction.h"
#include "../include/Axis.h"

Snake::Snake()
:headSymbol('^'), headCoords(Coords(7, 4)), oldHeadCoords(Coords(0, 0)) {}

void Snake::move(Direction dir)
{
    oldHeadCoords = headCoords;
    
    switch(dir)
    {
        case Up:
            headCoords.decrement(Axis::y);
            break;
            
        case Down:
            headCoords.increment(Axis::y);
            break;
            
        case Left:
            headCoords.decrement(Axis::x);
            break;
            
        case Right:
            headCoords.increment(Axis::x);
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