#include <iostream>
#include "node.h"
#include "abc.h"
#include <cstring>
using namespace std;

int main()
{
    abc arb1(19),arb2;
    cout<<"Dati nr de noduri pt arb1: ";    ///7 noduri: 14,27,16,9,7,12,23
    cin>>arb1;
    cout<<"Dati nr de noduri pt arb2: ";    ///5 noduri: 17(rad),15,20,9,16
    cin>>arb2;
    cout<<"Dati metoda de afisare pt arb1: "<<arb1<<endl;   ///inordine,postordine,inordine
    cout<<"Dati metoda de afisare pt arb2: "<<arb2<<endl;
    cout<<"Frunzele lui arb1 sunt: "; arb1.frunze(arb1.getRad());
    arb1.stergere(arb1.getRad(),23);
    cout<<"Dupa stergerea lui 23 arb1 devine: (Dati metoda de afisare) "<<arb1<<endl;
    int x;
    cout<<"Adaugati un nod in arb1: ";cin>>x; arb1=arb1+x;cout<<endl;
    cout<<"Dupa adaugare, arb! este: (Dati metoda de afisare) "<<arb1;endl;
}
