#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int BI, idade, peso, prop;
} Socio;

Socio *LerVectorSociosdoFicheiro(int *N, const char *fich)
{
    Socio *S;
    FILE *f;
    f = fopen(fich, "r");
    if (f == NULL)
        return NULL;
    S = (Socio *)malloc(sizeof(Socio));
    *N = 0;
    while (!feof(f))
    {
        S = (Socio *)realloc(S, (*N + 1) * sizeof(Socio));
        if (S == NULL)
            return NULL;
        fscanf(f, "%d", &S[*N].BI);
        fscanf(f, "%d", &S[*N].idade);
        fscanf(f, "%d", &S[*N].peso);
        fscanf(f, "%d", &S[*N].prop);
        (*N)++;
    }
    fclose(f);
    return S;
}
void EscreverVectorSocios(Socio S[], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        printf("BI = %d\n", S[i].BI);
        printf("Idade = %d\n", S[i].idade);
        printf("Peso = %d\n", S[i].peso);
        printf("Proponente = %d\n", S[i].prop);
        printf("\n");
    }
}
int proposta(Socio *v, int totV, int BIpessoa, int BIProp)
{
    //1=Sim, 0=Não
    int i = 0;
    int j = 0;
    while (i < totV)
    {
        if ((v[i].BI == BIpessoa))
        {
            //encontrou proponente direto
            if (v[i].BI == BIpessoa && v[i].prop == BIProp)
            {
                if (j == 0)
                {
                    printf("---------Propomente Direto-------------\n");
                }
                else

                {
                    printf("---------Proponente Indireto-------------\n");
                }

                return 1;
            }
            //nao achou direto
            else if (v[i].prop != -1)
            {
                //return 1;
                BIpessoa = v[i].prop;
                i = 0;
                j++;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            i++;
        }
    }
    return 0;
}

void main()
{
    int *tam, bipessoa, biproponente, resposta;
    Socio *S;
    S = (Socio *)malloc(0 * sizeof(Socio));
    printf("Introduza BI pessoa\n");
    scanf("%d", &bipessoa);
    printf("Introduza BI proponente");
    scanf("%d", &biproponente);
    S = LerVectorSociosdoFicheiro(tam, "/home/dlavareda/Documents/UBI/2019-2020/Estruturas e Algoritmos de Dados/Revisões/socios.txt");
    printf("Foram lidos %d Sócios\n", *tam);
    EscreverVectorSocios(S, tam);
    resposta = proposta(S, *tam, bipessoa, biproponente);
    if (resposta == 0)
    {
        printf("---------Proponente Não Encontrado-------------\n");
    }
    else if (resposta == 1)
    {
        printf("ENcontrado");
    }
}
