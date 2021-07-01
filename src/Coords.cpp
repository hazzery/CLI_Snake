#include "../include/Coords.h"
using std::cout;
using std::endl;

Coords::Coords()
	:xOrdinate(-1), yOrdinate(-1) {}

Coords::Coords(const int x, const int y)
	:xOrdinate(x), yOrdinate(y) {}

Coords::Coords(const Coords& pos)
    :xOrdinate(pos.xOrdinate), yOrdinate(pos.yOrdinate)
{ /*cout << "bro, you just coppied " << pos << endl; */ }
    
int Coords::Get(const Axis& ax) const
{
    if(ax == Axis::x)
        return xOrdinate;
    else
        return yOrdinate;
}

void Coords::Increment(const Axis& ax)
{
    if(ax == Axis::x)
        xOrdinate++;
    else
        yOrdinate++;
}

void Coords::Decrement(const Axis& ax)
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
