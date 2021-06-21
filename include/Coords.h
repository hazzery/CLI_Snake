#pragma once
#include "Axis.h"
#include <iostream>
using std::ostream;

class Coords
{
  private:
    int xOrdinate, yOrdinate;
    
  public:
    Coords();
    Coords(const int x, const int y);
    Coords(const Coords& pos);

    int get(const Axis& ax) const;

    void increment(const Axis& ax);
    void decrement(const Axis& ax);
    
    friend ostream& operator<<(ostream& os, const Coords& pos);
};
