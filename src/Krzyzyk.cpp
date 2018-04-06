#include "../include/Krzyzyk.h"

Krzyzyk::Krzyzyk()
{
    if(!tekstura.loadFromFile("zasoby/krzyzyk.png"))
    {
        //blad
    }
    tekstura.setSmooth(true);
    sprite.setTexture(tekstura);
}

Krzyzyk::~Krzyzyk()
{
    //dtor
}

void Krzyzyk::rysujFigure(sf::RenderWindow &okno, float x, float y)
{
    sprite.setPosition(x,y);
    okno.draw(sprite);
}
