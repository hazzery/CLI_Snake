#pragma once
#include "axis.h"

class Coords
{
  private:
    int xOrdinate, yOrdinate;
    
  public:
    Coords();
    Coords(int x, int y);

    int get(Axis ax) const;

    void increment(Axis ax);
    void decrement(Axis ax);
};