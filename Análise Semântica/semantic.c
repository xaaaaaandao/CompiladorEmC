#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"

void transfereLinha(int l){
	erroLinha = l;
}

void erroDeclaraVariavel(Arvore *tipo, Arvore *lista_variaveis, int qualErro){
	fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] erro aproximadamente na linha %d\n", erroLinha);
	if (qualErro == 1){
		fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] falta \033[1m\033[31m:\033[0m\n");
		fprintf(arquivoSemantico, "%s  ", tipo -> string);	
	} else if(qualErro == 2){
		fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] falta declarar o tipo da(s) variável(is)\n");
		fprintf(arquivoSemantico, "   : ");	
	}
	Arvore *auxiliar = lista_variaveis -> filho;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> string, ",") == 0){
			fprintf(arquivoSemantico, ", ");
		} else if (compareString(auxiliar -> string, "var") == 0){
			Arvore *auxiliarFilho = auxiliar -> filho;
			fprintf(arquivoSemantico, "%s", auxiliarFilho -> string);
			if(auxiliarFilho -> proximo != NULL){
				Arvore *indice = auxiliarFilho -> proximo -> filho;
				while(indice != NULL){
					if(compareString(indice -> string, "expressao") == 0){
						memset(folha, 0, sizeof(folha));
						procuraFilho(indice);
						fprintf(arquivoSemantico, "%s", folha);
					} else {
						fprintf(arquivoSemantico, "%s", indice -> string);
					}
					indice = indice -> proximo;
				}
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	if(qualErro == 1){
		if(compareString(tipo -> string, "inteiro") == 0){
			fprintf(arquivoSemantico, "\n       \033[1m\033[31m↑\033[0m\n");	
		} else if(compareString(tipo -> string, "flutuante") == 0){
			fprintf(arquivoSemantico, "\n         \033[1m\033[31m↑\033[0m\n");	
		}
	} else if(qualErro == 2){
		fprintf(arquivoSemantico, "\n\033[1m\033[31m↑\033[0m\n");	
	}
}

void imprimeErro(){
	if(erroSemantico == true)
		system("cat semantico.txt");
	system("rm semantico.txt");
} 