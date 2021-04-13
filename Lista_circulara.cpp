#include "Lista_circulara.h"
#include <Nod_dublu.h>
#include <iostream>

Nod* Lista_circulara::operator[](int pos){
    Nod* temp = Lista::getHead();
    pos--;
    while(pos){
        if(temp->getNext()==nullptr)temp=Lista::getHead();
        else temp=temp->getNext();
        pos--;
    }
    return temp;
}
void Lista_circulara::del(int pos){
    Nod* temp = Lista::getHead();
    pos--;
    if(Lista::getHead()==Lista::getTail()){
        Lista::setHead(nullptr);
        Lista::setTail(nullptr);
        return;
    }
    while(pos){
        if(temp==Lista::getTail())temp=Lista::getHead();
        else temp=temp->getNext();
        pos--;
    }

        if(temp!=Lista::getHead()){//orice element care nu e primul
            if(temp->getNext()==nullptr){
                temp->getAnte()->setNext(nullptr);
                Lista::setTail(temp->getAnte());
            }else{
                temp->getAnte()->setNext(temp->getNext());
                temp->getNext()->setAnte(temp->getAnte());
            }
        }else{
            Lista::setHead(temp->getNext());
            temp->getNext()->setAnte(nullptr);
        }
        if(temp)
        delete temp;
}
void Lista_circulara::delRef(Nod* x){
    if(x==Lista::getHead()){
        x->getNext()->setAnte(nullptr);
        Lista::setHead(x->getNext());
    }else
    if(x==Lista::getTail()){
        x->getAnte()->setNext(nullptr);
        Lista::setTail(x->getAnte());
    }else{
        x->getAnte()->setNext(x->getNext());
        x->getNext()->setAnte(x->getAnte());
    }
}
int Lista_circulara::josep(){
    if(Lista::getHead()==Lista::getTail())return 1;
    Nod* temp = Lista::getHead()->getNext();
    Nod* aux=temp;
    while(Lista::getHead()!=Lista::getTail()){
        aux=temp;
        if(temp==Lista::getTail())temp=Lista::getHead()->getNext();
        else if(temp==Lista::getTail()->getAnte())temp=Lista::getHead();
        else temp=temp->getNext()->getNext();
        Lista_circulara::delRef(aux);
    }
    return Lista::getHead()->getInfo();
}
Lista_circulara& Lista_circulara::operator=(Lista_circulara& lista){
    Nod* temp = new Nod_dublu;
    temp=lista.getTail();
    while(temp->getAnte()){
        this->add(temp->getInfo(),1);
        temp=temp->getAnte();
    }
    this->add(temp->getInfo(),1);
    return *this;
}
Lista_circulara::Lista_circulara()
{
    setHead(nullptr);
    setTail(nullptr);
}
Lista_circulara::Lista_circulara(Nod* head,Nod* tail):Lista{head,tail}
{
}
Lista_circulara::Lista_circulara(Lista_circulara& lista)
{
    Nod* temp = new Nod_dublu;
    temp=lista.getTail();
    while(temp->getAnte()){
        this->add(temp->getInfo(),1);
        temp=temp->getAnte();
    }
    this->add(temp->getInfo(),1);
}

Lista_circulara::~Lista_circulara()
{
}
