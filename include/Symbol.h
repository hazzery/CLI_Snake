#pragma once
#include <iostream>
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

class Symbol
{
public:
    Symbol();
    Symbol(char sym);
    Symbol(const Symbol& sym);

public:
    char Get() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Symbol& sym);
    friend bool operator==(const Symbol& sym1, const Symbol& sym2);
    
    operator int() const;

protected:
    char icon;
};

class Head_Symbol : public Symbol
{
    using Symbol::Symbol;
    //I just realized that this probably means that I could instanciate a headsymbol by passing a body symbol.
    //If that is the case, the copy construcotr should probably be private and each subclass should have its own copy constructor
};

class Body_Symbol : public Symbol
{
    using Symbol::Symbol;
};

class Misc_Symbol : public Symbol
{
    using Symbol::Symbol;
};


namespace Symbols
{
    extern Head_Symbol HeadUp;
    extern Head_Symbol HeadDown;
    extern Head_Symbol HeadLeft;
    extern Head_Symbol HeadRight;
    
    extern Body_Symbol Body;
    
    extern Misc_Symbol Apple;
    extern Misc_Symbol Blank;
}
