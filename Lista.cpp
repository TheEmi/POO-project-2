#include "Lista.h"
#include <iostream>

Nod* Lista::getHead(){
    return head;
}
Nod* Lista::getTail(){
    return tail;
}
void Lista::setHead(Nod* x){
    head=x;
}
void Lista::setTail(Nod* x){
    tail=x;
}
void Lista::add(int x,int pos){
    if(head==nullptr){//lista nula
        head = new Nod_dublu;
        head->setInfo(x);
        tail = head;
        return;
    }
    Nod* temp = new Nod_dublu;
    temp = head;
    int poz=pos;
    poz--;
    while(poz&&temp->getNext()!=nullptr){
        temp=temp->getNext();
        poz--;
    }
    Nod* nou = new Nod_dublu;
    nou->setInfo(x);
    if(temp->getNext()!=nullptr){
        nou->setNext(temp);
        if(pos!=1){//orice element care nu e primul
            nou->setAnte(temp->getAnte());
            temp->getAnte()->setNext(nou);
        }
        temp->setAnte(nou);
        if(pos==1)head=nou;
    }else{//ultimul element
        if(pos==1){
            nou->setNext(temp);
            temp->setAnte(nou);
            head=nou;
        }else{
            nou->setAnte(temp);
            temp->setNext(nou);
            tail=nou;
        }
    }
}
void Lista::del(int pos){
    Nod* temp = head;
    int poz=pos;
    poz--;
    while(poz&&temp->getNext()!=nullptr){
        temp=temp->getNext();
        poz--;
    }
    if(temp->getNext()!=nullptr){
        if(pos!=1){//orice element care nu e primul
            temp->getAnte()->setNext(temp->getNext());
            temp->getNext()->setAnte(temp->getAnte());
        }else{
            head=temp->getNext();
            temp->getNext()->setAnte(nullptr);
        }
    }else{//ultimul element
         temp->getAnte()->setNext(nullptr);
         tail=temp->getAnte();
    }
    delete temp;
}
Lista::Lista(){
    head = nullptr;
    tail = nullptr;
}
Lista::Lista(Nod* x,Nod* y){
    head = x;
    tail = y;
}
Lista::Lista(Lista* lista)
{
    Nod* temp = new Nod_dublu;
    temp=lista->getTail();
    while(temp->getAnte()){
        this->add(temp->getInfo(),1);
        temp=temp->getAnte();
    }
    this->add(temp->getInfo(),1);
}
std::ostream& operator<<(std::ostream& out,Lista& lista){
    Nod* temp = lista.head;
     while(temp!=lista.tail){
        out << temp->getInfo() << " ";
        temp=temp->getNext();
    }
    out << temp->getInfo() << " ";
    return out;
}
std::istream& operator>>(std::istream& in,Lista& lista){
    int x;
    in >> x;
    lista.add(x,1);
    return in;
}
Lista::~Lista()
{
    Nod* temp =this->getTail();
    while(temp!=this->getHead()){
        temp=temp->getAnte();
        delete temp->getNext();
    }
    delete temp;
}
