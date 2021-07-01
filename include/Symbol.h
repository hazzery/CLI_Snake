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

    char Get() const;

private:
    char icon;
};

class Head_Symbol : public Symbol
{
    using Symbol::Symbol;
    using Symbol::Get;
};

class Body_Symbol : public Symbol
{
    using Symbol::Symbol;
    using Symbol::Get;
};

class Misc_Symbol : public Symbol
{
    using Symbol::Symbol;
    using Symbol::Get;
};

extern Head_Symbol HeadUpSym;
extern Head_Symbol HeadDownSym;
extern Head_Symbol HeadLeftSym;
extern Head_Symbol HeadRightSym;

extern Body_Symbol BodySym;

extern Misc_Symbol AppleSym;