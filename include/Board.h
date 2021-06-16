#pragma once

template<int X, int Y>
class Board
{
    public:
        Board();

        void print();

    private:
        char pixelArray[X][Y];
};