#pragma once

#include "Direction.h"
#include "Apple.h"
#include "Snake.h"
#include "Board.h"


template <int X, int Y>
class CLI_Snake
{
public:
    CLI_Snake();

    bool Game();

private:
    Board<X, Y> board;
    Snake snake;
    Apple apple;

    Direction dir;
    Direction oldDir;

    char keyboardInput;
};