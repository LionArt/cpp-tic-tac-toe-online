#include "ManagerPlanszy.h"

ManagerPlanszy::ManagerPlanszy()
{
    //ctor
}

ManagerPlanszy::~ManagerPlanszy()
{
    //dtor
}

void ManagerPlanszy::resetujPlansze(Plansza *plansza)
{
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    plansza->stanPlanszy[i][j]=2;
}


bool ManagerPlanszy::sprawdzCzyPelna(Plansza *plansza)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(plansza->stanPlanszy[i][j]==2)
            return 0;
        }
    }
    return 1;
}
