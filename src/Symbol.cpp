#include "../include/Symbol.h"

Symbol::Symbol()
	:icon(' ') {}

Symbol::Symbol(char sym)
	: icon(sym) {}

Symbol::Symbol(const Symbol& sym)
	: icon(sym.icon) {}

char Symbol::Get() const
{ return icon; }

Head_Symbol HeadUpSym('^');
Head_Symbol HeadDownSym('V');
Head_Symbol HeadLeftSym('<');
Head_Symbol HeadRightSym('>');

Body_Symbol BodySym('"');

Misc_Symbol AppleSym('@');