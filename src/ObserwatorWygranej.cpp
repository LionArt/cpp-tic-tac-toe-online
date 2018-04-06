#include "ObserwatorWygranej.h"
#include <SFML/Graphics.hpp>

ObserwatorWygranej::ObserwatorWygranej()
{
    //ctor
}

ObserwatorWygranej::~ObserwatorWygranej()
{
}

void ObserwatorWygranej::onNotify(int wygrana, sf::Text *text)
{
    switch (wygrana)
    {
    case 0:
      {
            text->setPosition(93,365);
            text->setString("WYGRAL KLIENT");
            text->setColor(sf::Color::Red);
            break;
      }
    case 1:
      {
            text->setPosition(93,365);
            text->setString("WYGRAL SERWER");
            text->setColor(sf::Color::Red);
            break;
      }
    case -1:
      {
            text->setPosition(130,365);
            text->setString("REMIS");
            text->setColor(sf::Color::Red);
            break;
      }
      break;
    }
      // Handle other events, and update heroIsOnBridge_...
}
