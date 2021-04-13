#ifndef LISTA_CIRCULARA_H
#define LISTA_CIRCULARA_H
#include <Nod_dublu.h>
#include <Lista.h>
class Lista_circulara : public Lista
{
    public:
        Nod* operator[](int);
        void del(int pos);
        int josep();
        void delRef(Nod* x);
         Lista_circulara();
         Lista_circulara(Nod* head,Nod* tail);
         Lista_circulara(Lista_circulara& lista);
        ~Lista_circulara();
        Lista_circulara& operator=(Lista_circulara& lista);
};

#endif // LISTA_CIRCULARA_H
