#include <stdio.h>
#include <stdlib.h>

typedef struct NODO
{
    int id;
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
                nv = makenode();
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
                nv = makenode();
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
                nv = makenode();
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
                nv = makenode();
                nv->id = ind_nv;
                nv->custo = 1;
                g[i] = insertlast(g[i], nv);
            }
        }
    }
}
Nodo *Dijkstra(Nodo **G, int totV, int vo, int vd)
{
    int menor, IM=0, n;
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
            if (C[j] < menor && E[j] != 1)
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

void atravessa_labirinto(Nodo **g, int n, int **t)
{
    int i, vo, vd, r, c;
    Nodo *aux;
    Nodo *lista;
    for (int i = 0; i < n * n; i++)
    {
        ind_z_row_col(i, &r, &c, n);
        if (t[r][c] == 2)
        {
            vo = i;
        }
        if (t[r][c] == 3)
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
    // lista = clear_list(lista);
}

int main()
{
    int N, **tab;
    Nodo **Grafo;
    printf("Qual o tamanho do tabuleiro ?\n");
    scanf("%d", &N);
    tab = get_tabuleiro(N);
    Grafo = constroi_grafo(tab, N);
    atravessa_labirinto(Grafo, N, tab);
    for (; N > 0; N--)
    {
        free(tab[N - 1]);
        //clear_list(Grafo[N - 1]);
    }
    free(tab);
    free(Grafo);
    exit(0);
}
