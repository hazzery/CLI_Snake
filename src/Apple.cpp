#include "../include/Apple.h"

Apple::Apple()
    :_pos(Coords()) {}

Apple::Apple(const Coords& pos)
    :_pos(pos) {}

const Coords& Apple::Pos()
{ return _pos; }
