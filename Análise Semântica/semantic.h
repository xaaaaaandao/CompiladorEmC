#ifndef SEMANTIC_H
#define	SEMANTIC_H

#include <stdbool.h>
#include "syntaxtree.h"

FILE *arquivoSemantico;
bool erroSemantico;
int erroLinha;

void transfereLinha(int);
void erroDeclaraVariavel(Arvore*, Arvore*, int);
void imprimeErro();

#endif