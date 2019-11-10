#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct NODO
{
    int BI; //critério de ordenação (ascendente)
    char nome[80];
    float salario;
    Data dtNascimento;
    struct NODO *nseg;
    struct NODO *nant;
} Nodo;

/*a. (4 valores) Implemente uma função que verifique se a lista
está bem ordenada.*/
//0=Não, 1=Sim
int bemOrdenada(Nodo *L)
{
    while (L->nseg != NULL)
    {
        if (L->BI > L->nseg->BI)
        {
            return 0;
        }
        L = L->nseg;
    }
    return 1;
}

/*b. Crie uma função que calcule o valor total de salários dos
trabalhadores com determinada idade (especificada em anos).
Protótipo: */

//Devolve “0” caso as datas sejam iguais. “1” caso D1 seja anterior a D2. “-1” caso D2 seja anterior a “D1”.

int comparaDatas(Data d1, Data d2)
{
    if (d1.ano < d2.ano)
        return -1;

    else if (d1.ano > d2.ano)
        return 1;

    if (d1.ano == d2.ano)
    {
        if (d1.mes < d2.mes)
            return -1;
        else if (d1.mes > d2.mes)
            return 1;
        else if (d1.dia < d2.dia)
            return -1;
        else if (d1.dia > d2.dia)
            return 1;
        else
            return 0;
    }
}
Data adicionaData(Data D, int dias, int meses, int anos);
//Adiciona “dias”, “meses” e “anos” a uma determinada data. Devolve a data actualizada. Aceita valores negativos.

//Data now(); //Coloca em “dia”, “mês”, “ano” os valores respeitantes à data actual.
float totalSalarios(Nodo *L, int anos)
{
    Data now, datatmp;
    now.ano = 2019;
    datatmp.ano;
    int resultado, numanos;
    float salarios;
    while (L != NULL)
    {
        datatmp.ano = now.ano;
        datatmp.mes = L->dtNascimento.mes;
        datatmp.dia = L->dtNascimento.dia;
        resultado = comparaDatas(datatmp, now);
        if (resultado == -1 || resultado == 0) //ja fez anos este ano
        {
            numanos = now.ano - L->dtNascimento.ano;
            if (numanos == anos)
            {
                salarios += L->salario;
            }
        }
        else //vai fazer anos este ano
        {
            numanos = (now.ano - L->dtNascimento.ano) - 1;
            if (numanos == anos)
            {
                salarios += L->salario;
            }
        }
        L = L->nseg;
    }
    return salarios;
}

/*c. (4 valores) Implemente uma função que mostre no écran o
nome completo de todas as pessoas cujo BI acabe num
determinado algarismo. */

//digitoBI= último dígito de BI desejado
void mostraEcran(Nodo *L, int digitoBI)
{

    while (L != NULL)
    {
        if ((L->BI) % 10 == digitoBI)
        {
            printf("%s\n", L->nome);
        }
        L = L->nseg;
    }
}

/*d. (4 valores) Crie uma função que divida a lista de trabalhadores
segundo o seu salário. Na primeira lista deverão ficar os 50%
com maiores salários. Na segunda lista, deverão ficar os
restantes elementos.*/
Nodo *insertLast(Nodo *L, Nodo *nv);

//A função deve retornar um apontador para a lista original (vazia)
Nodo *divideLista(Nodo *L, Nodo **primeira, Nodo **segunda)
{
    float menor = FLT_MAX;
    int BImenor, tamanho = 0, tam, count = 0;
    Nodo *aux = L;
    Nodo *aux2;
    //Conta o numero de elementos
    while (L != NULL)
    {
        tamanho++;
        L=L->nseg;
    }
    tamanho = tamanho / 2; // count numero de elementos na lista 1
    L = aux;
    while (L != NULL)
    {
        menor = L->salario;
        BImenor = L->BI;
        aux2 = L->nseg;
        while (aux2 != NULL)
        {
            if (aux2->salario < menor)
            {
                menor = aux2->salario;
                BImenor = aux2->BI;
            }
            aux2 = aux2->nseg;
        }
        L = aux;
        //Já encontrou o menor da lista L
        if (count <= tamanho)
        {
            count++;
            //insere na lista 1
            //remove da lista L
            while (L != NULL)
            {
                if (L->BI == BImenor)
                {
                    *primeira = insertLast(*primeira, L);
                    L->nant->nseg = L->nseg;
                    L->nseg->nant = L->nant;
                }
            }
        }
        else
        {
            //insere na lista 2
            //remove da lista L
            while (L != NULL)
            {
                if (L->BI == BImenor)
                {
                    *segunda = insertLast(*segunda, L);
                    L->nant->nseg = L->nseg;
                    L->nseg->nant = L->nant;
                }
            }
        }

        L = L->nseg;
    }

    return L;
}
