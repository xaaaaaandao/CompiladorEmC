#include <stdio.h>
#include "msgerro.h"

void erroDeclaraVariavel(int tipoErro, int linha, char *tipo, Arvore *variaveis){
	Arvore *auxiliar;
	if(tipoErro == 1){
		auxiliar = variaveis -> filho;
    	printf("[\033[1m\033[31merro\033[0m] na linha %d\n", linha);
    	printf("[\033[1m\033[31merro\033[0m] falta ':' na declaração de variável\n");
    	printf("%s   ", tipo);
    	while(auxiliar != NULL){
    		if(compareString(auxiliar -> string, "var") == 0){
    			Arvore *variavel = auxiliar -> filho;
    			printf("%s", variavel -> string);
    			if(auxiliar -> proximo != NULL){
    				printf(", ");
    			}
    		}
    		auxiliar = auxiliar -> proximo;
    	}
    	printf("\n");
    	if(compareString(tipo, "inteiro") == 0){
    		printf("        ^\n");
    	} else if(compareString(tipo, "flutuante") == 0){
    		printf("          ^\n");
    	}
	} else if(tipoErro == 2){
    	printf("[\033[1m\033[31merro\033[0m] na linha %d\n", linha);
    	printf("[\033[1m\033[31merro\033[0m] falta declarar a variável\n");
    	printf("%s : \n", tipo);
    	if(compareString(tipo, "inteiro") == 0){
    		printf("          ^\n");
    	} else if(compareString(tipo, "flutuante") == 0){
    		printf("            ^\n");
    	}
	}
}