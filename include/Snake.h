#pragma once

#include "Direction.h"
#include "Coords.h"
#include "Symbol.h"
#include "Apple.h"
#include <vector>
using std::vector;

/**
 * @brief Class to hold all functionality related to the snake itself
**/
class Snake
{
public:
    /**
     * @brief Creates a new Snake object with head at (-1, -1)
    **/
    Snake();

    /**
     * @brief Created a new snake with head set to the centre of the board
     * 
     * @param x The width of the board
     * @param y the height of the board
    **/
    Snake(const int x, const int y);
    
    /**
     * @brief Moves the snake one unit in the specified direction
     * 
     * @param dir The direction the snake should move
    **/
    void Move(const Direction& dir);

    /**
     * @brief Consumes an apple, increasing length by one
     * 
     * @param appl The apple to be eaten by snake
    **/
    void Eat(Apple& appl);

    /**
     * @brief Puts new headCoords into body vector and removes tail element
    **/
    void UpdateBody();

public:
    /**
     * @brief Gets the length of the snake
     * 
     * @return The length of the snake
    **/
    const unsigned int Length() const;
    
    /**
     * @brief Gets the position of the snake's head
     * 
     * @return Coords object containing the Coordinates of snake's head
    **/
    const Coords& HeadCoords() const;

    /**
     * @brief Gets the previous position of the snake's head
     * 
     * @return Coords object containing previous position of the snake's head
    **/
    const Coords& OldHeadCoords() const;
    
    /**
     * @brief Gets the symbol representing the snake's head
     * 
     * @return The Head_Symbol object currently representing the snake's head
    **/
    const Head_Symbol& HeadSymbol() const;

    /**
     * @brief Gets the symbol representing the snake's body
     * 
     * @return The Body_Symbol object currently representing the snake's body
    **/
    const Body_Symbol& BodySymbol() const;

    /**
     * @brief Gets the vector holding the body coordinates
     * 
     * @return a std::vector with all of the coordinates which make up the snake's body
    **/
    const vector<Coords>& BodyArray() const;
    
    /**
     * @brief Get the position of the snakes's tail
     * 
     * @return Coords object holding position on snake's tail
    **/
    const Coords& TailCoords() const;
    
    
private:
    int length;
    
    Coords headCoords;
    Coords oldHeadCoords;

    Head_Symbol headSymbol;
    Body_Symbol bodySymbol;
    
    vector<Coords> bodyArray;
    
    Coords tailCoords;
    
};
