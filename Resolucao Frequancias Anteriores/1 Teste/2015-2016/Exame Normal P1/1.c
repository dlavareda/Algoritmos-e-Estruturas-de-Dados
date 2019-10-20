#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct EVENTO
{
    int codigo; //criterio de ordenaçao na lista
    int dia, mes, ano;
    char descricao[80];
    float distanciaKM;
    struct EVENTO *nseg;
} Evento;

typedef struct PARTICIPACAO
{ //sem criterio de ordenação especificado
    Evento *evento;
    struct PARTICIPACAO *nseg;
} Participacao;

typedef struct SOCIO
{ //sem criterio de ordenação especificado
    int codigo;
    char nome[80];
    struct SOCIO *nseg, *nant;
    Participacao *eventos;
} Socio;
#include "functions.h"

void main()
{
    Evento *E = NULL;
    Evento *nve = NULL;

    nve = makenodeEvento();
    nve->codigo = 1;
    nve->ano = 2016;
    strcpy(nve->descricao, "Maratona");
    nve->dia = 1;
    nve->distanciaKM = 42.1;
    nve->mes = 3;
    E = insertlastEvento(E, nve);

    nve = makenodeEvento();
    nve->codigo = 2;
    nve->ano = 2016;
    strcpy(nve->descricao, "Curta");
    nve->dia = 5;
    nve->distanciaKM = 2;
    nve->mes = 6;
    E = insertlastEvento(E, nve);

    nve = makenodeEvento();
    nve->codigo = 3;
    nve->ano = 2016;
    strcpy(nve->descricao, "Média");
    nve->dia = 8;
    nve->distanciaKM = 12;
    nve->mes = 11;
    E = insertlastEvento(E, nve);

    nve = makenodeEvento();
    nve->codigo = 4;
    nve->ano = 2016;
    strcpy(nve->descricao, "Longa");
    nve->dia = 4;
    nve->distanciaKM = 28;
    nve->mes = 11;
    E = insertlastEvento(E, nve);

    while (E != NULL)
    {
        printf("%f\n", E->distanciaKM);
        E = E->nseg;
    }

    Socio *S = NULL;
    Socio *nvs = NULL;

    nvs = makenodeSocio();
    nvs->codigo = 1;
    strcpy(nvs->nome, "José Ramos");
    nvs->eventos
}