#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
    if(no -> filho == NULL){
        printf("-> %s \n\n", no -> string);        
        return;
    } else {
        printf("%s \n", no -> string);
        Arvore *filho =  no -> filho;
        while(filho != NULL){
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