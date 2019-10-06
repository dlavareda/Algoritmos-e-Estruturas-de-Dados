
#include <stdio.h>
#include <stdlib.h>

typedef struct NODO
{
    int ID; //Identificador do nó;
    //campos associados aos dados da lista
    struct NODO *nseg;
    struct NODO *nant;

} Nodo;

//makenode
Nodo *makenode()
{
    Nodo *nv;
    nv = (Nodo *)malloc(sizeof(Nodo));
    nv->nseg = NULL;
    nv->nant = NULL;
    return (nv);
}

//1 - Implemente uma função para devolver o total de elementos de uma lista.
int totalElementos(Nodo *L)
{
    int count = 0;
    while (L->nseg != NULL)
    {
        count++;
        L = L->nseg;
    }
    return count;
}

//2 - Implemente uma função para devolver o total de elementos diferentes de uma lista.

//Sem ordenação
int totalElementosDiferentes(Nodo *L)
{
    Nodo *aux;
    int count = 0;
    while (L != NULL) //Passa por todos
    {
        aux = L->nant;
        while (aux != NULL) //ver se para tras do L existe algum igual
        {
            if (L->ID == aux->ID)
            {
                break;
            }
            aux = aux->nant;
        }
        if (aux == NULL) //se o AUX for NULL é que chegou ao inicio e nao encontrou nenhum igual
        {
            count++;
        }
        L = L->nseg;
    }
    return count;
}

//Ordenada
int totalElementosDiferentesOrdenada(Nodo *L)
{
    int count = 1;
    if (L == NULL)
        return 0;
    while (L->nseg != NULL)
    {
        if (L->ID != (L->nseg)->ID)
        {
            count++;
        }
        L = L->nseg;
    }
    return count;
}

//3 - Codifique uma função que permita inserir um novo elemento na primeira posição da lista.
Nodo *insertfirst(Nodo *L, Nodo *nv)
{
    nv->nseg = L;
    return nv;
}

//4 - Codifique uma função que permita inserir um novo elemento na última posição da lista.

Nodo *insertlast(Nodo *L, Nodo *nv)
{

    Nodo *aux = L;
    if (L == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    nv->nant = aux;
    return L;
}

//////////////////////////5 - Codifique uma função que permita inserir numa posição definida pelo utilizador um novo elemento na lista.
Nodo *insereElemento(Nodo *L, Nodo *nv, int pos)
{
    Nodo *aux = L;
    Nodo *R;
    int count = 0;
    if (pos == 0)
    {
        R = insertfirst(L, nv);
        return R;
    }
    while (L != NULL)
    {
        if (count != pos)
        {
            L = L->nseg;
            count++;
        }
        else
        {
            L->nant->nseg = nv;
            nv->nant = L->nant;
            nv->nseg = L;
            L->nant = nv;
            break;
        }
    }
    return aux;
}

//6 - Codifique uma função que permita inserir ordenadamente um novo elemento na lista.
Nodo *insereElementoOrdem(Nodo *L, Nodo *nv)
{

    Nodo *AUX = L;
    //insere no inicio porque esta vazia
    if (L == NULL)
    {
        return nv;
    }
    if (L->ID > nv->ID)
    {
        nv->nseg = L;
        return nv;
    }

    //insere pelo meio
    while (L->nseg != NULL)
    {
        if (((L->nseg)->ID) > nv->ID)
        {
            break;
        }
        L = L->nseg;
    }
    nv->nseg = L->nseg;
    L->nseg = nv;
    return (AUX);
}

//7- Verifique se L está ordenada ou não
int listaOrdenada(Nodo *L)
{
    int aux;

    //corre a lista
    while (L != NULL && L->nseg != NULL)
    {
        if (L->ID < ((L->nseg)->ID))
        {
            //Encontrou um que nao esta por ordem
            return 0;
        }
        L = L->nseg;
    }
    //Existem 0, 1 elementos ou chegou ao fim da lista e está ordenada
    return 1;
}

//8- Faça uma cópia da lista L em uma outra lista L2;
Nodo *copiaLista(Nodo *L)
{

    Nodo *N = NULL, *nv;
    while (L != NULL)
    {
        nv = makenode();
        nv->ID = L->ID;
        N = insertlast(N, nv);
        L = L->nseg;
    }
}
//9 - Inverta L colocando o resultado em L2;
Nodo *inverteListaComL2(Nodo *L)
{
    Nodo *aux, *R;
    while (L != NULL)
    {
        aux = L;
        L = L->nseg;
        aux->nseg = NULL;
        if (L != NULL)
        {
            L->nant = NULL;
        }
        R = insertfirst(R, aux);
    }
    return R;
}
//10 - Inverta L colocando o resultado na própria L;
/*Nodo *inverteLista(Nodo *L)
{
    Nodo *aux;
    L = L->nseg;

    while (L->nseg != NULL)
    {
        aux=L->nseg;
        L->nant->nseg = L->nant->nant;
        L->nant = NULL;
        L = aux;
    }
    L->nseg = L->nant;
    L->nant = NULL;

    return L;
}*/
//11 - Intercale L1 com a lista L2, gerando a lista L3. Considere que
// a - L1, L2 estão ordenadas, bem como a lista resultante L3 deverá estar.
Nodo *intercalaLista(Nodo *L1, Nodo *L2)
{
    Nodo *nv;
    Nodo *L3 = NULL;
    while (L1 != NULL && L2 != NULL)
    {
        nv = makenode();
        nv->ID = L1->ID;
        nv->nant = NULL;
        nv->nseg = NULL;
        L3 = insertlast(L3, nv);
        nv = makenode();
        nv->ID = L2->ID;
        nv->nant = NULL;
        nv->nseg = NULL;
        L3 = insertlast(L3, nv);
        L1 = L1->nseg;
        L2 = L2->nseg;
    }
    return L3;
}

// b - L1, L2 não têm ordenação específica, assim como a lista resultante L3.
/*Nodo *intercalaLista(Nodo *L1, Nodo *L2)
{
}
*/
//12 - Elimine de L todas as ocorrências de um elemento dado, estando a lista ordenada.
/*Nodo *intercalaLista(Nodo *L1, int chave)
{
}
*/
//13 - Assumindo que existe um atributo em “Nodo” que guarda um inteiro positivo (int valor), crie uma função que imprima o elemento que ocorre mais vezes na lista.
/*void imprimeFrequente(Nodo *L)
{
}*/