#include <stdio.h>
#include <stdlib.h>

typedef struct T
{
    int ID;
    struct T *nseg;
} Nodo;

int totEltsDif(Nodo *L)
{
    int count = 1;
    if (L == NULL)
        return 0;
    while (L->nseg != NULL)
    {
        if (L->ID != (L->nseg)->ID)
        {
            count++;
        }
        L = L->nseg;
    }
    return count;
}

int main()
{
}
