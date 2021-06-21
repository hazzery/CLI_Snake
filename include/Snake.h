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
    Snake(const int x, const int y);
    
    void move(const Direction& dir, const Direction& oldDir);
    
    const unsigned int Length() const;
    
    const Coords& HeadCoords() const;
    const unsigned int HeadCoord(const Axis& ax) const;

    const Coords& OldHeadCoords() const;
    const unsigned int OldHeadCoord(const Axis& ax) const;
    
    const Head_Symbol& HeadSymbol() const;
    const Body_Symbol& BodySymbol() const;

    const vector<Coords>& BodyArray() const;
    
    
private:
    int length;
    
    Coords headCoords;
    Coords oldHeadCoords;

    Head_Symbol headSymbol;
    Body_Symbol bodySymbol;
    
    vector<Coords> bodyArray;
    
private:
    void updateArray();
};
