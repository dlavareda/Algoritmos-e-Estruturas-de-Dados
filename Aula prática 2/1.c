/*-criava uma lista auxilia com cad valo novo*/
#include <stdio.h>
#include <stdlib.h>

typedef struct T
{
    int ID;
    struct T *nseg;
    struct R *nant;
} Nodo;
int contaDiferentes(Nodo *L)
{
    Nodo *aux;
    int count = 0;
    while (L != NULL)//Passa por todos
    {
        aux = L->nant;
        while (aux != NULL) //ver se para tras do L existe algum igual
        {
            if (L->ID == aux->ID)
            {
                break;
            }
            aux = aux->nant;
        }
        if (aux == NULL)//se o AUX for NULL é que chegou ao inicio e nao encontrou nenhum igual
        {
            count++;
        }
        L= L->nseg;
    }
    return count;
}