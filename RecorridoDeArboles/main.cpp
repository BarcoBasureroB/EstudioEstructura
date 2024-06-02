#include <iostream>
#include "Nodo.h"
#include <stack>

using namespace std;

Nodo* insertarNodo(int dato, Nodo* &raiz)
{

    if(raiz == nullptr){
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

void preOrdenRecursivo(Nodo* &raiz)
{
    if(raiz == nullptr){
        return;
    }

    cout<<raiz->dato<<"";
    preOrdenRecursivo(raiz->hijoIzq);
    preOrdenRecursivo(raiz->hijoDer);
}



void inOrdenRecursivo(Nodo* &raiz)
{
    if(raiz == nullptr){
        return;
    }
    
    inOrdenRecursivo(raiz->hijoIzq);
    cout<<raiz->dato<<"";
    inOrdenRecursivo(raiz->hijoDer);
}

void postOrdenRecursivo(Nodo* &raiz)
{
    if(raiz == nullptr){
        return;
    }

    postOrdenRecursivo(raiz->hijoIzq);
    postOrdenRecursivo(raiz->hijoDer);
    cout<<raiz->dato<<"";
}

void preOrdenIterativo(Nodo* &raiz)
{
    if(raiz == nullptr){

        return;
    }

    stack<Nodo*> stack;
    stack.push(raiz);

    while(!stack.empty())
    {
        Nodo* aux = stack.top();
        stack.pop();

        cout<<aux->dato<<"";

        if(aux->hijoDer)
        {
            stack.push(aux->hijoDer);
        }

        if(aux->hijoIzq)
        {
            stack.push(aux->hijoIzq);
        }
    }
}

void inOrdenIterativo(Nodo* &raiz)
{
    stack<Nodo*> stack;
    Nodo* aux = raiz;

    while(aux ||!stack.empty())
    {
        while(aux)
        {
            stack.push(aux);
            aux = aux->hijoIzq;
        }

        aux = stack.top();
        stack.pop();

        cout<<aux->dato<<"";
        
        aux = aux->hijoDer;  
    }
    
}

void postOrdenIterativo(Nodo* &raiz)
{
    stack<Nodo*> stack;
    Nodo* ultimoVisto = nullptr;
    Nodo* aux = raiz;

    while(aux||!stack.empty())
    {
        if(aux)
        {
            stack.push(aux);
            aux = aux->hijoIzq;
        } 
        else
        {
            Nodo* temp = stack.top();
            
        }


    }



}

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

    //Formas RECURSIVAS
    preOrdenRecursivo(raiz);
    cout<<""<<endl;
    inOrdenRecursivo(raiz);
    cout<<""<<endl;
    postOrdenRecursivo(raiz);
    cout<<""<<endl;

    //Formas ITERATIVAS
    preOrdenIterativo(raiz);
    cout<<""<<endl;
    inOrdenIterativo(raiz);
    cout<<""<<endl;
    postOrdenIterativo(raiz);
}