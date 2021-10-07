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

/**
 * @brief Class to abstract symbols from their underlying type (char)
**/
class Symbol
{
public:
    /**
     * @brief Creates a new Sybol object with specified value
     * 
     * @param sym The char which the Symbol uses to display  
    **/
    Symbol(char sym);

    /**
     * @brief Symbol copy constructor
     * 
     * @param sym symbol to be coppied
    **/
    Symbol(const Symbol& sym);

public:
    /**
     * @brief Gets the underlying char
     * 
     * @return The underlying char for the Symbol 
    **/
    char Get() const;

private:
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