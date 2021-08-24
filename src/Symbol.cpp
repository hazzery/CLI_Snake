#include "../include/Symbol.h"

Symbol::Symbol()
	:icon(' ') {}

Symbol::Symbol(char sym)
	: icon(sym) {}

Symbol::Symbol(const Symbol& sym)
	: icon(sym.icon) {}

char Symbol::Get() const
{ return icon; }

std::ostream& operator<<(std::ostream& os, const Symbol& sym)
{
    os << sym.icon;
    return os;
}

Symbol::operator int() const
{
    return (int)icon;
}

bool operator==(const Symbol& sym1, const Symbol& sym2)
{
    return (sym1.icon == sym2.icon);
}

namespace Symbols
{
    Head_Symbol HeadUp('^');
    Head_Symbol HeadDown('V');
    Head_Symbol HeadLeft('<');
    Head_Symbol HeadRight('>');
    
    Body_Symbol Body('"');
    
    Misc_Symbol Apple('@');
    Misc_Symbol Blank('_');
};
