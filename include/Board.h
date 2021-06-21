#pragma once

#include "Coords.h"
#include "Symbol.h"

template<int X, int Y>
class Board
{
    public:
        Board();

        void print() const;

        static int constexpr width = X;
        static int constexpr height = Y;

        void set(const Coords& pos, const Head_Symbol sym);
        void set(const Coords& pos, const Body_Symbol sym);
    
        int get(const Coords& pos) const;

    private:
        const char* pixelArray[X][Y];
};
