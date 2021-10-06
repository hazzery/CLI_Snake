#pragma once

#include "Direction.h"
#include "Apple.h"
#include "Snake.h"
#include "Board.h"

enum Difficulty : int8_t
{
    Null = -1,
    Easy = 1,
    Normal,
    Hard
};


template <uint8_t _width, uint8_t _height>
class CLI_Snake
{
public:
    CLI_Snake();
    CLI_Snake(const Difficulty& _difficulty);
    
    short Game();
    
private:
    Board<_width, _height> board;
    Snake snake;
    Apple apple;
    
    Direction dir;
    Direction oldDir;
    
    Difficulty difficulty;
    char keyboardInput;
    unsigned short timeDelay;
    
    short score;
};
