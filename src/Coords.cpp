#include "../include/Coords.h"
using std::cout;
using std::endl;

Coords::Coords()
	:xOrdinate(0), yOrdinate(0) {}

Coords::Coords(const uint8_t _x, const uint8_t _y)
	:xOrdinate(_x), yOrdinate(_y) {}

Coords::Coords(const Coords& _pos)
    :xOrdinate(_pos.xOrdinate), yOrdinate(_pos.yOrdinate)
{ /*cout << "bro, you just coppied " << pos << endl; */ }
    
uint8_t Coords::Get(const Axis& _axis) const
{
    if(_axis == Axis::X)
        return xOrdinate;
    else
        return yOrdinate;
}

void Coords::Increment(const Axis& _axis)
{
    if(_axis == Axis::X)
        xOrdinate++;
    else
        yOrdinate++;
}

void Coords::Decrement(const Axis& _axis)
{
    if(_axis == Axis::X)
        xOrdinate--;
    else
        yOrdinate--;
}

std::ostream& operator<<(std::ostream& _os, const Coords& _pos)
{
    _os << "(" << _pos.xOrdinate << ", " << _pos.yOrdinate << ")";
    return _os;
}
