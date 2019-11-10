#include <stdio.h>
#include <stdlib.h>

typedef struct STACK
{
    int hora, minuto, segundo; //momento de entrada na pilha
    char nomeCliente[80];
    int codigoFuncionario;
    struct STACK *nseg;
} Stack;

//push = insert first
Stack *push(Stack *F, Stack *nv)
{
    nv->nseg = F;
    return nv;
}

//remove first
/*
Stack *pop(Stack **F){
    *F = *F->nseg;
    return *F;
}
*/
//remove last
Stack *pop(Stack **F)
{
    Stack *aux = *F;
    Stack *node;
    if((*F)->nseg == NULL)
        return NULL;
    while ((*F)->nseg->nseg != NULL)
    {
        (*F) = (*F)->nseg->nseg;
    }
    node = (*F)->nseg;

    *F = aux;
    return node;
}

Stack *makenode()
{
    Stack *nv;
    nv = (Stack *)malloc(sizeof(Stack));
    nv->nseg = NULL;
    return (nv);
}

int main()
{
    Stack **S, *node;

    node = makenode();
    node->codigoFuncionario = 1;
    node->hora = 2;
    node->minuto = 3;
    node->segundo = 2;

    (*S) = push((&S), node);

Stack *SA;
SA = pop(&S);

return 1;
}