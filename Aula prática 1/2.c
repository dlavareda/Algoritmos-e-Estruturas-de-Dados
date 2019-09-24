#include <stdio.h>
#include <stdlib.h>

typedef struct
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
Nodo *insertorder(Nodo *L, Nodo *nv)
{
    Nodo *AUX = L;
    //insere no inicio porque esta vazia
    if (L == NULL)
    {
        return nv;
    }
    if (L->ID > nv->ID)
    {
        nv->nseg = L;
        return nv;
    }

    //insere pelo meio
    while (L->nseg != NULL)
    {
        if (((L->nseg)->ID) > nv->ID)
        {
            break;
        }
        L = L->nseg;
    }
    nv->nseg = L->nseg;
    L->nseg = nv;
    return (AUX);
}
int main()
{
}
