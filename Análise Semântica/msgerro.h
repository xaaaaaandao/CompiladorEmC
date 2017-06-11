#ifndef MSGERRO_H
#define	MSGERRO_H

#include "syntaxtree.h"

void imprimeErro();
void erroDeclaraVariavel(int, int, char*, Arvore*);
void erroIndice(char*, int);

FILE *logErro;
static bool erroSintaxe = false;
int tipoErroIndice;

#endif