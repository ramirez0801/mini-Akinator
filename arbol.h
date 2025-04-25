#pragma once
#include "nodoA.h"

class cArbol 
{
private:
    cNodoA* raiz;
public:
    cArbol();
    void insertar();
    void preordenCar();
    void guardar();
};

cArbol::cArbol()
{
    raiz = NULL;
}

void cArbol::insertar()
{
    string nd;
    if (raiz == NULL)
    {
        raiz = new cNodoA;
        cout<<"En que estas pensando?: ";
        cin>>nd;
        raiz->fdato = nd;
    }
    else
    {
        raiz->buscar(raiz);
    }

}

void cArbol::guardar()
{
    //cout<<"raiz"<<raiz->pNo->fdato;
    if(raiz != nullptr)
    {
        cout<<"\nGuardando...\n\n";
        fstream myFile;
        myFile.open("aki.txt",fstream::out);
        myFile<<raiz->fdato;
        cout<<raiz->fdato<<" ";
    }
}
