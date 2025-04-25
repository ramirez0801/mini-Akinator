#include <iostream>
#pragma once

using namespace std;

//Clase Nodo***
class cNodo
{
private:
    float dato;
    cNodo* sig, * ant;
public:
    cNodo();
    ~cNodo();
    void agregarSig(float);
    float eliminarSig();
    friend class cLista;
};

cNodo::cNodo()
{
}

cNodo::~cNodo()
{
}

void cNodo::agregarSig(float dato)
{
    cNodo* pnn = new cNodo;
    pnn->dato = dato;
    pnn->sig = this->sig;
    pnn->ant = this;
    this->sig->ant = pnn;
    this->sig = pnn;
}

float cNodo::eliminarSig()
{
    cNodo* pnn = new cNodo;
    pnn = this->sig;
    this->sig = pnn->sig;
    pnn->sig->ant = this;
    pnn->sig = NULL;
    pnn->ant = NULL;
    return pnn->dato;
    ///delete pnn;
}

//Clase para lista***
class cLista
{
private:
    cNodo Inicio;
    cNodo Final;
public:
    cLista();
    ~cLista();
    void insertarInicio(float);
    void insertarFinal(float);
    int tamanio();
    bool vacio();
    void vaciar();
    void mostrar();
    float eliminarInicio();
    float eliminarFinal();
};

cLista::cLista()
{
    Inicio.sig = &Final;
    Final.ant = &Inicio;
}

cLista::~cLista()
{
    vaciar();
}

void cLista::insertarInicio(float _dato)
{
    Inicio.agregarSig(_dato);
}

void cLista::insertarFinal(float _dato)
{
    Final.ant->agregarSig(_dato);
}

int cLista::tamanio()
{
    int i;
    cNodo* p = Inicio.sig;
    //Recorre la lista y cuenta los nodos encontrados
    for (i = 0; p != &Final; i++)
    {
        p = p->sig;
    }
    return i;
}

bool cLista::vacio()
{
    //Si el nodo siguiente de la cabecera inicio es el nodo fina, la lista esta vacia
    return (Inicio.sig == &Final ? true : false);
}

void cLista::vaciar()
{   
    while(!vacio())
    {
        Inicio.eliminarSig();
    }
}

void cLista::mostrar()
{
    cNodo* pnn = new cNodo;
    if (vacio())
        cout << "\n\t---Lista vacia---\n";
    else
    {
        pnn = Inicio.sig;
        for (int i = 1; pnn != &Final; i++)
        {
            cout << "Dato[" << i << "]: " << pnn->dato << endl;
            pnn = pnn->sig;
        }
    }
    cout<<'\n';
}

float cLista::eliminarInicio()
{
    float dato;
    dato = Inicio.eliminarSig();
    return dato;
}

float cLista::eliminarFinal()
{
    float dato;
    dato = Final.ant->ant->eliminarSig();
    return dato;
}