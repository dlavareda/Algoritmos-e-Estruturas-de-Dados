#include <stdio.h>
#include <stdlib.h>
typedef struct T
{
    char c;
    struct T *nseg;
} Nodo;

Nodo *makenode()
{
    Nodo *nv;
    nv = (Nodo *)malloc(sizeof(Nodo));
    nv->nseg = NULL;
    return (nv);
}

Nodo *insertFirst(Nodo *L, Nodo *nv)
{
    nv->nseg = L;
    return nv;
}

int main()
{

    Nodo *P, *V, *C;
    Nodo *nv;

    nv = makenode();
    nv->c = 'e';
    P = insertFirst(P, nv);
    nv = makenode();
    nv->c = 'o';
    P = insertFirst(P, nv);
    nv = makenode();
    nv->c = 'i';
    P = insertFirst(P, nv);
    nv = makenode();
    nv->c = 'b';
    P = insertFirst(P, nv);
    nv = makenode();
    nv->c = 'a';
    P = insertFirst(P, nv);

    Nodo *aux;
    while (P != NULL)
    {
        aux = P;
        P = P->nseg;
        if (aux->c == 'a' || aux->c == 'e' || aux->c == 'i')
        {
            V = insertFirst(C, aux);
        }else{
            C=insertFirst(V, aux);
        }
    }
    return 1;
}