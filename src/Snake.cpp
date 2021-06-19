#include "../include/Direction.h"
#include "../include/Coords.h"
#include "../include/Symbol.h"
#include "../include/Snake.h"
#include "../include/Axis.h"
#include <iostream>
using std::cout;
using std::endl;

Snake::Snake()
    :headCoords(Coords()), oldHeadCoords(Coords()), headSymbol(Symbol::LookUp), bodySymbol(Symbol::Vertical)
{ cout << "constructed empty snake" << endl; }

Snake::Snake(int x, int y)
    : headCoords(Coords(((x+1)/2)-1, ((y + 1) / 2) - 1)), oldHeadCoords(Coords()), headSymbol(Symbol::LookUp), bodySymbol(Symbol::Vertical) 
{ cout << "constructed snake at pos (" << ((x + 1) / 2) - 1 << ", " << ((y + 1) / 2) - 1 << ")" << endl; }

void Snake::move(Direction dir)
{
    oldHeadCoords = headCoords;
    
    cout << "move snake ";

    switch(dir)
    {
        case Up:
            headCoords.decrement(Axis::y);
            headSymbol = Symbol::LookUp;
            switch(oldDir)
            {
                case Up:
                    bodySymbol = Symbol::Vertical;
                    break;
                    
                case Down:
                    bodySymbol = Symbol::Vertical;
                    break;
                    
                case Left:
                    bodySymbol = Symbol::BottomLeft;
                    break;
                    
                case Right:
                    bodySymbol = Symbol::BottomRight;
                    break;
                    
                case None:
                    bodySymbol = Symbol::Vertical;
                    break;
            }
            break;
            
        case Down:
            headCoords.increment(Axis::y);
            headSymbol = Symbol::LookDown;
            switch(oldDir)
            {
                case Up:
                    bodySymbol = Symbol::Vertical;
                    break;
                    
                case Down:
                    bodySymbol = Symbol::Vertical;
                    break;
                    
                case Left:
                    bodySymbol = Symbol::TopLeft;
                    break;
                    
                case Right:
                    bodySymbol = Symbol::TopRight;
                    break;
                    
                case None:
                    bodySymbol = Symbol::Vertical;
                    break;
            }
            break;
            
        case Left:
            headCoords.decrement(Axis::x);
            headSymbol = Symbol::LookLeft;
            switch(oldDir)
            {
                case Up:
                    bodySymbol = Symbol::TopRight;
                    break;
                    
                case Down:
                    bodySymbol = Symbol::BottomRight;
                    break;
                    
                case Left:
                    bodySymbol = Symbol::Horizontal;
                    break;
                    
                case Right:
                    bodySymbol = Symbol::Horizontal;
                    break;
                    
                case None:
                    bodySymbol = Symbol::Horizontal;
                    break;
            }
            break;
            
        case Right:
            headCoords.increment(Axis::x);
            headSymbol = Symbol::LookRight;
            switch(oldDir)
            {
                case Up:
                    bodySymbol = Symbol::TopLeft;
                    break;
                    
                case Down:
                    bodySymbol = Symbol::BottomLeft;
                    break;
                    
                case Left:
                    bodySymbol = Symbol::Horizontal;
                    break;
                    
                case Right:
                    bodySymbol = Symbol::Horizontal;
                    break;
                    
                case None:
                    bodySymbol = Symbol::Horizontal;
                    break;
            }
            break;
        case None:
            cout << "Current direction was None :/" << endl;
            break;
    }
}

Coords Snake::HeadCoords() const
{ return headCoords; }

Coords Snake::OldHeadCoords() const
{ return oldHeadCoords; }

int Snake::HeadCoord(Axis ax) const
{ return headCoords.get(ax); }

int Snake::OldHeadCoord(Axis ax) const
{ return oldHeadCoords.get(ax); }

Symbol Snake::HeadSymbol() const
{ return headSymbol; }

Symbol Snake::BodySymbol() const
{ return bodySymbol; }