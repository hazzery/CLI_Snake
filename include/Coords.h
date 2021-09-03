#pragma once
#include "Axis.h"
#include <iostream>

class Coords
{
  public:
    Coords();
    Coords(const uint8_t _x, const uint8_t _y);
    Coords(const Coords& _pos);

    uint8_t Get(const Axis& _axis) const;

    void Increment(const Axis& _axis);
    void Decrement(const Axis& _axis);
    
    friend std::ostream& operator<<(std::ostream& _os, const Coords& _pos);
    
private:
    uint8_t xOrdinate, yOrdinate;
};
