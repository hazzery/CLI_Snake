#pragma once

template<int X, int Y>
class Board
{
    public:
        Board();

        void print();

        static constexpr int width = X;
        static constexpr int height = Y;

    private:
        char pixelArray[X][Y];
};