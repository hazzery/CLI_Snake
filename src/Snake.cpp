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
    :length(1), headCoords(Coords()), oldHeadCoords(Coords()), headSymbol(Head_Symbol()), bodySymbol(Symbols::Vertical)
{/*cout << "constructed empty snake" << endl;*/ }

Snake::Snake(uint8_t _x, uint8_t _y)
    :length(1), headCoords(Coords(((_x+1)/2)-1, ((_y + 1) / 2) - 1)), oldHeadCoords(Coords()), headSymbol(Symbols::HeadUp), bodySymbol(Symbols::Vertical)
{
    bodyArray.reserve(2);
    bodyArray.push_back(headCoords);
}

void Snake::Move(const Direction& _dir, const Direction& _oldDir)
{
    oldHeadCoords = headCoords;
//    cout << "move snake ";

    switch(_dir)
    {
        case Up:
//            cout << "up" << endl;
            headCoords.Decrement(Axis::Y);
            headSymbol = Symbols::HeadUp;
            switch(_oldDir)
            {
            case Up:
                bodySymbol = Symbols::Vertical;
                break;
                
            case Down:
                bodySymbol = Symbols::Vertical;
                break;
                
            case Left:
                bodySymbol = Symbols::BottomLeft;
                break;
                
            case Right:
                bodySymbol = Symbols::BottomRight;
                break;
                
            case None:
                bodySymbol = Symbols::Vertical;
                break;
            }
            break;
            
        case Down:
//            cout << "down" << endl;
            headCoords.Increment(Axis::Y);
            headSymbol = Symbols::HeadDown;
            switch(_oldDir)
            {
            case Up:
                bodySymbol = Symbols::Vertical;
                break;
                
            case Down:
                bodySymbol = Symbols::Vertical;
                break;
                
            case Left:
                bodySymbol = Symbols::TopLeft;
                break;
                
            case Right:
                bodySymbol = Symbols::TopRight;
                break;
                
            case None:
                bodySymbol = Symbols::Vertical;
                break;
            }
            break;
            
        case Left:
//            cout << "left" << endl;
            headCoords.Decrement(Axis::X);
            headSymbol = Symbols::HeadLeft;
            switch(_oldDir)
            {
            case Up:
                bodySymbol = Symbols::TopRight;
                break;
                
            case Down:
                bodySymbol = Symbols::BottomRight;
                break;
                
            case Left:
                bodySymbol = Symbols::Horizontal;
                break;
                
            case Right:
                bodySymbol = Symbols::Horizontal;
                break;
                
            case None:
                bodySymbol = Symbols::Horizontal;
                break;
            }
            break;
            
        case Right:
//            cout << "right" << endl;
            headCoords.Increment(Axis::X);
            headSymbol = Symbols::HeadRight;
            switch(_oldDir)
            {
            case Up:
                bodySymbol = Symbols::TopLeft;
                break;
                
            case Down:
                bodySymbol = Symbols::BottomLeft;
                break;
                
            case Left:
                bodySymbol = Symbols::Horizontal;
                break;
                
            case Right:
                bodySymbol = Symbols::Horizontal;
                break;
                
            case None:
                bodySymbol = Symbols::Horizontal;
                break;
            }
            break;
        case None:
            cout << "Current direction was None :/" << endl;
            break;
    }
}

void Snake::Eat(Apple& _apple)
{
    length++;
    bodyArray.reserve(bodyArray.capacity() + 1);
    bodyArray.emplace_back(0, 0);

//    cout << "length increased to: " << length << endl;
    _apple.RandomisePosition(21, 11);//Fuck, that wasn't supposed to happen :/
}

void Snake::UpdateBody()
{
    bodyArray.insert(bodyArray.begin(), headCoords);

    tailCoords = bodyArray[length];

    bodyArray.erase(bodyArray.begin() + length);
    
}

const unsigned short Snake::Length() const
{ return length; }

const Coords& Snake::HeadCoords() const
{ return headCoords; }

const Coords& Snake::OldHeadCoords() const
{ return oldHeadCoords; }

const Head_Symbol& Snake::HeadSymbol() const
{ return headSymbol; }

const Body_Symbol& Snake::BodySymbol() const
{ return bodySymbol; }

const std::vector<Coords>& Snake::BodyArray() const
{ return bodyArray; }

const Coords& Snake::TailCoords() const
{ return tailCoords; }
