#include "../include/FabrykaFigur.h"
FabrykaFigur::FabrykaFigur()
{
    //ctor
}

FabrykaFigur::~FabrykaFigur()
{
    //dtor
}

Figura* FabrykaFigur::NowaFigura (int numerFigury)
{
    switch(numerFigury)
    {
        case 0:
            return new Kolko;
        case 1:
            return new Krzyzyk;
        default:
            return new PustaFigura;
    }
}
