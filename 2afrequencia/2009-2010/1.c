#include <stdio.h>

typedef struct PRODUTO
{
    int codProduto; //chave de ordenacao
    char descricao[100];
    float preco;
    int stock;
    struct PRODUTO *fe, *fd;
} Produto;

Produto *treeInsert(Produto *root, Produto nv)
{ //inserir elemento na arvore
    if (root == NULL)
    {
        // return igualEstrutura(A1->fe, A2->fe) * igualEstrutura(A1->fd, A2->fd);
        Produto *aux = (Produto *)malloc(sizeof(Produto));
        aux->codProduto = nv.codProduto;
        strcpy(aux->descricao, nv.descricao);
        aux->preco = nv.preco;
        aux->stock = nv.stock;
        aux->fe = NULL;
        aux->fd = NULL;
        return aux;
    }
    else
    {
        if (nv.codProduto > root->codProduto)
        {
            root->fd = treeInsert(root->fd, nv);
        }
        else if (nv.codProduto < root->codProduto)
        {
            root->fe = treeInsert(root->fe, nv);
        }
    }
    return root;
}
Produto *makenode(int id, char descricao[100], float preco, int stock)
{
    Produto *nv;
    nv = (Produto *)malloc(sizeof(Produto));
    nv->codProduto = id;
    strcpy(nv->descricao, descricao);
    nv->preco = preco;
    nv->stock = stock;
    nv->fe = NULL;
    nv->fd = NULL;
    return (nv);
}

/*
1b
*/
void mostraFaltas(Produto *A)
{
    if (A == NULL)
    {
        return;
    }
    if (A->fe != NULL)
    {
        mostraFaltas(A->fe);
    }
    if (A->stock == 0)
    {
        printf("%s\n", A->descricao);
    }
    if (A->fd != NULL)
    {
        mostraFaltas(A->fd);
    }
}
/*
1c
*/
int stock(Produto *A, int cod) // Não funciona em todos os elementos da arvore
{
    if (A == NULL)
    {
        return 0;
    }
    if (A->codProduto == cod)
    {
        return A->stock;
    }
    else
    {
        if (A->fe != NULL)
        {
            return stock(A->fe, cod);
        }
        if (A->fd != NULL)
        {
            return stock(A->fd, cod);
        }
    }
}

void main()
{
    Produto *AB, *nv;
    nv = makenode(5, "Caderno", 5.4, 3);
    AB = treeInsert(AB, *nv);
    nv = makenode(4, "Caneta", 2, 0);
    AB = treeInsert(AB, *nv);
    nv = makenode(7, "Lapis", 1, 2);
    AB = treeInsert(AB, *nv);
    nv = makenode(2, "Borracha", 0.5, 0);
    AB = treeInsert(AB, *nv);
    nv = makenode(1, "Estojo", 7.5, 3);
    AB = treeInsert(AB, *nv);
    nv = makenode(3, "Lapiseira", 8, 3);
    AB = treeInsert(AB, *nv);
    nv = makenode(6, "Minas", 0.10, 6);
    AB = treeInsert(AB, *nv);
    nv = makenode(8, "Régua", 4, 0);
    AB = treeInsert(AB, *nv);
    nv = makenode(9, "Compasso", 10, 2);
    AB = treeInsert(AB, *nv);
    mostraFaltas(AB);
    printf("%d\n", stock(AB, 6));
    printf("Pause");
}