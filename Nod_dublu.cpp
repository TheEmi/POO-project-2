#include "Nod_dublu.h"
#include <iostream>

Nod* Nod_dublu::getAnte(){
    return ante;
}
void Nod_dublu::setAnte(Nod* x){
    ante=x;
}
int Nod_dublu::numar_noduri=0;
Nod_dublu::Nod_dublu()
{
    numar_noduri++;
    setNext(nullptr);
    setAnte(nullptr);
}
Nod* Nod_dublu::operator=(Nod* dupa){
    std::cout << "ajutoor";
    this->setInfo(dupa->getInfo());
    this->setNext(dupa->getNext());
    this->setAnte(dupa->getAnte());
    return this;
}
Nod_dublu::Nod_dublu(int x, Nod* y, Nod* z):Nod{x,y}
{
    numar_noduri++;
    this->setAnte(z);
}
Nod_dublu::Nod_dublu(Nod_dublu& nod)
{
    numar_noduri++;
    this->setInfo(nod.getInfo());
    this->setNext(nod.getNext());
    this->setAnte(nod.getAnte());
}

Nod_dublu::~Nod_dublu()
{
    //dtor
}
