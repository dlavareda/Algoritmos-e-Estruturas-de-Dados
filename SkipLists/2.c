#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(NULL));
    int a = ((rand() % 4) + 1);
    for (int i = 0; i < 100; i++)
    {
        a = ((rand() % 4) + 1);
        printf("%d\n", a);
    }
    
}