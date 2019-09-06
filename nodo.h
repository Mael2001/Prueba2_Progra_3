#ifndef nodo_h
#define nodo_h

struct nodo
{
    char *nombre;
    nodo *anterior;
    nodo *siguiente;

    nodo()
    {
        anterior = 0;
        siguiente = 0;
        nombre = (char *)' ';
    }
};
void insertar(nodo **, char *);
void eliminar(nodo **, char *);
bool buscar(nodo **, char *);
void imprimir(nodo **);
#endif