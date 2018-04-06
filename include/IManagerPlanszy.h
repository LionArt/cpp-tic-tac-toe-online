#ifndef IMANAGERPLANSZY_H
#define IMANAGERPLANSZY_H
#include <Plansza.h>

class IManagerPlanszy
{
    public:
        IManagerPlanszy();
        virtual ~IManagerPlanszy();
        virtual void resetujPlansze(Plansza *plansza)=0;
        virtual bool sprawdzCzyPelna(Plansza *plansza)=0;
    protected:

    private:
};

#endif // IMANAGERPLANSZY_H
