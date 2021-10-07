#include "../include/Direction.h"
#include "../include/Coords.h"
#include "../include/Symbol.h"
#include "../include/Apple.h"
#include "../include/Snake.h"
#include "../include/Axis.h"
#include <iostream>
using std::cout;
using std::endl;

Snake::Snake()
    :length(1), headCoords(Coords()), oldHeadCoords(Coords()), headSymbol(Head_Symbol()), bodySymbol(BodySym) {} //Defaults the values of Snake member values

Snake::Snake(int x, int y)
    :length(1), headCoords(Coords(((x+1)/2)-1, ((y + 1) / 2) - 1)), oldHeadCoords(Coords()), headSymbol(HeadUpSym), bodySymbol(BodySym) //Sets the snake's to to centre of the board
{
    bodyArray.reserve(2);   //Allocates two memory slots for the boady of the snake
    bodyArray.push_back(headCoords);    //Places the coordinates of the snake's head into the array of body coordinates
}

void Snake::Move(const Direction& dir)
{
    switch(dir) //Updates the snake's head coordinates and head symbol based on direction of movement
    {
        case Direction::Up:
            headCoords.Decrement(Axis::y);
            headSymbol = HeadUpSym;
            break;
            
        case Direction::Down:
            headCoords.Increment(Axis::y);
            headSymbol = HeadDownSym;
            break;
            
        case Direction::Left:
            headCoords.Decrement(Axis::x);
            headSymbol = HeadLeftSym;
            break;
            
        case Direction::Right:
            headCoords.Increment(Axis::x);
            headSymbol = HeadRightSym;
            break;

        case Direction::None:
            cout << "Current direction was None :/" << endl;
            break;
    }
}

void Snake::Eat(Apple& appl)
{
    length++;   //Increases leangth of snake
    bodyArray.reserve(bodyArray.capacity() + 1);    //increaces capacity of vector by one
    bodyArray.emplace_back(-1, -1); //adds empty coordinates to end of body as to not disrupt length of snake on screen when UpdateBody is called

    appl.New(); //Randomises the coodinates of the apple
}

void Snake::UpdateBody()
{
    bodyArray.insert(bodyArray.begin(), headCoords);    //Places the snake's head's new coordinates to top of body array

    tailCoords = bodyArray[length]; //Saves the coordinates of the last element as the snake's tail

    bodyArray.erase(bodyArray.begin() + length);    //Removes last element of snake's body
}

const unsigned int Snake::Length() const
{ return length; }  //Gets the length of the snake

const Coords& Snake::HeadCoords() const
{ return headCoords; }  //Gets the coordinates of the snake's head

const Coords& Snake::OldHeadCoords() const
{ return oldHeadCoords; }   //Gets the previous coordinates of snake's head

const Head_Symbol& Snake::HeadSymbol() const
{ return headSymbol; }  //Gets the symbol representing the snake's head

const Body_Symbol& Snake::BodySymbol() const
{ return bodySymbol; }  //Gets the symbol representing the snake's body

const vector<Coords>& Snake::BodyArray() const
{ return bodyArray; }   //Returns the snake's body vector

const Coords& Snake::TailCoords() const
{ return tailCoords; }  //Rrturns the coordinates of the snake's tail