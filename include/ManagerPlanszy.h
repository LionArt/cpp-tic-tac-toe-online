#ifndef MANAGERPLANSZY_H
#define MANAGERPLANSZY_H
#include <IManagerPlanszy.h>

class ManagerPlanszy : public IManagerPlanszy
{
    public:
        ManagerPlanszy();
        virtual ~ManagerPlanszy();
        void resetujPlansze(Plansza *plansza);
        bool sprawdzCzyPelna(Plansza *plansza);
    protected:

    private:
};

#endif // MANAGERPLANSZY_H
