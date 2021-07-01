#include "../include/Symbol.h"

Symbol::Symbol()
	:icon(' ') {}

Symbol::Symbol(char sym)
	: icon(sym) {}

Symbol::Symbol(const Symbol& sym)
	: icon(sym.icon) {}

char Symbol::Get() const
{ return icon; }