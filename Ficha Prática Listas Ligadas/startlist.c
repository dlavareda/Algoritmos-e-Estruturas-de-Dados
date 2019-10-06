#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
//Função criada para criar uma lista duplamente ligada de forma a testar as funções da ficha
int main()
{
    Nodo *L = NULL, *nv;
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        nv = makenode();
        nv->ID = i;
        L = insertlast(L, nv);
    }
    count = totalElementos(L);
    printf("%d", count);
}