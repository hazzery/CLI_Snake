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

Snake::Snake(int x, int y)
    :length(1), headCoords(Coords(((x+1)/2)-1, ((y + 1) / 2) - 1)), oldHeadCoords(Coords()), headSymbol(Symbols::HeadUp), bodySymbol(Symbols::Vertical)
{
    bodyArray.reserve(2);
    bodyArray.push_back(headCoords);
}

void Snake::Move(const Direction& dir, const Direction& oldDir)
{
    oldHeadCoords = headCoords;
//    cout << "move snake ";

    switch(dir)
    {
        case Up:
//            cout << "up" << endl;
            headCoords.Decrement(Axis::y);
            headSymbol = Symbols::HeadUp;
            switch(oldDir)
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
            headCoords.Increment(Axis::y);
            headSymbol = Symbols::HeadDown;
            switch(oldDir)
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
            headCoords.Decrement(Axis::x);
            headSymbol = Symbols::HeadLeft;
            switch(oldDir)
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
            headCoords.Increment(Axis::x);
            headSymbol = Symbols::HeadRight;
            switch(oldDir)
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

void Snake::Eat(Apple& appl)
{
    length++;
    bodyArray.reserve(bodyArray.capacity() + 1);
    bodyArray.emplace_back(-1, -1);

//    cout << "length increased to: " << length << endl;
    appl.New();
}

void Snake::UpdateBody()
{
    bodyArray.insert(bodyArray.begin(), headCoords);

    tailCoords = bodyArray[length];

    bodyArray.erase(bodyArray.begin() + length);
    
}

const unsigned int Snake::Length() const
{ return length; }

const Coords& Snake::HeadCoords() const
{ return headCoords; }

const int Snake::HeadCoord(const Axis& ax) const
{ return headCoords.Get(ax); }

const Coords& Snake::OldHeadCoords() const
{ return oldHeadCoords; }

const int Snake::OldHeadCoord(const Axis& ax) const
{ return oldHeadCoords.Get(ax); }

const Head_Symbol& Snake::HeadSymbol() const
{ return headSymbol; }

const Body_Symbol& Snake::BodySymbol() const
{ return bodySymbol; }

const vector<Coords>& Snake::BodyArray() const
{ return bodyArray; }

const Coords& Snake::TailCoords() const
{ return tailCoords; }
