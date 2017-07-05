#ifndef LISTA_H
#define	LISTA_H

#include "syntaxtree.h"

typedef struct novariaveis{
	bool usada;
	char tipo[MAX];
	char nome[MAX];
	bool ehUnidimensional;
	bool ehBidimensional;
	char valor1[MAX];
	char valor2[MAX];
	bool ehGlobal;
	bool indiceValido;
	struct novariaveis *proximo;
}NoVariaveis;

typedef struct{
	NoVariaveis *primeiro, *ultimo;
	int tamanho;
}ListaVariaveis;

typedef struct noinicializacao{
	char origem[MAX];
	bool origemUnidimensional;
	bool origemBidimensional;
	char origemValor1[MAX];
	char origemValor2[MAX];
	char destino[MAX];
	bool destinoUnidimensional;
	bool destinoBidimensional;
	char destinoValor1[MAX];
	char destinoValor2[MAX];
	struct noinicializacao *proximo;
}NoInicializacao;

typedef struct{
	NoInicializacao *primeiro, *ultimo;
	int tamanho;
}ListaInicializacao;

typedef struct nofuncao{
	bool ehChamada;
	char tipo[MAX];
	char nome[MAX];
	Arvore *endereco;
	Arvore *parametros;
	Arvore *corpo;
	int numeroArgumento;
	struct nofuncao *proximo;
}NoFuncao;

typedef struct{
	NoFuncao *primeiro, *ultimo;
	int tamanho;
}ListaFuncao;

void limpaListaInicializacao(ListaInicializacao*);
void limpaListaVariavel(ListaVariaveis*);
void inicializaListaFuncao(ListaFuncao*);
void inicializaListaVariaveis(ListaVariaveis*);
void inicializaListaInicializacao(ListaInicializacao*);
int vaziaListaFuncao(ListaFuncao*);
int vaziaListaVariaveis(ListaVariaveis*);
int vaziaListaInicializacao(ListaInicializacao*);
void insereListaFuncao(ListaFuncao*, char*, char*, Arvore*, Arvore*, Arvore*, int, bool);
void insereListaVariaveis(ListaVariaveis*, char*, char*, bool, bool, char*, char*, bool, bool);
void insereListaInicializacao(ListaInicializacao*, char*, bool, bool, char*, char*, char*, bool, bool, char*, char*);
int tamanhoListaFuncao(ListaFuncao*);
int tamanhoListaVariaveis(ListaVariaveis*);
int tamanhoListaInicializacao(ListaInicializacao*);
void imprimeListaFuncao(ListaFuncao*);
void imprimeListaVariaveis(ListaVariaveis*);
void imprimeListaInicializacao(ListaInicializacao*);

#endif /* LISTA_H */