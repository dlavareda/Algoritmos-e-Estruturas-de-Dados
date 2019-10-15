typedef struct OBSERVADOR
{
    int codigo; //critério de ordenação na lista
    char nome[80];
    struct OBSERVADOR *nseg;
} Observador;
typedef struct OBSERVACAO
{
    int dia, mes, ano;
    / data da observação char nome[80]; //critério de ordenação na lista
    Observador *observador;
    float distancia;
    struct OBSERVACAO *nseg[4]; //lista de salto
    int nivel;
    / nível na lista de salto
} Observacao;