#include <stdio.h>
#include <stdlib.h>

typedef struct NODO
{
    int ID;
    int salto;
    struct NODO *nseg[4];
    struct NODO *nant[4];

} Nodo;

int LSBemFormada(Nodo *L)
{
    Nodo *aux = L;
    Nodo *aux2 = L;
    int nanterior = 0;
    int nactual = 0;
    while (aux != NULL)
    {
        for (int i = L->salto; i >=0 ; i++)
        {
            L = L->nseg[i];
            nactual = L->ID - L->nant[i]->ID;
            if (nactual < nanterior)
            {
                return 0;
            }
            
            nanterior = nactual;
        }
        nactual = 0;
        nanterior = 0;  
    }
    return 1;

}