#include <stdio.h>
#include <stdlib.h>
#include "msgerro.h"
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

//Verifica se as atribuições globais, tem suas variáveis declaradas
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
                    break;
                }
                declaracao_variaveis = declaracao_variaveis -> proximo;
            }
        }
        auxiliar = auxiliar -> proximo;
    }
    return false;
}

bool verificaAtribuicoesGlobal(Arvore *arvore){
    bool variavaelDeclarada = true ;
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
                    Arvore *variavel = atribuicao -> filho;
                    if(verificaVariavelGlobal(arvore, variavel -> filho -> string) == false){
                        fprintf(logErro, "[\033[1m\033[35maviso\033[0m] variável \033[1m\033[31m%s\033[0m não declarada\n", variavel -> filho -> string);
                        variavaelDeclarada = false;
                    }
                }
            }
        }
        auxiliar = auxiliar -> proximo;
    }
    if(variavaelDeclarada)
        return true;
    return false;
}

//Verifica a existência da função principal
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
    fprintf(logErro, "[\033[1m\033[31merro\033[0m] não existe uma função principal\n");
    return false;
}

//Verifica se existe a redefinição de funções
bool nomeFuncaoRepetido(Arvore *arvore, char *nomeFuncao){
    int somatorio = 0;
    Arvore *auxiliar = arvore -> filho;
    while(auxiliar != NULL){
        if(compareString(auxiliar -> string, "declaracao_funcao") == 0){
            //Verifico se tem um filho chamado atribuição
            Arvore *declaracao_funcao = auxiliar -> filho;
            while(declaracao_funcao != NULL){
                if(compareString(declaracao_funcao -> string, "cabecalho") == 0){
                    if(compareString(declaracao_funcao -> filho -> string, nomeFuncao) == 0){
                        somatorio++;
                    }
                }
                declaracao_funcao = declaracao_funcao -> proximo;
            }

        }
        auxiliar = auxiliar -> proximo;
    }
    if(somatorio == 1)
        return true;
    return false;
}

bool verificaRedefinicaoFuncao(Arvore *arvore){
    bool redefinicaoFuncao = false;
    Arvore *auxiliar = arvore -> filho;
    while(auxiliar != NULL){
        if(compareString(auxiliar -> string, "declaracao_funcao") == 0){
            //Verifico se tem um filho chamado atribuição
            Arvore *declaracao_funcao = auxiliar -> filho;
            while(declaracao_funcao != NULL){
                if(compareString(declaracao_funcao -> string, "cabecalho") == 0){
                    if(nomeFuncaoRepetido(arvore, declaracao_funcao -> filho -> string) == false){
                        fprintf(logErro, "[\033[1m\033[31merro\033[0m] redefinição da função %s\n", declaracao_funcao -> filho -> string);    
                        //return false;
                        redefinicaoFuncao = true;
                    }
                }
                declaracao_funcao = declaracao_funcao -> proximo;
            }

        }
        auxiliar = auxiliar -> proximo;
    }
    if(redefinicaoFuncao)
        return false;
    return true;
}

//Verifica se existe a redefinição de variáveis globais
bool nomeVariavelRepetido(Arvore *arvore, char *nomeVariavel){
    int somatorio = 0;
    Arvore *auxiliar = arvore -> filho;
    while(auxiliar != NULL){
        if(compareString(auxiliar -> string, "declaracao_variaveis") == 0){
            //Verifico se tem um filho chamado atribuição
            Arvore *lista_variaveis = auxiliar -> filho;
            while(lista_variaveis != NULL){
                if(compareString(lista_variaveis -> string, "lista_variaveis") == 0){
                    Arvore *variaveis = lista_variaveis -> filho;
                    while(variaveis != NULL){
                        if(compareString(variaveis -> filho -> string, nomeVariavel) == 0){
                            somatorio++;
                        }
                        variaveis = variaveis -> proximo;
                    }
                    break;
                }
                lista_variaveis = lista_variaveis -> proximo;
            }
        }
        auxiliar = auxiliar -> proximo;
    }
    if(somatorio == 1)
        return true;
    return false;
}

//Retorna o tipo de uma variável
bool verificaRedefinicaoVariavelGlobal(Arvore *arvore){
    bool redefinicaoVariavelGlobal = false;
    Arvore *auxiliar = arvore -> filho;
    while(auxiliar != NULL){
        if(compareString(auxiliar -> string, "declaracao_variaveis") == 0){
            //Verifico se tem um filho chamado atribuição
            Arvore *lista_variaveis = auxiliar -> filho;
            while(lista_variaveis != NULL){
                if(compareString(lista_variaveis -> string, "lista_variaveis") == 0){
                    Arvore *variaveis = lista_variaveis -> filho;
                    while(variaveis != NULL){
                        if(nomeVariavelRepetido(arvore, variaveis -> filho -> string) == false){
                            fprintf(logErro, "[\033[1m\033[31merro\033[0m] redefinição da variável global %s\n", variaveis -> filho -> string);    
                            redefinicaoVariavelGlobal = true;
                        }
                        variaveis = variaveis -> proximo;
                    }
                    break;
                }
                lista_variaveis = lista_variaveis -> proximo;
            }
        }
        auxiliar = auxiliar -> proximo;
    }
    if(redefinicaoVariavelGlobal)
        return false;
    return true;
}

//////////////
char *retornaTipoFuncao(Arvore *arvore, char *funcao){
    Arvore *auxiliar = arvore -> filho;
    //Percorro a lista de declarações
    while(auxiliar != NULL){
        //Verifico se existe alguma declaracao de variável global
        if(compareString(auxiliar -> string, "declaracao_funcao") == 0){
            Arvore *tipo_funcao = auxiliar -> filho;
            Arvore *declaracao_funcao = auxiliar -> filho;
            while(declaracao_funcao != NULL){
                //Verifico se tem lista de variáveis
                if(compareString(declaracao_funcao -> string, "cabecalho") == 0){
                    Arvore *cabecalho = declaracao_funcao -> filho;
                    if(compareString(cabecalho -> string, funcao) == 0){
                        if(compareString(tipo_funcao -> string, "cabecalho") == 0){
                            return "void";
                        } else {
                            return tipo_funcao -> string;
                        }
                    }
                }
                declaracao_funcao = declaracao_funcao -> proximo;
            }
        }
        auxiliar = auxiliar -> proximo;
    }
}

char *retornaTipoVariavel(Arvore *arvore, char *variavel){
    Arvore *auxiliar = arvore -> filho;
    //Percorro a lista de declarações
    while(auxiliar != NULL){
        //Verifico se existe alguma declaracao de variável global
        if(compareString(auxiliar -> string, "declaracao_variaveis") == 0){
            Arvore *tipo_variavel = auxiliar -> filho;
            Arvore *declaracao_variaveis = auxiliar -> filho;
            while(declaracao_variaveis != NULL){
                //Verifico se tem lista de variáveis
                if(compareString(declaracao_variaveis -> string, "lista_variaveis") == 0){
                    Arvore *lista_variaveis = declaracao_variaveis -> filho;
                    //Percorro por todos var, já que podemos ter mais de uma var
                    while(lista_variaveis != NULL){
                        //Verifico se a variável é igual
                        if(compareString(lista_variaveis -> filho -> string, variavel) == 0){
                            return tipo_variavel -> string;
                        }
                        lista_variaveis = lista_variaveis -> proximo;
                    }
                    break;
                }
                declaracao_variaveis = declaracao_variaveis -> proximo;
            }
        }
        auxiliar = auxiliar -> proximo;
    }
    return "NULL";
}

int compatibilidadeTipo(Arvore *arvore, char *variavelAtribuicao, char *tipoValor, char *valor){
    if(compareString(tipoValor, "INTEIRO") == 0){
        if(compareString(retornaTipoVariavel(arvore, variavelAtribuicao), "inteiro") == 0){
            return 0;
        } else {
            fprintf(logErro, "[\033[1m\033[31merro\033[0m] a atribuição da variável \033[1m\033[31m%s\033[0m espera um valor \033[1m\033[31m%s\033[0m, e o valor \033[1m\033[31m%s\033[0m que você está atribuindo é do tipo \033[1m\033[31minteiro\033[0m\n", variavelAtribuicao, retornaTipoVariavel(arvore, variavelAtribuicao), valor);    
            return 1;
        }
    } else if(compareString(tipoValor, "FLUTUANTE") == 0){
        if(compareString(retornaTipoVariavel(arvore, variavelAtribuicao), "flutuante") == 0){
            return 0;
        } else {
            fprintf(logErro, "[\033[1m\033[31merro\033[0m] a atribuição da variável \033[1m\033[31m%s\033[0m espera um valor \033[1m\033[31m%s\033[0m, e o valor \033[1m\033[31m%s\033[0m que você está atribuindo é do tipo \033[1m\033[31mflutuante\033[0m\n", variavelAtribuicao, retornaTipoVariavel(arvore, variavelAtribuicao), valor);    
            return 1;
        }
    } else if(compareString(tipoValor, "chamada_funcao") == 0){
        if(compareString(retornaTipoFuncao(arvore, valor), retornaTipoVariavel(arvore, variavelAtribuicao)) == 0){
            return 0;
        } else {
            if(compareString(retornaTipoFuncao(arvore, valor), "NULL") == 0){
                fprintf(logErro, "[\033[1m\033[31merro\033[0m] a atribuição da variável \033[1m\033[31m%s\033[0m espera um valor \033[1m\033[31m%s\033[0m, e o retorno da função \033[1m\033[31m%s\033[0m retorna \033[1m\033[31mnada\033[0m\n", variavelAtribuicao, retornaTipoVariavel(arvore, variavelAtribuicao), valor);    
            } else {
                fprintf(logErro, "[\033[1m\033[31merro\033[0m] a atribuição da variável \033[1m\033[31m%s\033[0m espera um valor \033[1m\033[31m%s\033[0m, e o retorno da função \033[1m\033[31m%s\033[0m retorna \033[1m\033[31m%s\033[0m\n", variavelAtribuicao, retornaTipoVariavel(arvore, variavelAtribuicao), valor, retornaTipoFuncao(arvore, valor));    
            }
            return 1;
        }
    } else if(compareString(tipoValor, "var")  == 0){
        if(compareString(retornaTipoVariavel(arvore, variavelAtribuicao), retornaTipoVariavel(arvore, valor)) == 0){
            return 0;
        } else {
            if(compareString(retornaTipoVariavel(arvore, valor), "NULL") == 0){
                fprintf(logErro, "[\033[1m\033[31merro\033[0m] a atribuição da variável \033[1m\033[31m%s\033[0m espera um valor \033[1m\033[31m%s\033[0m, e a variável \033[1m\033[31m%s\033[0m não foi declarada\n", variavelAtribuicao, retornaTipoVariavel(arvore, variavelAtribuicao), valor);    
            } else {
                fprintf(logErro, "[\033[1m\033[31merro\033[0m] a atribuição da variável \033[1m\033[31m%s\033[0m espera um valor \033[1m\033[31m%s\033[0m, e a variável \033[1m\033[31m%s\033[0m é do tipo \033[1m\033[31m%s\033[0m\n", variavelAtribuicao, retornaTipoVariavel(arvore, variavelAtribuicao), valor, retornaTipoVariavel(arvore, valor));                    
            }
            return 1;
        }
    }
}

bool verificaAtribuicoesCompatibilidadeTipo(Arvore *arvore){
    bool insereNovoFilho;
    int i = 0, j = 0, k = 0;
    int quantidadeErro = 0;
    Arvore *todosIrmaos[MAX], *auxiliar = arvore -> filho;
    //Percorro a lista de declarações
    while(auxiliar != NULL){
        //Verifico se existe alguma inicialização de variável fora de função
        if(compareString(auxiliar -> string, "inicializacao_variaveis") == 0){
            //Verifico se tem um filho chamado atribuição
            if(compareString(auxiliar -> filho -> string, "atribuicao") == 0){
                Arvore *atribuicao = auxiliar -> filho;
                //Pego o nome da variável
                if(compareString(atribuicao -> filho -> string, "var") == 0){
                    Arvore *expressao = atribuicao -> filho -> proximo;
                    while(expressao -> filho != NULL){
                        Arvore *filho = expressao -> filho -> proximo;
                        while(filho != NULL){
                            k = 0;
                            insereNovoFilho = true;
                            while(k < i){
                                if(todosIrmaos[k] == filho){
                                    insereNovoFilho = false;
                                    break;
                                }
                                k++;
                            }
                            if(insereNovoFilho){
                                todosIrmaos[i] = filho;    
                                i++;
                            }
                            filho = filho -> proximo;
                        }
                        expressao = expressao -> filho;
                        if(expressao -> filho -> filho == NULL){
                            quantidadeErro = quantidadeErro + compatibilidadeTipo(arvore, atribuicao -> filho -> filho -> string, expressao -> string, expressao -> filho -> string);
                            if(i == j){
                                break;
                            }
                            while(todosIrmaos[j] -> filho == NULL){
                                j++;
                            }
                            expressao = todosIrmaos[j];
                            j++;
                        }
                        
                    }
                }
            }
        }
        auxiliar = auxiliar -> proximo;
    }
    printf("quantidadeErro %d\n", quantidadeErro);
    if(quantidadeErro > 0)
        return false;
    return true;
}

//Verificar os erros
bool percorreArvore(Arvore *arvore){
    Arvore *lista_declaracoes = retornaNo(arvore, "lista_declaracoes");
    bool okAtribuicoesCompatibilidadeTipo;
    bool okAtribuicoesGlobal, okFuncaoPrincipal;
    bool okRedefinicaoFuncao, okRedefinicaoVariavelGlobal;
    //Verificamos se existe lista_declaracoes, caso não tenha existe algum erro
    if(lista_declaracoes != NULL){
        //Verificamos se existem atribuições globais e se elas tem a variável declarada
        okAtribuicoesGlobal = verificaAtribuicoesGlobal(lista_declaracoes);
        if(okAtribuicoesGlobal){
            //Existem erros de compatibilidade 
            okAtribuicoesCompatibilidadeTipo = verificaAtribuicoesCompatibilidadeTipo(lista_declaracoes);    
        }
        //Verificamos se existe a função principal
        okFuncaoPrincipal = verificaFuncaoPrincipal(lista_declaracoes);
        //Verificamos se existe alguma função redefinida
        okRedefinicaoFuncao = verificaRedefinicaoFuncao(lista_declaracoes);
        //Verificamos se existe alguma variável global definida
        okRedefinicaoVariavelGlobal = verificaRedefinicaoVariavelGlobal(lista_declaracoes);
        if(okAtribuicoesGlobal && okFuncaoPrincipal && okRedefinicaoFuncao && okRedefinicaoVariavelGlobal
            && okAtribuicoesCompatibilidadeTipo){
            printf("tudo certo com as definições fora de funções\n");
            /*
            Exemplo
            if(okFuncaoRetorno){
                return true;
            } else {
                return false;
            }
            e o return de baixo não necessário
            */
            return true;
        } else {
            //Caso exista algum erro no escopo global do arquivo
            printf("[\033[1m\033[31merro\033[0m] existem alguns erros foram de funções\n");
            return false;
        }
    } else {
        fprintf(logErro, "\033[1m\033[31merro na árvore\033[0m\n");
    }
    return true;
}
