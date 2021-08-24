#pragma once
#include "Axis.h"
#include <iostream>

class Coords
{
  private:
    int xOrdinate, yOrdinate;
    
  public:
    Coords();
    Coords(const int x, const int y);
    Coords(const Coords& pos);

    int Get(const Axis& ax) const;

    void Increment(const Axis& ax);
    void Decrement(const Axis& ax);
    
    friend std::ostream& operator<<(std::ostream& os, const Coords& pos);
};
