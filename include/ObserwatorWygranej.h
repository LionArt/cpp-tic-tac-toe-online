#ifndef OBSERWATORWYGRANEJ_H
#define OBSERWATORWYGRANEJ_H
#include <Obserwator.h>
#include <SFML/Graphics.hpp>

class ObserwatorWygranej : public Obserwator
{
    public:
        ObserwatorWygranej();
        virtual ~ObserwatorWygranej();
        void onNotify(int wygrana, sf::Text *tekst);

    protected:

    private:
};

#endif // OBSERWATORWYGRANEJ_H
