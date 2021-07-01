#pragma once
#include "Coords.h"
#include "Symbol.h"

class Apple
{
public:
    Apple();
    Apple(const Coords& pos);
    const Coords& Pos();
    const Symbol& Sym();

private:
    Coords coords;
    Symbol sym;
};
