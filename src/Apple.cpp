#include "../include/Apple.h"

Apple::Apple()
    :coords(Coords()), sym(Symbols::Apple) {}

Apple::Apple(const Coords& pos)
    : coords(pos), sym(Symbols::Apple) {}

void Apple::New()
{
    coords = Coords({ std::rand() % 21, std::rand() % 11 });
}

const Coords& Apple::Pos()
{ return coords; }

const Misc_Symbol& Apple::Sym()
{ return sym; }