#pragma once

#include "Coords.h"
#include "Direction.h"
#include "Symbol.h"

class Snake
{
public:
    Snake();
    Snake(int x, int y);

    void move(Direction dir, Direction oldDir);
    
    Coords HeadCoords() const;
    int HeadCoord(Axis ax) const;

    Coords OldHeadCoords() const;
    int OldHeadCoord(Axis ax) const;
    
    Symbol HeadSymbol() const;
    Symbol BodySymbol() const;


private:
    Coords headCoords;
    Coords oldHeadCoords;

    Symbol headSymbol;
    Symbol bodySymbol;
};