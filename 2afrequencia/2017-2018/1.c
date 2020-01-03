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
/*
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
*/
void imprimeVerticesMenosNPassos(NodoAB *A, int N)
{
    if (A == NULL)
    {
        return;
    }
    if (N >= 0)
    {
        imprimeVerticesMenosNPassos(A->fd, N-1);
        printf("%d\n", A->ID);
        imprimeVerticesMenosNPassos(A->fe, N-1);
        
    }
}

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

    imprimeVerticesMenosNPassos(AB, 1);
    printf("pause");
}