#include "../include/Apple.h"

Apple::Apple()
    :coords(Coords()), sym(AppleSym) {}

Apple::Apple(const Coords& pos)
    : coords(pos), sym(AppleSym) {}

const Coords& Apple::Pos()
{ return coords; }

const Misc_Symbol& Apple::Sym()
{ return sym; }