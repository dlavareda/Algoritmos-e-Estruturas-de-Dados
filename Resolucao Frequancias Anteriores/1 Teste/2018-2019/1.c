#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <string.h>
//1b

int main()
{

    Servico *S = NULL;
    Servico *nvs = NULL;
    Recebidos *R = NULL;
    Recebidos *nvr = NULL;
    Prestados *P = NULL;
    Prestados *nvp = NULL;
    Pessoa *Person = NULL;
    Pessoa *nvperson = NULL;

    //preeenche pessoa
    //Pessoa 1
    nvperson = makenodePessoa();
    nvperson->BI = 123456789;
    strcpy(nvperson->nome, "Pedro Amaro");
    Person = insertlastPessoa(Person, nvperson);
    //Pessoa 2
    nvperson = makenodePessoa();
    nvperson->BI = 789456123;
    strcpy(nvperson->nome, "Manuel Silva");
    Person = insertlastPessoa(Person, nvperson);
    //Pessoa 3
    nvperson = makenodePessoa();
    nvperson->BI = 963852741;
    strcpy(nvperson->nome, "Maria Coelho");
    Person = insertlastPessoa(Person, nvperson);
    //Pessoa 4
    nvperson = makenodePessoa();
    nvperson->BI = 147258369;
    strcpy(nvperson->nome, "Jose Silva");
    Person = insertlastPessoa(Person, nvperson);
    //Pessoa 5
    nvperson = makenodePessoa();
    nvperson->BI = 852963741;
    strcpy(nvperson->nome, "Filipe Gomes");
    Person = insertlastPessoa(Person, nvperson);
    //Pessoa 6
    nvperson = makenodePessoa();
    nvperson->BI = 789654123;
    strcpy(nvperson->nome, "Carlos Joaquim");
    Person = insertlastPessoa(Person, nvperson);

    //Preenche Servico / Prestados / Recebidos
    //Servico 1
    nvs = makenodeServico();
    nvs->ano = 2018;
    nvs->mes = 12;
    nvs->dia = 23;
    strcpy(nvs->descricao, "Passar a Ferro");
    nvp = makenodePrestados();
    nvp->person = getPessoaBI(Person, 963852741);
    P = insertlastPrestados(P, nvp);
    nvp = makenodePrestados();
    nvp->person = getPessoaBI(Person, 147258369);
    P = insertlastPrestados(P, nvp);   
    nvs->P = P;
    nvr = makenodeRecebidos();
    nvr->person = getPessoaBI(Person, 789456123);
    R = insertlastRecebidos(R, nvr);
    nvr = makenodeRecebidos();
    nvr->person = getPessoaBI(Person, 147258369);
    R = insertlastRecebidos(R, nvr);
    nvs->R = R;
    S = insertlastServico(S, nvs);
    R = NULL;
    P = NULL;
   //Servico 2
    nvs = makenodeServico();
    nvs->ano = 2019;
    nvs->mes = 1;
    nvs->dia = 2;
    strcpy(nvs->descricao, "Limpar a casa");
    nvp = makenodePrestados();
    nvp->person = getPessoaBI(Person, 147258369);
    P = insertlastPrestados(P, nvp);
    nvs->P = P;
    nvr = makenodeRecebidos();
    nvr->person = getPessoaBI(Person, 147258369);
    R = insertlastRecebidos(R, nvr);
    nvr = makenodeRecebidos();
    nvr->person = getPessoaBI(Person, 852963741);
    R = insertlastRecebidos(R, nvr);
    nvs->R = R;
    S = insertlastServico(S, nvs);
    R = NULL;
    P = NULL;
   //Servico 3
    nvs = makenodeServico();
    nvs->ano = 2019;
    nvs->mes = 15;
    nvs->dia = 12;
    strcpy(nvs->descricao, "Lavar o carro");
    nvp = makenodePrestados();
    nvp->person = getPessoaBI(Person, 963852741);
    P = insertlastPrestados(P, nvp);
    nvs->P = P;
    nvr = makenodeRecebidos();
    nvr->person = getPessoaBI(Person, 789654123);
    R = insertlastRecebidos(R, nvr);
    nvs->R = R;
    S = insertlastServico(S, nvs);
    R = NULL;
    P = NULL;
   //Servico 4
    nvs = makenodeServico();
    nvs->ano = 2019;
    nvs->mes = 7;
    nvs->dia = 20;
    strcpy(nvs->descricao, "Arranjar o telhado");
    nvp = makenodePrestados();
    nvp->person = getPessoaBI(Person, 963852741);
    P = insertlastPrestados(P, nvp);
    nvs->P = P;
    nvr = makenodeRecebidos();
    nvr->person = getPessoaBI(Person, 852963741);
    R = insertlastRecebidos(R, nvr);
    nvs->R = R;
    S = insertlastServico(S, nvs);
    R = NULL;
    P = NULL;

    int total = totalServicosPrestados(S, 147258369);
    printf("%d", total);
    printf("\n");
    listaPreguicosos(Person, S);
    return 0;
}
/*
Pessoa
123456789 - Pedro amaro;
789456123 - Manuel Silva;
963852741 - Maria Coelho;
147258369 - Jose Silva;
852963741 - Filipe Gomes;
789654123 - Carlos Joaquim;

Servicos
23/12/2018
Passar a Ferro
recebidos 789456123, 147258369
prestados 963852741, 147258369

2/01/2019
Limpar a casa
recebidos 147258369, 852963741
prestados 147258369

12/05/2019
Lavar o carro
recebidos 789654123
prestados 963852741

20/07/2019
Arranjar o telhado
recebidos 852963741
prestados 963852741
*/