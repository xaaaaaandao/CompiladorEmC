#include <stdio.h>
#include "msgerro.h"
#include "syntaxtree.h"

void imprimeErro(){
    char linha[32768];
    logErro = fopen("logErro.txt", "r");
    while(fgets(linha, sizeof(linha), logErro) != NULL)
        printf("%s", linha);
    fclose(logErro);
}

void erroDeclaraVariavel(int tipoErro, int linha, char *tipo, Arvore *variaveis){
	Arvore *auxiliar;
    fprintf(logErro, "[\033[1m\033[31merro\033[0m] aproximadamente na linha %d\n", linha);
	if(tipoErro == 1){
		auxiliar = variaveis -> filho;
    	fprintf(logErro, "[\033[1m\033[31merro\033[0m] falta ':' na declaração de variável\n");
    	fprintf(logErro, "%s   ", tipo);
    	while(auxiliar != NULL){
    		if(compareString(auxiliar -> string, "var") == 0){
    			Arvore *variavel = auxiliar -> filho;
    			fprintf(logErro, "%s", variavel -> string);
    			if(auxiliar -> proximo != NULL){
    				fprintf(logErro, ", ");
    			}
    		}
    		auxiliar = auxiliar -> proximo;
    	}
    	fprintf(logErro, "\n");
    	if(compareString(tipo, "inteiro") == 0){
    		fprintf(logErro, "        ^\n");
    	} else if(compareString(tipo, "flutuante") == 0){
    		fprintf(logErro, "          ^\n");
    	}
	} else if(tipoErro == 2){
    	fprintf(logErro, "[\033[1m\033[31merro\033[0m] falta declarar a variável\n");
    	fprintf(logErro, "%s : \n", tipo);
    	if(compareString(tipo, "inteiro") == 0){
    		fprintf(logErro, "          ^\n");
    	} else if(compareString(tipo, "flutuante") == 0){
    		fprintf(logErro, "            ^\n");
    	}
	} else if(tipoErro == 3){
        fprintf(logErro, "[\033[1m\033[31merro\033[0m] falta declarar o tipo\n");
        fprintf(logErro, "  : ");
        auxiliar = variaveis -> filho;
        while(auxiliar != NULL){
            if(compareString(auxiliar -> string, "var") == 0){
                Arvore *variavel = auxiliar -> filho;
                fprintf(logErro, "%s", variavel -> string);
                if(auxiliar -> proximo != NULL){
                    fprintf(logErro, ", ");
                }
            }
            auxiliar = auxiliar -> proximo;
        }
        fprintf(logErro, "\n");
        fprintf(logErro, "^\n");
    } else if(tipoErro == 4){
        
    }
}

void erroIndice(char *variavel, int linha){
    fprintf(logErro, "[\033[1m\033[31merro\033[0m] aproximadamente na linha %d\n", linha);
    if(tipoErroIndice ==  1){
        fprintf(logErro, "[\033[1m\033[31merro\033[0m] a variável \033[1m\033[31m%s\033[0m só pode ter ser um \033[1m\033[32mvetor\033[0m ou uma \033[1m\033[32mmatriz\033[0m\n", variavel);   
    }
}