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

enum class Head_Symbol
{
    LookUp,
    LookLeft,
    LookRight,
    LookDown
};

enum class Body_Symbol
{
    TopLeft,
    TopRight,
    BottomLeft,
    BottomRight,
    Horizontal,
    Vertical
};

extern const char* GetSymbol(const Head_Symbol sym);
extern const char* GetSymbol(const Body_Symbol sym);
