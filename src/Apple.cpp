#include "../include/Apple.h"

Apple::Apple()
    :pos(Coords()), sym(Symbols::Apple) {}

Apple::Apple(const Coords& _pos)
    : pos(_pos), sym(Symbols::Apple) {}

void Apple::RandomisePosition(uint8_t _maxWidth, uint8_t _maxHeight)
{
    pos = Coords(std::rand() % _maxWidth, std::rand() % _maxHeight);
}

const Coords& Apple::Pos()
{ return pos; }

const Misc_Symbol& Apple::Sym()
{ return sym; }