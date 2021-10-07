#pragma once
#include "Axis.h"
#include <iostream>
using std::ostream;

/**
 * @brief Data structure that holds coordinate pairs
**/
class Coords
{
  private:
    int xOrdinate, yOrdinate;
    
  public:
    /**
     * @brief Constructs Coords object with value of (-1, -1)
    **/
    Coords();

    /**
     * @brief Construtcs a coords object with specified value
	 * 
	 * @param x X ordinate of coordinates
	 * @param y Y ordinate of coordinates
    **/
    Coords(const int x, const int y);

    /**
     * @brief Coords copy constructor
	 * 
	 * @param pos Coords object to be coppied
    **/
    Coords(const Coords& pos);

    /**
     * @brief Gets value of specified ordinate
	 * 
	 * @param ax either Axis::X or Axis::Y
	 * 
	 * @return the value of the ordinate at specified axis
    **/
    int Get(const Axis& ax) const;

    /**
     * @brief Adds one to the value of specified ordinate
	 * 
	 * @param ax either Axis::X or Axis::Y
    **/
    void Increment(const Axis& ax);

    /**
     * @brief Subtracts one from the value of specified ordinate
	 * 
	 * @param ax either Axis::X or Axis::Y
    **/
    void Decrement(const Axis& ax);
    
    /**
     * @brief Prints value of the coodinates to console
	 * 
	 * @param os std::cout
	 * @param pos Coords object to be printed
    **/
    friend ostream& operator<<(ostream& os, const Coords& pos);
};
