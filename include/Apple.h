#pragma once
#include "Coords.h"
#include "Symbol.h"

class Apple
{
public:
    Apple();
    Apple(const Coords& pos);
    const Coords& Pos();
    const Misc_Symbol& Sym();

private:
    Coords coords;
    Misc_Symbol sym;
};
