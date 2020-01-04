#include <stdio.h>
#include <strings.h>

typedef struct NODOAB
{
{
    int codigo; //id
    char nome[80];
    struct NODOAB *fe, *fd;
} NodoAB;

NodoAB *treeInsert(NodoAB *root, NodoAB nv)
{ //inserir elemento na arvore
    if (root == NULL)
    {
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
NodoAB *makenode(int codigo, char nome[])
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
2a) (2 valores) Implemente uma função que conte o número de empregados com um determinado 1º nome.
Protótipo: int contaNomeProprio(NodoAB *A, char *nome)
*/
int contaNomeProprio(NodoAB *A, char *nome)
{
    if (A == NULL)
    {
        return 0;
    }
    if (strstr(A->nome, nome) != NULL)
    {
        return 1 + contaNomeProprio(A->fe, nome) + contaNomeProprio(A->fd, nome);
    }
    else
    {
        return contaNomeProprio(A->fe, nome) + contaNomeProprio(A->fd, nome);
    }
}

/*2b) (3 valores) Implemente a função que apaga uma árvore binária.
Protótipo: NodoAb* apagaArvoreo(NodoAB *A)*/

NodoAB *getpai(NodoAB *A, NodoAB *filho)
{
    if (A == NULL)
    {
        return NULL;
    }
    if (A->fe == filho || A->fd == filho)
    {
        return A;
    }
    else
    {
        getpai(A->fe, filho);
        getpai(A->fd, filho);
    }
}
NodoAB *apagaArvoreAUX(NodoAB *A, NodoAB *ORIGINAL)
{
    if (A == NULL)
    {
        return A;
    }
    if (A->fe == NULL && A->fd == NULL)
    {
        NodoAB *aux = getpai(A, ORIGINAL);
        if (aux->fe == A)
        {
            aux->fe = NULL;
            free(A);   
        }else{
            aux->fd = NULL;
            free(A);
        }
        return NULL;
    }else
    {
        apagaArvoreAUX(A->fe, ORIGINAL);
        apagaArvoreAUX(A->fd, ORIGINAL);
    }
}
NodoAB *apagaArvore(NodoAB *A) // Não concluido
{
    return apagaArvoreAUX(A, A);
}


void main()
{
    NodoAB *AB, *nv;
    nv = makenode(2, "José Andrade");
    AB = treeInsert(AB, *nv);
    nv = makenode(3, "André Almeida");
    AB = treeInsert(AB, *nv);
    nv = makenode(1, "André Soares");
    AB = treeInsert(AB, *nv);
    nv = makenode(4, "Paula Correia");
    AB = treeInsert(AB, *nv);
    nv = makenode(7, "Vitor Santos");
    AB = treeInsert(AB, *nv);
    nv = makenode(6, "Hugo Filipe");
    AB = treeInsert(AB, *nv);
    printf("TOtal de Andrés =  %d", contaNomeProprio(AB, "André"));
    AB = apagaArvore(AB);
    printf("pause");
}