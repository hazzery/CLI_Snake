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
 Single threaded order of operations.
 
 Head coords are updated
 check if new head coords are occupied by apple/wall/body
 case apple
    snake.length++
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
