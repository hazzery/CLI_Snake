#include "../include/Coords.h"

Coords::Coords()
	:xOrdinate(-1), yOrdinate(-1) {}

Coords::Coords(const int x, const int y)
	:xOrdinate(x), yOrdinate(y) {}
    
int Coords::get(const Axis& ax) const
{
    if(ax == Axis::x)
        return xOrdinate;
    else
        return yOrdinate;
}

void Coords::increment(const Axis& ax)
{
    if(ax == Axis::x)
        xOrdinate++;
    else
        yOrdinate++;
}

void Coords::decrement(const Axis& ax)
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
