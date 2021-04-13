#ifndef NOD_DUBLU_H
#define NOD_DUBLU_H

#include <Nod.h>


class Nod_dublu : public Nod
{
    private:
        Nod* ante;
    public:
        static int numar_noduri;
        Nod_dublu();
        Nod_dublu(int x, Nod* next, Nod* ante);
        Nod_dublu(Nod_dublu&);
        ~Nod_dublu();
        Nod* getAnte();
        void setAnte(Nod* x);
        Nod* operator=(Nod* dupa);
};

#endif // NOD_DUBLU_H
