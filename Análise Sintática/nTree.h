#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>

#define MAX 3276

struct arvore {
    unsigned long int p;
    unsigned long int f;
    char string[MAX];
    struct arvore *proximo;
    struct arvore *filho;
};

typedef struct arvore Arvore;


FILE *fileLog;

int compareString(char stringA[], char stringB[]){
    int i = 0;
    int resultado;
    int igual = 1;
    if(strlen(stringA) != strlen(stringB)){
        return -1;
    }
    while(igual && stringA[i] != '\0' && stringB[i] != '\0'){
        if(stringA[i] != stringB[i]){
            igual = 0;
        }
        i++;
    }
    if(stringA[i-1] == '\0' && stringB[i-1] == '\0'){
        resultado = 0; 
    } else {
        resultado = stringA[i-1] - stringB[i-1];   
    }
    return resultado;
}

Arvore* adicionaIrmao(Arvore *no, Arvore *novoIrmao){
    if (no == NULL)
        return NULL;

    while (no -> proximo)
        no = no -> proximo;

    return (no -> proximo = novoIrmao);
}

Arvore *adicionaFilho(Arvore *no, Arvore *novoIrmao){
    if (no == NULL)
        return NULL;

    if (no -> filho)
        return adicionaIrmao(no -> filho, novoIrmao);
    else
        return (no -> filho = novoIrmao);
}

void imprimeArvore(Arvore *no){
    static unsigned long int i = 1;
    if(no -> filho == NULL){
        printf("-> %s \n\n", no -> string);        
        return;
    } else {
        //printf("%s (p:%lu) (f:%lu)\n", no -> string, no -> p, no -> f);
        printf("%s \n", no -> string);
        Arvore *filho =  no -> filho;
        while(filho != NULL){
            filho -> p = no -> f;
            filho -> f = i++;
            printf("%s ", filho -> string);
            filho = filho -> proximo;
        }
        printf("\n\n");
        filho =  no -> filho;
        while(filho != NULL){
            imprimeArvore(filho);
            filho = filho -> proximo;   
        }
    }
}

Arvore *criaNo(char *string, int numArg, ...){
    Arvore *no = malloc(sizeof(Arvore));
    if (no) {
        no->proximo = NULL;
        no->filho = NULL;
        strcpy(no->string, string);
        no -> p = 0;
        no -> f = 0;
        if(numArg > 0){
            va_list filhos;

            va_start(filhos, numArg);
            int i;
            for(i = 0; i < numArg; i++){
                Arvore *auxiliar = va_arg(filhos, Arvore*);
                adicionaFilho(no, auxiliar);
            }
            va_end(filhos);
        }
    }
    return no;
}

bool pertenceArvore(Arvore *no, char *string){
    static bool existe = false;
    if(no -> filho == NULL){
        if(compareString(no -> string, string) == 0){
            existe = true;
            return true;
        }
    } else {
        if(compareString(no -> string, string) == 0){
            existe = true;
            return true;
        }
        Arvore *filho =  no -> filho;
        while(filho != NULL){
            if(compareString(filho -> string, string) == 0){
                existe = true;
                return true;
            }
            filho = filho -> proximo;
        }
        filho =  no -> filho;
        while(filho != NULL){
            pertenceArvore(filho, string);
            filho = filho -> proximo;   
        }
    }
    if(existe){
        return true;
    }
    return false;
}

void verificarLog(){
    struct stat st;
    if (stat("log.txt", &st) == 0) {
        system("rm log.txt");
    } else {
        printf("\033[1m\033[31mGEROU LOG!\n");    
    }
}

char *nomeRotulo(unsigned long int valor){
    char *rotulo = (char*) calloc (MAX, sizeof(char));
    if(valor == 4294967295){
        printf("\033[1m\033[31mnão foi possível gerar .dot!\n");            
        exit(1);
    }
    sprintf(rotulo, "%lu", valor);
    return rotulo;
}

void arvoreDot(FILE *dot, Arvore *no){
    static bool primeiraVez = true;
    char rotuloOrigem[MAX], rotuloDestino[MAX], transicao[MAX];
    if(no -> filho == NULL){
        return;
    } else {
        if(primeiraVez){
            strcpy(rotuloOrigem, nomeRotulo(no -> f));
            strcat(rotuloOrigem, "[label=\"");
            strcat(rotuloOrigem, no -> string);
            strcat(rotuloOrigem, "\"];");
            //printf("%s\n", rotuloOrigem);
            fprintf(dot, "%s\n", rotuloOrigem);
            primeiraVez = false;       
        }
        //printf("%s (p:%lu) (f:%lu)\n", no -> string, no -> p, no -> f);
        Arvore *filho =  no -> filho;
        while(filho != NULL){
            strcpy(rotuloDestino, nomeRotulo(filho -> f));
            strcat(rotuloDestino, "[label=\"");
            strcat(rotuloDestino, filho -> string);
            strcat(rotuloDestino, "\"];");
            //printf("%s\n", rotuloDestino);
            fprintf(dot, "%s\n", rotuloDestino);
            strcpy(transicao, nomeRotulo(filho -> p));
            strcat(transicao, " -> ");
            strcat(transicao, nomeRotulo(filho -> f));
            strcat(transicao, ";");
            //printf("%s\n", transicao);
            fprintf(dot, "%s\n", transicao);
            //printf("%s (p:%lu) (f:%lu)\n", filho -> string, filho -> p, filho -> f);
            filho = filho -> proximo;
        }
        filho =  no -> filho;
        while(filho != NULL){
            arvoreDot(dot, filho);
            filho = filho -> proximo;   
        }
    }
}


void gerandoDot(Arvore *a){
    FILE *dot = fopen("syntax-tree.dot", "w");
    fprintf(dot, "digraph tree {\n");
    arvoreDot(dot, a);
    fprintf(dot, "}");
    fclose(dot);
    system("dot -Tpng -O syntax-tree.dot && shotwell syntax-tree.dot.png &");
}