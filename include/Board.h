#pragma once

template<int X, int Y>
class Board
{
    public:
        Board();

    private:
        char pixelArray[X][Y];
};