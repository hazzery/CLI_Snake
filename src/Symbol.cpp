#include "../include/Symbol.h"

Symbol::Symbol()
	:character(" ") {}

Symbol::Symbol(const char * _char)
	: character(_char) {}

Symbol::Symbol(const Symbol& _sym)
	: character(_sym.character) {}

const char * Symbol::Get() const
{ return character; }

std::ostream& operator<<(std::ostream& _os, const Symbol& _sym)
{
    _os << _sym.character;
    return _os;
}

Symbol::operator int() const
{
    return (int)character[0];
}

bool operator==(const Symbol& _sym1, const Symbol& _sym2)
{
    return (_sym1.character == _sym2.character);
}

namespace Symbols
{
    Head_Symbol HeadUp("⩓");
    Head_Symbol HeadDown("⩔");
    Head_Symbol HeadLeft("⪡");
    Head_Symbol HeadRight("⪢");
    
    Body_Symbol TopLeft("╔");
    Body_Symbol TopRight("╗");
    Body_Symbol BottomLeft("╚");
    Body_Symbol BottomRight("╝");
    Body_Symbol Horizontal("═");
    Body_Symbol Vertical("║");
    
    Misc_Symbol Apple("");
    Misc_Symbol Blank("_");
};
