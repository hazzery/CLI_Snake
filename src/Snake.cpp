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
    :length(1), headCoords(Coords()), oldHeadCoords(Coords()), headSymbol(Head_Symbol()), bodySymbol(Body_Symbol())
{/*cout << "constructed empty snake" << endl;*/ }

Snake::Snake(int x, int y)
    :length(1), headCoords(Coords(((x+1)/2)-1, ((y + 1) / 2) - 1)), oldHeadCoords(Coords()), headSymbol(HeadUpSym), bodySymbol(Body_Symbol())
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
            headSymbol = HeadUpSym;
            
            updateBody();

            bodySymbol = BodySym;
            break;
            
        case Down:
//            cout << "down" << endl;
            headCoords.Increment(Axis::y);
            headSymbol = HeadDownSym;
            
            updateBody();
            
            bodySymbol = BodySym;
            break;
            
        case Left:
//            cout << "left" << endl;
            headCoords.Decrement(Axis::x);
            headSymbol = HeadLeftSym;
            
            updateBody();
            
            bodySymbol = BodySym;
            break;
            
        case Right:
//            cout << "right" << endl;
            headCoords.Increment(Axis::x);
            headSymbol = HeadRightSym;
            
            updateBody();
            
            bodySymbol = BodySym;
            break;
        case None:
            cout << "Current direction was None :/" << endl;
            break;
    }
}

void Snake::Eat(Apple& appl)
{
    length++;

    appl.New();
}

const unsigned int Snake::Length() const
{ return length; }

const Coords& Snake::HeadCoords() const
{ return headCoords; }

const unsigned int Snake::HeadCoord(const Axis& ax) const
{ return headCoords.Get(ax); }

const Coords& Snake::OldHeadCoords() const
{ return oldHeadCoords; }

const unsigned int Snake::OldHeadCoord(const Axis& ax) const
{ return oldHeadCoords.Get(ax); }

const Head_Symbol& Snake::HeadSymbol() const
{ return headSymbol; }

const Body_Symbol& Snake::BodySymbol() const
{ return bodySymbol; }

const vector<Coords>& Snake::BodyArray() const
{ return bodyArray; }

const Coords& Snake::TailCoords() const
{ return tailCoords; }

void Snake::updateBody()
{
    bodyArray.push_back(headCoords);
    
    tailCoords = bodyArray[length - 1];
    
    bodyArray.erase(bodyArray.begin() + length - 1);
    
    //cout << "bodyArray now be looking like: ";
    //for (const Coords& pos : bodyArray) {
    //    cout << pos << ", ";
    //}
    //cout << endl;
}

