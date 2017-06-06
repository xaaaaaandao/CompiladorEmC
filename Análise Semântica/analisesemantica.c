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

bool verificaFuncaoPrincipal(Arvore *arvore){
    Arvore *auxiliar = arvore -> filho;
    //Percorro a lista de declarações
    while(auxiliar != NULL){
        //Verifico se existe alguma declaração de função
        if(compareString(auxiliar -> string, "declaracao_funcao") == 0){
            //Verifico se tem um filho chamado atribuição
            Arvore *declaracao_funcao = auxiliar -> filho;
            while(declaracao_funcao != NULL){
                if(compareString(declaracao_funcao -> string, "cabecalho") == 0){
                    if(compareString(declaracao_funcao -> filho -> string, "principal") == 0){
                        return true;
                    }
                }
                declaracao_funcao = declaracao_funcao -> proximo;
            }

        }
        auxiliar = auxiliar -> proximo;
    }
    printf("[\033[1m\033[31merro\033[0m] não existe uma função principal\n");
    return false;
}

/*
PERGUNTAR
1 - COMO RETORNAR A LINHA DO ERRO??
2 - QUE TIPO DE ERRO QUE AGENTE DETECTA NA ANÁLISE SINTÁTICA?
3 - A FUNÇÃO PRINCIPAL PODE OU NÃO TER PARAMETROS?
4 - POSSO CRIAR REGRAS QUE SÃO ERRADA E GERAR ERROS?
5 - UMA FUNÇÃO É OBRIGATÓRIO TER CORPO?
*/
void percorreArvore(Arvore *arvore){
    Arvore *lista_declaracoes = retornaNo(arvore, "lista_declaracoes");
    bool okAtribuicoesGlobal, okFuncaoPrincipal;
    //Verificamos se existe lista_declaracoes, caso não tenha existe algum erro
    if(lista_declaracoes != NULL){
       //Verificamos se existem atribuições globais
        okAtribuicoesGlobal = verificaAtribuicoesGlobal(lista_declaracoes);
        okFuncaoPrincipal = verificaFuncaoPrincipal(lista_declaracoes);
        if(okAtribuicoesGlobal && okFuncaoPrincipal){
            printf("tudo certo\n");
        }
    } else {
        printf("\033[1m\033[31merro na árvore\033[0m\n");
    }
}