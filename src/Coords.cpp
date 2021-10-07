#include "../include/Coords.h"
using std::cout;
using std::endl;

Coords::Coords()
	:xOrdinate(-1), yOrdinate(-1) {}    //Empty Coords objects get set to (-1, -1)

Coords::Coords(const int x, const int y)
	:xOrdinate(x), yOrdinate(y) {}  //Sets both ordinates to specified values

Coords::Coords(const Coords& pos)
    :xOrdinate(pos.xOrdinate), yOrdinate(pos.yOrdinate) {} //Coords copy constructor
    
int Coords::Get(const Axis& ax) const
{
    if(ax == Axis::x)   //Gets specified ordinate from coordinates
        return xOrdinate;
    else
        return yOrdinate;
}

void Coords::Increment(const Axis& ax)
{
    if(ax == Axis::x)   //Adds one to specified ordinate
        xOrdinate++;
    else
        yOrdinate++;
}

void Coords::Decrement(const Axis& ax)
{
    if(ax == Axis::x)   //Subtracts one from specified ordinate
        xOrdinate--;
    else
        yOrdinate--;
}

ostream& operator<<(ostream& os, const Coords& pos)
{
    os << "(" << pos.xOrdinate << ", " << pos.yOrdinate << ")"; //Prints coordinates to console
    return os;
}
