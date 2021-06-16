#pragma once

class Coords
{
  private:
    int xOrdinate, yOrdinate;
    
  public:
    Coords(int x, int y);

    int getX() const;
    int getY() const;
};