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
    Board<14, 8> board;
    Snake snake(14, 8);
    
    Direction dir = None;

    int loops = 0;
    while (loops < 15)
    {
        board.set(snake.HeadCoords(), snake.HeadSymbol());
        board.print();

        char keyboardInput;
        cin >> keyboardInput;
        dir = (Direction)keyboardInput;
        snake.move(dir);
        
        board.set(snake.OldHeadCoords(), snake.BodySymbol());

        loops++;

    }
//        cout << "(" << snake.OldHeadCoords().get(Axis::x) << ", " << snake.OldHeadCoords().get(Axis::x) << ")" << endl;
}