#pragma once
#include "axis.h"
#include <iostream>
using std::ostream;

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
    
    friend ostream& operator<<(ostream& os, const Coords& pos);
};
