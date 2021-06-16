#pragma once

#include "Coords.h"
#include "Direction.h"

class Snake
{
public:
    Snake();

    void move(Direction dir);
    Coords HeadCoords() const;
    Coords OldHeadCoords() const;
    unsigned char HeadSymbol() const;

private:
    unsigned char headSymbol;
    Coords headCoords;
    Coords oldHeadCoords;
};