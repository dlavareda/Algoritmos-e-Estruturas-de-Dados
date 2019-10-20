typedef struct SERVICO
{
    int dia, mes, ano;
    char descricao[80];
    struct Recebidos *R;
    struct Prestados *P;
    struct SERVICO *nseg;
    struct SERVICO *nant;
} Servico;

typedef struct RECEBIDOS
{
    struct Pessoa *person;
    struct RECEBIDOS *nseg;
} Recebidos;

typedef struct PRESTADOS
{
    struct Pessoa *person;
    struct PRESTADOS *nseg;
} Prestados;

typedef struct PESSOA
{
    int BI;
    char nome[80];
    struct PESSOA *nseg; //adicionar depois para lista salto 10

} Pessoa;

Pessoa *makenodePessoa()
{
    Pessoa *nv;
    nv = (Pessoa *)malloc(sizeof(Pessoa));
    nv->nseg = NULL;
    return (nv);
}
Pessoa *insertlastPessoa(Pessoa *M, Pessoa *nv)
{

    Pessoa *aux = M;
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

Servico *makenodeServico()
{
    Servico *nv;
    nv = (Servico *)malloc(sizeof(Servico));
    nv->nseg = NULL;
    return (nv);
}
Servico *insertlastServico(Servico *M, Servico *nv)
{

    Servico *aux = M;
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
Recebidos *makenodeRecebidos()
{
    Recebidos *nv;
    nv = (Recebidos *)malloc(sizeof(Recebidos));
    nv->nseg = NULL;
    return (nv);
}
Recebidos *insertlastRecebidos(Recebidos *M, Recebidos *nv)
{

    Recebidos *aux = M;
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
Prestados *makenodePrestados()
{
    Prestados *nv;
    nv = (Prestados *)malloc(sizeof(Prestados));
    nv->nseg = NULL;
    return (nv);
}
Prestados *insertlastPrestados(Prestados *M, Prestados *nv)
{

    Prestados *aux = M;
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

int totalServicosPrestados(Servico *S, int BI)
{
    Prestados *Prest = NULL;
    Pessoa *Person = NULL;

    int count = 0;
    while (S != NULL)
    {
        Prest = S->P;

        while (Prest != NULL)
        {
            Person = Prest->person;
            if (Person->BI == BI)
            {
                count++;
            }
            Prest = Prest->nseg;
        }
        S = S->nseg;
    }
    return count;
}
Pessoa *getPessoaBI(Pessoa *P, int BI)
{
    while (P != NULL)
    {
        if (P->BI == BI)
        {
            return P;
        }
        P = P->nseg;
    }
}

void listaPreguicosos(Pessoa *A, Servico *S)
{
    int count = 0;
    Servico *aux= S;
    Prestados *Prest = NULL;
    Pessoa *Person = NULL;
    while (A != NULL)
    {
        count = 0;
        S = aux;
        while (S != NULL)
        {
            Prest = S->P;
            while (Prest != NULL)
            {
                Person = Prest->person;
                if (Person->BI == A->BI)
                {
                    count++;
                }
                Prest = Prest->nseg;
            }
            S = S->nseg;
        }
        if (count == 0)
        {
           printf("%s\n", A->nome);
        }
        A = A->nseg;
    }
}