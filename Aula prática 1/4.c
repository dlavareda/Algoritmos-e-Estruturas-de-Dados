#include <stdio.h>
#include <stdlib.h>

typedef struct T
{
    int ID;
    struct T *nseg;
} Nodo;

int totEltsDif(Nodo *L)
{
    int count = 0;
    if (L == NULL)
        return 0;
    if (L->nseg == NULL)
        return 1;
    while (L->nseg != NULL)
    {
        if (L->ID != (L->nseg)->ID)
        {
            count++;
        }
    }
    return count;
}

int main()
{
}
