#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"
//Função criada para criar uma lista duplamente ligada de forma a testar as funções da ficha
int main()
{
    Nodo *L1 = NULL, *nv;
    Nodo *L2 = NULL;
    Nodo *L3 = NULL;
    int count = 0;
    for (int i = 0; i <= 100; i++)
    {
        nv = makenode();
        nv->ID = i;
        L1 = insertlast(L1, nv);
    }
    int num;
printf("Introduza o numero a remover 0-100\n");
scanf("%d", &num);
  L1 = removeocorrencias(L1, num);

    while (L1 != NULL)
    {
        printf("ID = %d\n", L1->ID);
        L1 = L1->nseg;
    }
}