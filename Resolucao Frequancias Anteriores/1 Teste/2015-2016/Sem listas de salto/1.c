#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{

    Observacao *O = NULL;
    Observador *P = NULL;
    Observacao *nvo = NULL;
    Observador *nvp = NULL;
    nvp = makenodeObservador();
    nvp->codigo = 3;
    strcpy(nvp->nome, "José Andrade");
    P = insertlastObservador(P, nvp);
    nvp = makenodeObservador();
    nvp->codigo = 2;
    strcpy(nvp->nome, "Vitor Coelho");
    P = insertlastObservador(P, nvp);
    nvp = makenodeObservador();
    nvp->codigo = 4;
    strcpy(nvp->nome, "Andreia Soares");
    P = insertlastObservador(P, nvp);
    nvp = makenodeObservador();
    nvp->codigo = 1;
    strcpy(nvp->nome, "Paula Correia");
    P = insertlastObservador(P, nvp);

    nvo = makenodeObservacao();
    nvo->dia = 12;
    nvo->ano = 2014;
    nvo->mes = 10;
    strcpy(nvo->nome, "xyz14");
    nvo->observador = getObservador(P, 1);
    nvo->distancia = 300;
    O = insertlastObservacao(O, nvo);

    nvo = makenodeObservacao();
    nvo->dia = 12;
    nvo->ano = 2014;
    nvo->mes = 11;
    strcpy(nvo->nome, "alfa14");
    nvo->observador = getObservador(P, 2);
    nvo->distancia = 100;
    O = insertlastObservacao(O, nvo);

    nvo = makenodeObservacao();
    nvo->dia = 2;
    nvo->ano = 2014;
    nvo->mes = 12;
    strcpy(nvo->nome, "beta10");
    nvo->observador = getObservador(P, 2);
    nvo->distancia = 100;
    O = insertlastObservacao(O, nvo);

    nvo = makenodeObservacao();
    nvo->dia = 12;
    nvo->ano = 2015;
    nvo->mes = 1;
    strcpy(nvo->nome, "zz23");
    nvo->observador = getObservador(P, 1);
    nvo->distancia = 10;
    O = insertlastObservacao(O, nvo);

    nvo = makenodeObservacao();
    nvo->dia = 10;
    nvo->ano = 2015;
    nvo->mes = 2;
    strcpy(nvo->nome, "omega0");
    nvo->observador = getObservador(P, 1);
    nvo->distancia = 14;
    O = insertlastObservacao(O, nvo);

    nvo = makenodeObservacao();
    nvo->dia = 10;
    nvo->ano = 2015;
    nvo->mes = 15;
    strcpy(nvo->nome, "omega1");
    nvo->observador = getObservador(P, 4);
    nvo->distancia = 25;
    O = insertlastObservacao(O, nvo);

    mostraObservaforesNulos(P, O);
    int dia1, mes1, ano1, dia2, mes2, ano2, total;
printf("\n");
    printf("Ano 1\n");
    scanf("%d", &ano1);
    printf("Mes 1\n");
    scanf("%d", &mes1);
    printf("Dia 1\n");
    scanf("%d", &dia1);
    printf("Ano 2\n");
    scanf("%d", &ano2);
    printf("Mes 2\n");
    scanf("%d", &mes2);
    printf("Dia 2\n");
    scanf("%d", &dia2);
total = totalObservacoes(O, dia1, mes1, ano1, dia2, mes2, ano2);
printf("Total de observaçoes no intervalo = %d\n", total);
    return 0;
}
