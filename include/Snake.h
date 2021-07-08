#pragma once

#include "Direction.h"
#include "Coords.h"
#include "Symbol.h"
#include "Apple.h"
#include <vector>
using std::vector;

class Snake
{
public:
    Snake();
    Snake(const int x, const int y);
    
    void Move(const Direction& dir, const Direction& oldDir);

    void Eat(Apple& appl);

public:
    const unsigned int Length() const;
    
    const Coords& HeadCoords() const;
    const int HeadCoord(const Axis& ax) const;

    const Coords& OldHeadCoords() const;
    const int OldHeadCoord(const Axis& ax) const;
    
    const Head_Symbol& HeadSymbol() const;
    const Body_Symbol& BodySymbol() const;

    const vector<Coords>& BodyArray() const;
    
    const Coords& TailCoords() const;
    
    
private:
    int length;
    
    Coords headCoords;
    Coords oldHeadCoords;

    Head_Symbol headSymbol;
    Body_Symbol bodySymbol;
    
    vector<Coords> bodyArray;
    
    Coords tailCoords;
    
private:
    void updateBody();
};
