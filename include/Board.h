#pragma once

#include "Coords.h"
#include "Symbol.h"

/**
 * @brief class representing the grid in which snake is played on
 * 
 * @tparam X The horizontal width of the board
 * @tparam Y the Vertical height of the board
**/
template<int X, int Y>
class Board
{
public:
    /**
     * @brief Constructs a new Board object
    **/
    Board();

    /**
     * @brief Prints the whole board to the screen
    **/
    void Print() const;

    /**
     * @brief Sets a specified cell in the board to a specified symbol
     * 
     * @param pos A Coords object specifiying which cell should be updated
     * @param sym Any kind of Symbol object to be placed onto the board
    **/
    void Set(const Coords& pos, const Symbol& sym);

    /**
     * @brief Read value at specified position
     * 
     * @param pos Coords object constaining position to read from
     * 
     * @return 0 for empty space, 1 for snake body, 2 for apple, 3 for snake head, or the char value of symbol if anything else is found
    **/
    int Get(const Coords& pos) const;
    
    /**
     * @brief Sets the symbol at specified position to BlankSym
     * 
     * @param pos Coords object containing position of cell to be cleared
    **/
    void Clear(const Coords& pos);

public:
    static int constexpr Width = X;
    static int constexpr Height = Y;

private:
    char pixelArray[X][Y];
};
