typedef struct OBSERVADOR
{
    int codigo; //critério de ordenação na lista
    char nome[80];
    struct OBSERVADOR *nseg;
} Observador;

typedef struct OBSERVACAO
{
    int dia, mes, ano; // data da observação
    char nome[80];     //critério de ordenação na lista
    Observador *observador;
    float distancia;
    struct OBSERVACAO *nseg;
} Observacao;

Observador *getObservador(Observador *O, int codigo)
{
    while (O != NULL)
    {
        if (O->codigo == codigo)
        {
            return O;
        }
        O = O->nseg;
    }
}

Observador *makenodeObservador()
{
    Observador *nv;
    nv = (Observador *)malloc(sizeof(Observador));
    nv->nseg = NULL;
    return (nv);
}
Observador *insertlastObservador(Observador *M, Observador *nv)
{

    Observador *aux = M;
    if (M == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    return M;
}

Observacao *makenodeObservacao()
{
    Observacao *nv;
    nv = (Observacao *)malloc(sizeof(Observacao));
    nv->nseg = NULL;
    return (nv);
}
Observacao *insertlastObservacao(Observacao *M, Observacao *nv)
{

    Observacao *aux = M;
    if (M == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    return M;
}

void mostraObservaforesNulos(Observador *L, Observacao *LO)
{
    int i;
    Observacao *aux = LO;
    while (L != NULL)
    {
        LO = aux;
        i = 0;
        while (LO != NULL)
        {
            if (LO->observador == L)
            {
                i = 1;
            }
            LO = LO->nseg;
        }
        if (i == 0)
        {
            printf("Nome: %s", L->nome);
        }
        L = L->nseg;
    }
}
int totalObservacoes(Observacao *LO, int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int count = 0;
    while (LO != NULL)
    {
        if (LO->ano >= ano1 && LO->ano <= ano2)
        {
            if (LO->mes >= mes1 && LO->mes <= mes2)
            {
                if (LO->dia >= dia1 && LO->dia <= dia2)
                {
                    count++;
                }
            }
        }
        LO = LO->nseg;
    }
    return count;
}