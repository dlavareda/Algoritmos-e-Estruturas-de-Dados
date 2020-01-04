#include <stdio.h>

typedef struct BIN
{
    int chave; //Critério de ordenação na árvore
    int aux;
    struct BIN *fe, *fd;
} Bin;

Bin *treeInsert(Bin *root, Bin nv)
{ //inserir elemento na arvore
    if (root == NULL)
    {
        Bin *aux = (Bin *)malloc(sizeof(Bin));
        aux->chave = nv.chave;
        aux->aux = nv.aux;
        aux->fe = NULL;
        aux->fd = NULL;
        return aux;
    }
    else
    {
        if (nv.chave > root->chave)
        {
            root->fd = treeInsert(root->fd, nv);
        }
        else if (nv.chave < root->chave)
        {
            root->fe = treeInsert(root->fe, nv);
        }
    }
    return root;
}
Bin *makenode(int chave, int aux)
{
    Bin *nv;
    nv = (Bin *)malloc(sizeof(Bin));
    nv->chave = chave;
    nv->aux = aux;
    nv->fe = NULL;
    nv->fd = NULL;
    return (nv);
}
/*	
a.(3 valores) Crie uma função que devolva o total de nós com aux=X.
int total(Bin *A, int aux);
*/
int total(Bin *A, int aux)
{
    if (A == NULL)
    {
        return 0;
    }
    if (A->aux == aux)
    {
        return 1 + total(A->fe, aux) + total(A->fd, aux);
    }
    else
    {
        return total(A->fe, aux) + total(A->fd, aux);
    }
}
/*
b. (3 valores) Implemente uma função que insira um novo nó na árvore. 

Bin* insereArvore(Bin *A, Bin *nv)
*/

/*
Do exame Normal 2016-2017
1e) (3 valores) Implemente uma função que conte o total de nós-folha na árvore que ordena os clientes.
Protótipo: int contaNosFolha(NodoAb *A);
*/

int contaNosFolha(Bin *A)
{
    if (A == NULL)
    {
        return 0;
    }
    
    if (A->fe == NULL &&A->fd == NULL)
    {
        return 1;
    }
    return contaNosFolha(A->fe) + contaNosFolha(A->fd);
    
}
int main()
{
    Bin *AB = NULL, *nv = NULL;
    nv = makenode(5, 2);
    AB = treeInsert(AB, *nv);
    nv = makenode(3, 2);
    AB = treeInsert(AB, *nv);
    nv = makenode(1, 1);
    AB = treeInsert(AB, *nv);
    nv = makenode(4, 3);
    AB = treeInsert(AB, *nv);
    nv = makenode(7, 1);
    AB = treeInsert(AB, *nv);
    nv = makenode(6, 4);
    AB = treeInsert(AB, *nv);
    nv = makenode(8, 2);
    AB = treeInsert(AB, *nv);
    printf("Total 1s = %d\n", total(AB, 1));
    printf("Total 2s = %d\n", total(AB, 2));
    printf("Total 3s = %d\n", total(AB, 3));
    printf("Total 4s = %d\n", total(AB, 4));
    printf("Total nos folha = %d", contaNosFolha(AB));
    printf("pause");
}