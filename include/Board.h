#pragma once

template<int X, int Y>
class Board
{
    public:
        Board();

        void print();

        static int constexpr width = X;
        static int constexpr height = Y;

        void set(Coords pos, unsigned char symbol);

    private:
        char pixelArray[X][Y];
};