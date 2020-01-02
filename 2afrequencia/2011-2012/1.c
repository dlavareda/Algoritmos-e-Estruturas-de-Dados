#include <stdio.h>

typedef struct NODO
{
    int id; //critério de ordenação na árvore
    char nome[80];
    struct NODO *fe;
    struct NODO *fd;
} NodoAB;

NodoAB *treeInsert(NodoAB *root, NodoAB nv)
{ //inserir elemento na arvore
    if (root == NULL)
    {
        // return igualEstrutura(A1->fe, A2->fe) * igualEstrutura(A1->fd, A2->fd);
        NodoAB *aux = (NodoAB *)malloc(sizeof(NodoAB));
        aux->id = nv.id;
        strcpy(aux->nome, nv.nome);
        aux->fe = NULL;
        aux->fd = NULL;
        return aux;
    }
    else
    {
        if (nv.id > root->id)
        {
            root->fd = treeInsert(root->fd, nv);
        }
        else if (nv.id < root->id)
        {
            root->fe = treeInsert(root->fe, nv);
        }
    }
    return root;
}
NodoAB *makenode(int id, char nome[80])
{
    NodoAB *nv;
    nv = (NodoAB *)malloc(sizeof(NodoAB));
    nv->id = id;
    strcpy(nv->nome, nome);
    nv->fe = NULL;
    nv->fd = NULL;
    return (nv);
}

/*
a. (4 valores) Implemente uma função que verifique se dois nós
(especificados através de apontadores) pertencem ao mesmo
ramo da árvore binária (1=sim, 0=não).
Protótipo: int igualRamo(Nodo* A, Nodo *n1, Nodo *n2);
//A=raiz, n1,n2=nós a pesquisar
*/

int igualRamo(Nodo* A, Nodo *n1, Nodo *n2){
    
}
void main(){
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

    printf("pause");
}