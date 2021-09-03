#pragma once

#include "Direction.h"
#include "Coords.h"
#include "Symbol.h"
#include "Apple.h"
#include <vector>

class Snake
{
public:
    Snake();
    Snake(const uint8_t _x, const uint8_t _y);
    
    void Move(const Direction& _dir, const Direction& _oldDir);

    void Eat(Apple& _apple);

    void UpdateBody();

public:
    const unsigned short Length() const;
    
    const Coords& HeadCoords() const;
    const Coords& OldHeadCoords() const;
    
    const Head_Symbol& HeadSymbol() const;
    const Body_Symbol& BodySymbol() const;

    const std::vector<Coords>& BodyArray() const;
    
    const Coords& TailCoords() const;
    
    
private:
    unsigned short length;
    
    Coords headCoords;
    Coords oldHeadCoords;

    Head_Symbol headSymbol;
    Body_Symbol bodySymbol;
    
    std::vector<Coords> bodyArray;
    
    Coords tailCoords;
    
};
