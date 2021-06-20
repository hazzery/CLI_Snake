#include "../include/Direction.h"
#include "../include/Coords.h"
#include "../include/Symbol.h"
#include "../include/Snake.h"
#include "../include/Axis.h"
#include <iostream>
using std::cout;
using std::endl;

Snake::Snake()
    :headCoords(Coords()), oldHeadCoords(Coords()), headSymbol(Head_Symbol::LookUp), bodySymbol(Body_Symbol::Vertical)
{ cout << "constructed empty snake" << endl; }

Snake::Snake(int x, int y)
    : headCoords(Coords(((x+1)/2)-1, ((y + 1) / 2) - 1)), oldHeadCoords(Coords()), headSymbol(Head_Symbol::LookUp), bodySymbol(Body_Symbol::Vertical) 
{ cout << "constructed snake at pos (" << ((x + 1) / 2) - 1 << ", " << ((y + 1) / 2) - 1 << ")" << endl; }

int Snake::Length() const
{ return length; }

Coords Snake::HeadCoords() const
{ return headCoords; }

int Snake::HeadCoord(Axis ax) const
{ return headCoords.get(ax); }

Coords Snake::OldHeadCoords() const
{ return oldHeadCoords; }

int Snake::OldHeadCoord(Axis ax) const
{ return oldHeadCoords.get(ax); }

Head_Symbol Snake::HeadSymbol() const
{ return headSymbol; }

Body_Symbol Snake::BodySymbol() const
{ return bodySymbol; }

vector<Coords> Snake::BodyArray() const
{ return bodyArray; }

void Snake::move(Direction dir, Direction oldDir)
{
    oldHeadCoords = headCoords;
    
    cout << "move snake ";

    switch(dir)
    {
        case Up:
            cout << "up" << endl;
            headCoords.decrement(Axis::y);
            headSymbol = Head_Symbol::LookUp;
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
            cout << "down" << endl;
            headCoords.increment(Axis::y);
            headSymbol = Head_Symbol::LookDown;
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
            cout << "left" << endl;
            headCoords.decrement(Axis::x);
            headSymbol = Head_Symbol::LookLeft;
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
            cout << "right" << endl;
            headCoords.increment(Axis::x);
            headSymbol = Head_Symbol::LookRight;
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
