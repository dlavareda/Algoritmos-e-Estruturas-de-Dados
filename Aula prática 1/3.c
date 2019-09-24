#include <stdio.h>
#include <stdlib.h>

typedef struct T
{
    int ID;
    struct T *nseg;
} Nodo;

Nodo *makenode()
{
    Nodo *nv;
    nv = (Nodo *)malloc(sizeof(Nodo));
    nv->nseg = NULL;
    return (nv);
}

Nodo *insertlast(Nodo *L, Nodo *nv)
{
    Nodo *aux;
    if (L == NULL)
    {
        return nv;
    }
    while (aux -> nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux ->nseg =nv;
    return L;
}
Nodo *copylist(Nodo *L)
{
    Nodo *N = NULL, *nv;
    while (L != NULL)
    {
        nv = makenode();
        nv->ID = L ->ID;
        N = insertlast(N, nv);
        L = L->nseg;
    }
}
int main()
{
}