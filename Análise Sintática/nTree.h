#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>

/* Definindo valor MAX */
#define MAX 3276

/* Definindo estrutura árvore */
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

/**
* Esta função compareString compara duas strings, e verifica
* se as duas strings elas são iguais ou não, caso for retorna zero
* ou caso contrário um valor de diferente de zero;
@param stringA, sequência de caracteres a ser comparada;
@param stringB, sequência de caracteres a ser comparada;
@return resultado, retorna zero se for igual ou qualquer valor diferente de zero é diferente.
*/
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


/**
* Esta função adicionaIrmao recebe dois nós, 
* em que os dois nós irão virar irmãos;
@param no, nó da Árvore que será adicionado o seu irmão;
@param novoIrmao, nó da Árvore que será adicionado o seu irmão;
@return no, retorna nó com o seu irmão adicionado.
*/
Arvore* adicionaIrmao(Arvore *no, Arvore *novoIrmao){
    if (no == NULL)
        return NULL;

    while (no -> proximo)
        no = no -> proximo;

    return (no -> proximo = novoIrmao);
}

/**
* Esta função adicionaFilho recebe dois nós, 
* em que os dois nós irão virar irmãos;
@param no, nó da Árvore que será adicionado o seu irmão;
@param novoIrmao, nó da Árvore que será adicionado o seu irmão;
@return no, retorna nó com o seu irmão adicionado.
*/
Arvore *adicionaFilho(Arvore *no, Arvore *novoIrmao){
    if (no == NULL)
        return NULL;

    if (no -> filho)
        return adicionaIrmao(no -> filho, novoIrmao);
    else
        return (no -> filho = novoIrmao);
}

/**
* Esta função imprime recebe um nó da Árvore, 
* em que iremos imprimir o pai e os filhos, respectivamente;
@param no, nó da Árvore que será adicionado impresso;
@return void, ou seja, retorna nada.
*/
void imprimeArvore(Arvore *no){
    static unsigned long int i = 1;
    if(no -> filho == NULL){
	printf("\033[1m\033[32m%s\033[0m\n\n", no -> string);	
        return;
    } else {
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

/**
* Esta função criaNo em que iremos receber o valor,
* e o número de filhos, em que podemos adicionar quantos filhos quisermos;
@param string, sequência de caractere que será adicionado o nó;
@param numArg, seria um inteiro com o número de argumentos;
@param ..., seria nó da árvore que seria adicionado irmãos;
@return no, retorna nó com o seu irmão adicionado.
*/
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

/**
* Esta função pertenceArvore em que iremos receber o nó da Árvore,
* para onde iremos começar a buscar e valor que será procurado;
@param no, seria o nó da Árvore onde começara a busca;
@param string, sequência de caractere que será procurado a existência do nó;
@return bool, retorna true caso exista ou false caso não exista.
*/
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

/**
* Esta função verificarLog que não recebe nenhum parâmetro
* em que verifica o tamanho do arquivo log se for zero 
* ou seja, não contém nada escrito então apaga o log
* caso exista alguma coisa se tiver avisa;
@param nenhum, não recebe nenhum parâmetro;
@return void, ou seja, retorna nada.
*/
void verificarLog(){
    struct stat st;
    if (stat("log.txt", &st) == 0) {
        system("rm log.txt");
    } else {
        printf("\033[1m\033[31mGEROU LOG!\n");    
    }
}

/**
* Esta função nomeRotulo que recebe um valor
* e converte esse valor em forma de sequência de caractere;
@param valor, é um inteiro longo sem sinal que será convertido;
@return rotulo, valor do inteiro longo sem sinal convertido para string.
*/
char *nomeRotulo(unsigned long int valor){
    char *rotulo = (char*) calloc (MAX, sizeof(char));
    if(valor == 4294967295){
        printf("\033[1m\033[31mnão foi possível gerar .dot!\n");            
        exit(1);
    }
    sprintf(rotulo, "%lu", valor);
    return rotulo;
}

/**
* Esta função arvoreDot que seria o arquivo .dot que é necessário
* para conseguirmos visualizar de maneira mais clara, a árvore sintática;
@param dot, é do tipo FILE que irá conter o conteúdo do formato .dot;
@param no, é do tipo Árvore em que irá percorrer a árvore colocando o conteúdo no .dot;
@return void, ou seja, retorna nada.
*/
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

/**
* Esta função gerandoDot que irá gerar o arquivo
* .dot para gerarmos uma a imagem dá árvore.
@param a, é do tipo Árvore em que irá percorrer a árvore colocando o conteúdo no .dot;
@return void, ou seja, retorna nada.
*/
void gerandoDot(Arvore *a){
    FILE *dot = fopen("syntax-tree.dot", "w");
    fprintf(dot, "digraph tree {\n");
    arvoreDot(dot, a);
    fprintf(dot, "}");
    fclose(dot);
    system("dot -Tpng -O syntax-tree.dot && shotwell syntax-tree.dot.png &");
}

int linhadoArquivo(){
    FILE *entrada = fopen("linha.txt", "r");
    char linha[MAX];
    while((fgets(linha, sizeof(linha), entrada)) != NULL)
    fclose(entrada);
    return atoi(linha);
}