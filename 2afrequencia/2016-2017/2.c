#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODO_AB
{
    int BI; //chave de ordenação na árvore
    char nome[80];
    int totalMinutos; //total de minutos facturados
    struct NODO_AB *fe, *fd;
} NodoAB;

NodoAB *treeInsert(NodoAB *root, NodoAB nv)
{ //inserir elemento na arvore
    if (root == NULL)
    {
        NodoAB *aux = (NodoAB *)malloc(sizeof(NodoAB));
        aux->BI = nv.BI;
        // strcpy(aux->nome, nv.nome);
        aux->totalMinutos = nv.totalMinutos;
        aux->fe = NULL;
        aux->fd = NULL;
        return aux;
    }
    else
    {
        if (nv.BI > root->BI)
        {
            root->fd = treeInsert(root->fd, nv);
        }
        else if (nv.BI < root->BI)
        {
            root->fe = treeInsert(root->fe, nv);
        }
    }
    return root;
}
NodoAB *makenode(int BI, char nome, int totalMinutos)
{
    NodoAB *nv;
    nv = (NodoAB *)malloc(sizeof(NodoAB));
    nv->BI = BI;
    //strcpy(nv->nome, nome);
    nv->totalMinutos = totalMinutos;
    nv->fe = NULL;
    nv->fd = NULL;
    return (nv);
}

/*
Implemente uma função que mostre (ordenadamente) o BI dos elementos com valor total de minutos facturados superior a um limite.
Protótipo: void mostraClientes(NodoAB *A, int totMinutos);
*/

void mostraClientes(NodoAB *A, int totMinutos)
{
    if (A == NULL)
    {
        return;
    }
    if (A->fe != NULL)
    {
        mostraClientes(A->fe, totMinutos);
    }
    if (A->totalMinutos > totMinutos)
    {
        printf("%d\n", A->BI);
    }
    if (A->fd != NULL)
    {
        mostraClientes(A->fd, totMinutos);
    }
}

/*
II-3 (3 valores) Implemente uma função que remova todas as folhas de uma árvore.
Protótipo: NodoAB* cortaFolhas(NodoAB *A);
*/
int altura(NodoAB *A)
{
    int d, e;
    if (A == NULL)
        return 0;
    e = altura(A->fe);
    d = altura(A->fd);
    if (e > d)
    {
        return e + 1;
    }
    else
    {
        return d + 1;
    }
}
NodoAB *getpai(NodoAB *filho, NodoAB *AB)
{
    if (AB == NULL)
    {
        return;
    }
    if (filho == AB->fe || filho == AB->fd)
    {
        return AB;
    }
    getpai(filho, AB->fe);
    getpai(filho, AB->fd);
}

NodoAB *cortaFolhasAux(NodoAB *AB, NodoAB *ABORIGINAL)
{
    NodoAB *aux;
    if (AB == NULL)
    {
        return NULL;
    }
    if (AB->fe == NULL && AB->fd == NULL)
    {
        aux = getpai(AB, ABORIGINAL);
        if (aux->fe == AB)
        {
            aux->fe = NULL;
            free(AB);
        }
        else
        {
            aux->fd = NULL;
            free(AB);
        }
        return NULL;
    }
    AB->fe = cortaFolhasAux(AB->fe, ABORIGINAL);
    AB->fd = cortaFolhasAux(AB->fd, ABORIGINAL);
    //return AB;
}
NodoAB *cortaFolhas(NodoAB *A)
{
    return cortaFolhasAux(A, A);
}

/*
II-4 (3 valores) Implemente uma função que compare 2 árvores binárias e confirme se estas têm igual estrutura, isto é, independentemente do
conteúdo de cada nó, o total de nós e a sua organização em ambas as árvores é ou não igual (1=sim, 0=não).
Protótipo: int igualEstrutura(NodoAB *A1, NodoAB *A2);
*/
int igualEstrutura(NodoAB *A1, NodoAB *A2)
{
    if (A1 == NULL && A2 == NULL)
    {
        return 1;
    }
    if (A1->fe && A2->fe && A1->fd && A2->fd)
    {
        return 1 * igualEstrutura(A1->fe, A2->fe) * igualEstrutura(A1->fd, A2->fd);
    }
    else if (A1->fe && A2->fe && !A1->fd && !A2->fd)
    {
        return 1 * igualEstrutura(A1->fe, A2->fe);
    }
    else if (!A1->fe && !A2->fe && A1->fd && A2->fd)
    {
        return 1 * igualEstrutura(A1->fd, A2->fd);
    }else if (!A1->fe && !A2->fe && !A1->fd && !A2->fd)
    {
        return 1;
    }
     return 0;
    
   // return igualEstrutura(A1->fe, A2->fe) * igualEstrutura(A1->fd, A2->fd);
}

void main()
{ /* condition */
    NodoAB *AB, *nv;
    NodoAB *AB2 = NULL;
    nv = makenode(5, "Diogo", 60);
    AB = treeInsert(AB, *nv);
    nv = makenode(1, "Pedro", 50);
    AB = treeInsert(AB, *nv);
    nv = makenode(10, "Diogo", 40);
    AB = treeInsert(AB, *nv);
    nv = makenode(20, "Diogo", 40);
    AB = treeInsert(AB, *nv);

    mostraClientes(AB, 10);
    AB = cortaFolhas(AB);
    printf("2");
    mostraClientes(AB, 10);
    printf("\nCompare AB com AB check %d", igualEstrutura(AB, AB));

    nv = makenode(5, "Diogo", 40);
    AB2 = treeInsert(AB2, *nv);
    nv = makenode(17, "Diogo", 40);
    AB2 = treeInsert(AB2, *nv);
    nv = makenode(50, "Diogo", 40);
    AB2 = treeInsert(AB2, *nv);
    printf("\nCompare AB com AB2 check %d", igualEstrutura(AB, AB2));
}