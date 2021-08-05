#include "../include/Game.h"
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

template <int X, int Y>
CLI_Snake<X, Y>::CLI_Snake()
    :snake(X, Y), apple({ std::rand() % X, std::rand() % Y }), dir(Direction::None), oldDir(Direction::None), keyboardInput(0)
{
	board.Set(snake.HeadCoords(), snake.HeadSymbol());
	board.Set(apple.Pos(), apple.Sym());
	board.Print();

    while (!_kbhit());
}

template <int X, int Y>
bool CLI_Snake<X, Y>::Game()
{
        snake.Move(dir, oldDir); //Move the snake in the chosen direction
        oldDir = dir; //Store the previos movement direction.

        switch (board.Get(snake.HeadCoords())) //Check what is currently at the co-ordinates the snake just moved to
        {
        case -1: //Snake hit a wall
            cout << "Get good! That was a wall, try not doing that next time " << endl;
            return false;

        case 0: //Empty space
            break;

        case 1: //Snake crashed into itself
            cout << "Ha! Retard. You crashed into yourself" << endl;
            return false;

        case 2: //Found an apple
            snake.Eat(apple);
            break;
        }

        snake.UpdateBody(); //Update the coordinates stored in the snake body vector

        board.Set(snake.HeadCoords(), snake.HeadSymbol()); //Move snake's head to new pos
        board.Set(snake.OldHeadCoords(), snake.BodySymbol()); //Show snake's previous head coordinates as body
        board.Clear(snake.TailCoords()); //Maintain same snake body length

        board.Set(apple.Pos(), apple.Sym()); //show apple

        cout << "\x1B[1J\x1B[H"; //Clear console

        board.Print(); //Display board in console

        if (_kbhit()) //If the keyboard is being pressed
        {
            keyboardInput = _getch();
            switch (keyboardInput)
            {
            case 119:
                dir = Direction::Up;
                break;
            case 115:
                dir = Direction::Down;
                break;
            case 97:
                dir = Direction::Left;
                break;
            case 100:
                dir = Direction::Right;
                break;
            default:
                break;
            }
        }

        return true;
}