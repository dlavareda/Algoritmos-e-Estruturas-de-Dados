#include <stdio.h>
#include <stdlib.h>

typedef struct STACK
{
    int hora, minuto, segundo; //momento de entrada na pilha
    char nomeCliente[80];
    int codigoFuncionario;
    struct STACK *nseg;
} Stack;

Stack *push(Stack *F, Stack *nv)
{
    nv->nseg = F;
    return nv;
}
Stack *pop(Stack **F)
{
    Stack *aux = *F;
    Stack *node;
    if ((*F)->nseg == NULL)
        return NULL;
    while ((*F)->nseg->nseg != NULL)
    {
        (*F) = (*F)->nseg->nseg;
    }
    node = (*F)->nseg;

    *F = aux;
    return node;
}

int totalSegundos(int a, int b, int c, int d, int e, int f);
Stack *transfereAtrasados(Stack **P, int n)
{
    Stack *A, *AUX, *tmp;
    while (*P != NULL)
    {
    if(n > totalSegundos((*P)->minuto){
        AUX = push(AUX, (*P);
    }else
    {
        tmp = push(AUX, (*P));
    }
    }
    while (tmp != NULL)
    {
        (*P) = push((*P), pop(&tmp));
    }
    while (AUX != NULL)
    {
        (A) = push((A), pop(&AUX));
    }
}