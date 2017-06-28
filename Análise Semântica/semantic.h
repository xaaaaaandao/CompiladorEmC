#ifndef SEMANTIC_H
#define	SEMANTIC_H

#include <stdbool.h>
#include "syntaxtree.h"

/* Variáveis globais para uso geral */
FILE *arquivoSemantico;
FILE *auxiliarSemantico;
bool erroSemantico;
int erroLinha;

/* Variáveis globais para erro de paramêtros */
int erroParametro;
char erroTipo[MAX];
char erroIdentificador[MAX];

void transfereLinha(int);
void erroDeclaraVariavel(Arvore*, Arvore*, int);
void erroFuncao(char*);
void erroParametroFuncao();
void erroListaParametros(Arvore*);
void imprimeErro();

#endif