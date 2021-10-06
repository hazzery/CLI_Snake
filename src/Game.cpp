#include "../include/Game.h"
#include "Board.cpp"
using std::cout;
using std::endl;
using std::cin;

template <uint8_t _width, uint8_t _height>
CLI_Snake<_width, _height>::CLI_Snake()
    :snake(_width, _height), apple({ static_cast<uint8_t>(std::rand() % _width), static_cast<uint8_t>(std::rand() % _height) }), dir(Direction::None), oldDir(Direction::None), keyboardInput(0), score(0)
{
    board.Set(snake.HeadCoords(), snake.HeadSymbol());
    board.Set(apple.Pos(), apple.Sym());
    board.Print();
}

template <uint8_t _width, uint8_t _height>
CLI_Snake<_width, _height>::CLI_Snake(const Difficulty& _difficulty)
    :CLI_Snake()
{
        switch (_difficulty) {
            case Difficulty::Easy:
                timeDelay = 200;
                break;
                
            case Difficulty::Normal:
                timeDelay = 150;
                break;
                
            case Difficulty::Hard:
                timeDelay = 100;
                break;
                
            default:
                break;
        }
    
    while (/*!_kbhit()*/0);
}

template <uint8_t _width, uint8_t _height>
short CLI_Snake<_width, _height>::Game()
{
    for (;;)
    {
        snake.Move(dir, oldDir); //Move the snake in the chosen direction
        oldDir = dir; //Store the previos movement direction.
        
        switch (board.Get(snake.HeadCoords())) //Check what is currently at the co-ordinates the snake just moved to
        {
            case -1: //Snake hit a wall
                cout << "Get good! That was a wall, try not doing that next time " << endl;
                return score;
                
            case 0: //Empty space
                break;
                
            case 1: //Snake crashed into itself
                cout << "Ha! Retard. You crashed into yourself" << endl;
                return score;
                
            case 2: //Found an apple
                score++;
                snake.Eat(apple);
                break;
        }
        
        snake.UpdateBody(); //Update the coordinates stored in the snake body vector
        
        board.Set(snake.HeadCoords(), snake.HeadSymbol()); //Move snake's head to new pos
        board.Set(snake.OldHeadCoords(), snake.BodySymbol()); //Show snake's previous head coordinates as body
        board.Clear(snake.TailCoords()); //Maintain same snake body length
        
        board.Set(apple.Pos(), apple.Sym()); //show apple
        
    //    cout << "\x1B[1J\x1B[H"; //Clear console
        
        board.Print(); //Display board in console
        
        cin >> keyboardInput;
        switch(keyboardInput)
        {
            case 'w':
                dir = Direction::Up;
                break;
            case 'a':
                dir = Direction::Left;
                break;
            case 's':
                dir = Direction::Down;
                break;
            case 'd':
                dir = Direction::Right;
                break;
        }
        
        return true;
    }
}
