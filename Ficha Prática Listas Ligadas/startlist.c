#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
//Função criada para criar uma lista duplamente ligada de forma a testar as funções da ficha
int main()
{
    Nodo *L1 = NULL, *nv;
    Nodo *L2 = NULL;
    Nodo *L3 = NULL;
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        nv = makenode();
        nv->ID = i;
        L1 = insertlast(L1, nv);
    }

    count = 0;
    for (int i = 0; i < 10; i++)
    {
        nv = makenode();
        nv->ID = i + 10;
        L2 = insertlast(L2, nv);
    }

   L3 = intercalaLista(L1, L2);
    while (L3 != NULL)
    {
        printf("ID = %d\n", L3->ID);
        L3 = L3->nseg;
    }
}