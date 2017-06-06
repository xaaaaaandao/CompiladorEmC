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

bool verificaVariavelGlobal(Arvore *arvore, char *variavel){
    Arvore *auxiliar = arvore -> filho;
    //Percorro a lista de declarações
    while(auxiliar != NULL){
        //Verifico se existe alguma declaracao de variável global
        if(compareString(auxiliar -> string, "declaracao_variaveis") == 0){
            Arvore *declaracao_variaveis = auxiliar -> filho;
            while(declaracao_variaveis != NULL){
                //Verifico se tem lista de variáveis
                if(compareString(declaracao_variaveis -> string, "lista_variaveis") == 0){
                    Arvore *lista_variaveis = declaracao_variaveis -> filho;
                    //Percorro por todos var, já que podemos ter mais de uma var
                    while(lista_variaveis != NULL){
                        //Verifico se a variável é igual
                        if(compareString(lista_variaveis -> filho -> string, variavel) == 0){
                            return true;
                        }
                        lista_variaveis = lista_variaveis -> proximo;
                    }
                }
                declaracao_variaveis = declaracao_variaveis -> proximo;
            }
        }
        auxiliar = auxiliar -> proximo;
    }
    return false;
}

bool verificaAtribuicoesGlobal(Arvore *arvore){
    Arvore *auxiliar = arvore -> filho;
    //Percorro a lista de declarações
    while(auxiliar != NULL){
        //Verifico se existe alguma inicialização de variável fora de função
        if(compareString(auxiliar -> string, "inicializacao_variaveis") == 0){
            //Verifico se tem um filho chamado atribuição
            if(compareString(auxiliar -> filho -> string, "atribuicao") == 0){
                Arvore *atribuicao = auxiliar -> filho;
                //Pego o nome da variável
                if(compareString(atribuicao -> filho -> string, "var") == 0){
                    Arvore *variavel = atribuicao -> filho -> filho;
                    if(verificaVariavelGlobal(arvore, variavel -> string) == false){
                        printf("[\033[1m\033[35maviso\033[0m] variável \033[1m\033[31m%s\033[0m não declarada\n", variavel -> string);
                        return false;
                    }
                }
            }
        }
        auxiliar = auxiliar -> proximo;
    }
    return true;
}


void percorreArvore(Arvore *arvore){
    Arvore *lista_declaracoes = retornaNo(arvore, "lista_declaracoes");
    bool okAtribuicoesGlobal;
    //Verificamos se existe lista_declaracoes, caso não tenha existe algum erro
    if(lista_declaracoes != NULL){
       //Verificamos se existem atribuições globais
        okAtribuicoesGlobal = verificaAtribuicoesGlobal(lista_declaracoes);
        if(okAtribuicoesGlobal){
            printf("tudo certo\n");
        }
    } else {
        printf("\033[1m\033[31merro na árvore\033[0m\n");
    }
    /*if(pai != NULL){
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

    }*/
}