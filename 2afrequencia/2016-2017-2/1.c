#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODOAB
{
    int codigo; //chave de ordenação na árvore
    char nome[80];
    struct NODOAB *fe, *fd;
} NodoAB;

NodoAB *treeInsert(NodoAB *root, NodoAB nv)
{ //inserir elemento na arvore
    if (root == NULL)
    {

        // return igualEstrutura(A1->fe, A2->fe) * igualEstrutura(A1->fd, A2->fd);
        NodoAB *aux = (NodoAB *)malloc(sizeof(NodoAB));
        aux->codigo = nv.codigo;
        strcpy(aux->nome, nv.nome);
        aux->fe = NULL;
        aux->fd = NULL;
        return aux;
    }
    else
    {
        if (nv.codigo > root->codigo)
        {
            root->fd = treeInsert(root->fd, nv);
        }
        else if (nv.codigo < root->codigo)
        {
            root->fe = treeInsert(root->fe, nv);
        }
    }
    return root;
}
NodoAB *makenode(int codigo, char nome[80])
{
    NodoAB *nv;
    nv = (NodoAB *)malloc(sizeof(NodoAB));
    nv->codigo = codigo;
    strcpy(nv->nome, nome);
    nv->fe = NULL;
    nv->fd = NULL;
    return (nv);
}

/*
1c) (3 valores) Codifique uma função que conte o total de pessoas com um determinado primeiro nome. Por exemplo, para os dados acima e
o nome “André”, deveria devolver 2.
Protótipo: int totalNomeProprio(NodoAb *A, char *nome);
*/

int totalNomeProprio(NodoAB *A, char *nome)
{
    if (A == NULL)
    {
        return 0;
    }

    int flag = 1;
    if (strstr(A->nome, nome) != NULL)
    {
        return 1 + totalNomeProprio(A->fe, nome) + totalNomeProprio(A->fd, nome);
    }
    else
    {
        return totalNomeProprio(A->fe, nome) + totalNomeProprio(A->fd, nome);
    }
}

/*
1d) (3 valores) Implemente uma função que imprima o nome de todos os elementos com código superior a determinado valor. Suponha que
tem à sua disposição a função “int contaNos(NodoAb *A)”, que retorna o total de nós de uma árvore binária.
Protótipo: void listaNomes(NodoAb *A, int cod);
*/
void listaNomes(NodoAB *A, int cod)
{
    if (A == NULL)
    {
        return;
    }
    listaNomes(A->fe, cod);
    if (A->codigo > cod)
    {
        printf("%s\n", A->nome);
    }
    listaNomes(A->fd, cod);
}

/*
1e) (3 valores) Implemente uma função que conte o total de nós a um determinado nível da árvore. Se achar conveniente, pode criar funções
auxiliares com parâmetros adicionais.
Protótipo: int contaNosNivel(NodoAb *A, int nivel);
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
int contaNosNivel(NodoAB *A, int nivel)
{
    if (A == NULL)
    {
        return 0;
    }
    if (altura(A) == nivel)
    {
        return 1;
    }
    else
    {
        return contaNosNivel(A->fe, nivel) + contaNosNivel(A->fd, nivel);
    }
}

void main()
{
    NodoAB *AB, *nv;
    nv = makenode(2, "José Andrade");
    AB = treeInsert(AB, *nv);
    nv = makenode(3, "André Almeida");
    AB = treeInsert(AB, *nv);
    nv = makenode(4, "André Soares");
    AB = treeInsert(AB, *nv);
    nv = makenode(1, "Paula Correia");
    AB = treeInsert(AB, *nv);
    nv = makenode(5, "Vitor Santos");
    AB = treeInsert(AB, *nv);
    nv = makenode(7, "Hugo Filipe");
    AB = treeInsert(AB, *nv);
    printf("Total André: %d", totalNomeProprio(AB, "André"));
    listaNomes(AB, 5);
    printf("Numero nos nivel 2 %d", contaNosNivel(AB, 2));
    printf("\npausa");
}