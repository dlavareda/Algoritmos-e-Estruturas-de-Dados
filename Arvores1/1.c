#include <stdio.h>
#include <stdlib.h>

typedef struct NODO{
    int ID;
    struct NODO *fd;
    struct NODO *fe;
}Nodo;


int contaNos(Nodo *A){
	if(A == NULL)
		return 0; //Não há nós para contar
		
	return 1 + contarNos(A -> fd) + contarNos(A -> fe);
} // Para contar 5 nós esta funcao é chamada/executada 11 vezes

int contaFolhas(Nodo *A){
	if(A == NULL)
		return 0;
		
	if(A -> fe == A -> fd) //O filho esquerdo e o filho direito sao NULL
		return 1;
		
	return contaFolhas(A ->fd) + contaFolhas(A -> fe);
}

int cheia(Nodo *A){ // Retorna 1 se esta cheia e zero se nao esta
	if(A == NULL) //Se a árvore estiver vazia está cheia
		return 1;
		
	if((A -> fd == NULL && A -> fe != NULL) || (A -> fd != NULL && A -> fe == NULL))
		return 0;
		
	return cheia(A -> fe) && cheia(A -> fd); // Tambem podemos por return cheia(A -> fe) * cheia(A -> fd)
	
	
}

int completa(Nodo *A){
	if(A == NULL)
		return 1;
		
	if(contaNos(A -> fe) != contaNos(A -> fd))
		return 0;
		
	return (completa(A -> fd) && completa(A -> fe));
}

int equilibrada(Nodo *A){
	int diferenca;
	
	if(A == NULL)
		return 1;
		
	diferenca = contaNos(A -> fd) - contaNos(A -> fe);
	
	if((diferenca < -1) || (diferenca > 1))
		return 0;
		
	return equilibrada(A -> fd) && equilibrada(A -> fe);
}

//ou

int equilibrada(Nodo *A){
	if(A == NULL)
		return 1;
		
	if(fabs(ContaNos(A -> fd) - contaNos(A -> fe))>1)
		return 0;
		
	return equilibrada(A -> fd) && equilibrada(A -> fe);
}
/*
Nodo * remove(Nodo *A, Nodo *el){
	
}
*/