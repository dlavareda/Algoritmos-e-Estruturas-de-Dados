//Exercicio 14 folha pratica 2

typedef struct TRABALHO
{
    int numero;      //número do aluno;
    int codTrabalho; //identificador do trabalho;
    float nota;      //guarda nota do trabalho [0,20]
    struct TRABALHO *nseg;
} Trabalho;

Trabalho *makenode()
{
    Trabalho *nv;
    nv = (Trabalho *)malloc(sizeof(Trabalho));
    nv->nseg = NULL;
    return (nv);
}

Trabalho *insertlast(Trabalho *T, Trabalho *nv)
{

    Trabalho *aux = T;
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

//a - Contar o total de trabalhos feitos por determinado aluno;
int contarTrabalhosPorAluno(Trabalho *T, int numeroaluno)
{
    int count = 0;
    while (T->nseg != NULL)
    {
        if (T->numero == numeroaluno)
        {
            count++;
        }
        T = T->nseg;
    }
    return count;
}

//b - Calcular a classificação média de um aluno;
float classificacaoMediaAluno(Trabalho *T, int numeroaluno)
{
    float soma = 0.0, media = 0.0;
    int count = 0;
    while (T->nseg != NULL)
    {
        if (T->numero == numeroaluno)
        {
            count++;
            soma += T->nota;
        }
        T = T->nseg;
    }
    media = soma / count;
    return media;
}
//c - Imprimir o código do trabalho que mais alunos fizeram;
void trabalhoMaisRealizado(Trabalho *T)
{
}
//d - Mostrar uma pauta com as classificações dos alunos a determinado trabalho

//d1 Sem ordenação específica;
void classificacoes(Trabalho *T, int codTrabalho)
{
    while (T->nseg != NULL)
    {
        if (T->codTrabalho == codTrabalho)
        {
            printf("Aluno %d Nota %f\n", T->numero, T->nota);
        }
        T = T->nseg;
    }
}

//d2 Mostrando as classificações dos alunos por ordem decresente;
void classificacoesOrdenadas(Trabalho *T)
{
}

// e - Contar o número de alunos com classificação média superior a um determinado valor;

int contarMediasSuperiores(Trabalho *T, float media)
{
}
//f - Contar o número de alunos que nunca alcançaram uma nota positiva;
int contarNegativas(Trabalho *T)
{
  
}