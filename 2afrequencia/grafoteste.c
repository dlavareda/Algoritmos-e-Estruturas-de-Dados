#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODO
{
    char id;
    int custo;
    struct NODO *nseg;
} Nodo;

Nodo *makenode()
{
    Nodo *nv;
    nv = (Nodo *)malloc(sizeof(Nodo));
    nv->custo = 0;
    nv->id = 0;
    nv->nseg = NULL;
    return (nv);
}

Nodo *insertlast(Nodo *L, Nodo *nv)
{

    Nodo *aux = L;
    if (L == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    return L;
}

Nodo *Dijkstra(Nodo **G, int totV, int vo, int vd)
{
    int menor, IM = 0, n;
    Nodo *aux;
    Nodo *L, *nv;
    int *C = (int *)malloc(totV * sizeof(int));
    int *E = (int *)malloc(totV * sizeof(int));
    int *P = (int *)malloc(totV * sizeof(int));
    for (int i = 0; i < totV; i++)
    {
        C[i] = 2147483647;
        E[i] = 0;
        P[i] = -1;
    }
    C[vd] = 0;
    for (int i = 0; i < totV; i++)
    {
        menor = 2147483647;
        for (int j = 0; j < totV; j++)
        {
            if (C[j] < menor && E[j] != 1) //if (C[j] < menor && E[j] != 1)
            {
                menor = C[j];
                IM = j;
            }
            E[IM] = 1;
            aux = G[IM];
            while (aux != NULL)
            {
                if (C[aux->id] > C[IM] + aux->custo)
                {
                    C[aux->id] = C[IM] + aux->custo;
                    P[aux->id] = IM;
                }
                aux = aux->nseg;
            }
        }
    }
    L = NULL;
    nv = makenode();
    nv->id = vo;
    L = insertlast(L, nv);
    while (1)
    {
        n = P[nv->id];
        nv = makenode();
        nv->id = n;
        L = insertlast(L, nv);
        if (n == vd)
        {
            break;
        }
    }
    free(E);
    free(P);
    free(C);
    return L;
}

Nodo **constroi_grafo(int n)
{
    Nodo **g = (Nodo *)malloc(n * n * sizeof(Nodo *));
    Nodo *nv;
    int r, c, ind_nv;
    //inicializa as n listas
    for (int i = 0; i < n; i++)
    {
        g[i] = NULL;
    }
    //Ligações do A
    nv = makenode();
    nv->id = 'B';
    nv->custo = 2;
    g[0] = insertlast(g[0], nv);
    nv = makenode();
    nv->id = 'C';
    nv->custo = 7;
    g[0] = insertlast(g[0], nv);
    nv = makenode();
    nv->id = 'D';
    nv->custo = 3;
    g[0] = insertlast(g[0], nv);
    //Ligações do B
    nv = makenode();
    nv->id = 'E';
    nv->custo = 4;
    g[1] = insertlast(g[1], nv);
    //Ligações do D
    nv = makenode();
    nv->id = 'E';
    nv->custo = 1;
    g[3] = insertlast(g[3], nv);
    //Ligações do E
    nv = makenode();
    nv->id = 'C';
    nv->custo = 5;
    g[4] = insertlast(g[4], nv);
    return g;
}
/*Exercicios do slide est_10_19_20.pdf
Implemente funções em linguagem C que permitam:
¨ Calcular o grau de um vértice.
¨ Calcular o grau de entrada de um vértice.
¨ Calcular o grau de saída de um vértice.
¨ Verificar se um grafo é completo.
¨ Verificar se dois vértices são adjacentes.
¨ Verificar se duas arestas são adjacentes.
¨ Calcular o custo de um caminho.*/

/*
Calcular o grau de saída de um vértice.
*/
Nodo *findNode(Nodo **G, int t, char c)
{
    for (int i = 0; i < t; i++)
    {
        while (G[i] != NULL)
        {
            if (G[i]->id == c)
            {
                return G[i];
            }
            G[i] = G[i]->nseg;
        }
    }
    return NULL;
}

int grauSaidaVertice(Nodo **G, int t, int v)
{ //G - grafo v- vertice(0->n-1), t- numero de elementos do grafo
    Nodo **aux = G;
    int count = 0;
    while (G[v] != NULL)
    {
        count++;
        G[v] = G[v]->nseg;
    }
    G = aux;
    return count;
}
int grauEntradaVertice(Nodo **G, int t, int v)
{
    int count = 0;
    for (int i = 0; i < t; i++)
    {
        if (findNode(G, t, v) != NULL)
        {
            count++;
        }
    }
    return count;
}

int parte(Nodo **G, int tv)
{
    int count = 1;
    Nodo *aux;
    int *checked = (int *)malloc(tv * sizeof(int));
    for (int i = 0; i < tv; i++)
    {
        checked[i] = -1;
    }

    for (int i = 0; i < tv; i++)
    {
        if (checked[i] == -1)
        {
            for (int ii = 0; ii < tv; ii++)
            {
                if (checked[ii] == -1)
                {
                    aux = Dijkstra(G, tv, i, ii);
                }
                if (aux != NULL)
                {
                    count++;
                }
            }
            while (aux != NULL)
            {
                if (checked[aux->id] == -1)
                {
                    checked[aux->id] = count;
                }
                aux = aux->nseg;
            }
            free(aux);
        }
    }
    return count;
}

/*
resolução professor
*/
int partesProf(Nodo **G, int tv)
{
    int c = 1;
    int *v = calloc(tv, sizeof(int));
    Nodo *aux;
    while (1)
    {
        for (int i = 0; i < tv; i++)
        {
            if (v[i] == 0)
            {
                break;
            }
            if (i == tv)
            {
                free(v);
                return (c);
            }
            v[i] = c;
            for (int j = 0; j < tv; j++)
            {
                if (v[j] != 0)
                {
                    continue;
                }
                aux = Dijkstra(G, tv, i, j);
                if (aux != NULL)
                {
                    v[j] = c;
                }
                free(aux);
            }
        }
        c++;
    }
    return c;
}

int main()
{
    int t = 5;
    Nodo **G;
    G = constroi_grafo(t);
    printf("GRAUS SAIDA\n");
    for (int i = 0; i < t; i++)
    {
        printf("Grau Saida vertice %d = %d\n", i, grauSaidaVertice(G, t, i));
    }
    printf("GRAU ENTRADA\n");
    for (int i = 0; i < t; i++)
    {
        printf("Grau Entrada vertice %d = %d\n", i, grauEntradaVertice(G, t, i));
    }
    printf("numero de grafos %d\n", parte(G, t));
}