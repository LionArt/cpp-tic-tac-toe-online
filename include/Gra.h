#ifndef GRA_H
#define GRA_H
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <conio.h>
#define _WIN32_WINNT 0x0500
#include "Figura.h"
#include "FabrykaFigur.h"
#include "Plansza.h"
#include <windows.h>
#include <cstdlib>

class Gra
{
    public:
        Gra();
        static Gra *Instance();
        int wygrana=2;
        int run();
        void rysujSiatke(sf::RenderWindow *window);
        int sprawdzWygrana(Plansza *plansza);
        void ukryjKonsole();
        virtual ~Gra();

    protected:

    private:
        static Gra *instance;
};

#endif // GRA_H
