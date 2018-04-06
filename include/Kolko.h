#ifndef KOLKO_H
#define KOLKO_H
#include "Figura.h"
#include <SFML/Graphics.hpp>
class Kolko: public Figura
{
    public:
    float x;
    float y;
    Kolko();
    ~Kolko();
    virtual void rysujFigure(sf::RenderWindow&, float x, float y);
    protected:

    private:
    sf::Texture tekstura;
    sf::Sprite sprite;
};

#endif // KOLKO_H
