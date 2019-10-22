Membro *makenodeMembro()
{
    Membro *nv;
    nv = (Membro *)malloc(sizeof(Membro));
    nv->nseg = NULL;
    return (nv);
}
Membro *insertlastMembro(Membro *M, Membro *nv)
{

    Membro *aux = M;
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
Encontro *makenodeEncontro()
{
    Encontro *nv;
    nv = (Encontro *)malloc(sizeof(Encontro));
    nv->nseg = NULL;
    return (nv);
}

Encontro *insertlastEncontro(Encontro *E, Encontro *nv)
{

    Encontro *aux = E;
    if (E == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    return E;
}

Presencas *makenodePresencas()
{
    Presencas *nv;
    nv = (Presencas *)malloc(sizeof(Presencas));
    nv->nseg = NULL;
    return (nv);
}

Presencas *insertlastPresencas(Presencas *P, Presencas *nv)
{

    Presencas *aux = P;
    if (P == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    return P;
}

/*1c) (3 valores) Implemente uma função que devolva o número médio de elementos presentes nos encontros
organizados por um determinado membro. (adapte o protótipo da função às estruturas de dados por si definidas).
Protótipo: */
float mediaPresentes(Encontro *E, Presencas *P, int BIOrganizador)
{
    int count = 0;
    int npart = 0;
    float media = 0.0;
    Presencas *Paux = P;
    Encontro *Eaux = E;
    //Conta o numero de eventos do Organizador
    while (E != NULL)
    {
        if (E->organizacao == BIOrganizador)
        {
            count++;
            while (P != NULL)
            {
                if (P->IDencontro == E->ID)
                {
                    npart++;
                }
                P = P->nseg;
            }
        }
        P = Paux;
        E = E->nseg;
    }
    media = (float)npart / (float)count;
    return media;
}

/*1c) (3 valores) Codifique a função que lista o nome dos membros que nunca organizaram nenhum encontro.
Protótipo:*/
void mostraInactivos(Encontro *E, Membro *M)
{
    int flag = 0;
    Encontro *Eaux = E;
    while (M != NULL)
    {
        while (E != NULL)
        {
            if (M->BI == E->organizacao)
            {
                flag = 1; //enconrou um encontro organizado pelo menbro
                break;
            }
            E = E->nseg;
        }
        if (flag == 0)
        {
            printf("%s - %d\n", M->Nome, M->BI);
        }
        E = Eaux;
        M = M->nseg;
        flag = 0;
    }
}

/*1d) (2 valores) Implemente uma função que devolva o total de encontros realizados num determinado ano civil.
Protótipo: */
int totalAno(Encontro *E, int ano)
{
    int count = 0;
    while (E != NULL)
    {
        if (E->dtencontro.ano == ano)
        {
            count++;
        }
        E = E->nseg;
    }

    return count;
}

