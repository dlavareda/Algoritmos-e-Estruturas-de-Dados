#include <stdio.h>
#include <stdlib.h>

typedef struct T
{
    int ID;
    struct T *nseg;
    struct R *nant;
} Nodo;

Nodo *insertFirst(Nodo *L, Nodo *nv)
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
        L = L->nseg;
        aux->nseg = NULL;
        if (L != NULL)
        {
            L->nant = NULL;
        }
        R = insertFirst(R, aux);
    }
    return R;
}