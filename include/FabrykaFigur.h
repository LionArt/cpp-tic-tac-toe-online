#ifndef FABRYKAFIGUR_H
#define FABRYKAFIGUR_H
#include <Figura.h>
#include <Kolko.h>
#include <Krzyzyk.h>
#include <PustaFigura.h>

class FabrykaFigur
{
    public:
        FabrykaFigur();
        ~FabrykaFigur();
        static Figura* NowaFigura (int numerFigury);
};

#endif // FABRYKAFIGUR_H
