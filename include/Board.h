#pragma once

#include "Coords.h"
#include "Symbol.h"

template<int X, int Y>
class Board
{
public:
    Board();

    void Print() const;

    void Set(const Coords& pos, const Head_Symbol sym);
    void Set(const Coords& pos, const Body_Symbol sym);

    int Get(const Coords& pos) const;
    
    void Clear(const Coords& pos);

public:
    static int constexpr Width = X;
    static int constexpr Height = Y;

private:
    const char* pixelArray[X][Y];
};
