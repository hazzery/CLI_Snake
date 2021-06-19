#include "../include/Coords.h"

Coords::Coords()
	:xOrdinate(-1), yOrdinate(-1) {}

Coords::Coords(int x, int y)
	:xOrdinate(x), yOrdinate(y) {}
    
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

ostream& operator<<(ostream& os, const Coords& pos)
{
    os << "(" << pos.xOrdinate << ", " << pos.yOrdinate << ")";
    return os;
}
