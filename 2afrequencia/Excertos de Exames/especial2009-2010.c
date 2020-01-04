#include <stdio.h>

typedef struct ALUNO
{
    int numAluno;
    int distrito;
    struct ALUNO *fe, *fd;
} Aluno;

Aluno *treeInsert(Aluno *root, Aluno nv)
{ //inserir elemento na arvore
    if (root == NULL)
    {
        Aluno *aux = (Aluno *)malloc(sizeof(Aluno));
        aux->numAluno = nv.numAluno;
        aux->distrito = nv.distrito;
        aux->fe = NULL;
        aux->fd = NULL;
        return aux;
    }
    else
    {
        if (nv.numAluno > root->numAluno)
        {
            root->fd = treeInsert(root->fd, nv);
        }
        else if (nv.numAluno < root->numAluno)
        {
            root->fe = treeInsert(root->fe, nv);
        }
    }
    return root;
}
Aluno *makenode(int numAluno, int distrito)
{
    Aluno *nv;
    nv = (Aluno *)malloc(sizeof(Aluno));
    nv->numAluno = numAluno;
    nv->distrito = distrito;
    nv->fe = NULL;
    nv->fd = NULL;
    return (nv);
}

/*
a. (3 valores) Crie uma função que verifique se existem ou não alunos de um 
determinado distrito. A função deverá escrever uma das seguintes 
mensagens: “Existem alunos” ou “Não existem alunos”. 
void existemAlunos(Aluno *A, int distrito);
*/
int existem(Aluno *A, int distrito)
{ //0 sim, 1 não
    if (A == NULL)
    {
        return 1;
    }
    if (A->distrito == distrito)
    {
        return 0;
    }
    else
    {
        return existem(A->fe, distrito) * existem(A->fd, distrito);
    }
}

void existemAlunos(Aluno *A, int distrito)
{
    if (existem(A, distrito) == 0)
    {
        printf("Existem alunos!");
    }
    else
    {
        printf("Não existem alunos");
    }
}

/*
b. (3 valores) Implemente uma função que verifica se a árvore está ou não bem 
formada, isto é, se todos os números de aluno à direita são maiores que o 
próprio nó e os da esquerda menores. A função deverá devolver “1” em caso 
de bem formada, ou “0” caso contrario.
int verificaFormada(Aluno *A)
*/
Aluno *minA(Aluno *A)
{
    Aluno *e, *d, *r;
    if (A == NULL)
    {
        return NULL;
    }
    e = minA(A->fe);
    d = minA(A->fd);
    r = A;
    if (e != NULL)
    {
        if (e->numAluno < A->numAluno)
        {
            r = e;
        }
    }
    if (d != NULL)
    {
        if (d->numAluno < r->numAluno)
        {
            r = d;
        }
    }
    return r;
}

Aluno *maxA(Aluno *A)
{
    Aluno *e, *d, *r;
    if (A == NULL)
    {
        return NULL;
    }
    e = maxA(A->fe);
    d = maxA(A->fd);
    r = A;
    if (e != NULL)
    {
        if (e->numAluno > A->numAluno)
        {
            r = e;
        }
    }
    if (d != NULL)
    {
        if (d->numAluno > r->numAluno)
        {
            r = d;
        }
    }
    return r;
}
int verificaFormada(Aluno *A)
{
    if (A == NULL)
    {
        return 1;
    }
    if (maxA(A->fe) != NULL && A->numAluno < maxA(A->fe)->numAluno)
    {
        return 0;
    }
    if (minA(A->fd) != NULL && A->numAluno > minA(A->fd)->numAluno)
    {
        return 0;
    }
    return verificaFormada(A->fe) * verificaFormada(A->fd);
}

int main()
{
    Aluno *AB = NULL, *nv = NULL;
    nv = makenode(5, 2);
    AB = treeInsert(AB, *nv);
    nv = makenode(3, 1);
    AB = treeInsert(AB, *nv);
    nv = makenode(1, 3);
    AB = treeInsert(AB, *nv);
    nv = makenode(7, 2);
    AB = treeInsert(AB, *nv);
    nv = makenode(6, 1);
    AB = treeInsert(AB, *nv);
    nv = makenode(8, 2);
    existemAlunos(AB, 2);
    printf("\nMenor = %d\n", minA(AB)->numAluno);
    printf("Maior = %d\n", maxA(AB)->numAluno);
    printf("Bem formada = %d\n", verificaFormada(AB));
    printf("pause");
}