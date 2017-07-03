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
bool erroParametro;
bool erroIndiceParametro;
bool erroDoisIndiceParametro;
bool erroTipoIndiceParametro;

/* Variáveis globais para erro de corpo de função */
bool erroCorpo;
bool erroLeia;
bool erroEscreva;
bool erroRetorna;

void transfereLinha(int);
void erroDeclaraVariavel(Arvore*, Arvore*, int);
void erroFuncao(char*);
void erroParametroFuncao();
void erroListaParametros(Arvore*);
void erroCorpoFuncao(Arvore*);
void imprimeErro();

#endif