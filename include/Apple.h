#pragma once
#include "Coords.h"

class Apple
{
public:
    Apple();
    Apple(const Coords& pos);
    const Coords& Pos();

private:
    Coords _pos;
};
