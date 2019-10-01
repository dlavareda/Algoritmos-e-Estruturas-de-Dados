#include <stdio.h>
#include <stdlib.h>

typedef struct T
{
    int ID;
    struct T *nseg;
    struct T *nant;
} Nodo;

//passamos pela lista toda e contamos o que é mais frequente
Nodo *ordenaOcorrencias(Nodo *L)
{
    int c, maior = 0, IDmaior;;
    Nodo *aux, *R = NULL, *LO = L;
    while (LO != NULL)
    {
        while (L != NULL)
        {
            aux = L;
            while (aux != NULL)
            {
                if (aux->ID == L->ID)
                {
                    c++;
                }
                aux = aux->nseg;
            }
            if (c > maior)
            {
                maior = L->ID;
            }
            L = L->nseg;
        }
        L = LO;
        while (L != NULL)
        {
            if (L->ID == IDmaior)
            {
                aux = L;
                if (aux->nseg != NULL)
                {
                    aux->nseg->nant = aux->nant;
                }
                if (aux->nant != NULL)
                {
                    aux->nant->nseg = aux->nseg;
                }else
                {
                    
                    LO = LO->nseg;
                }
                
                aux->nseg = NULL;
                aux->nant = NULL;
                R = insertLast(R, aux);
            }
            else
            {
                L->nant->nseg;
            }
        }
    }
    return R;
}