#pragma once
#include "Coords.h"
#include "Symbol.h"

class Apple
{
public:
    /**
     * @brief Constructs apple with coordinates (-1, -1)
    **/
    Apple();

    /**
     * @brief Constructs Apple with specified coordinates
     * 
     * @param pos Coords object to initialize coodinates with
    **/
    Apple(const Coords& pos);

    /**
     * @brief Randomises the cordinates of the apple
    **/
    void New();

public:
    /**
     * @brief gets the coordinates of the apple
     * 
     * @return A Coords object containing the current position of the apple
    **/
    const Coords& Pos();

    /**
     * @brief Gets the symbol representing the apple
     * 
     * @return The Miscelaneous symbol object representing the apple
    **/
    const Misc_Symbol& Sym();

private:
    Coords coords;
    Misc_Symbol sym;
};
