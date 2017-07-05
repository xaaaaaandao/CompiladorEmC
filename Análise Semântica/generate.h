#ifndef GENERATE_H
#define	GENERATE_H

#include "lista.h"

void cabecalhoCode(char*,FILE*);
void caudaCode(char*, FILE*);
void preencheCodeGlobal(FILE*, ListaVariaveis*, ListaInicializacao*);

#endif /* GENERATE_H */