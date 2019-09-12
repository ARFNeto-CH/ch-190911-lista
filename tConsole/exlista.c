#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "windows.h"

struct NO
{
	int elemento;
	struct NO* prox;
	struct NO* ant;
};
////////////////////////////////////////////////////////////////////////
/*
             essa parte veio pronta
 */
////////////////////////////////////////////////////////////////////////

typedef struct
{
	struct NO* inicio;
} LISTA;


void init(LISTA* ls)
{
	ls->inicio = NULL;
}


int empty(LISTA* ls)
{
	if (ls->inicio == NULL)
		return 1;
	else
		return 0;
}


void insert(LISTA* ls, int elemento)
{
	struct NO* novo = (struct NO*) malloc(sizeof(struct NO));
	if (ls->inicio != NULL)
	{
		ls->inicio->ant = novo;
	}
	novo->elemento = elemento;
	novo->prox = ls->inicio;
	novo->ant = NULL;
	ls->inicio = novo;
}	// end insert()
////////////////////////////////////////////////////////////////////////

/*                as duas funcoes novas             */

////////////////////////////////////////////////////////////////////////


int insere_mais_na_lista(LISTA* lista, int a_inserir, int* valores)
{
	// verifica os parametros antes
	if (lista == NULL)			return -1;
	if (valores == NULL)		return -2;
	if (a_inserir < 1)			return -3;

	// ok tem ao menos um
	for (int i = 0; i < a_inserir; i++)
	{
		insert(lista, valores[i]);
	}
}	// end insere_mais_na_lista()


int tamanho_da_lista(LISTA* lista)
{
	// verifica os ponteiros antes
	if (lista == NULL) return -1;
	int n = 0;
	struct NO* ponteiro = lista->inicio;
	while( ponteiro != NULL )
	{
		n += 1;
		ponteiro = ponteiro->prox;
	} 
	return n;
}	// end tamanho_da_lista()


/////////////////////////////////////////////////////////////////////
// uma funcao pra mostrar os valores afinal queremos saber se esta ok
/////////////////////////////////////////////////////////////////////


int mostra(LISTA* p)
{
	if (p == NULL) return -1;
	if (p->inicio == NULL) return -2;
	struct NO* ponteiro = p->inicio;
	int n = 1;
	printf("\nmostrando os elementos da lista\n");
	do
	{
		printf("%d: [%d]\n", n, ponteiro->elemento);
		n += 1;
		ponteiro = ponteiro->prox;
	} while (ponteiro != NULL);

	return n-1;	// somou antes
}


int main(int argc, char** argv)
{
	LISTA	nova;
	LISTA*	pLista = &nova;
	int		v[6] = { 6, 5, 4, 3, 2, 1 };
	int		r;  

	init( pLista );
	r = insere_mais_na_lista(pLista, 6, v);
	r = tamanho_da_lista(pLista);
	printf("Tamanho da lista depois de inserir os 6 [%d] (deve ser 6 claro)\n", r);
	printf("\nAgora mostra a lista: deve ter (1 2 3 4 5 6) ja que insere sempre no inicio\n");
	r = mostra(pLista);
	return 0;
	//r = tamanho_da_lista(pLista);
	//printf("Tamanho inicial da lista (vazia) [%d] (deve ser -2)\n", r );
	//// agora insere os caras
	//printf("Agora vai tentar inserir (6 5 4 3 2 1) na lista\n");
	//r = insere_mais_na_lista(pLista, 6, v);
	//printf("insere_mais_na_lista() retornou %d\n", r);
	//r = tamanho_da_lista(pLista);
	//printf("Tamanho da lista depois de inserir os 6 [%d] (deve ser 6 claro)\n", r);
	//printf("\nAgora mostra a lista: deve ter (1 2 3 4 5 6) ja que insere sempre no inicio\n");
	//mostra(pLista);
	//return 0;
}	// end main()