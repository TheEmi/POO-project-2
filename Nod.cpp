#include "Nod.h"

int Nod::getInfo(){
    return info;
}
void Nod::setInfo(int x){
    info=x;
}
Nod* Nod::getNext(){
    return next;
}
void Nod::setNext(Nod* x){
    next=x;
}
Nod::Nod()
{
    info=0;
    next=nullptr;
}
Nod::Nod(int x)
{
    info=x;
    next=nullptr;
}
Nod::Nod(int x, Nod* y)
{
    info=x;
    next=y;
}

Nod::~Nod()
{
    //dtor
}
