#include "include/Direction.h"
#include "include/Coords.h"
#include "include/Symbol.h"
#include "include/Board.h"
#include "include/Snake.h"
#include "include/Apple.h"
#include "include/Game.h"
#include "src/Board.cpp"
#include "src/Game.cpp"
#include "Windows.h"
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::cout;
using std::endl;
using std::cin;
/*
int main()
{
    static constexpr int const width = 21;
    static constexpr int const height = 11;

    Board<width, height> board;
    Snake snake(width, height);
    Apple apple({ 6, 5 });

    Direction dir = None;
    Direction oldDir = None;

    void gameOver();

    cout << "Hello!" << endl << "Welcome to CLI_Snake" << endl << endl << "Please press enter" << endl;
    cin.get();
    cout << "\x1B[3J\x1B[H";//Clear console

    board.Set(snake.HeadCoords(), snake.HeadSymbol());
    board.Set(apple.Pos(), apple.Sym());
    board.Print();

    char keyboardInput;
    cin >> keyboardInput;
    dir = (Direction)keyboardInput;

    int loops = 0;
    while (snake.Length() < 100)
    {
        snake.Move(dir, oldDir);
        oldDir = dir;

        //TODO: find out why initializing snake length to 3 breaks program :/
        //TODO: Make Game auto move withough keyboard input.

        switch (board.Get(snake.HeadCoords()))
        {
        case -1:
            gameOver();
            cout << "Get good! That was a wall, try not doing that next time " << endl;
            return 3;

        case 0:
            break;

        case 1:
            gameOver();
            cout << "Ha! Retard. You crashed into yourself" << endl;
            return 2;

        case 2:
            snake.Eat(apple);
            break;
        }

        snake.UpdateBody();

        board.Set(snake.HeadCoords(), snake.HeadSymbol());
        board.Set(snake.OldHeadCoords(), snake.BodySymbol());
        board.Clear(snake.TailCoords());

        board.Set(apple.Pos(), apple.Sym());

        cout << "\x1B[3J\x1B[H";//Clear console

        board.Print();

        loops++;

        sleep_for(milliseconds(150));

        if (_kbhit()) // If key hit
        {
            keyboardInput = _getch();
            dir = (Direction)keyboardInput;
        }

    }
}
*/

int main()
{
    CLI_Snake<21, 11> game;
}

void gameOver()
{
    cout << "Game!" << endl;
}

/*
 Single threaded order of operations.

 Head coords are updated
 check if new head coords are occupied by apple/wall/body
 case apple
    snake.length++
    new apple
    continue

 case wall
    game over (for standard difficulty, teleport to opposote side in easy)

 case snake
    game over

 case none
    continue

 add new head coords to body array
 remove bodyArray[length-1]

 Update screen
 */

 /*
  (probably bad) Idea for multi threading

  the main thread focuses plays the whole game without any visual output.
  It never ever reads or writes to the board class.

  Drawing on the board is entirely handled by a sperate thread,
  which is constantly checking the Coords values from the main thread,
  updating the symbols onto the board accordingly.
  */
