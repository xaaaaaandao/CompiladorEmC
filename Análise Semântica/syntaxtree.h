#ifndef SYNTAXTREE_H
#define	SYNTAXTREE_H

#include <stdbool.h>
#include <stdarg.h>

#define MAX 3276

struct arvore {
    unsigned long int p;
    unsigned long int f;
    char string[MAX];
    struct arvore *proximo;
    struct arvore *filho;
};

typedef struct arvore Arvore;

/* Variável global */
FILE *fileLog;
int linhaAtual;

int compareString(char[], char[]);
Arvore* adicionaIrmao(Arvore*, Arvore*);
Arvore *adicionaFilho(Arvore*, Arvore*);
void imprimeArvore(Arvore*);
Arvore *criaNo(char*, int, ...);
bool pertenceArvore(Arvore*, char*);
void verificarLog();
char *nomeRotulo(unsigned long int);
void arvoreDot(FILE*, Arvore*);
void gerandoDot(Arvore*);
void erroLinha(int);

#endif