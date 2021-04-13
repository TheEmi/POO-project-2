#ifndef LISTA_H
#define LISTA_H

#include <Nod_dublu.h>
#include <iostream>

class Lista
{
    private:
        Nod* head;
        Nod* tail;
    public:
        Lista();
        Lista(Lista* lista);
        Lista(Nod* x,Nod* y);
        ~Lista();
        Nod* getHead();
        Nod* getTail();
        void setHead(Nod* x);
        void setTail(Nod* x);
        void add(int x,int poz);
        void del(int poz);
        friend std::ostream& operator<<(std::ostream& out,Lista& lista);
        friend std::istream& operator>>(std::istream&,Lista& lista);

};

#endif // LISTA_H
