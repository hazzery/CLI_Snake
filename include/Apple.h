#pragma once
#include "Coords.h"
#include "Symbol.h"

class Apple
{
public:
    Apple();
    Apple(const Coords& _pos);

    void RandomisePosition(uint8_t _maxWidth, uint8_t _maxHeight);

public:
    const Coords& Pos();
    const Misc_Symbol& Sym();

private:
    Coords pos;
    Misc_Symbol sym;
};
