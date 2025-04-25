#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



class cNodoA {
private:
    string fdato;
    cNodoA *pSi, *pNo;
public:
    cNodoA();
    void insertar();
    void preordenCar();
    void preordenGuar();
    bool buscar(cNodoA*);
    bool hoja();

    int hijos();
    cNodoA *dameHijo();
    friend class cArbol;
    
};



cNodoA::cNodoA()
{
    pNo = NULL;
    pSi = NULL;
}

bool cNodoA::buscar(cNodoA *raiz)
{
    int opc = 0;
    string nd;
    cNodoA *pActual = raiz;
    while (pActual)
    {
        
        if(pActual->hijos() == 0)
        {
            cout<<"(0-SI 1-NO)Estas pensando en "<<pActual->fdato<<"? ";
            cin>>opc;
            if(opc == 0)
            {
                cout<<"\nAdivine!!!\n";
                return true;
            }
            else if(opc == 1)
            {
                pActual->insertar();
            }
        }
        else
        {
            pActual = raiz;
            while(pActual->hijos() != 0)
            {
                cout<<"(0-SI 1-NO)Tiene o es "<<pActual->fdato<<"? ";
                cin>>opc;
                if(opc == 0)
                {
                    pActual = pActual->pSi;
                }
                else if(opc == 1)
                {
                    pActual = pActual->pNo;
                }
            }
        }
    }
    return true;
}

bool cNodoA::hoja()
{
    if(this->pNo != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}



void cNodoA::insertar()
{
    string nd;
    pNo = new cNodoA;
    pSi = new cNodoA;
    pNo->fdato = this->fdato;
    cout<<"En que estas pensando?: ";
    cin>>nd;
    pSi->fdato = nd;
    cout<<"Cual es caracteristica?: ";
    cin>>nd;
    this->fdato = nd;
}



void cNodoA::preordenGuar()
{
    ofstream myFile;
    myFile.open("aki.txt", ios::out | ios::app);
    myFile.seekp(ios::beg);
    if(pSi != NULL)
    {   
        cout<<pSi->fdato<<" ";
        myFile<<pSi->fdato<<"\n";
        pSi->preordenGuar();
    }
    if (pNo != NULL)
    {
        cout<<pNo->fdato<<" ";
        myFile<<pNo->fdato<<"\n";
        pNo->preordenGuar();
    }
}

int cNodoA::hijos()
{
    int i = 0;
    if(pNo != NULL)
    {
        i++;
    }
    if(pSi != NULL)
    {
        i++;
    }
    return i;
}

cNodoA* cNodoA::dameHijo()
{
    int i = 0;
    cNodoA *aux;
    
    if(pSi != NULL)
    {
        i++;
        aux = pSi;
    }
    if(pNo != NULL)
    {
        i++;
        aux = pNo;
    }

    switch (i)
    {
    case 1:
        return aux;
        break;
    case 2:
        return NULL;
        break;
    case 0: 
        return NULL;
        break;
    }
    return NULL;
}