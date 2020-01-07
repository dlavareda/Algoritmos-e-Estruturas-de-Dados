#include <stdio.h>
#include <stdlib.h>
typedef struct ESTRADA
{
    int idDestino;
    int distancia; //valor em km.
    struct ESTRADA *nseg;
} Estrada;


void listaVizinhas(Estrada **G, int tv, int x)
{
    Estrada *aux, *aux2;
    int distancia = 0;
    for (int i = 0; i < tv; i++)
    {
        for (int j = i + 1; i < tv; i++)
        {
            distancia = 0;
            aux = Dikstra(G, tv, i, j);
            aux2 = aux;
            while (aux != NULL)
            {
                distancia += aux->distancia;
                aux = aux->nseg;
            }
            aux = clearListe(aux2);
            if (distancia < x)
            {
                printf("%d - %d", G[i]->idDestino, G[j]->idDestino);
            }
        }
    }
}