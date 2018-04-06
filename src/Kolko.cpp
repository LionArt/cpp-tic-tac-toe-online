#include "../include/Kolko.h"

Kolko::Kolko()
{
    if(!tekstura.loadFromFile("zasoby/kolko.png"))
    {
        //blad
    }
    tekstura.setSmooth(true);
    sprite.setTexture(tekstura);
}

Kolko::~Kolko()
{
    //dtor
}

void Kolko::rysujFigure(sf::RenderWindow &okno, float x, float y)
{
    sprite.setPosition(x,y);
    okno.draw(sprite);
}
