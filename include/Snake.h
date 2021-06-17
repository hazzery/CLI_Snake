#pragma once

#include "Coords.h"
#include "Direction.h"

class Snake
{
public:
    Snake();

    void move(Direction dir);
    
    Coords HeadCoords() const;
    int HeadCoord(Axis ax) const;

    Coords OldHeadCoords() const;
    int OldHeadCoord(Axis ax) const;
    
    char HeadSymbol() const;


private:
    unsigned char headSymbol;
    Coords headCoords;
    Coords oldHeadCoords;
};