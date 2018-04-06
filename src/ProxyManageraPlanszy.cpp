#include "ProxyManageraPlanszy.h"

ProxyManageraPlanszy::ProxyManageraPlanszy()
{
    managerPlanszy_=NULL;
}

ProxyManageraPlanszy::~ProxyManageraPlanszy()
{
    if(managerPlanszy_)
    delete managerPlanszy_;
}

ManagerPlanszy* ProxyManageraPlanszy::getManagerPlanszyInstance()
{
    if(!managerPlanszy_)
    managerPlanszy_ = new ManagerPlanszy();
    return managerPlanszy_;
}

bool ProxyManageraPlanszy::sprawdzCzyPelna(Plansza *plansza)
{
    return getManagerPlanszyInstance()->sprawdzCzyPelna(plansza);
}

void ProxyManageraPlanszy::resetujPlansze(Plansza *plansza)
{
    getManagerPlanszyInstance()->resetujPlansze(plansza);
}

