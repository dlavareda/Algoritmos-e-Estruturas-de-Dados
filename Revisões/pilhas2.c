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

Nodo *insertlast(Nodo *E, Nodo *nv)
{

    Nodo *aux = E;
    if (E == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    return E;
}
int main()
{

    Nodo *Q = NULL;
    Nodo *nv  = NULL;


    Nodo *nnv = NULL;

    nv = makenode();
    nv->c = 'a';
    Q = insertlast(Q, nv);
    
    nv = makenode();
    nv->c = 'b';
    Q = insertlast(Q, nv);
    
    nv = makenode();
    nv->c = 'i';
    Q = insertlast(Q, nv);
    
    nv = makenode();
    nv->c = 'e';
    Q = insertlast(Q, nv);
    
    nv = makenode();
    nv->c = 'o';
    Q = insertlast(Q, nv);
    
    nv = makenode();
    nv->c = 'u';
    Q = insertlast(Q, nv);
        Nodo *aux2 = NULL;

    while (Q != NULL)
    {
        aux2 = makenode();
        aux2->c = Q->c;
        
        aux2->nseg = NULL;
        Q = Q->nseg;
        if (aux2->c == 'a' || aux2->c == 'e' || aux2->c == 'i')
        {
            nnv = insertlast(nnv, aux2);
        }
        else
        {
            nnv = insertlast(aux2, nnv);
        }
    }
    return 1;
}