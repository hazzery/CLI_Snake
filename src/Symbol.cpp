#include "../include/Symbol.h"

Symbol::Symbol()
	:icon(' ') {}	//Sets the default value for a symbol to an empty char

Symbol::Symbol(char sym)
	: icon(sym) {}	//Sets the value of the symbol to a specified char

Symbol::Symbol(const Symbol& sym)
	: icon(sym.icon) {}	//Copy constructor for Symbol

char Symbol::Get() const
{ return icon; }	//Gets the char value of the Symbol

Head_Symbol HeadUpSym('^');		//Symbol to represent the head of the snake facing upwards
Head_Symbol HeadDownSym('V');	//Symbol to represent the head of the snake facing downwards
Head_Symbol HeadLeftSym('<');	//Symbol to represent the head of the snake facing left
Head_Symbol HeadRightSym('>');	//Symbol to represent the head of the snake facing right

Body_Symbol BodySym('"');		//Symbol to represent the body of the snake

Misc_Symbol AppleSym('@');		//Symbol to represent the apple
Misc_Symbol BlankSym('_');		//Symbol to represent an enpty cell