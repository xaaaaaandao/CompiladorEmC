#include <stdio.h>
#include <stdlib.h>
#include "analisesemantica.h"


Arvore *retornaNo(Arvore *no, char *string){
    if(no -> filho == NULL){
        if(compareString(no -> string, string) == 0){
            return no;
        }
    } else {
        if(compareString(no -> string, string) == 0){
            return no;
        }
        Arvore *filho =  no -> filho;
        while(filho != NULL){
            if(compareString(filho -> string, string) == 0){
                return filho;
            }
            filho = filho -> proximo;
        }
        filho =  no -> filho;
        while(filho != NULL){
            pertenceArvore(filho, string);
            filho = filho -> proximo;   
        }
    }
    return NULL;
}

bool existeInicializacao(Arvore *arvore){
    Arvore *auxiliar = arvore -> filho;
    while(auxiliar != NULL){
        if(compareString(auxiliar -> string, "inicializacao_variaveis") == 0){
            return true;
        }
        auxiliar = auxiliar -> proximo;
    }
    return false;
}




void percorreArvore(Arvore *arvore){
    Arvore *pai = retornaNo(arvore, "lista_declaracoes");
    if(pai != NULL){
        //Verifico se existem atribuições
        if(existeInicializacao(pai)){
            //Existe a inicialização
            //Ando por todas as inicializações
            Arvore *inicializacao = pai -> filho;
            while(inicializacao != NULL){
                if(compareString(inicializacao -> string, "inicializacao_variaveis") == 0){
                    //Achei a inicialização de variável
                    Arvore *variavel = retornaNo(inicializacao, "atribuicao");
                    //Pego o nome de variável
                    printf("nome var: %s\n", variavel -> filho -> filho -> string);
                    //Passo o nome para todas as declarações de variáveis
                }
                inicializacao = inicializacao -> proximo;
            }
        }

    } else {
        printf("\033[1m\033[31merro na árvore\033[0m\n");
    }
}