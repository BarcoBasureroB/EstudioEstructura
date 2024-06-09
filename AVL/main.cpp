#include <iostream>
#include "Nodo.h"
#include <stack>

using namespace std;

Nodo* busqueda(Nodo* &raiz, int dato)
{
    if(raiz == nullptr)
    {
        return nullptr;
    }

    if(raiz->dato == dato)
    {
        return raiz;
    }

    if(dato > raiz->dato)
    {
        return busqueda(raiz->hijoDer, dato);
    }
    return busqueda(raiz->hijoIzq, dato);
}


Nodo* insercion(Nodo* &raiz, int dato)
{
    if(raiz == nullptr)
    {
        return new Nodo(dato);
    }   

    Nodo* aux = busqueda(raiz, dato);

    if(aux == nullptr)
    {
        if(raiz->dato > dato)
        {
            raiz->hijoIzq = insercion(raiz->hijoIzq, dato);
        }
        else 
        {
            raiz->hijoDer = insercion(raiz->hijoDer, dato);
        }
    }
    else
    {
        cout<<"Número Repetido"<<endl;
    }
    return raiz;
}