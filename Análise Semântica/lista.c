#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void limpaListaInicializacao(ListaInicializacao *l){
    NoInicializacao *temporario, *atual;

    atual = l -> primeiro;
    while(atual != NULL){
    	temporario = atual -> proximo;
    	free(atual);
    	atual = temporario;
    }
    free(l);
}

void limpaListaVariavel(ListaVariaveis *l){
    NoVariaveis *temporario, *atual;

    atual = l -> primeiro;
    while(atual != NULL){
    	temporario = atual -> proximo;
    	free(atual);
    	atual = temporario;
    }
    free(l);
}

void inicializaListaFuncao(ListaFuncao *l){
	l -> primeiro  = NULL;
	l -> ultimo = NULL;
	l -> tamanho = 0;
}

void inicializaListaVariaveis(ListaVariaveis *l){
	l -> primeiro  = NULL;
	l -> ultimo = NULL;
	l -> tamanho = 0;
}

void inicializaListaInicializacao(ListaInicializacao *l){
	l -> primeiro  = NULL;
	l -> ultimo = NULL;
	l -> tamanho = 0;
}

int vaziaListaFuncao(ListaFuncao *l){
	return (l -> primeiro == NULL);
}  

int vaziaListaVariaveis(ListaVariaveis *l){
	return (l -> primeiro == NULL);
}  

int vaziaListaInicializacao(ListaInicializacao *l){
	return (l -> primeiro == NULL);
}  

void insereListaFuncao(ListaFuncao *l, char *tipo, char *nome, Arvore *endereco,  Arvore *lista_parametros, Arvore *corpo, int numeroArgumento, bool ehUsada){
	NoFuncao *novo = (NoFuncao *) malloc(sizeof(NoFuncao));
	strcpy(novo -> tipo, tipo);
	strcpy(novo -> nome, nome);
	novo -> endereco = endereco;
	novo -> parametros = lista_parametros;
	novo -> corpo = corpo;
	novo -> numeroArgumento = numeroArgumento;
	novo -> ehChamada = ehUsada;
	novo -> proximo = NULL;

	if (vaziaListaFuncao(l)){
		l -> primeiro = novo;
		l -> ultimo   = novo;
	} else {
		l -> ultimo -> proximo = novo;
		l -> ultimo = novo;
	}
	
	l -> tamanho++;
}

void insereListaVariaveis(ListaVariaveis *l, char *tipo, char *nome, bool ehUnidimensional, bool ehBidimensional, char *valor1, char *valor2, bool ehGlobal, bool indiceValido){
	NoVariaveis *novo = (NoVariaveis *) malloc(sizeof(NoVariaveis));
	strcpy(novo -> tipo, tipo);
	strcpy(novo -> nome, nome);
	novo -> ehUnidimensional = ehUnidimensional;
	novo -> ehBidimensional = ehBidimensional;
	strcpy(novo -> valor1, valor1);
	strcpy(novo -> valor2, valor2);
	novo -> ehGlobal = ehGlobal;
	novo -> indiceValido = indiceValido;
	novo -> proximo = NULL;

	if (vaziaListaVariaveis(l)){
		l -> primeiro = novo;
		l -> ultimo   = novo;
	} else {
		l -> ultimo -> proximo = novo;
		l -> ultimo = novo;
	}
	
	l -> tamanho++;
}


void insereListaInicializacao(ListaInicializacao *l, char *origem, bool origemUnidimensional, bool origemBidimensional, char *origemValor1, char* origemValor2, char *destino, bool destinoUnidimensional, bool destinoBidimensional, char *destinoValor1, char *destinoValor2){
	NoInicializacao *novo = (NoInicializacao *) malloc(sizeof(NoInicializacao));
	strcpy(novo -> origem, origem);
	novo -> origemUnidimensional = origemUnidimensional;
	novo -> origemBidimensional = origemBidimensional;
	strcpy(novo -> origemValor1, origemValor1);
	strcpy(novo -> origemValor2, origemValor2);
	strcpy(novo -> destino, destino);
	novo -> destinoUnidimensional = destinoUnidimensional;
	novo -> destinoBidimensional = destinoBidimensional;
	strcpy(novo -> destinoValor1, destinoValor1);
	strcpy(novo -> destinoValor2, destinoValor2);
	novo -> proximo = NULL;
	if (vaziaListaInicializacao(l)){
		l -> primeiro = novo;
		l -> ultimo   = novo;
	} else {
		l -> ultimo -> proximo = novo;
		l -> ultimo = novo;
	}
	
	l -> tamanho++;
}

int tamanhoListaFuncao(ListaFuncao *l){
	return (l -> tamanho);
}

int tamanhoListaVariaveis(ListaVariaveis *l){
	return (l -> tamanho);
}

int tamanhoListaInicializacao(ListaInicializacao *l){
	return (l -> tamanho);
}

void imprimeListaFuncao(ListaFuncao *l){
	if (vaziaListaFuncao(l)){
		printf( "Empty list!\n");
	} else {
		NoFuncao *auxiliar;
		auxiliar = l -> primeiro;
		while (auxiliar != NULL){ 
			printf("tipo: %s \n", auxiliar -> tipo);
			printf("nome: %s \n", auxiliar -> nome);
			printf("numeroArgumento: %d \n", auxiliar -> numeroArgumento);			
			auxiliar = auxiliar -> proximo;
		}
	}    
}

void imprimeListaVariaveis(ListaVariaveis *l){
	if (vaziaListaVariaveis(l)){
		printf( "Empty list!\n");
	} else {
		NoVariaveis *auxiliar;
		auxiliar = l -> primeiro;
		while (auxiliar != NULL){ 
			if(auxiliar -> ehGlobal){
				printf("é global\n");
			} else {
				printf("não é global\n");
			}
			printf("tipo variável: %s\n", auxiliar -> tipo);
			printf("nome variável: %s\n", auxiliar -> nome);
			if(auxiliar -> ehUnidimensional){
				printf("%s\n", auxiliar -> valor1);
			} else if(auxiliar -> ehBidimensional){
				printf("%s\n", auxiliar -> valor1);
				printf("%s\n", auxiliar -> valor2);
			}
			printf("\n");
			auxiliar = auxiliar -> proximo;
		}
	}    
}

void imprimeListaInicializacao(ListaInicializacao *l){
	if (vaziaListaInicializacao(l)){
		printf( "Empty list!\n");
	} else {
		NoInicializacao *auxiliar;
		auxiliar = l -> primeiro;
		while (auxiliar != NULL){ 
			printf("nome: %s\n", auxiliar -> origem);
			if(auxiliar -> origemUnidimensional){
				printf("%s\n", auxiliar -> origemValor1);
			} else if(auxiliar -> origemBidimensional){
				printf("%s\n", auxiliar -> origemValor1);
				printf("%s\n", auxiliar -> origemValor2);
			}
			printf("destino: %s\n", auxiliar -> destino);
			if(auxiliar -> destinoUnidimensional){
				printf("%s\n", auxiliar -> destinoValor1);
			} else if(auxiliar -> destinoBidimensional){
				printf("%s\n", auxiliar -> destinoValor1);
				printf("%s\n", auxiliar -> destinoValor2);
			}
			printf("\n");
			auxiliar = auxiliar -> proximo;
		}
	}    
}

        