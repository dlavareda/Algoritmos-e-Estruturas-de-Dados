typedef struct NODO
{
    int chave; //Identificador
    int nivel;
    struct NODO *nseg[4]; //4 níveis
    struct NODO *nant[4]; //4 níveis
} Nodo;

Nodo *pesquisaListaSalto(Nodo *LS, int c)
{
    Nodo *aux = LS;
    int i;
    if (LS->chave == c)
        return LS;
 
    for (i = LS->nivel; i >= 0; i--)
    {
        if (LS->nseg[i] == NULL)
        {
            continue;
        }
        if (LS->nseg[i]->chave > c)
        {
            continue;
        }
        LS = LS->nseg[i];
        break;
    }
    if (i < 0)
    {
        return NULL;
    }
}
Nodo *findLast(Nodo *LS, int n)
{
    while (LS != NULL)
    {
        if (LS->nseg[n]->nivel >= n && LS->nseg[n] == NULL)
        {
            return LS;
        }
    }
    LS = LS->nseg[0];
    return NULL;
}
Nodo *findnext(Nodo *LS, int chave, int n)
{
    while (LS != NULL)
    {
        if (LS->chave > chave && LS->nivel >= n)
        {
            return LS;
        }
        LS = LS->nseg[0];
    }
    return NULL;
}
Nodo *findPrevious(Nodo *LS, int chave, int n)
{
    if (LS == NULL)
    {
        return LS;
    }
    
    Nodo *aux = findnext(LS, chave, n);
    if (aux == NULL)
    {
        return (aux->nant[n]);
    }
    return (findLast(LS, n));
}
Nodo *inserirListaSalto(Nodo *LS, Nodo *nv)
{
    int i;
    Nodo *p, *n;
    for (i = 0; i <= nv->nivel; i++)
    {
        p = findPrevious(LS, nv->chave, i);
        n = findnext(LS, nv->chave, i);
        if (p == NULL && n == NULL){
            return nv;
        }
        nv->nseg[i] = n;
        nv->nant[i] = p;
        if (n != NULL)
        {
            n->nant[i] = nv;
        }
        if (p->nseg[i] = nv)
        {
            p->nseg[i] = nv;
        }
    }
    return (LS == NULL ? nv : nv->nant[0] == NULL ? nv : LS);
}

Nodo *makenode()
{
    Nodo *nv;
    nv = (Nodo *)malloc(sizeof(Nodo));
    //4 niveis
    for (int i = 0; i < 4; i++)
    {
        nv->nseg[i] = NULL;
    }
   srand(time(NULL)); 
    nv->nivel = (rand()%4)+1; 
    return nv;
}