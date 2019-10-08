#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia, mes, ano;
} Data;
typedef struct MEMBRO
{
    int BI;
    char Nome[80];
    Data dtadmicao;
    struct MEMBRO *nseg;
    struct MEMBRO *nant;
} Membro;

typedef struct ENCONTRO
{
    int ID;
    Data dtencontro;
    int organizacao;
    char tema[80];
    struct ENCONTRO *nseg;
    struct ENCONTRO *nant;
} Encontro;

typedef struct PRESENCAS
{
    int BI;
    int IDencontro;
    struct PRESENCAS *nseg;
    struct PRESENCAS *nant;
} Presencas;
#include "functions.h"

int main()
{
    Encontro *E = NULL;
    Encontro *Env = NULL;
    Membro *M = NULL;
    Membro *Mnv = NULL;
    Presencas *P = NULL;
    Presencas *Pnv = NULL;
    //preenche membros

    Mnv = makenodeMembro();
    Mnv->BI = 123456;
    strcpy(Mnv->Nome, "José Andrade");
    Mnv->dtadmicao.ano = 2000;
    Mnv->dtadmicao.mes = 10;
    Mnv->dtadmicao.dia = 1;
    M = insertlastMembro(M, Mnv);
    Mnv = makenodeMembro();
    Mnv->BI = 321321;
    strcpy(Mnv->Nome, "Vitor Coelho");
    Mnv->dtadmicao.ano = 2002;
    Mnv->dtadmicao.mes = 11;
    Mnv->dtadmicao.dia = 2;
    M = insertlastMembro(M, Mnv);
    Mnv = makenodeMembro();
    Mnv->BI = 123431;
    strcpy(Mnv->Nome, "Andreia Soares");
    Mnv->dtadmicao.ano = 2006;
    Mnv->dtadmicao.mes = 11;
    Mnv->dtadmicao.dia = 3;
    M = insertlastMembro(M, Mnv);
    Mnv = makenodeMembro();
    Mnv->BI = 163435;
    strcpy(Mnv->Nome, "Rita Ferreira");
    Mnv->dtadmicao.ano = 2009;
    Mnv->dtadmicao.mes = 12;
    Mnv->dtadmicao.dia = 13;
    M = insertlastMembro(M, Mnv);

    //preenche Encontros
    Env = makenodeEncontro();
    Env->ID = 1;
    Env->dtencontro.ano = 2014;
    Env->dtencontro.mes = 10;
    Env->dtencontro.dia = 12;
    Env->organizacao = 123456;
    strcpy(Env->tema, "O buraco do ozono");
    E = insertlastEncontro(E, Env);
    //preenche participaçoes do encontro
    Pnv = makenodePresencas();
    Pnv->IDencontro = 1;
    Pnv->BI = 123456;
    P = insertlastPresencas(P, Pnv);
    Pnv = makenodePresencas();
    Pnv->IDencontro = 1;
    Pnv->BI = 321321;
    P = insertlastPresencas(P, Pnv);
    Pnv = makenodePresencas();
    Pnv->IDencontro = 1;
    Pnv->BI = 123431;
    P = insertlastPresencas(P, Pnv);

    //preenche Encontros
    Env = makenodeEncontro();
    Env->ID = 2;
    Env->dtencontro.ano = 2014;
    Env->dtencontro.mes = 11;
    Env->dtencontro.dia = 22;
    Env->organizacao = 321321;
    strcpy(Env->tema, "Espécies animais ameaçadas");
    E = insertlastEncontro(E, Env);
    //preenche participaçoes do encontro
    Pnv = makenodePresencas();
    Pnv->IDencontro = 2;
    Pnv->BI = 321321;
    P = insertlastPresencas(P, Pnv);
    Pnv = makenodePresencas();
    Pnv->IDencontro = 2;
    Pnv->BI = 163435;
    P = insertlastPresencas(P, Pnv);
    //preenche Encontros
    Env = makenodeEncontro();
    Env->ID = 3;
    Env->dtencontro.ano = 2014;
    Env->dtencontro.mes = 11;
    Env->dtencontro.dia = 22;
    Env->organizacao = 321321;
    strcpy(Env->tema, "Turismo na Beira Interior");
    E = insertlastEncontro(E, Env);
    //preenche participaçoes do encontro
    Pnv = makenodePresencas();
    Pnv->IDencontro = 3;
    Pnv->BI = 321321;
    P = insertlastPresencas(P, Pnv);
    int BIORG = 0;
    printf("Introduza o BI a pesquizar");
    scanf("%d", &BIORG);
    float media = 0.0;
    media = mediaPresentes(E, P, BIORG);
    printf("%f", media);
    mostraInactivos(E, M);
    int total = 0;
    int ano = 0;
    printf("Qual o ano a consultar o numero de encontros?\n");
    scanf("%d", &ano);
    total = totalAno(E, ano);
    printf("NO ano %d existiram %d encontros\n", ano, total);
    
}