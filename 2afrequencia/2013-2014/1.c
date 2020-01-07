#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
a. (3 valores) Implemente uma função que verifique se existem
activos (diferentes de NULL) mais filhos esquerdos ou direitos
na árvore (-1=esquerdos, 0=igual, 1=direitos).
Protótipo: int maisFilhosActivos(Nodo* A);
//A=raiz
*/
int contaFE(NodoAB *A)
{
    if (A == NULL)
    {
        return 0;
    }
    if (A->fe != NULL)
    {
        return 1 + contaFE(A->fe) + contaFE(A->fd);
    }
    return contaFE(A->fd);
}
int contaFD(NodoAB *A)
{
    if (A == NULL)
    {
        return 0;
    }
    if (A->fd != NULL)
    {
        return 1 + contaFD(A->fe) + contaFD(A->fd);
    }
    return contaFD(A->fe);
}

int maisFilhosActivos(NodoAB *A)
{
    if (contaFE(A) > contaFD(A))
    {
        return -1;
    }
    else if (contaFD(A) > contaFE(A))
    {
        return 1;
    }
    return 0;
}

/*
b. (3 valores) Implemente uma função que mostre o nome dos
elementos com ID num determinado intervalo.
Protótipo: void mostraNomeIntervalo(Nodo* A, int idInf, int idSup);
//A=raiz. idInf, idSup= limites inferior e superior do intervalo
*/
void mostraNomeIntervalo(NodoAB *A, int idInf, int idSup)
{

    if (A == NULL)
    {
        return;
    }
    if (A->fe != NULL)
    {
        mostraNomeIntervalo(A->fe, idInf, idSup);
    }
    if (A->id >= idInf && A->id <= idSup)
    {
        printf("%s\n", A->nome);
    }
    if (A->fd != NULL)
    {
        mostraNomeIntervalo(A->fd, idInf, idSup);
    }
}

/*
(3 valores) Codifique uma função que verifique se uma árvore
está contida noutra, isto é, se os ID de todos os elementos da
primeira árvore também estão na segunda árvore.
Protótipo: int arvoreContida(Nodo* A1, Nodo* A2);
//A1=raiz da sub-árvore, A2=raiz da árvore
*/

int findID(NodoAB *AB, int id)
{
    if (AB == NULL)
    {
        return;
    }
    if (AB->id == id)
    {
        return 1;
    }
    return 0 || findID(AB->fe, id) || findID(AB->fd, id);
}

int arvoreContida(NodoAB *A1, NodoAB *A2)//Nao funciona nao sei porque
{
    if (A1 == NULL)
    {
        return 1;
    }
    if (findID(A2, A1->id) == 0)
    {
        return 0;
    }
    else
    {
        if (A1->fe != NULL)
        {
            return 1 * arvoreContida(A1->fe, A2);
        }
        if (A1->fd != NULL)
        {
            return 1 * arvoreContida(A1->fd, A2);
        }
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
    int a = maisFilhosActivos(AB);
    //2a
    printf("%d\n", a);
    //2b
    mostraNomeIntervalo(AB, 0, 3);

    printf("Arvore contaida\n");
    int b = arvoreContida(AB, AB);
    printf("%d", b);
    printf("pause");
}