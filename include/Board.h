#pragma once

#include "Coords.h"
#include "Symbol.h"

template<uint8_t width, uint8_t height>
class Board
{
public:
    Board();

    void Print() const;

    void Set(const Coords& pos, const Symbol& sym);

    int8_t Get(const Coords& pos) const;
    
    void Clear(const Coords& pos);
    
    uint8_t Width();
    uint8_t Height();

private:
    Symbol array[width][height];
};
