#include <stdio.h>
#include <stdlib.h>
#include "funcoestrabalho.h"

/*int main(){
    //preencher com dados dummy

    typedef struct TRABALHO{
int numero; //número do aluno;
int codTrabalho; //identificador do trabalho;
float nota; //guarda nota do trabalho [0,20]
struct TRABALHO *nseg;
 }Trabalho;*/
int main()
{
    Trabalho *nv, *T = NULL, *aux;
    int numTrabalhosAluno, numaluno;
    //preenche a Lista com dados random 1 por aluno
    for (int i = 0; i < 10; i++)
    {
        nv = makenode();
        nv->codTrabalho = 1;
        nv->numero = i + 38950;
        nv->nota = (float)rand() / (float)(RAND_MAX / 20);
        T = insertlast(T, nv);
    }
    //preenche a Lista com dados random 1 por aluno
    for (int i = 0; i < 10; i++)
    {
        nv = makenode();
        nv->codTrabalho = 2;
        nv->numero = i + 38950;
        nv->nota = (float)rand() / (float)(RAND_MAX / 20);
        T = insertlast(T, nv);
    }
    // T = T->nseg;
    aux = T;
    while (T != NULL)
    {
        printf("Numero %d\n", T->numero);
        printf("Cod Trabalho %d\n", T->codTrabalho);
        printf("Nota %f\n", T->nota);
        printf("\n");
        T = T->nseg;
    }
    T = aux;

    printf("Introduza o numero de aluno \n");
    scanf("%d", &numaluno);
    numTrabalhosAluno = contarTrabalhosPorAluno(T, numaluno);
    printf("O aluno %d realizou %d trabalhos\n", numaluno, numTrabalhosAluno);
    float mediaAluno;
    mediaAluno = classificacaoMediaAluno(T, numaluno);

    printf("A classificação média do aluno %d é de %f\n", numaluno, mediaAluno);
    printf("\nPauta de classificação Trabalho 1\n");
    classificacoes(T, 1);
    

}