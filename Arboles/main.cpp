#include <iostream>
#include "Nodo.h"

using namespace std;

int main()
{
    Nodo* raiz = nullptr;
    raiz = insertarNodo(5, raiz);
    insertarNodo(3,raiz);
    insertarNodo(8,raiz);
    insertarNodo(2,raiz);
    insertarNodo(4,raiz);
    insertarNodo(7,raiz);
    insertarNodo(9,raiz);

}

Nodo* insertarNodo(int dato, Nodo* raiz)
{

    if(raiz=nullptr){
        return new Nodo(dato);
    }

    if(dato < raiz->dato){
        raiz->hijoIzq = insertarNodo(dato,raiz->hijoIzq);
    }
    else
    {
        raiz->hijoDer = insertarNodo(dato,raiz->hijoDer);
    }

    return raiz;
}

void preOrdenRecursivo(Nodo* raiz)
{
    if(raiz = nullptr){
        return;
    }

    

}

void inOrdenRecursivo(Nodo* raiz)
{
    if(raiz = nullptr){
        return;
    }
    

}

void postOrdenRecursivo(Nodo* raiz)
{
    if(raiz = nullptr){
        return;
    }

}