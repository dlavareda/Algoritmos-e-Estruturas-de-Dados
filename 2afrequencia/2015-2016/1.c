#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ALUNO
{
    int numero; //critério de ordenação na árvore
    char nome[80];
    int codigoCurso;
    struct ALUNO *fe, *fd;
} Aluno;

Aluno *treeInsert(Aluno *root, Aluno nv)
{ //inserir elemento na arvore
    if (root == NULL)
    {

        // return igualEstrutura(A1->fe, A2->fe) * igualEstrutura(A1->fd, A2->fd);
        Aluno *aux = (Aluno *)malloc(sizeof(Aluno));
        aux->numero = nv.numero;
        strcpy(aux->nome, nv.nome);
        aux->codigoCurso = nv.codigoCurso;
        aux->fe = NULL;
        aux->fd = NULL;
        return aux;
    }
    else
    {
        if (nv.numero > root->numero)
        {
            root->fd = treeInsert(root->fd, nv);
        }
        else if (nv.numero < root->numero)
        {
            root->fe = treeInsert(root->fe, nv);
        }
    }
    return root;
}
Aluno *makenode(int numero, char nome[80], int codcurso)
{
    Aluno *nv;
    nv = (Aluno *)malloc(sizeof(Aluno));
    nv->numero = numero;
    strcpy(nv->nome, nome);
    nv->codigoCurso = codcurso;
    nv->fe = NULL;
    nv->fd = NULL;
    return (nv);
}
/*
1c) (2 valores) Implemente uma função que imprima o nome dos alunos inscritos num determinado curso.
Protótipo: void mostraAlunosCurso(Aluno *A, int codigoCurso);
*/
void mostraAlunosCurso(Aluno *A, int codigoCurso)
{
    if (A == NULL)
    {
        return;
    }
    if (A->fe != NULL)
    {
        mostraAlunosCurso(A->fe, codigoCurso);
    }
    if (A->codigoCurso == codigoCurso)
    {
        printf("%s\n", A->nome);
    }
    if (A->fd != NULL)
    {
        mostraAlunosCurso(A->fd, codigoCurso);
    }
}

/*
1d) (2 valores) Codifique uma função que retorne (através de parâmetros “fe” / “fd” passados por referência) o total de ligações “fe” e “fd”
activas na árvore (isto é, diferentes de NULL).
Protótipo: void totalApontadoresActivos(Aluno *A, int *fe, int *fd);
*/
void totalApontadoresActivos(Aluno *A, int *fe, int *fd)
{
    if (A == NULL)
    {
        return;
    }
    if (A->fe != NULL)
    {
        (*fe)++;
        totalApontadoresActivos(A->fe, fe, fd);
    }
    if (A->fd != NULL)
    {
        (*fd)++;
        totalApontadoresActivos(A->fd, fe, fd);
    }
}

/*
1e) (3 valores) Implemente uma função que conte de forma eficiente o total de alunos com numero superior a um valor introduzido por
parâmetro.
Protótipo: int contaAlunos(Aluno *A, int numero);
Considere que tem à sua disposição a seguinte função:
int contaNos(Aluno *A);
//Devolve o total de nós numa árvore binária
*/

int contaAlunos(Aluno *A, int numero)
{
  
  
}
void main()
{

    Aluno *AB = NULL, *nv = NULL;
    int fe = 0, fd = 0;
    nv = makenode(2, "José Andrade", 3);
    AB = treeInsert(AB, *nv);
    nv = makenode(3, "Vitor Coelho", 2);
    AB = treeInsert(AB, *nv);
    nv = makenode(4, "Andreia Soares", 3);
    AB = treeInsert(AB, *nv);
    nv = makenode(1, "Paula Correia", 1);
    AB = treeInsert(AB, *nv);
    nv = makenode(5, "João Raposo", 1);
    AB = treeInsert(AB, *nv);
    nv = makenode(7, "Sandra Henrique", 3);
    AB = treeInsert(AB, *nv);
    printf("Alunos Curso 2:\n");
    mostraAlunosCurso(AB, 2); /* condition */
    printf("Alunos Curso 3:\n");
    mostraAlunosCurso(AB, 3);
    totalApontadoresActivos(AB, &fe, &fd);
    printf("FE = %d  --  ", fe);
    printf("FD = %d", fd);
    printf("\npausa");
}