#include "nodo.h"
#include <iostream>
#include <cstring>

void insertar(nodo **raiz, char *nombre)
{
    nodo *nuevo = new nodo;
    nuevo->nombre = nombre;
    if (buscar(raiz, nombre) == 1)
    {
        delete nuevo;
        return;
    }
    else if (*raiz == 0)
    {
        *raiz = nuevo;
        return;
    }
    nodo *actual = *raiz;
    while (actual != 0)
    {
        if (strcmp(actual->nombre, nombre) > 0)
        {
            if (actual == (*raiz))
            {
                actual->siguiente = (*raiz);
                (*raiz)->anterior = actual;
                (*raiz) = actual;
            }
            actual->anterior->siguiente = nuevo;
            nuevo->anterior = actual->anterior;
            nuevo->siguiente = actual;
            actual->anterior = nuevo;
            return;
        }
        else if (actual->siguiente == 0)
        {
            nuevo->anterior = actual;
            actual->siguiente = nuevo;
            return;
        }
        actual = actual->siguiente;
    }
}

void eliminar(nodo **raiz, char *nombre)
{
    if (buscar(&(*raiz), nombre) == 0)
    {
        return;
    }
    nodo *actual = *raiz;
    while (actual != 0)
    {
        if (strcmp(actual->nombre, nombre) == 0)
        {
            if (actual == *raiz)
            {
                *raiz = actual->siguiente;
                delete actual;
                return;
            }
            if (actual->siguiente == nullptr)
            {
                actual->anterior->siguiente = 0;
                delete actual;
                return;
            }
            actual->anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = actual->anterior;
            delete actual;
            return;
        }
        actual = actual->siguiente;
    }
}
void imprimir(nodo **raiz)
{
    if (*raiz == 0)
    {
        return;
    }
    std::cout << " [ " << (*raiz)->nombre << " ] ";
    imprimir(&(*raiz)->siguiente);
}

bool buscar(nodo **raiz, char *nombre)
{
    if (*raiz == 0)
    {
        return false;
    }
    else
    {
        if ((*raiz)->nombre == nombre)
        {
            return true;
        }
    }
    buscar(&(*raiz)->siguiente, nombre);
}