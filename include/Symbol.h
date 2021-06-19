#pragma once

enum class Symbol
{
    TopLeft,
    TopRight,
    BottomLeft,
    BottomRight,
    Horizontal,
    Vertical,
    LookUp,
    LookLeft,
    LookRight,
    LookDown,
};

extern const char* GetSymbol(Symbol sym);