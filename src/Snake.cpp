#include "../include/Snake.h"

Snake::Snake()
:headSymbol('^'), headCoords(Coords(7, 4)) {}

Coords Snake::getHeadCoords() const
{ return headCoords; }

char Snake::getHeadSymbol() const
{ return headSymbol; }