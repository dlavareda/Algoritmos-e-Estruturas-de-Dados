#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int ContaNos(Nodo *L);

typedef struct NODO
{
    int N;
    struct NODO *nseg;
    struct NODO *nant;

} Nodo;

int maior(Nodo *A, Nodo *B)
{
    int sizeA, sizeB;
    sizeA = ContaNos(A);
    sizeB = ContaNos(B);
    if (sizeA > sizeB)
        return 1;
    else if (sizeB > sizeA)
        return 0;
    while (A != NULL)
    {
        if (A->N > B->N)
            return 1;
        if (B->N > A->N)
            return 0;
        A = A->nseg;
        B = B->nseg;
    }
    return 0;
}

void main()
{
    Nodo *L;
}