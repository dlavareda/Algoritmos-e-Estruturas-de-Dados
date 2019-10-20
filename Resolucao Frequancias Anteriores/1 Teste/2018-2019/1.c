#include <stdio.h>

//1b

int totalServicosPrestados(Servico *S, int BI)
{
    Prestados *P = S->P;
    Pessoa *Person = P->person;

    int count = 0;
    while (S != NULL)
    {
        while (P != NULL)
        {
            if (S->P->Person->BI == BI)
            {
                count++;
            }
            P = P->nseg;
        }
        S = S->nseg;
    }
    return count;
}