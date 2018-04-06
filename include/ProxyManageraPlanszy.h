#ifndef PROXYMANAGERAPLANSZY_H
#define PROXYMANAGERAPLANSZY_H
#include <IManagerPlanszy.h>
#include <ManagerPlanszy.h>

class ProxyManageraPlanszy : public IManagerPlanszy
{
    public:
        ProxyManageraPlanszy();
        virtual ~ProxyManageraPlanszy();
        void resetujPlansze(Plansza *plansza);
        bool sprawdzCzyPelna(Plansza *plansza);
    protected:

    private:
    ManagerPlanszy* managerPlanszy_;
    ManagerPlanszy* getManagerPlanszyInstance(void);
};

#endif // PROXYMANAGERAPLANSZY_H
