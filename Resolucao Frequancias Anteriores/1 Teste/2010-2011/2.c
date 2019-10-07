#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    Eleicao *L = NULL;
    Eleicao *nv = NULL;
    nv = makenode();
    nv->BI = 123456781;
    nv->totVotos = 2;
    nv->BIVoto = 100000001;
    L = insertlast(L, nv);
    nv = makenode();
    nv->BI = 123456782;
    nv->totVotos = 1;
    nv->BIVoto = 100000002;
    L = insertlast(L, nv);
    nv = makenode();
    nv->BI = 123456783;
    nv->totVotos = 1;
    nv->BIVoto = 100000002;
    L = insertlast(L, nv);
    nv = makenode();
    nv->BI = 123456784;
    nv->totVotos = 1;
    nv->BIVoto = 100000002;
    L = insertlast(L, nv);
    nv = makenode();
    nv->BI = 123456786;
    nv->totVotos = 2;
    nv->BIVoto = 100000001;
    L = insertlast(L, nv);
    int fraude = 0;
    fraude = fraudulentas(L);
    if (fraude == 1)
    {
        printf("Votação fraudulenta\n");
    }
    else
    {
        printf("Votação válida\n");
    }
    int totalvotos;
    totalvotos = totalVotos(L);
    printf("Total de votos = %d\n", totalvotos);

    int query;
    float percent;
    printf("Qual o BI do candidato a consultar a percentagem de votaçoes: ");
    scanf("%d", &query);
    percent = percentagem(L, query);
    printf("A percentagem do candidato %d foi de %f\n", query, percent);
    int winner;
    winner = vencedor(L);
    printf("O vencedor foi: %d\n", winner);
}