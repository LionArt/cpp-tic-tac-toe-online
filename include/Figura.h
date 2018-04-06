#ifndef FIGURA_H
#define FIGURA_H
#include <SFML/Graphics.hpp>

class Figura
{
    public:
        Figura();
        virtual void rysujFigure(sf::RenderWindow&, float x, float y)=0;
        virtual ~Figura();

    protected:

    private:
};

#endif // FIGURA_H
