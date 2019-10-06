//Exercicio 14 folha pratica 2

typedef struct TRABALHO{
int numero; //número do aluno;
int codTrabalho; //identificador do trabalho;
float nota; //guarda nota do trabalho [0,20]
struct TRABALHO *nseg;
 }Trabalho;

 //a - Contar o total de trabalhos feitos por determinado aluno;
int contarTrabalhosPorAluno(Trabalho *T, int numeroaluno){




}

 //b - Calcular a classificação média de um aluno;
float classificacaoMediaAluno(Trabalho *T, int numeroaluno){

}
 //c - Imprimir o código do trabalho que mais alunos fizeram;
void trabalhoMaisRealizado(Trabalho *T){

}
 //d - Mostrar uma pauta com as classificações dos alunos a determinado trabalho

//d1 Sem ordenação específica;
void classificacoes(Trabalho *T){

}

//d2 Mostrando as classificações dos alunos por ordem decresente;
void classificacoesOrdenadas (Trabalho *T){

}

// e - Contar o número de alunos com classificação média superior a um determinado valor;

int contarMediasSuperiores(Trabalho *T, float media){

}
//f - Contar o número de alunos que nunca alcançaram uma nota positiva;
int contarPositivas(Trabalho *T){

}