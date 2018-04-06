#ifndef KRZYZYK_H
#define KRZYZYK_H
#include "Figura.h"
#include <SFML/Graphics.hpp>
class Krzyzyk: public Figura
{
    public:
    float x;
    float y;
    Krzyzyk();
    ~Krzyzyk();
    virtual void rysujFigure(sf::RenderWindow&, float x, float y);
    protected:

    private:
    sf::Texture tekstura;
    sf::Sprite sprite;
};

#endif // KRZYZYK_H
