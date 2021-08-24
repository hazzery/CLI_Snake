#pragma once
//};
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
    
    explicit operator int() const;

protected:
    char icon;
};

class Head_Symbol : public Symbol
{
    using Symbol::Symbol;
};

class Body_Symbol : public Symbol
{
    using Symbol::Symbol;
};

class Misc_Symbol : public Symbol
{
    using Symbol::Symbol;
};

extern Head_Symbol HeadUpSym;
extern Head_Symbol HeadDownSym;
extern Head_Symbol HeadLeftSym;
extern Head_Symbol HeadRightSym;

extern Body_Symbol BodySym;

extern Misc_Symbol AppleSym;
extern Misc_Symbol BlankSym;