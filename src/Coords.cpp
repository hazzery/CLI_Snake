#include "../include/Coords.h"

Coords::Coords(int x, int y)
	:xOrdinate(x), yOrdinate(y){}
    
int Coords::get(Axis ax) const
{
    if(ax == Axis::x)
        return xOrdinate;
    else
        return yOrdinate;
}

void Coords::increment(Axis ax)
{
    if(ax == Axis::x)
        xOrdinate++;
    else
        yOrdinate++;
}

void Coords::decrement(Axis ax)
{
    if(ax == Axis::x)
        xOrdinate--;
    else
        yOrdinate--;
}