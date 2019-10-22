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
    int i;
    while (L != NULL) // Percorre a lista
    {
        for (i = 0; i < L->salto - 1; i++) //teta para todos os niveis
        {
            if ((L->nseg[i] == NULL) && (L->nseg[i + 1] != NULL)) // Verifica se ha ulma ligação acima que nao ha abaixo
                return 0;
            if ((L->nseg[i] != NULL) && (L->nseg[i + 1] != NULL)) // Se ha um salto maior em baixo do que em cima
            {
                if (L->nseg[i]->ID > L->nseg[i + 1]->ID)
                {
                    return 0;
                }
            }
        }
        L = L->nseg[0];
    }
    return 1;
}

Nodo *muliplexer(Nodo **A, Nodo **B)
{
    Nodo *out;
    while (*A != NULL || *B != NULL)
    {
        if (*A != NULL)
            out = push(out, pop(A));
        if (*B != NULL)
            out = push(out, pop(B));
    }
    return out;
}

void demultiplexer(Nodo **in, Nodo **out_p, Nodo **out_i)
{

    while (*in != NULL)
    {
        *out_p = push(*out_p, pop(in));
        if (*in != NULL)
        {
            *out_i = push(*out_i, pop(in));
        }
    }
}

int ListaCircular(Nodo *L)
{

    while (L != NULL)
    {
        if (L->nseg != NULL)
        {
            if (L->nseg->ID < L->ID)
            {
                return 0;
            }
        }
        L = L->nseg;
    }
    return 1;
}

int ListaCircular(Nodo *L)
{
    Nodo *aux;
    Nodo *act = L;
    while (act != NULL)
    {
        aux = L;
        while (aux != act)
        {
            if (act->nseg == aux)
                return 1;
            aux = aux->nseg;
        }
        act = act->nseg;
    }
    return 0;
}