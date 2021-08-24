#include "../include/Symbol.h"

Symbol::Symbol()
	:icon(" ") {}

Symbol::Symbol(const char * sym)
	: icon(sym) {}

Symbol::Symbol(const Symbol& sym)
	: icon(sym.icon) {}

const char * Symbol::Get() const
{ return icon; }

std::ostream& operator<<(std::ostream& os, const Symbol& sym)
{
    os << sym.icon;
    return os;
}

Symbol::operator int() const
{
    return (int)(char)icon;
}

bool operator==(const Symbol& sym1, const Symbol& sym2)
{
    return (sym1.icon == sym2.icon);
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
    
    Misc_Symbol Apple("🍎");
    Misc_Symbol Blank("_");
};
