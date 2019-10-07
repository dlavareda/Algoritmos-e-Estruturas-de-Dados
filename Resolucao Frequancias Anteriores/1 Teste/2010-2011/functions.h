typedef struct ELEICAO
{
    int BI;       //BI do sócio-votante
    int totVotos; //total de votos que o votante detém
    int BIVoto;   //BI do elemento em que o sócio votou
    struct ELEICAO *nseg;
} Eleicao;

/*a. (4 valores) Implemente uma função que verifique se as eleições foram
fraudulentas, isto é, se existiram elementos que votaram mais que uma vez.
A função deverá devolver 1 em caso afirmativo ou 0 em caso contrário.*/
int fraudulentas(Eleicao *L)
{
    Eleicao *aux;
    while (L->nseg != NULL)
    {
        aux = L->nseg;
        while (aux != NULL)
        {
            if(L->BI == aux->BI){
                return 1;
            }
            aux = aux->nseg;
        }
         L = L->nseg;
    }
    return 0;
}
/*b. (3 valores) Implemente uma função que conte o total acumulado de votos de
todos os eleitores.*/
int totalVotos(Eleicao* L){
    int count = 0;
    while (L != NULL)
    {
       count+=(L->totVotos);
       L = L->nseg;
    }
    return count;
}

/*c. (3 valores) Implemente uma função que devolva a percentagem de votos que
um determinado elemento teve, em relação ao total calculado na alínea
anterior.*/
float percentagem(Eleicao* L, int BI){
    int count = 0;
    int somavotos;
    float percent = 0.0;
    Eleicao *aux = L;
    while (L != NULL)
    {
        if(L->BIVoto == BI){
            count+=(L->totVotos);
        }
        L=L->nseg;
    }
    somavotos = totalVotos(aux);

    percent = (float)count/(float)somavotos;
    return percent*100;
}

/*d. (4 valores) Implemente uma função que devolva o BI do vencedor das
eleições.*/
int vencedor(Eleicao* L){
    float maior, percent;
    int vencedor;
    while (L != NULL)
    {
        percent = percentagem(L, L->BIVoto);
        if (percent > maior)
        {
            maior = percent;
            vencedor = L->BIVoto;
        }
        L=L->nseg;
    }
    return vencedor;
}

//Funçoes para preencher a lista e testar o programa

Eleicao *makenode()
{
    Eleicao *nv;
    nv = (Eleicao *)malloc(sizeof(Eleicao));
    nv->nseg = NULL;
    return (nv);
}

Eleicao *insertlast(Eleicao *T, Eleicao *nv)
{

    Eleicao *aux = T;
    if (T == NULL)
    {
        return nv;
    }
    while (aux->nseg != NULL)
    {
        aux = aux->nseg;
    }
    aux->nseg = nv;
    return T;
}