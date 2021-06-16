#include "../include/Coords.h"

Coords::Coords(int x, int y)
  :xOrdinate(x), yOrdinate(y){}
    
int Coords::getX() const
{ return xOrdinate; }

int Coords::getY() const
{ return yOrdinate; }