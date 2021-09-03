#pragma once
#include <iostream>
//╔
//╗
//╚
//╝
//═
//║
//⩓
//⩔
//⪡
//⪢

class Symbol
{
public:
    Symbol();
    Symbol(const char * _char);
    Symbol(const Symbol& _sym);

public:
    const char * Get() const;
    
    friend std::ostream& operator<<(std::ostream& _os, const Symbol& _sym);
    friend bool operator==(const Symbol& _sym1, const Symbol& _sym2);
    
    operator int() const;

protected:
    const char * character;
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
    
    extern Body_Symbol TopLeft;
    extern Body_Symbol TopRight;
    extern Body_Symbol BottomLeft;
    extern Body_Symbol BottomRight;
    extern Body_Symbol Horizontal;
    extern Body_Symbol Vertical;
    
    extern Misc_Symbol Apple;
    extern Misc_Symbol Blank;
}
