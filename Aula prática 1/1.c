#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ID;
    struct T *nseg;
} Nodo;

int ordenada(Nodo *L)
{
    int aux;

    //corre a lista
    while (L != NULL && L->nseg != NULL)
    {
        if (L->ID < ((L->nseg)->ID))
        {
            //Encontrou um que nao esta por ordem
            return 0;
        }
        L = L->nseg;
    }
    //Existem 0, 1 elementos ou chegou ao fim da lista e está ordenada
    return 1;
}

int main()
{
}
