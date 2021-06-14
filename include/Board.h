#pragma once

template<int X, int Y>
class Board
{
    public:
        Board();

        char* getPixels();

    private:
        char pixelArray[X][Y];
};