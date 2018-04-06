#ifndef OBSERWATOR_H
#define OBSERWATOR_H


class Obserwator
{
    public:
        Obserwator();
        virtual ~Obserwator();
        virtual void onNotify(int wygrana) = 0;
    protected:

    private:
};

#endif // OBSERWATOR_H
