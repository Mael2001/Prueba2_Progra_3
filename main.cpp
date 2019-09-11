#include "nodo.h"
#include <iostream>

int main()
{
    nodo *raiz = 0;
    int opcion{0};
    char *palabra;
    int cantidad{0};
    do
    {
        std::cout << "\n1.Crear Lista Manual\n";
        std::cout << "\n2.Cargar Lista De Archivo\n";
        std::cout << "\n3.Guardar Lista En Archivo\n";
        std::cout << "\n4.Salir\n";
        std::cin >> opcion;
        switch (opcion)
        {
        case 1:

            std::cout << "\n Ingresé Cantidad De Nombres\n";
            std::cin >> cantidad;
            while (cantidad != 0)
            {
                std::cout << "\n Ingresé el nombre a insertar\n";
                std::cin >> palabra;
                insertar(&raiz, palabra);
                cantidad--;
            }
            imprimir(&raiz);
            std::cout<<"\n\n";
            insertar(&raiz, (char *)"Pablo");
            insertar(&raiz, (char *)"Panera");

            imprimir(&raiz);
            break;
        case 2:
            leerdeArchivo(&raiz);
            break;
        case 3:
            guardarenArchivo(&raiz);
            break;
        case 4:
            std::cout << "Saliendo\n";
            break;
        default:
            std::cout << "Numero 1-4 Solo";
            break;
        }
    } while (opcion != 4);
}