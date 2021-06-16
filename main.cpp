#include <iostream>
#include "include/Coords.h"
#include "include/Board.h"
#include "include/Snake.h"
#include "src/Board.cpp"
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    Board<14, 8> board;
    Snake snake;
    
    int loops = 0;
    
    while (loops < 15)
    {
        board.set(snake.OldHeadCoords(), '0');
        board.set(snake.HeadCoords(), snake.HeadSymbol());
        
        board.print();
        
    
        int keyStroke = cin.get();
        snake.move((Direction)keyStroke);
        
//        cout << "(" << snake.OldHeadCoords().get(Axis::x) << ", " << snake.OldHeadCoords().get(Axis::x) << ")" << endl;
        
        loops++;
    }
}