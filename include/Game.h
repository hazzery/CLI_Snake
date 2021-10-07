#pragma once

#include "Direction.h"
#include "Apple.h"
#include "Snake.h"
#include "Board.h"

/**
 * @brief Class wrapper that holds all of the Snake game logic
 * 
 * @tparam X The horizontal width of the game board
 * @tparam Y The vertical height of the game board
**/
template <int X, int Y>
class CLI_Snake
{
public:
    /**
     * @brief constructs new Game object
    **/
    CLI_Snake();

    /**
     * @brief runs the game logic
     * 
     * Runninng Game() will not loop, it is synchronus with the surrounding code so therefor must be placed in a while loop
     * while(CLI_Snake.Game()) does the trick, except you'll need some kind of delay
     * If you #include<chrono> and <thread> you can std::this_thread::sleep_for(milliseconds(150))
     * Obvoiusly you can play with the 150, thats just the speed i'm running
     * 
     * @return wether or not the game should continue to run
    **/
    bool Game();

private:
    Board<X, Y> board;
    Snake snake;
    Apple apple;

    Direction dir;
    Direction oldDir;

    char keyboardInput;
};