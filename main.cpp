#include "include/Direction.h"
#include "include/Coords.h"
#include "include/Symbol.h"
#include "include/Board.h"
#include "include/Snake.h"
#include "src/Board.cpp"
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    static constexpr int const width = 19;
    static constexpr int const height = 11;
    
    Board<width, height> board;
    Snake snake(width, height);
    
    Direction dir = None;
    Direction oldDir = None;

    int loops = 0;
    while (loops < 15)
    {
        board.set(snake.HeadCoords(), snake.HeadSymbol());
        board.print();

        char keyboardInput;
        cin >> keyboardInput;
        dir = (Direction)keyboardInput;
        snake.move(dir, oldDir);
        oldDir = dir;
        
        board.set(snake.OldHeadCoords(), snake.BodySymbol());

//        cout << snake.OldHeadCoords() << endl;
        
        loops++;
    }
}


/*
 Head coords are updated
 check if new head coords are occupied by apple/wall/body
 case apple
    snake.length++
    continue
 
 case wall
    game over (for for standard mode, teleport to opposote end in easy)
 
 case snake
    game over
 
 case none
    continue
 
 add new head coords to body array
 remove bodyArray[length-1]
 */
