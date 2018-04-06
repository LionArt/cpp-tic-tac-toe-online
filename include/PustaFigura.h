#ifndef PUSTAFIGURA_H
#define PUSTAFIGURA_H
#include <Figura.h>

class PustaFigura: public Figura
{
    public:
        virtual ~PustaFigura();
        float x;
        float y;
        virtual void rysujFigure(sf::RenderWindow&, float x, float y);
    protected:
    PustaFigura();
    private:
};

#endif // PUSTAFIGURA_H
