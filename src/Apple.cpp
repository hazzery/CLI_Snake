#include "../include/Apple.h"

Apple::Apple()
    :coords(Coords()), sym(AppleSym) {} //Gives new apple blank coordinates and symbol

Apple::Apple(const Coords& pos)
    :coords(pos), sym(AppleSym) {}  //Gives new Apple specified coordinates and symnbol

void Apple::New()
{
    coords = Coords({ std::rand() % 21, std::rand() % 11 });    //Gives the apple a new, randomised pair of coordinates
}

const Coords& Apple::Pos()
{ return coords; }  //Gets the cuurent position of the apple

const Misc_Symbol& Apple::Sym()
{ return sym; } //Gets the apple's symbol