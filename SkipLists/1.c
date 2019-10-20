#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main(){

    Nodo *N = NULL;
    Nodo *nv = NULL;
    nv = makenode();
    nv->chave = 1234;
    N = inserirListaSalto(N, nv);
        nv = makenode();
    nv->chave = 4321;
    N = inserirListaSalto(N, nv);
    return 0;

}
