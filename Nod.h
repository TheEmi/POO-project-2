#ifndef NOD_H
#define NOD_H


class Nod
{
    private:
        int info;
        Nod* next;
     public:
        Nod();
        Nod(int x);
        Nod(int x,Nod* y);
        ~Nod();
        int getInfo();
        void setInfo(int x);
        Nod* getNext();
        void setNext(Nod* x);
        virtual Nod* getAnte()=0;
        virtual void setAnte(Nod* x)=0;
        virtual Nod* operator=(Nod*)=0;
};

#endif // NOD_H
