#ifndef SEMANTIC_H
#define	SEMANTIC_H

#include <stdbool.h>
#include "lista.h"
#include "syntaxtree.h"

/* Variáveis globais para uso geral */
FILE *arquivoSemantico;
FILE *auxiliarSemantico;
bool erroSemantico;
int erroLinha;
bool erroGrave;
bool erroVisita;

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

bool retornaCompativel(char *, char*, ListaVariaveis*, ListaVariaveis*, ListaVariaveis*);
bool confirmacaoTipo(ListaVariaveis*, ListaVariaveis*,  ListaVariaveis*, char*, bool, bool);
bool varUnidimensional(ListaVariaveis*, char*);
bool varBidimensional(ListaVariaveis*, char*);
void transfereLinha(int);
void erroDeclaraVariavel(Arvore*, Arvore*, int);
void erroFuncao(char*);
void erroListaParametros(Arvore*);
void erroCorpoFuncao(Arvore*);
bool indiceEhInteiro(Arvore*);
void imprimeErro(char*, Arvore*);

#endif