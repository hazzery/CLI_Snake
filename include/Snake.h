#pragma once

#include "Coords.h"
#include "Direction.h"
#include "Symbol.h"
#include <vector>
using std::vector;

class Snake
{
public:
    Snake();
    Snake(int x, int y);
    
    int Length() const;
    
    Coords HeadCoords() const;
    int HeadCoord(Axis ax) const;

    Coords OldHeadCoords() const;
    int OldHeadCoord(Axis ax) const;
    
    Symbol HeadSymbol() const;
    Symbol BodySymbol() const;

    vector<Coords> BodyArray() const;
    
    void move(Direction dir, Direction oldDir);
    
private:
    Coords headCoords;
    Coords oldHeadCoords;

    Symbol headSymbol;
    Symbol bodySymbol;
    
    vector<Coords> bodyArray;
};
