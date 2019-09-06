#include "nodo.h"
#include <iostream>

int main()
{
    nodo* raiz=0;
    insertar(&raiz,(char*)"Aanuel");
    insertar(&raiz,(char*)"Braian");
    insertar(&raiz,(char*)"Aaron");
    insertar(&raiz,(char*)"Dinamarca");
    insertar(&raiz,(char*)"Zio");
    insertar(&raiz,(char*)"Diestro");
    insertar(&raiz,(char*)"Bradley");
    
    imprimir(&raiz);
    std::cout<<"\n"<<buscar(&raiz,(char*)"Braian")<<"\n";
    eliminar(&raiz,(char*)"Dinamarca");
    imprimir(&raiz);

}