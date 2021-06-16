#pragma once

#include "Coords.h"

class Snake
{
public:
    Snake();

    Coords getHeadCoords() const;
    char getHeadSymbol() const;

private:
    char headSymbol;
    Coords headCoords;
};