#pragma once

#include "Coords.h"
#include "Symbol.h"

template<uint8_t _width, uint8_t _height>
class Board
{
public:
    Board();

    void Print() const;

    void Set(const Coords& _pos, const Symbol& _sym);

    int8_t Get(const Coords& _pos) const;
    
    void Clear(const Coords& _pos);
    
    static constexpr uint8_t Width();
    static constexpr uint8_t Height();

private:
    Symbol array[_width][_height];
};
