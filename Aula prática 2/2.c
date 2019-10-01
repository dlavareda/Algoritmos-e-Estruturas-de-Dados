#include <stdio.h>
#include <stdlib.h>

typedef struct T
{
    int ID;
    struct T *nseg;
    struct R *nant;
} Nodo;

Nodo *inserFirst(Nodo *L, Nodo *nv)
{
    nv->nseg = L;
    return nv;
}

Nodo *inverteLista(Nodo *L)
{
    Nodo *aux, *R;
    while (L != NULL)
    {
        aux = L;
        aux->nseg = NULL;
        aux->nant = NULL;
        L = L->nseg;
        R = inserFirst(R, aux);
        return R;
    }
}