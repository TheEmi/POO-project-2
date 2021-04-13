#include <iostream>
#include <Lista_circulara.h>
using namespace std;

int main()
{
    Lista_circulara a;
    Lista_circulara b;
    int n,x,y;
    bool active=1;
    //for(int i=41;i>0;i--){
    //    a.add(i,1);
    //}
    //cin >> a;//adauga pe poz 1
    while(active){
        cout << "1 Inserare Nod\n2 Stergere nod\n3 Afisare Lista\n4 Problema lui Josephus pe lista curenta\n5 Exit\n";
        cin >> n;
        switch(n){
            case 1:
                cout << "Valoare de adaugat: ";
                cin >> x;
                cout << "Pozitia pe care se adauga: ";
                cin >> y;
                a.add(x,y);
                break;
            case 2:
                cout << "Pozitia de pe care se sterge: ";
                cin >> x;
                a.del(x);
                break;
            case 3:
                cout << a << endl;
                break;
            case 4:
                b=a;
                b.josep();
                cout <<"Supravietuitor: " <<b << endl;
                b.del(1);
                break;
            default:
                active=0;
                break;
        }
    }
    return 0;
}
