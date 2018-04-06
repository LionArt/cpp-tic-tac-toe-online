#include <Gra.h>

Gra *Gra::instance=NULL;

int main()
{
    Gra::Instance()->run();
    return 0;
}
