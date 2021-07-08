#include "../include/Apple.h"

Apple::Apple()
    :coords(Coords()) {}

Apple::Apple(const Coords& pos)
    : coords(pos) {}

const Coords& Apple::Pos()
{ return coords; }
