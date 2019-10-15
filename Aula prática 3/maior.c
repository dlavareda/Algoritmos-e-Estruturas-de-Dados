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
Nodo *findLast(Nodo *L)
{
    if (L == NULL)
        return L;
    while (L->nseg != NULL)
    {
        L = L->nseg;
    }
    return L;
}

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
Nodo *soma(Nodo *A, Nodo *B)
{
    int t = 0;
    Nodo *R = NULL, *nv;
    A = findLast(A);
    B = findLast(B);
    while (A != NULL || B != NULL)
    {
        nv = makenode();
        nv->N = t;
        if (A != NULL)
        {
            nv->N += A->N;
            A = A->nant;
        }
        if (B != NULL)
        {
            nv->N += B->N;
            B = B->nant;
        }
        t = nv->N / 10;
        R = insertfirst(R, nv);
    }
    if (t > 0)
    {
        nv = makenode();
        nv->N = t;
        R = insertfirst(R, nv);
    }
    return R;
}
Nodo *produtoAux(Nodo *L, int x)
{
    int t = 0;
    Nodo *R = NULL, *nv;
    L = findLast(L);
    while (L != NULL)
    {
        nv = makenode();
        nv->N = t + (L->N * x);
        t = nv->N / 10;
        nv->N %= 10;
        R = insertfirst(L, nv);
        L = L->nant;
    }
    if (t > 0)
    {
        nv = makenode();
        nv->N = t;
        R = insertfirst(R, nv);
    }
    return R;
}

Nodo *produto(Nodo *A, Nodo *B)
{
    Nodo *R = NULL, *nv;
    A = findLast(A);
    B = findLast(B);
    while (A != NULL || B != NULL)
    {
        /* code */
    }
}

void main()
{
    Nodo *L;
}