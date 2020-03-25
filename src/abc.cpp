#include "abc.h"
#include <iostream>
#include <cstring>
#include "node.h"

abc::abc()
{
    rad=NULL;
}

abc::abc(int val)
{
    rad=new node;
    rad->info=val;
    rad->st=rad->dr=NULL;
}

abc::abc(const abc &a)
{
    node *r[100];    ///vector de pointeri la node ai arborelui a
    int p=0,u=0;     ///p=primul elem, u=ultimul elem
    r[0]=a.rad;
    rad=new node;
    rad->info=r[0]->info;       ///copiem radacina arborelui a cu ajutorul vectorului r
    rad->st=rad->dr=NULL;
    if(r[p]->st!=NULL)          ///daca radacina are fiu stang, se actualizeaza u si se pune in vector pointerul respectiv
    {
        u++;
        r[u]=r[p]->st;
    }
    if(r[p]->dr!=NULL)          ///la fel daca radacina are fiu drept
    {
        u++;
        r[u]=r[p]->dr;
    }
    p++;
    while(p<=u)                 ///se parcurg toate nodurile arborelui a
    {
        inserare(rad,r[p]->info);       ///se insereaza, pe rand, nodurile arborelui a in arborele in care se face copierea
        if(r[p]->st!=NULL)          ///la fel ca la radacina
        {
            u++;
            r[u]=r[p]->st;
        }
        if(r[p]->dr!=NULL)
        {
            u++;
            r[u]=r[p]->dr;
        }
        p++;
    }
}

void abc::delete_(node* nod)  ///sterge recursiv nodurile mai intai in subarborele stang apoi in subarborele drept
{
    if (nod)
    {
        delete_(nod->st);
        delete_(nod->dr);
        delete nod;
    }
}

abc::~abc()
{
    delete_(rad);
    cout<<"gata"<<endl;
}


node*& abc::getRad()
{
    return rad;
}

istream& operator>>(istream &in,abc &arb)
{
    int nr_noduri,val;
    cin>>nr_noduri;
    for(int i=0;i<nr_noduri;i++)
    {
        in>>val;        ///se citeste o valoare care trebuie introdusa in arbore
        arb.inserare(arb.rad,val);  ///se creeaza arborele
    }
    return in;
}

ostream& operator<<(ostream &out,const abc &arb)    ///apeleaza una din metodele de parcurgere
{
    char metoda_afis[10];
    cin>>metoda_afis;
    if(strcmp(metoda_afis,"preordine")==0)
        arb.preordine(arb.rad);
    else
        if(strcmp(metoda_afis,"inordine")==0)
                arb.inordine(arb.rad);
        else
            if(strcmp(metoda_afis,"postordine")==0)
                arb.postordine(arb.rad);
    return out;
}

node* abc::inserare(node *&nod,int x)
{
    if(nod==NULL)  ///daca nodul nu exista se creeaza
    {
        nod=new node;
        nod->info=x;
        nod->st=nod->dr=NULL;
    }
    else
        if(x<nod->info)
            nod->st=inserare(nod->st,x);   ///se parcurge subarborele stang
        else
            nod->dr=inserare(nod->dr,x);   ///se parcurge subarborele drept

    return nod;
}

node* abc::stergere(node *nod, int x)
{
    if(nod==NULL)
        return nod;

    if(x<nod->info)
        nod->st=stergere(nod->st,x);
    else
        if(x>nod->info)
            nod->dr=stergere(nod->dr,x);
    else
    {
        if(nod->dr==NULL && nod->st==NULL)  ///daca nodul nu are nici fiu drept nici fiu stang
            return NULL;
        if(nod->dr==NULL)   ///daca nodul are doar fiu stang
            return nod->st;
        else
            if(nod->st==NULL)   ///daca nodul are doar fiu drept
                return nod->dr;

        ///pt nodurile cu 2 fii:
        nod->info=minim(nod->dr);   ///se cauta minimul din subarborele drept
        nod->dr=stergere(nod->dr,nod->info);    ///se sterge minimul gasit
    }
    return nod;

}

void abc::inordine(node *nod)const  ///are const deoarece am apelat functia din operator<< unde parametrul este de tip const Abc
{
    if(nod==NULL)
        return;
    inordine(nod->st);  ///parcurgem subarborele stang
    cout<<nod->info<<' ';   ///vizitam nodurile
    inordine(nod->dr);  ///parcurgem subarborele drept
}

void abc::postordine(node *nod)const
{
    if(nod==NULL)
        return;
    postordine(nod->st);
    postordine(nod->dr);
    cout<<nod->info<<' ';
}

void abc::preordine(node *nod)const
{
    if(nod==NULL)
        return;
    cout<<nod->info<<' ';
    preordine(nod->st);
    preordine(nod->dr);
}

int abc::nr_noduri(node *nod)
{
    int nr=0;
    if(nod==NULL)
        return 0;
    nr++;
    nr=nr+nr_noduri(nod->st)+nr_noduri(nod->dr);    ///aflam nr de noduri in fiecare subarbore
    return nr;
}
void abc::frunze(node *nod)const
{
    if (nod==NULL)
        return;
    if ((nod->st==NULL && nod->dr==NULL) ///conditia ca nodul sa fie frunza este ca acesta sa nu aiba descendenti
        cout<<nod->info<<' ';
    if ((nod->st!=NULL)) ///daca nodul are descendent la stanga, parcurgem mai departe arborele stang
        frunze(nod->st);
    if ((nod->dr!=NULL)) /// daca nodul are descendent la dreapta, parcurgem mai departe arborele drept
        frunze(nod->dr);
}
node&* abc::operator+(int val)
{
    this->rad=inserare(this->rad, val);
    return *this;
}
int abc::maxim(int a, int b)
{
    if (a>=b)
        return a;
    else
        return b;
}
int abc::inaltime_arb(node *nod)const
{
    if(nod==NULL)
        return 0;
    int h_st=inaltime_arb(nod->st);     ///aflam inaltimea subarborelui stang
    int h_dr=inaltime_arb(nod->dr);     ///aflam inaltimea subarborelui drept
    return 1+maxim(h_st,h_dr);         ///returnam 1(nivelul radacinii)+max(h_st,h_dr)
}
