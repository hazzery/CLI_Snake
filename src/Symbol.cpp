#include "../include/Symbol.h"

Symbol::Symbol()
	:character(" ") {}

Symbol::Symbol(const char * sym)
	: character(sym) {}

Symbol::Symbol(const Symbol& sym)
	: character(sym.character) {}

const char * Symbol::Get() const
{ return character; }

std::ostream& operator<<(std::ostream& os, const Symbol& sym)
{
    os << sym.character;
    return os;
}

Symbol::operator int() const
{
    return (int)character[0];
}

bool operator==(const Symbol& sym1, const Symbol& sym2)
{
    return (sym1.character == sym2.character);
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
