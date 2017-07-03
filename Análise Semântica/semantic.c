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

void erroFuncao(char *nomeFuncao){
	fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] erro aproximadamente na linha %d\n", erroLinha);
	fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] erro na função %s\n", nomeFuncao);
	char linha[MAX];
	FILE *auxiliar = fopen("auxiliar.txt", "r");
	while(fgets(linha, sizeof(linha), auxiliar) != NULL)
		fprintf(arquivoSemantico, "%s", linha);
	fclose(auxiliar);
}

void erroListaParametros(Arvore *lista_parametros){
	bool erroLista = false;
	Arvore *auxiliar = lista_parametros -> filho;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> string, "!@#") == 0){
			erroLista = true;
			break;
		}
		auxiliar = auxiliar -> proximo;
	}
	if(erroLista || erroIndiceParametro || erroDoisIndiceParametro || erroTipoIndiceParametro){
		if(erroLista){
			fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] falta \033[1m\033[31m,\033[0m\n");
		}
		if(erroDoisIndiceParametro){
			fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] falta \033[1m\033[31m:\033[0m\n");
		}
		if(erroIndiceParametro){
			fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] falta(m) índice(s) da(s) variável(is)\n");
		}
		if(erroTipoIndiceParametro){
			fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] falta declarar o tipo\n");
			fprintf(arquivoSemantico, "  ");
		}
		auxiliar = lista_parametros -> filho;
		while(auxiliar != NULL){
			if(compareString(auxiliar -> string, "!@#") == 0){
				fprintf(arquivoSemantico, "\033[1m\033[31m,\033[0m ");
			} else if(compareString(auxiliar -> string, "parametro") == 0){
				Arvore *auxiliarFilho = auxiliar -> filho;
				while(auxiliarFilho != NULL){
					if(compareString(auxiliarFilho -> string, "[") == 0){
						fprintf(arquivoSemantico, "%s", auxiliarFilho -> string);	
					} else if(compareString(auxiliarFilho -> string, "\033[1m\033[31m[\033[0m") == 0){
						fprintf(arquivoSemantico, "%s", auxiliarFilho -> string);	
					} else if(compareString(auxiliarFilho -> string, "\033[1m\033[31m]\033[0m") == 0){
						fprintf(arquivoSemantico, "%s", auxiliarFilho -> string);	
					} else if(compareString(auxiliarFilho -> string, "]") == 0){
						fprintf(arquivoSemantico, "%s", auxiliarFilho -> string);	
					} else {
						fprintf(arquivoSemantico, "%s ", auxiliarFilho -> string);	
					}
					auxiliarFilho = auxiliarFilho -> proximo;
				}
			} else if(compareString(auxiliar -> string, ",") == 0){
				fprintf(arquivoSemantico, ", ");				
			}
			auxiliar = auxiliar -> proximo;
		}
		if(erroTipoIndiceParametro){
			fprintf(arquivoSemantico, "\n\033[1m\033[31m↑\033[0m\n");
		} else {
			fprintf(arquivoSemantico, "\n");				
		}	
	}
}

void erroCorpoFuncao(Arvore *corpo){
	Arvore *auxiliar = corpo -> filho;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> string, "acao") == 0){
			Arvore *acao = auxiliar -> filho;
			while(acao != NULL){
				if(((compareString(acao -> string, "LEIA") == 0)  && (erroLeia))
					|| ((compareString(acao -> string, "ESCREVA") == 0) && (erroEscreva))
					|| ((compareString(acao -> string, "RETORNA") == 0) && (erroRetorna))){
					fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] falta \033[1m\033[31m)\033[0m\n");
					fprintf(arquivoSemantico, "%s", acao -> string);
					Arvore *acaoFilho = acao -> filho;
					while(acaoFilho != NULL){
						if(compareString(acaoFilho -> string, "expressao") == 0){
							procuraFilho(acaoFilho);
							fprintf(arquivoSemantico, "%s", folha);
							memset(folha, 0, sizeof(folha));
						} else {
							fprintf(arquivoSemantico, "%s", acaoFilho -> string);
						}
						acaoFilho = acaoFilho -> proximo;
					}
					fprintf(arquivoSemantico, "\n");
				}
				acao = acao -> proximo;
			}
		}
		auxiliar = auxiliar -> proximo;
	}
}

void imprimeErro(){
	if(erroSemantico == true){
		system("clear");
		system("cat semantico.txt");
	}
	system("rm semantico.txt");
	system("rm auxiliar.txt");
} 