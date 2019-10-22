#include <stdio.h>
#include <stdlib.h>

typedef struct NODO
{
    int N;
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
        for (int i = salto; i >=0 ; i++)
        {
            while (L != NULL)
            {
                L = L->nseg[i];
                nactual++;
            }
            if (nanterior < nactual)
            {
                return 0;
            }
            L = aux2;
            nanterior = nactual;
        }
    }
}

no salto nivel maior do que no nivel acim
    a