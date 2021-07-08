#pragma once

#include "Coords.h"
#include "Symbol.h"

template<int X, int Y>
class Board
{
public:
    Board();

    void Print() const;

    void Set(const Coords& pos, const Symbol& sym);

    int Get(const Coords& pos) const;
    
    void Clear(const Coords& pos);

public:
    static int constexpr Width = X;
    static int constexpr Height = Y;

private:
    char pixelArray[X][Y];
};
