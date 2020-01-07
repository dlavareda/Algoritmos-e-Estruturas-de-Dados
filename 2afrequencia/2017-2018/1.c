#include <stdio.h>
#include <string.h>
typedef struct NODO_AB
{
    int ID;
    char aux[20];
    struct NODO_AB *fe, *fd;
} NodoAB;

NodoAB *treeInsert(NodoAB *root, NodoAB nv)
{ //inserir elemento na arvore
    if (root == NULL)
    {
        NodoAB *a = (NodoAB *)malloc(sizeof(NodoAB));
        a->ID = nv.ID;
        strcpy(a->aux, nv.aux);
        a->fe = NULL;
        a->fd = NULL;
        return a;
    }
    else
    {
        if (nv.ID > root->ID)
        {
            root->fd = treeInsert(root->fd, nv);
        }
        else if (nv.ID < root->ID)
        {
            root->fe = treeInsert(root->fe, nv);
        }
    }
    return root;
}
NodoAB *makenode(int id, char aux[20])
{
    NodoAB *nv;
    nv = (NodoAB *)malloc(sizeof(NodoAB));
    nv->ID = id;
    strcpy(nv->aux, aux);
    nv->fe = NULL;
    nv->fd = NULL;
    return (nv);
}

/*
2a
*/

int altura(NodoAB *A)
{
    int e, d;
    if (A == NULL)
    {
        return 0;
    }
    e = 1 + altura(A->fe);
    d = 1 + altura(A->fd);
    if (e > d)
    {
        return e;
    }
    else
    {
        return d;
    }
}

void imprimeVerticesMenosNPassos(NodoAB *A, int N)
{
    if (A == NULL)
    {
        return;
    }
    if (N > 1)
    {
        imprimeVerticesMenosNPassos(A->fd, N - 1);
        printf("%d\n", A->ID);
        imprimeVerticesMenosNPassos(A->fe, N - 1);
    }
}

/*
2B
*/
int todosIDsPositivos(NodoAB *A)
{ // de forma eficiente 1 - sim 0 - nao
    if (A == NULL)
    {
        return 1;
    }
    if (A->ID < 0)
    {
        return 0;
    }
    return todosIDsPositivos(A->fe);
}

/*
2C
*/
int contaFE(NodoAB *A)
{
    if (A == NULL)
    {
        return 0;
    }
    if (A->fe != NULL && A->fd != NULL)
    {
        return 1 + contaFE(A->fe) + contaFE(A->fd);
    }
    else if (A->fe != NULL)
    {
        return 1 + contaFE(A->fe);
    }
}

int contaFD(NodoAB *A)
{
    if (A == NULL)
    {
        return 0;
    }
    if (A->fd != NULL && A->fe != NULL)
    {
        return 1 + contaFD(A->fd) + contaFD(A->fe);
    }
    else if (A->fd != NULL)
    {
        return 1 + contaFD(A->fd);
    }
}

int maisFilhosAtivos(NodoAB *A)
{ //se ha mais filhos a esquerda retorna -1, se tem mais a direita devolve 1,  se for igual devolve 0
    if (contaFD(A) > contaFE(A))
    {
        return 1;
    }
    else if (contaFE(A) > contaFD(A))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/*
2D
*/
NodoAB *findNode(NodoAB *A, int ID)
{
    if (A == NULL)
    {
        return;
    }
    if (A->ID == ID)
    {
        return A;
    }
    else
    {
        if (findNode(A->fe, ID) != NULL)
        {
            return findNode(A->fe, ID);
        }
        if (findNode(A->fd, ID) != NULL)
        {
            findNode(A->fd, ID);
        }
    }
}

int arvoresDisjuntas(NodoAB *A, NodoAB *B)
{ //1 Sim - 0 Não sao disjuntas se nao tiverem NÓS com IDs iguais
    if (A == NULL)
    {
        return 1;
    }
    if (findNode(B, A->ID) != NULL)
    {
        return 0;
    }
    else
    {
        return arvoresDisjuntas(A->fe, B) * arvoresDisjuntas(A->fd, B);
    }
}

void printNosNivel(NodoAB *A, int nivel)
{
    if (A == NULL || nivel < 0)
    {
        return;
    }

    if (altura(A) == nivel)
    {
        printf("%s\n", A->aux);
        return;
    }
    else
    {
        printNosNivel(A->fe, nivel);
        printNosNivel(A->fd, nivel);
    }
}
int findNodeNaArvore(NodoAB *AB, NodoAB *item)
{
    if (AB == NULL)
    {
        return 0;
    }
    if (item->ID == AB->ID)
    {
        return 1;
    }
    if (item->ID < AB->ID)
    {
        return 1 + findNodeNaArvore(AB->fe, item);
    }
    if (item->ID > AB->ID)
    {
        return 1 + findNodeNaArvore(AB->fd, item);
    }
}
int contaFolhas(NodoAB *AB)
{
    if (AB == NULL)
    {
        return 0;
    }
    if (AB->fd == NULL && AB->fe == NULL)
    {
        return 1;
    }
    return contaFolhas(AB->fe) + contaFolhas(AB->fd);
}

//contar

int contaNos(NodoAB *A)
{
    if (A == NULL)
    {
        return 0;
    }
    return 1 + contaNos(A->fe) + contaNos(A->fd);
}
//true false
int bemcontruida(NodoAB *A)
{
    if (A == NULL)
    {
        return 1;
    }
    if (A->fe != NULL && A->fd != NULL)
    {
        if (A->fe->ID < A->ID && A->fd->ID > A->ID)
        {
            return bemcontruida(A->fe) * bemcontruida(A->fd);
        }
        else
        {
            return 0;
        }
    }
    else if (A->fe != NULL)
    {
        if (A->fe->ID < A->ID)
        {
            return bemcontruida(A->fe);
        }
        else
        {
            return 0;
        }
    }
    else if (A->fd != NULL)
    {
        if (A->fd->ID > A->ID)
        {
            return bemcontruida(A->fd);
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

//printar
void printIDX(NodoAB *A, int n)
{
    if (A == NULL)
    {
        return;
    }
    if (A->ID == n)
    {
        printf("%s\n", A->aux);
        return;
    }
    printIDX(A->fe, n);
    printIDX(A->fd, n);
}

NodoAB* getX(NodoAB *A, int n){
    if (A==NULL)
    {
        return;
    }
    if (A->ID == n)
    {
        return A;
    }else{
    return getX(A->fe, n);
    return getX(A->fd, n);
    }
}

//retornar no

int main()
{
    NodoAB *AB = NULL, *nv = NULL;
    nv = makenode(5, "Covilha");
    AB = treeInsert(AB, *nv);
    nv = makenode(3, "Fundao");
    AB = treeInsert(AB, *nv);
    nv = makenode(1, "Lisboa");
    AB = treeInsert(AB, *nv);
    nv = makenode(4, "Castelo Branco");
    AB = treeInsert(AB, *nv);
    nv = makenode(7, "Guarda");
    AB = treeInsert(AB, *nv);
    nv = makenode(6, "Viseu");
    AB = treeInsert(AB, *nv);
    nv = makenode(8, "Bragança");
    AB = treeInsert(AB, *nv);

    NodoAB *AB2 = NULL;
    nv = makenode(15, "Paris");
    AB2 = treeInsert(AB2, *nv);

    imprimeVerticesMenosNPassos(AB, 1);
    printf("Todos IDs positivos? %d\n", todosIDsPositivos(AB));
    printf("Conta FE =  %d\n", contaFE(AB));
    printf("Conta FD =  %d\n", contaFD(AB));
    printf("Existem mais FE do que FD? %d\n", maisFilhosAtivos(AB));
    printf("Arvores disjuntas? %d\n", arvoresDisjuntas(AB, AB2));
    printNosNivel(AB, 1);
    /*
6. Escreva uma função em C que aceite um ponteiro para uma árvore binária e um ponteiro
para um nó da árvore e retorne o nível do nó na árvore.
    */
    NodoAB *item = findNode(AB, 8);
    printf("Nivel nó = %d\n", findNodeNaArvore(AB, item));
    printf("Numero de folhas  = %d", contaFolhas(AB));
    printf("BEM CONSTRUIDA\n");
    printf("%d\n", bemcontruida(AB));
    printIDX(AB, 6);
    NodoAB *x = getX(AB, 6);
    //printf("blabsdabdas %d\n", getX(AB, 6)->ID);
    printf("pause");
}