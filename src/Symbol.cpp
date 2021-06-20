#include "../include/Symbol.h"

//╔
//╗
//╚
//╝
//═
//║
//^
//«
//»
//¥

const char* GetSymbol(Head_Symbol sym)
{
    switch(sym)
    {
       case Head_Symbol::LookUp:
            return "^";
            
        case Head_Symbol::LookLeft:
            return "«";
            
        case Head_Symbol::LookRight:
            return "»";
            
        case Head_Symbol::LookDown:
            return "¥";
    }
}
const char* GetSymbol(Body_Symbol sym)
{
    switch(sym)
    {
        case Body_Symbol::TopLeft:
            return "╔";
            
        case Body_Symbol::TopRight:
            return "╗";
            
        case Body_Symbol::BottomLeft:
            return "╚";
            
        case Body_Symbol::BottomRight:
            return "╝";
            
        case Body_Symbol::Horizontal:
            return "═";
            
        case Body_Symbol::Vertical:
            return "║";
    }
}
