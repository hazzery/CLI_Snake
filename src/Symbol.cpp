#include "../include/Symbol.h"

const char* GetSymbol(Symbol sym)
{
    switch(sym)
    {
        case Symbol::TopLeft:
            return "╔";
            
        case Symbol::TopRight:
            return "╗";
            
        case Symbol::BottomLeft:
            return "╚";
            
        case Symbol::BottomRight:
            return "╝";
            
        case Symbol::Horizontal:
            return "═";
            
        case Symbol::Vertical:
            return "║";
            
        case Symbol::LookUp:
            return "^";
            
        case Symbol::LookLeft:
            return "«";
            
        case Symbol::LookRight:
            return "»";
            
        case Symbol::LookDown:
            return "¥";
    }
}