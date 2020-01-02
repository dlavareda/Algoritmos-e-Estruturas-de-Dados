#include <stdio.h>
#include <stdlib.h>

typedef struct NODO
{
	int ID;
	int Idade;
	struct NODO *fd;
	struct NODO *fe;
} Nodo;

int contaNos(Nodo *A)
{
	if (A == NULL)
		return 0; //Não há nós para contar

	return 1 + contarNos(A->fd) + contarNos(A->fe);
} // Para contar 5 nós esta funcao é chamada/executada 11 vezes

int contaFolhas(Nodo *A)
{
	if (A == NULL)
		return 0;

	if (A->fe == A->fd) //O filho esquerdo e o filho direito sao NULL
		return 1;

	return contaFolhas(A->fd) + contaFolhas(A->fe);
}

int cheia(Nodo *A)
{				   // Retorna 1 se esta cheia e zero se nao esta
	if (A == NULL) //Se a árvore estiver vazia está cheia
		return 1;

	if ((A->fd == NULL && A->fe != NULL) || (A->fd != NULL && A->fe == NULL))
		return 0;

	return cheia(A->fe) && cheia(A->fd); // Tambem podemos por return cheia(A -> fe) * cheia(A -> fd)
}

int completa(Nodo *A)
{
	if (A == NULL)
		return 1;

	if (contaNos(A->fe) != contaNos(A->fd))
		return 0;

	return (completa(A->fd) && completa(A->fe));
}

int equilibrada(Nodo *A)
{
	int diferenca;

	if (A == NULL)
		return 1;

	diferenca = contaNos(A->fd) - contaNos(A->fe);

	if ((diferenca < -1) || (diferenca > 1))
		return 0;

	return equilibrada(A->fd) && equilibrada(A->fe);
}

//ou

int equilibrada(Nodo *A)
{
	if (A == NULL)
		return 1;

	if (fabs(ContaNos(A->fd) - contaNos(A->fe)) > 1)
		return 0;

	return equilibrada(A->fd) && equilibrada(A->fe);
}
/*
Nodo * remove(Nodo *A, Nodo *el){
	
}
*/

///////////////////////////////////////// Aula 2 /////////////////////////////////////////

Nodo *maxID(Nodo *A)
{
	while (A->fd != NULL)
		A = A->fd;
	return A;
}

Nodo *maxID(Nodo *A)
{
	if (A == NULL)
		return NULL;
	if (A->fd == NULL)
		return A;
	return maxID(A->fd);
}

Nodo *maxX(Nodo *A)
{
	Nodo *d, *e;
	if (A == NULL)
		return NULL;
	e = maxX(A->fe);
	d = maxX(A->fd);
	if (e != NULL)
	{
		if (e->Idade > A->Idade)
		{
			A = e;
		}
	}
	if (d != NULL)
	{
		if (d->Idade > A->Idade)
		{
			A = d;
		}
	}
	return A;
}

int altura(Nodo *A)
{
	int d, e;
	if (A == NULL)
		return 0;
	e = altura(A->fe);
	d = altura(A->fd);
	if (e > d)
	{
		return e + 1;
	}
	else
	{
		return d + 1;
	}
}

int profundidade(Nodo *A, Nodo *el)
{
	int aux;
	if (A == NULL)
		return -1;
	if (A == el)
		return 0;
	if (A->ID > el->ID)
	{
		aux = profundidade(A->fe, el);
		if (aux == -1)
			return -1;
		else
			return aux + 1;
	}
	aux = profundidade(A->fd, el);
	if (aux == -1)
		return -1;
	else
		return aux + 1;
}

Nodo *espelho(Nodo *A)
{
	Nodo *aux;
	if (A == NULL)
		return A;
	aux = espelho(A->fe);
	A->fe = espelho(A->fd);
	A->fd = aux;
	return A;
}

int bemFormada(Nodo *A)
{ //1 sim 0 não
	Nodo *aux;
	if (A == NULL)
	{
		return (1);
	}
	aux = maxX(A->fe);
	if (aux != NULL)
	{
		if (aux->Idade > A->Idade)
		{
			return 0;
		}
	}
	aux = minX(A->fd);
	if (aux != NULL)
	{
		if (aux->Idade < A->Idade)
		{
			return 0;
		}
	}
	return bemFormada(A->fe) && bemFormada(A->fd);
}
int repetidos(Nodo *A){
	
}