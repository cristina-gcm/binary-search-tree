#ifndef ABC_H
#define ABC_H
#include <iostream>
using namespace std;

class node; /// clasa friend nod

class abc /// clasa arbore binar de cautare
{   friend class node;
    node *rad; ///radacina este un pointer de tip node
public:
    abc();  ///ctor fara parametru
    abc(int val); /// ctor cu parametru
    abc (const abc &other); /// copy ctor
    ~abc(); /// destructor
    node &getRad(); ///getter pentru radacina arborelui
    friend istream &operator>>(istream &in, abc &arb); ///supraincarcarea operatorului de input
    friend ostream &operator<<(ostream &out, abc &arb); ///supraincarcarea operatorului de output
    void delete_(node* nod);    /// helper pentru destructor pentru stergeerea unui nod
    void inordine(node *nod)const;           ///parcurgere srd
    void preordine(node *nod)const;          ///parcurgere rsd
    void postordine(node *nod)const;         ///parcurgere sdr
    node* inserare(node *&nod,int x);        ///insereaza un nod nou in arbore
    bool cautare(node *nod,int x);           ///cauta un nod in arbore
    node* stergere(node *nod,int x);         ///sterge un nod din arbore
    int maxim(node *nod);                    ///returneaza maximul din arbore
    int minim(node *nod);                    ///returneaza minimul din arbore
    int nr_noduri(node *nod);                ///returneaza nr de noduri din arbore
    node *&operator+(int val);                ///suprainacrcarea operatorului plus;
    void frunze(node *nod)const;            ///afisare frunze
    int inaltime_arb(node *nod)const;        ///returneaza inaltimea arborelui
    int maxim(int a, int b);               /// ajuta la calcularea inaltimii arborelui
};
#endif // ABC_H
