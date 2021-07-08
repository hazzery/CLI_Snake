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

//⩓
//⩔
//⪡
//⪢

const char* GetSymbol(const Head_Symbol sym)
{
    switch(sym)
    {
       case Head_Symbol::LookUp:
            return "⩓";
            
        case Head_Symbol::LookLeft:
            return "⪡";
            
        case Head_Symbol::LookRight:
            return "⪢";
            
        case Head_Symbol::LookDown:
            return "⩔";
    }

    return "You done goofed my friend, this should have been a Head_Symbol, but now its an unfunny error message!";
}
const char* GetSymbol(const Body_Symbol sym)
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
    return "You done goofed my friend, this should have been a Body_Symbol, but now its an unfunny error message!";
}
