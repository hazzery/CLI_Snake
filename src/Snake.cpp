#include "../include/Direction.h"
#include "../include/Coords.h"
#include "../include/Symbol.h"
#include "../include/Snake.h"
#include "../include/Axis.h"
#include <iostream>
using std::cout;
using std::endl;

Snake::Snake()
    :length(1), headCoords(Coords()), oldHeadCoords(Coords()), headSymbol(Head_Symbol::LookUp), bodySymbol(Body_Symbol::Vertical)
{/*cout << "constructed empty snake" << endl;*/ }

Snake::Snake(int x, int y)
    :length(1), headCoords(Coords(((x+1)/2)-1, ((y + 1) / 2) - 1)), oldHeadCoords(Coords()), headSymbol(Head_Symbol::LookUp), bodySymbol(Body_Symbol::Vertical)
{
    bodyArray.reserve(2);
    bodyArray.push_back(headCoords);
}

const unsigned int Snake::Length() const
{ return length; }

const Coords& Snake::HeadCoords() const
{ return headCoords; }

const unsigned int Snake::HeadCoord(const Axis& ax) const
{ return headCoords.get(ax); }

const Coords& Snake::OldHeadCoords() const
{ return oldHeadCoords; }

const unsigned int Snake::OldHeadCoord(const Axis& ax) const
{ return oldHeadCoords.get(ax); }

const Head_Symbol& Snake::HeadSymbol() const
{ return headSymbol; }

const Body_Symbol& Snake::BodySymbol() const
{ return bodySymbol; }

const vector<Coords>& Snake::BodyArray() const
{ return bodyArray; }

void Snake::move(const Direction& dir, const Direction& oldDir)
{
    oldHeadCoords = headCoords;
    
//    cout << "move snake ";

    switch(dir)
    {
        case Up:
//            cout << "up" << endl;
            headCoords.decrement(Axis::y);
            headSymbol = Head_Symbol::LookUp;
            
            updateArray();

            switch(oldDir)
            {
                case Up:
                    bodySymbol = Body_Symbol::Vertical;
                    break;
                    
                case Down:
                    bodySymbol = Body_Symbol::Vertical;
                    break;
                    
                case Left:
                    bodySymbol = Body_Symbol::BottomLeft;
                    break;
                    
                case Right:
                    bodySymbol = Body_Symbol::BottomRight;
                    break;
                    
                case None:
                    bodySymbol = Body_Symbol::Vertical;
                    break;
            }
            break;
            
        case Down:
//            cout << "down" << endl;
            headCoords.increment(Axis::y);
            headSymbol = Head_Symbol::LookDown;
            
            updateArray();
            
            switch(oldDir)
            {
                case Up:
                    bodySymbol = Body_Symbol::Vertical;
                    break;
                    
                case Down:
                    bodySymbol = Body_Symbol::Vertical;
                    break;
                    
                case Left:
                    bodySymbol = Body_Symbol::TopLeft;
                    break;
                    
                case Right:
                    bodySymbol = Body_Symbol::TopRight;
                    break;
                    
                case None:
                    bodySymbol = Body_Symbol::Vertical;
                    break;
            }
            break;
            
        case Left:
//            cout << "left" << endl;
            headCoords.decrement(Axis::x);
            headSymbol = Head_Symbol::LookLeft;
            
            updateArray();
            
            switch(oldDir)
            {
                case Up:
                    bodySymbol = Body_Symbol::TopRight;
                    break;
                    
                case Down:
                    bodySymbol = Body_Symbol::BottomRight;
                    break;
                    
                case Left:
                    bodySymbol = Body_Symbol::Horizontal;
                    break;
                    
                case Right:
                    bodySymbol = Body_Symbol::Horizontal;
                    break;
                    
                case None:
                    bodySymbol = Body_Symbol::Horizontal;
                    break;
            }
            break;
            
        case Right:
//            cout << "right" << endl;
            headCoords.increment(Axis::x);
            headSymbol = Head_Symbol::LookRight;
            
            updateArray();
            
            switch(oldDir)
            {
                case Up:
                    bodySymbol = Body_Symbol::TopLeft;
                    break;
                    
                case Down:
                    bodySymbol = Body_Symbol::BottomLeft;
                    break;
                    
                case Left:
                    bodySymbol = Body_Symbol::Horizontal;
                    break;
                    
                case Right:
                    bodySymbol = Body_Symbol::Horizontal;
                    break;
                    
                case None:
                    bodySymbol = Body_Symbol::Horizontal;
                    break;
            }
            break;
        case None:
            cout << "Current direction was None :/" << endl;
            break;
    }
}

void Snake::updateArray()
{
    bodyArray.push_back(headCoords);
    bodyArray.erase(bodyArray.begin() + length - 1);
    
//    cout << "bodyArray now be looking like: ";
//    for (const Coords& pos : bodyArray) {
//        cout << pos << ", ";
//    }
//    cout << endl;
}
