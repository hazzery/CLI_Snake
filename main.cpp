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

    board.print();
}