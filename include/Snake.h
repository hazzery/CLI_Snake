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
    
    unsigned int Length() const;
    
    Coords HeadCoords() const;
    unsigned int HeadCoord(Axis ax) const;

    Coords OldHeadCoords() const;
    unsigned int OldHeadCoord(Axis ax) const;
    
    Head_Symbol HeadSymbol() const;
    Body_Symbol BodySymbol() const;

    vector<Coords> BodyArray() const;
    
    void move(Direction dir, Direction oldDir);
    
private:
    Coords headCoords;
    Coords oldHeadCoords;

    Head_Symbol headSymbol;
    Body_Symbol bodySymbol;
    
    vector<Coords> bodyArray;
};
