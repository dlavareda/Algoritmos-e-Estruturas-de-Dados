#include <stdio.h>
#include <stdlib.h>

typedef struct NODO
{
    int id;
    int custo;
    struct NODO *nseg;
} Nodo;

int **get_tabuleiro(int n)
{
    int **t = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        t[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            printf("Coluna %d / Linha %d", i, j);
            scanf("%d", &t[i][j]);
        }
    }
    return t;
}
void ind_z_row_col(int i, int *r, int *c, int n)
{
    *r = i % n;
    *c = i / n;
}

Nodo **constroi_grafo(int **t, int n)
{
    Nodo **g = (Nodo *)malloc(n * n * sizeof(Nodo *));
    Nodo *nv;
    int r, c, ind_nv;
    for (int i = 0; i < n * n; i++)
    {
        g[i] = NULL;
    }
    for (int i = 0; i < n * n; i++)
    {
        ind_z_row_col(i, &r, &c, n);
        if (r > 0)
        {
            if (t[r - 1][c] != 1)
            {
                ind_nv = i - 1;
                *nv = makenode();
                nv->id = ind_nv;
                nv->custo = 1;
                g[i] = insertlast(g[i], nv);
            }
        }
        if (r < n - 1)
        {
            if (t[r + 1][c] != 1)
            {
                ind_nv = i + 1;
                *nv = makenode();
                nv->id = ind_nv;
                nv->custo = 1;
                g[i] = insertlast(g[i], nv);
            }
        }
        if (c < n - 1)
        {
            if (t[r][c + 1] != 1)
            {
                ind_nv = i + n;
                *nv = makenode();
                nv->id = ind_nv;
                nv->custo = 1;
                g[i] = insertlast(g[i], nv);
            }
        }
        if (c > 0)
        {
            if (t[r][c - 1] != 1)
            {
                ind_nv = i - n;
                *nv = makenode();
                nv->id = ind_nv;
                nv->custo = 1;
                g[i] = insertlast(g[i], nv);
            }
        }
    }
}
Nodo *Dijkstra(Nodo **G, int totV, int vo, int vd)
{
}

void atravessa_labirinto(Nodo **g, int n, int **t)
{
    int i, vo, vd, r, c;
    Nodo *aux;
    Nodo *lista;
    for (int i = 0; i < n * n; i++)
    {
        if (t[r][c] == 0)
        {
            vo = i;
        }
        if (t[r][c])
        {
            vd = i;
        }
    }
    lista = Dijkstra(g, n * n, vo, vd);
    aux = lista;
    while (aux != NULL)
    {
        ind_z_row_col(aux->id, &r, &c, i);
        printf("[%d, %d]\n", r, c);
        aux = aux->nseg;
    }
    lista = clearLista(lista);
}

void main()
{
    int **t = get_tabuleiro(5);
}
