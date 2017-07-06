#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <llvm-c/Core.h>
#include <llvm-c/BitWriter.h>
#include "semantic.h"
#include "lista.h"
#include "generate.h"

void transfereLinha(int l){
	erroLinha = l;
}

void erroDeclaraVariavel(Arvore *tipo, Arvore *lista_variaveis, int qualErro){
	if(erroLinha == 0)
		erroLinha++;
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
	if(erroLinha == 0)
		erroLinha++;
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

bool indiceEhInteiro(Arvore *arvore){
	int i = 0;
	procuraFilho(arvore);
	while(folha[i] != '\0'){
		if(folha[i] == '.'){
			memset(folha, 0, sizeof(0));
			if(erroLinha == 0)
				erroLinha++;
			fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] erro aproximadamente na linha %d\n", erroLinha);
			fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] o valor presente no índice não é inteiro\n");
			return false;
		}
		i++;
	}
	memset(folha, 0, sizeof(0));
	return true;
}

/* Coloca as váriaveis em uma lista */
void preencheVariaveis(Arvore *arvore, ListaVariaveis *lista, bool ehGlobal){
	char valor1[MAX], valor2[MAX];
	Arvore *auxiliar = arvore -> filho -> filho;
	if(ehGlobal){
		auxiliar = arvore -> filho -> filho;
	} else {
		auxiliar = arvore -> filho;		
	}
	while(auxiliar != NULL){
		if(compareString(auxiliar -> string, "declaracao_variaveis") == 0){
			Arvore *tipo = auxiliar -> filho;
			Arvore *lista_variaveis = auxiliar -> filho -> proximo;
			//printf("tipo %s\n", tipo -> string);
			//printf("lista_variaveis %s\n", lista_variaveis -> string);
			Arvore *variaveis = lista_variaveis -> filho;
			while(variaveis != NULL){
				if(compareString(variaveis -> string, "var") == 0){
					Arvore *nomeVariavel = variaveis -> filho;
					Arvore *indice = variaveis -> filho -> proximo;
					//printf("var: %s\n", nomeVariavel -> string);
					if(indice != NULL){
						strcpy(valor1, "NULL");
						strcpy(valor2, "NULL");
						Arvore *valoresIndice = indice ->  filho;
						while(valoresIndice != NULL){
							//printf(":%s\n", valoresIndice -> string);
							if(compareString(valoresIndice -> string, "expressao") == 0){
								memset(folha, 0, sizeof(folha));
								procuraFilho(valoresIndice);
								if(compareString(valor1, "NULL") != 0){
									strcpy(valor2, folha);	
								} else {
									strcpy(valor1, folha);
								}
							}
							//printf("indi: %s\n", valoresIndice -> string);	
							valoresIndice = valoresIndice -> proximo;
						}
						if(compareString(valor2, "NULL") == 0){
							insereListaVariaveis(lista, tipo -> string, nomeVariavel -> string, true, false, valor1, "NULL", ehGlobal, false);
						} else {
							insereListaVariaveis(lista, tipo -> string, nomeVariavel -> string, false, true, valor1, valor2, ehGlobal, false);
						}
					} else {
						insereListaVariaveis(lista, tipo -> string, nomeVariavel -> string, false, false, "NULL", "NULL", ehGlobal, false);
					}
				}
				variaveis = variaveis -> proximo;
			}
		}
		auxiliar = auxiliar -> proximo;
	}
}

/* Verifica sem tem redefiniçaõ de variável */
void redefinicaoVariavel(char *nome, ListaVariaveis *variaveis, bool ehGlobal){
	int repetidos = 0;
	NoVariaveis *auxiliar = variaveis -> primeiro;
	NoVariaveis *auxiliarRepetido;
	while(auxiliar != NULL){
		auxiliarRepetido = variaveis -> primeiro;
		while(auxiliarRepetido != NULL){
			if(compareString(auxiliarRepetido -> nome, auxiliar -> nome) == 0){
				repetidos++;
			}
			auxiliarRepetido = auxiliarRepetido -> proximo;
		}
		if(repetidos > 1){
			erroVisita = true;
			if(ehGlobal){
				printf("\033[0m[\033[1m\033[35maviso\033[0m] erro no escopo global\n");
				printf("\033[0m[\033[1m\033[35maviso\033[0m] a variável \033[1m\033[31m%s\033[0m foi redeclarada\n", auxiliar -> nome);
			} else {
				printf("\033[0m[\033[1m\033[35maviso\033[0m] na função \033[1m\033[31m%s\033[0m", nome);
				printf(" a variável \033[1m\033[31m%s\033[0m é local e já foi declarado\n", auxiliar -> nome);													
			}
		}
		repetidos = 0;
		auxiliar = auxiliar -> proximo;
	}
}

/* Verifica se os índices são válidos */
char *retornaTipoVariavel(ListaVariaveis *variaveis, char *variavel){
	NoVariaveis *auxiliar = variaveis -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, variavel) == 0){
			return auxiliar -> tipo;
		}
		auxiliar = auxiliar -> proximo;
	}
	return "NULL";
}

bool verificaTipoIndice(ListaVariaveis *variaveis, char *valor){
	int i = 0;
	int quantidadeLetras = 0, quantidadeNumeros = 0;
	while(valor[i] != '\0'){
		if((valor[i] >= 'a' && valor[i] <= 'z') || (valor[i] >= 'A' && valor[i] <= 'Z')){
			quantidadeLetras++;
		} else if(valor[i] >= '0' && valor[i] <= '9'){
			quantidadeNumeros++;
		} 
		i++;
	}
	//é inteiro o índice
	if(quantidadeNumeros == strlen(valor)){
		return true;
	} else if(quantidadeLetras == strlen(valor)){
		if(compareString("flutuante", retornaTipoVariavel(variaveis, valor)) == 0){
			return false;
		} else if(compareString("inteiro", retornaTipoVariavel(variaveis, valor)) == 0){
			return true;	
		}
	}
	return false;
}


bool tipoIndice(char *tipo, char *valor, ListaVariaveis *lista_variaveis){
	bool tipoCerto = false;
	char auxiliar[MAX];
	int i = 0, j = 0;
	while(valor[i] != '\0'){
		if(valor[i] == '+' || valor[i] == '-' || valor[i] == '*' || valor[i] == '/'){
			auxiliar[j] = '\0';
			if(verificaTipoIndice(lista_variaveis, auxiliar)){
				tipoCerto = true;
			} else {
				return false;
			}
			j = 0;
			memset(auxiliar, 0, sizeof(auxiliar));
		} else {
			auxiliar[j] = valor[i];
			j++;
		}
		i++;
		if(valor[i] == '\0'){
			auxiliar[j] = '\0';
			if(verificaTipoIndice(lista_variaveis, auxiliar)){
				tipoCerto = true;
			} else {
				return false;
			}
		}
	}
	return tipoCerto;
}

void indiceValido(ListaVariaveis *variaveis, bool ehGlobal){
	NoVariaveis *auxiliar = variaveis -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> ehUnidimensional){
			if(tipoIndice(auxiliar -> tipo, auxiliar -> valor1, variaveis) == false){
				erroVisita = true;
				if(ehGlobal){
					printf("\033[0m[\033[1m\033[35maviso\033[0m] erro no escopo global\n");					
				}
				printf("\033[0m[\033[1m\033[35maviso\033[0m] a variável \033[1m\033[31m%s\033[0m tem seu índice \033[1m\033[31m%s\033[0m inválido\n", auxiliar -> nome, auxiliar -> valor1);
			} else {
				auxiliar -> indiceValido = true;
			}
		} else if(auxiliar -> ehBidimensional){
			bool indiceUm = false, indiceDois = false;
			if(tipoIndice(auxiliar -> tipo, auxiliar -> valor1, variaveis) == false){
				erroVisita = true;
				if(ehGlobal){
					printf("\033[0m[\033[1m\033[35maviso\033[0m] erro no escopo global\n");					
				}
				printf("\033[0m[\033[1m\033[35maviso\033[0m] a variável \033[1m\033[31m%s\033[0m tem seu primeiro índice \033[1m\033[31m%s\033[0m inválido\n", auxiliar -> nome, auxiliar -> valor1);
				indiceUm = true;
			}
			if(tipoIndice(auxiliar -> tipo, auxiliar -> valor2, variaveis) == false){
				erroVisita = true;
				if(ehGlobal){
					printf("\033[0m[\033[1m\033[35maviso\033[0m] erro no escopo global\n");					
				}
				printf("\033[0m[\033[1m\033[35maviso\033[0m] a variável \033[1m\033[31m%s\033[0m tem seu segundo índice \033[1m\033[31m%s\033[0m inválido\n", auxiliar -> nome, auxiliar -> valor2);
				indiceDois = true;
			}
			if(indiceUm && indiceDois){
				auxiliar -> indiceValido = true;
			}
		}
		auxiliar = auxiliar -> proximo;
	}
}

int quantidadeFilho(Arvore *arvore){
	Arvore *auxiliar = arvore -> filho;
	int contador = 0;
	while(auxiliar != NULL){
		contador++;
		auxiliar = auxiliar -> proximo;
	}
	return contador;
}

/* Preenche inicializações */
void preencheInicializacao(Arvore *arvore, ListaInicializacao *lista_inicializacao){
	bool origemUnidimensional, origemBidimensional;
	bool destinoUnidimensional, destinoBidimensional;
	char origemValor1[MAX], origemValor2[MAX];
	char destinoValor1[MAX], destinoValor2[MAX];
	char nomeOrigem[MAX], nomeDestino[MAX];
	Arvore *auxiliar = arvore -> filho -> filho;
	while(auxiliar != NULL){
		strcpy(origemValor1, "NULL");
		strcpy(origemValor2, "NULL");
		strcpy(destinoValor1, "NULL");
		strcpy(destinoValor2, "NULL");
		if(compareString(auxiliar -> string, "inicializacao_variaveis") == 0){
			Arvore *atribuicao = auxiliar -> filho;
			if(compareString(atribuicao -> string, "atribuicao") == 0){
				Arvore *var = atribuicao -> filho;
				if(compareString("var", var -> string) == 0){
					Arvore *nomeVariavel = var -> filho;
					strcpy(nomeOrigem, nomeVariavel -> string);
					if(nomeVariavel -> proximo != NULL){
						Arvore *indice = nomeVariavel -> proximo;
						if(compareString("indice", indice -> string) == 0){
							Arvore *valoresIndice = indice -> filho;
							strcpy(origemValor1, "NULL");
							strcpy(origemValor2, "NULL");
							while(valoresIndice != NULL){
								if(compareString(valoresIndice -> string, "expressao") == 0){
									if(compareString(origemValor1, "NULL") == 0){
										memset(folha, 0, sizeof(folha));
										procuraFilho(valoresIndice);
										strcpy(origemValor1, folha);
									} else {
										memset(folha, 0, sizeof(folha));
										procuraFilho(valoresIndice);
										strcpy(origemValor2, folha);										
									}
								}
								valoresIndice = valoresIndice -> proximo;
							}
						}
					}
				}
				Arvore *expressao = atribuicao -> filho -> proximo;
				if(compareString("expressao", expressao -> string) == 0){
					Arvore *var = NULL, *numero = NULL;
					Arvore *filhoExpressao = expressao;
					while(filhoExpressao != NULL){
						if(compareString(filhoExpressao -> string, "var") == 0){
							var = filhoExpressao;
							break;
						} else if(quantidadeFilho(filhoExpressao) > 1){
							memset(folha, 0, sizeof(folha));
							procuraFilho(filhoExpressao);
							break;
						} else if(compareString(filhoExpressao -> string, "numero") == 0){
							numero = filhoExpressao;
							break;
						}
						filhoExpressao = filhoExpressao -> filho;
					}
					if(var == NULL && numero == NULL){
						strcpy(nomeDestino, folha);
						//printf("numero %s\n", numero -> filho -> string);
					} else	if(var == NULL && numero != NULL){
						strcpy(nomeDestino, numero -> filho -> string);
						//printf("numero %s\n", numero -> filho -> string);
					} else if(var != NULL && numero == NULL){
						//printf("var %s\n", var -> filho);
						strcpy(nomeDestino, var -> filho -> string);
						if(var -> filho -> proximo != NULL){
							strcpy(destinoValor1, "NULL");
							strcpy(destinoValor2, "NULL");
							Arvore *indice = var -> filho -> proximo;
							if(compareString(indice -> string, "indice") == 0){
								Arvore *valoresIndice = indice -> filho;
								while(valoresIndice != NULL){
									if(compareString(valoresIndice -> string, "expressao") == 0){
										if(compareString(destinoValor1, "NULL") == 0){
											memset(folha, 0, sizeof(folha));
											procuraFilho(valoresIndice);
											strcpy(destinoValor1, folha);
										} else {
											memset(folha, 0, sizeof(folha));
											procuraFilho(valoresIndice);
											strcpy(destinoValor2, folha);										
										}
									}
									valoresIndice = valoresIndice -> proximo;
								}	
							}
						}
					}
				}
				if((compareString(origemValor1, "NULL") == 0) && (compareString(origemValor2, "NULL") == 0)){
					origemUnidimensional = origemBidimensional = false;
				} else if((compareString(origemValor1, "NULL") != 0) && (compareString(origemValor2, "NULL") != 0)){
					origemUnidimensional = false;
					origemBidimensional = true;
				//Se o primeiro for diferente de null
				} else if((compareString(origemValor1, "NULL") != 0) && (compareString(origemValor2, "NULL") == 0)){
					origemUnidimensional = true;
					origemBidimensional = false;
				}
				if((compareString(destinoValor1, "NULL") == 0) && (compareString(destinoValor2, "NULL") == 0)){
					destinoUnidimensional = destinoBidimensional = false;
				} else if((compareString(destinoValor1, "NULL") != 0) && (compareString(destinoValor2, "NULL") != 0)){
					destinoUnidimensional = false;
					destinoBidimensional = true;
				//Se o primeiro for diferente de null
				} else if((compareString(destinoValor1, "NULL") != 0) && (compareString(destinoValor2, "NULL") == 0)){
					destinoUnidimensional = true;
					destinoBidimensional = false;
				}
				insereListaInicializacao(lista_inicializacao, nomeOrigem, origemUnidimensional, origemBidimensional, origemValor1, origemValor2, nomeDestino, destinoUnidimensional, destinoBidimensional, destinoValor1, destinoValor2);
			}
		}
		auxiliar = auxiliar -> proximo;
	}
}

char *existeVariavel(ListaVariaveis *variaveis, char *nome, bool ehUnidimensional, bool ehBidimensional){
	NoVariaveis *auxiliar = variaveis -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, nome) == 0){
			if(auxiliar -> ehUnidimensional == ehUnidimensional){
				if(auxiliar -> ehBidimensional == ehBidimensional){
					return auxiliar -> tipo;
				}
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	int i = 0, quantidadeNumeros = 0;
	int virgula;
	while(nome[i] != '\0'){
		if(nome[i] == '.'){
			virgula = 1;
		} else if(nome[i] >= '0' && nome[i] <= '9'){
			quantidadeNumeros++;
		}
		i++;
	}
	if(quantidadeNumeros == strlen(nome)){
		return "inteiro";
	} else if(quantidadeNumeros + virgula == strlen(nome)){
		return "flutuante";
	}
	return "NULL";
}


bool percorreValor(char *tipo, ListaVariaveis *variaveis, char *nome, bool ehUnidimensional, bool ehBidimensional){
	bool tipoCerto = false;
	char auxiliar[MAX];
	int i = 0, j = 0;
	while(nome[i] != '\0'){
		if(nome[i] == '+' || nome[i] == '-' || nome[i] == '*' || nome[i] == '/'){
			auxiliar[j] = '\0';
			if(compareString(tipo, existeVariavel(variaveis, auxiliar, ehUnidimensional, ehBidimensional)) == 0){
				tipoCerto = true;
			} else {
				return false;
			}
			memset(auxiliar, 0, sizeof(auxiliar));
			j = 0;
		} else {
			auxiliar[j] = nome[i];
			j++;
		}
		i++;
		if(nome[i] == '\0'){
			auxiliar[j] = '\0';
			if(compareString(tipo, "NULL") == 0 && compareString("NULL", existeVariavel(variaveis, auxiliar, ehUnidimensional, ehBidimensional)) == 0){
				return false;
			}
			if(compareString(tipo, existeVariavel(variaveis, auxiliar, ehUnidimensional, ehBidimensional)) == 0){
				tipoCerto = true;
			} else {
				return false;
			}
		}
	}
	return tipoCerto;
}


void printAtribuicao(NoInicializacao *auxiliar){
	printf("\033[0m[\033[1m\033[35maviso\033[0m] erro na atribuição %s", auxiliar -> origem);									
	if(auxiliar -> origemUnidimensional){
		printf("[%s]", auxiliar -> origemValor1);
	} else if(auxiliar -> origemBidimensional){
		printf("[%s][%s]", auxiliar -> origemValor1, auxiliar -> origemValor2);
	}
	printf(" := %s", auxiliar -> destino);
	if(auxiliar -> destinoUnidimensional){
		printf("[%s]", auxiliar -> destinoValor1);
	} else if(auxiliar -> destinoBidimensional){
		printf("[%s][%s]", auxiliar -> destinoValor1, auxiliar -> destinoValor2);
	}
}

void inicializacaoValida(ListaVariaveis *variaveis, ListaInicializacao *inicializacao, bool ehGlobal){
	char tipo[MAX];
	NoInicializacao *auxiliar = inicializacao -> primeiro;
	while(auxiliar != NULL){
		strcpy(tipo, "NULL");
		strcpy(tipo, retornaTipoVariavel(variaveis, auxiliar -> origem));
		if(compareString(tipo, "NULL") == 0){
			printf("\033[0m[\033[1m\033[35maviso\033[0m] no escopo global\n");
			printAtribuicao(auxiliar);
			printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);
		} else {
			bool origemCorreta = true;
			bool origem11, origem12, bi, uni;
			bi = uni =	origem11 = 	origem12 = false;
			if(auxiliar -> origemUnidimensional){
				origemCorreta = false;
				origem11 = percorreValor(tipo, variaveis, auxiliar -> origemValor1, varUnidimensional(variaveis, auxiliar -> origemValor1), varBidimensional(variaveis, auxiliar -> origemValor1));
				if(origem11){
					uni = true;
					origemCorreta = true;
				}
			} else if(auxiliar -> origemBidimensional){
				origemCorreta = false;
				origem11 = percorreValor(tipo, variaveis, auxiliar -> origemValor1, varUnidimensional(variaveis, auxiliar -> origemValor1), varBidimensional(variaveis, auxiliar -> origemValor1));
				origem12 = percorreValor(tipo, variaveis, auxiliar -> origemValor2, varUnidimensional(variaveis, auxiliar -> origemValor2), varBidimensional(variaveis, auxiliar -> origemValor2));
				if(origem11 || origem12){
					bi = true;
					origemCorreta = true;
				}
			}
			if(origemCorreta){
				if(confirmacaoTipo(variaveis, variaveis, variaveis, auxiliar -> origem, uni, bi)){
					int i = 0, j = 0;
					char stringAux[MAX];
					int quantidadeVirgula, quantidadeNumeros;
					quantidadeVirgula = quantidadeNumeros = 0;
					while(auxiliar -> destino[i] != '\0'){
						if(auxiliar -> destino[i] == '.'){
							stringAux[j] = auxiliar -> destino[i];
							j++;
							quantidadeVirgula++;
						} else if(auxiliar -> destino[i] >= '0' && auxiliar -> destino[i] <= '9'){
							quantidadeNumeros++;
						} else if(auxiliar -> destino[i] == '+' || auxiliar -> destino[i] == '*' || auxiliar -> destino[i] == '-' || auxiliar -> destino[i] == '/'){
							stringAux[j] = '\0';
							if(compareString("NULL", existeVariavel(variaveis, stringAux, varUnidimensional(variaveis, stringAux), varBidimensional(variaveis, stringAux))) != 0){
								erroVisita = true;
								printf("\033[0m[\033[1m\033[35maviso\033[0m] no escopo global\n");
								printAtribuicao(auxiliar);
								printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", stringAux);
								return;
							}
							j = 0;
							memset(stringAux, 0, sizeof(stringAux));
						}
						i++;
					}
					if(quantidadeNumeros == strlen(auxiliar -> destino)){
						if(compareString(tipo, "inteiro") != 0){
							erroVisita = true;
							printf("\033[0m[\033[1m\033[35maviso\033[0m] no escopo global\n");
							printAtribuicao(auxiliar);
							printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);
						}
					} else if(quantidadeNumeros + quantidadeVirgula == strlen(auxiliar -> destino)){
						if(compareString(tipo, "flutuante") != 0){
							erroVisita = true;
							printf("\033[0m[\033[1m\033[35maviso\033[0m] no escopo global\n");
							printAtribuicao(auxiliar);
							printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);								
						}
					} else if(compareString(tipo, retornaTipoVariavel(variaveis, auxiliar -> destino)) != 0) {
						erroVisita = true;
						printf("\033[0m[\033[1m\033[35maviso\033[0m] no escopo global\n");
						printAtribuicao(auxiliar);
						printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);
					}
					if(auxiliar -> destinoUnidimensional){
						//bool varUnidimensional(ListaVariaveis *var, char *nome){
						strcpy(tipo, "inteiro");
						if(percorreValor(tipo, variaveis, auxiliar -> destinoValor1, varUnidimensional(variaveis, auxiliar->destinoValor1), varBidimensional(variaveis, auxiliar->destinoValor1)) != true ) {
							erroVisita = true;
							printf("\033[0m[\033[1m\033[35maviso\033[0m] no escopo global\n");
							printAtribuicao(auxiliar);
							printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);
						}
					} else	if(auxiliar -> destinoBidimensional){
						strcpy(tipo, "inteiro");
						if(percorreValor(tipo, variaveis, auxiliar -> destinoValor1, varUnidimensional(variaveis, auxiliar->destinoValor1), varBidimensional(variaveis, auxiliar->destinoValor1)) != true ||
							percorreValor(tipo, variaveis, auxiliar -> destinoValor2, varUnidimensional(variaveis, auxiliar->destinoValor2), varBidimensional(variaveis, auxiliar->destinoValor2))  != true ){
							erroVisita = true;
							printf("\033[0m[\033[1m\033[35maviso\033[0m] no escopo global\n");
							printAtribuicao(auxiliar);
							printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);
						}
					}
				} else {
					erroVisita = true;
					printf("\033[0m[\033[1m\033[35maviso\033[0m] a variável \033[1m\033[31m%s\033[0m tem um valor incompatível\n", auxiliar -> origem);
				}
			} else {
				//printf("::%s\n", auxiliar -> destino);
				if(retornaCompativel(tipo, auxiliar -> destino, variaveis, variaveis, variaveis) == false){
					erroVisita = true;
					printf("\033[0m[\033[1m\033[35maviso\033[0m] a variável \033[1m\033[31m%s\033[0m tem um valor incompatível\n", auxiliar -> origem);											
				}
			}
		}
		auxiliar = auxiliar -> proximo;
	}
}

bool existeAtribuicao(ListaInicializacao *inicializacao, char *nome, bool ehUnidimensional, bool ehBidimensional){
	bool origem = false, destino = false;
	int i = 0;
	NoInicializacao *auxiliar = inicializacao -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> origem, nome) == 0){
			if((auxiliar -> origemUnidimensional == ehUnidimensional) && (auxiliar -> origemBidimensional == ehBidimensional)){
				origem = true;
			}
		}
		if(auxiliar -> origemUnidimensional){
			if(strstr(auxiliar -> origemValor1, nome) != NULL){
				return true;
			}
		} else if(auxiliar -> origemBidimensional){
			if(strstr(auxiliar -> origemValor1, nome) != NULL || strstr(auxiliar -> origemValor2, nome) != NULL){
				return true;
			}
		}
		if(compareString(auxiliar -> destino, nome) == 0){
			if((auxiliar -> destinoUnidimensional == ehUnidimensional) && (auxiliar -> destinoBidimensional == ehBidimensional)){
				return true;
			}
		}
		if(auxiliar -> destinoUnidimensional){
			if(strstr(auxiliar -> destinoValor1, nome) != NULL){
				return true;
			}
		} else if(auxiliar -> destinoBidimensional){
			if(strstr(auxiliar -> destinoValor1, nome) != NULL || strstr(auxiliar -> destinoValor2, nome) != NULL){
				return true;
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	if(origem == false && destino == false){
		return false;
	}
	return origem;
}


void variavelInutilizada(ListaVariaveis* variaveis, ListaInicializacao *inicializacao, bool ehGlobal){
	int i = 0;
	NoVariaveis *auxiliar = variaveis -> primeiro;
	while(auxiliar != NULL){
		if(existeAtribuicao(inicializacao, auxiliar -> nome, auxiliar -> ehUnidimensional, auxiliar -> ehBidimensional)){
			auxiliar -> usada = true;
		}
		auxiliar = auxiliar -> proximo;
	}
}

void preencheFuncao(Arvore *arvore, ListaFuncao *listaFuncao){
	char tipo[MAX], nomeFuncao[MAX];
	int quantidadeParametros;
	Arvore *auxiliar = arvore -> filho -> filho;
	Arvore *parametro = NULL, *corpo;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> string, "declaracao_funcao") == 0){
			strcpy(tipo, "NULL");
			strcpy(nomeFuncao, "NULL");
			Arvore *cabecalho = auxiliar -> filho;
			while(cabecalho != NULL){
				if(compareString(cabecalho -> string, "cabecalho") == 0){
					Arvore *lista_parametros = cabecalho -> filho;
					parametro = NULL;
					quantidadeParametros = 0;
					while(lista_parametros != NULL){
						if(compareString(lista_parametros -> string, "lista_parametros") == 0){
							parametro = lista_parametros -> filho;
							while(parametro != NULL){
								if(compareString(parametro -> string, "parametro") == 0){
									quantidadeParametros++;
								}
								parametro = parametro -> proximo;
							}
							if(quantidadeParametros == 0){
								parametro = NULL;
							} else if(quantidadeParametros >= 1){
								parametro = lista_parametros -> filho;
							}
						//nome da função
						} else if(compareString(lista_parametros -> string, "corpo") != 0){
							strcpy(nomeFuncao, lista_parametros -> string);
						//corpo da função
						} else if(compareString(lista_parametros -> string, "corpo") == 0){
							corpo = lista_parametros;
						}
						lista_parametros = lista_parametros -> proximo;
					}
				//tipo da função
				} else {
					strcpy(tipo, cabecalho -> string);
				}
				cabecalho = cabecalho -> proximo;
			}
			if(compareString(tipo, "NULL") == 0){
				strcpy(tipo, "void");
			}
			if(quantidadeParametros == 0){
				parametro = NULL;
			} 
			insereListaFuncao(listaFuncao, tipo, nomeFuncao, auxiliar, parametro, corpo, quantidadeParametros, false);
		} 
		auxiliar = auxiliar -> proximo;
	}
}

void temFuncaoPrincipal(ListaFuncao *funcao){
	int principal = 0;
	NoFuncao *auxiliar = funcao -> primeiro;
	Arvore *parametro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, "principal") == 0){
			parametro = auxiliar -> parametros;		
			principal++;
		}
		auxiliar = auxiliar -> proximo;
	}
	if(principal == 0){
		erroVisita = true;
		printf("\033[0m[\033[1m\033[35maviso\033[0m] função \033[1m\033[31mprincipal\033[0m não existe\n");
	} else if(principal > 1){
		erroVisita = true;
		printf("\033[0m[\033[1m\033[35maviso\033[0m] redefinição da função \033[1m\033[31mprincipal\033[0m\n");		
	} else if(principal == 1){
		if(parametro != NULL){
			erroVisita = true;
			printf("\033[0m[\033[1m\033[35maviso\033[0m] função \033[1m\033[31mprincipal\033[0m não pode ter \033[1m\033[31mparamêtros\033[0m\n");			
		}
	}
}

bool repetidaFuncao(ListaFuncao *funcao, char *nome){
	int contador = 0;
	NoFuncao *auxiliar = funcao -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, nome) == 0){
			contador++;
		}
		auxiliar = auxiliar -> proximo;
	}
	if(contador > 1){
		return true;
	}
	return false;
}

void redefinicaoFuncao(ListaFuncao *funcao){
	NoFuncao *auxiliar = funcao -> primeiro;
	while(auxiliar != NULL){
		if(repetidaFuncao(funcao, auxiliar -> nome)){
			erroVisita = true;
			printf("\033[0m[\033[1m\033[35maviso\033[0m] redefinição da função \033[1m\033[31m%s\033[0m\n", auxiliar -> nome);		
		}
		auxiliar = auxiliar -> proximo;
	}
}

/* Pecorre todas as funções */
void parametroRepetido(char *nomefuncao, Arvore *arvore, ListaVariaveis *variaveis, int opcao){
	Arvore *auxiliar = arvore;
	while(auxiliar != NULL){
		//Verifico se tem algum parametro tem o mesmo nome que a variável global
		if((compareString(auxiliar -> string, ",") != 0) && (compareString(auxiliar -> string, "!@#") != 0)){
			Arvore *parametro = auxiliar -> filho;
			while(parametro != NULL){
				if((parametro -> proximo == NULL && parametro -> filho == NULL) || ((compareString(parametro -> proximo -> string, "[") == 0) || (compareString(parametro -> proximo -> string, "\033[1m\033[31m[%s]\033[0m") == 0))){
					if(compareString(retornaTipoVariavel(variaveis, parametro -> string), "NULL") != 0){
						erroVisita = true;
						if(opcao == 1){
							printf("\033[0m[\033[1m\033[35maviso\033[0m] redefinição da variável global \033[1m\033[31m%s\033[0m no parâmetro da função \033[1m\033[31m%s\033[0m\n", parametro -> string, nomefuncao);						
						} else if(opcao == 2){
							printf("\033[0m[\033[1m\033[35maviso\033[0m] redefinição do parâmetro \033[1m\033[31m%s\033[0m na variável local da função \033[1m\033[31m%s\033[0m\n", parametro -> string, nomefuncao);						
						}
					}
					break;
				}
				parametro = parametro -> proximo;
			}
		}
		auxiliar = auxiliar -> proximo;
	}
}

void comparaLocalGlobal(char *nome, ListaVariaveis *local, ListaVariaveis *global){
	NoVariaveis *auxiliarLocal = local -> primeiro;
	while(auxiliarLocal != NULL){
		NoVariaveis *auxiliarGlobal = global -> primeiro;
		while(auxiliarGlobal != NULL){
			if(compareString(auxiliarLocal -> nome, auxiliarGlobal -> nome) == 0){
				erroVisita = true;
				printf("\033[0m[\033[1m\033[35maviso\033[0m] redefinição da variável local \033[1m\033[31m%s\033[0m no escopo global\n", auxiliarLocal -> nome);						
			}
			auxiliarGlobal = auxiliarGlobal -> proximo;
		}
		auxiliarLocal = auxiliarLocal -> proximo;
	}
}

bool parametros(ListaVariaveis *parametro, char *nome){
	int contador = 0;
	NoVariaveis *auxiliar = parametro -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, nome) == 0){
			contador++;
		}
		auxiliar = auxiliar -> proximo;
	}
	if(contador > 1){
		return true;
	}
	return false;
}

void comparaParametros(char *nome, ListaVariaveis *parametro){
	NoVariaveis *auxiliar = parametro -> primeiro;
	while(auxiliar != NULL){
		if(parametros(parametro, auxiliar -> nome)){
			erroVisita = true;
			printf("\033[0m[\033[1m\033[35maviso\033[0m] redefinição do parâmetro \033[1m\033[31m%s\033[0m na função \033[1m\033[31m%s\033[0m\n", auxiliar -> nome, nome);						
		}
		auxiliar = auxiliar -> proximo;
	}
}

bool varUnidimensional(ListaVariaveis *var, char *nome){
	NoVariaveis *auxiliar = var -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, nome) == 0){
			return auxiliar -> ehUnidimensional;
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

bool varBidimensional(ListaVariaveis *var, char *nome){
	NoVariaveis *auxiliar = var -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, nome) == 0){
			return auxiliar -> ehBidimensional;
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

bool confirmacaoTipo(ListaVariaveis *variaveis, ListaVariaveis *globais,  ListaVariaveis *parametros, char *nome, bool unidimensional, bool bidimensional){
	NoVariaveis *auxiliar =  variaveis -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, nome) == 0){
			if(auxiliar -> ehUnidimensional == unidimensional){
				if(auxiliar -> ehBidimensional == bidimensional){
					return true;
				}
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	auxiliar =  globais -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, nome) == 0){
			if(auxiliar -> ehUnidimensional == unidimensional){
				if(auxiliar -> ehBidimensional == bidimensional){
					return true;
				}
			}
		}
		auxiliar = auxiliar -> proximo;
	}	
	auxiliar =  parametros -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, nome) == 0){
			if(auxiliar -> ehUnidimensional == unidimensional){
				if(auxiliar -> ehBidimensional == bidimensional){
					return true;
				}
			}
		}
		auxiliar = auxiliar -> proximo;
	}	
	return false;
}

void atribuicaoValida(ListaVariaveis *locais, ListaVariaveis *parametros, ListaVariaveis *globais, ListaInicializacao *inicializacao, char *nome){
	char tipo1[MAX], tipo2[MAX], tipo3[MAX], tipo[MAX];
	int tipoNULL = 0;
	NoInicializacao *auxiliar = inicializacao -> primeiro;
	while(auxiliar != NULL){
		tipoNULL = 0;
		strcpy(tipo, "NULL");
		strcpy(tipo1, retornaTipoVariavel(locais, auxiliar -> origem));
		strcpy(tipo2, retornaTipoVariavel(parametros, auxiliar -> origem));
		strcpy(tipo3, retornaTipoVariavel(globais, auxiliar -> origem));
		if(compareString(tipo1, "NULL") != 0){
			strcpy(tipo, tipo1);
		} else {
			tipoNULL++;						
		} 
		if(compareString(tipo2, "NULL") != 0){
			strcpy(tipo, tipo2);
		} else {
			tipoNULL++;						
		}
		if(compareString(tipo3, "NULL") != 0){
			strcpy(tipo, tipo3);
		} else {
			tipoNULL++;						
		}
		if(tipoNULL == 2){
			bool origemCorreta = true;
			bool origem11, origem21, origem31;
			bool origem12, origem22, origem32;
			bool bi, uni;
			bi = uni = false;
			origem11 = origem21 = origem31 = false;
			origem12 = origem22 = origem32 = false;
			if(auxiliar -> origemUnidimensional){
				origemCorreta = false;
				origem11 = percorreValor(tipo, locais, auxiliar -> origemValor1, varUnidimensional(locais, auxiliar -> origemValor1), varBidimensional(locais, auxiliar -> origemValor1));
				origem21 = percorreValor(tipo, parametros, auxiliar -> origemValor1, varUnidimensional(locais, auxiliar -> origemValor1), varBidimensional(locais, auxiliar -> origemValor1));
				origem31 = percorreValor(tipo, globais, auxiliar -> origemValor1, varUnidimensional(locais, auxiliar -> origemValor1), varBidimensional(locais, auxiliar -> origemValor1));
				if(origem11 || origem21 || origem31){
					uni = true;
					origemCorreta = true;
				}
			} else if(auxiliar -> origemBidimensional){
				origemCorreta = false;
				origem11 = percorreValor(tipo, locais, auxiliar -> origemValor1, varUnidimensional(locais, auxiliar -> origemValor1), varBidimensional(locais, auxiliar -> origemValor1));
				origem21 = percorreValor(tipo, parametros, auxiliar -> origemValor1, varUnidimensional(locais, auxiliar -> origemValor1), varBidimensional(locais, auxiliar -> origemValor1));
				origem31 = percorreValor(tipo, globais, auxiliar -> origemValor1, varUnidimensional(locais, auxiliar -> origemValor1), varBidimensional(locais, auxiliar -> origemValor2));
				origem12 = percorreValor(tipo, locais, auxiliar -> origemValor2, varUnidimensional(locais, auxiliar -> origemValor2), varBidimensional(locais, auxiliar -> origemValor2));
				origem22 = percorreValor(tipo, parametros, auxiliar -> origemValor2, varUnidimensional(locais, auxiliar -> origemValor2), varBidimensional(locais, auxiliar -> origemValor2));
				origem32 = percorreValor(tipo, globais, auxiliar -> origemValor2, varUnidimensional(locais, auxiliar -> origemValor2), varBidimensional(locais, auxiliar -> origemValor2));
				if(origem11 || origem21 || origem31 || origem12 || origem22 || origem32 ){
					bi = true;
					origemCorreta = true;
				}
			}
			if(origemCorreta){
				if(confirmacaoTipo(locais, globais, parametros, auxiliar -> origem, uni, bi)){
					int i = 0, j = 0;
					char stringAux[MAX];
					int quantidadeVirgula, quantidadeNumeros;
					quantidadeVirgula = quantidadeNumeros = 0;
					while(auxiliar -> destino[i] != '\0'){
						if(auxiliar -> destino[i] == '.'){
							stringAux[j] = auxiliar -> destino[i];
							j++;
							quantidadeVirgula++;
						} else if(auxiliar -> destino[i] >= '0' && auxiliar -> destino[i] <= '9'){
							quantidadeNumeros++;
						} else if(auxiliar -> destino[i] == '+' || auxiliar -> destino[i] == '*' || auxiliar -> destino[i] == '-' || auxiliar -> destino[i] == '/'){
							stringAux[j] = '\0';
							if(compareString("NULL", existeVariavel(locais, stringAux, varUnidimensional(locais, stringAux), varBidimensional(locais, stringAux))) != 0 ||
								compareString("NULL", existeVariavel(globais, stringAux, varUnidimensional(globais, stringAux), varBidimensional(globais, stringAux))) != 0 ||
								compareString("NULL", existeVariavel(parametros, stringAux, varUnidimensional(parametros, stringAux), varBidimensional(parametros, stringAux))) != 0 ){
								erroVisita = true;
								printf("\033[0m[\033[1m\033[35maviso\033[0m] no escopo global\n");
								printAtribuicao(auxiliar);
								printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", stringAux);
								return;
							}
							j = 0;
							memset(stringAux, 0, sizeof(stringAux));
						}
						i++;
					}
					if(quantidadeNumeros == strlen(auxiliar -> destino)){
						if(compareString(tipo, "inteiro") != 0){
							erroVisita = true;
							printf("\033[0m[\033[1m\033[35maviso\033[0m] atribuição inválida na função \033[1m\033[31m%s\033[0m\n", nome);
							printAtribuicao(auxiliar);
							printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);
						}
					} else if(quantidadeNumeros + quantidadeVirgula == strlen(auxiliar -> destino)){
						if(compareString(tipo, "flutuante") != 0){
							erroVisita = true;
							printf("\033[0m[\033[1m\033[35mdaviso\033[0m] atribuição inválida na função \033[1m\033[31m%s\033[0m\n", nome);
							printAtribuicao(auxiliar);
							printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);								
						}
					} else if((compareString(tipo, retornaTipoVariavel(locais, auxiliar -> destino)) != 0) && (compareString(tipo, retornaTipoVariavel(parametros, auxiliar -> destino)) != 0)  && (compareString(tipo, retornaTipoVariavel(globais, auxiliar -> destino)) != 0)){
						erroVisita = true;
						printf("\033[0m[\033[1m\033[35maviso\033[0m] atribuição inválida na função \033[1m\033[31m%s\033[0m\n", nome);
						printAtribuicao(auxiliar);
						printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);
					}
					if(auxiliar -> destinoUnidimensional){
						strcpy(tipo, "inteiro");
						if(percorreValor(tipo, locais, auxiliar -> destinoValor1, varUnidimensional(locais, auxiliar->destinoValor1), varBidimensional(locais, auxiliar->destinoValor1)) != true ||
							percorreValor(tipo, globais, auxiliar -> destinoValor1, varUnidimensional(globais, auxiliar->destinoValor1), varBidimensional(globais, auxiliar->destinoValor1)) != true ||
							percorreValor(tipo, parametros, auxiliar -> destinoValor1, varUnidimensional(parametros, auxiliar->destinoValor1), varBidimensional(parametros, auxiliar->destinoValor1)) != true ){
							erroVisita = true;
							printf("\033[0m[\033[1m\033[35maviso\033[0m] atribuição inválida na função \033[1m\033[31m%s\033[0m\n", nome);
							printAtribuicao(auxiliar);
							printf("\n\033[0m[\033[1m\033[35mviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);
						}
					} else if(auxiliar -> destinoBidimensional){
						strcpy(tipo, "inteiro");
						if(percorreValor(tipo, locais, auxiliar -> destinoValor1, varUnidimensional(locais, auxiliar->destinoValor1), varBidimensional(locais, auxiliar->destinoValor1)) != true ||
							percorreValor(tipo, globais, auxiliar -> destinoValor1, varUnidimensional(globais, auxiliar->destinoValor1), varBidimensional(globais, auxiliar->destinoValor1)) != true ||
							percorreValor(tipo, parametros, auxiliar -> destinoValor1, varUnidimensional(parametros, auxiliar->destinoValor1), varBidimensional(parametros, auxiliar->destinoValor1))  != true ||
							percorreValor(tipo, locais, auxiliar -> destinoValor2, varUnidimensional(locais, auxiliar->destinoValor2), varBidimensional(locais, auxiliar->destinoValor2)) != true ||
							percorreValor(tipo, globais, auxiliar -> destinoValor2, varUnidimensional(globais, auxiliar->destinoValor2), varBidimensional(globais, auxiliar->destinoValor2)) != true ||
							percorreValor(tipo, parametros, auxiliar -> destinoValor2, varUnidimensional(parametros, auxiliar->destinoValor2), varBidimensional(parametros, auxiliar->destinoValor2)) != true){
							erroVisita = true;
							printf("\033[0m[\033[1m\033[35maviso\033[0m] atribuição inválida na função \033[1m\033[31m%s\033[0m\n", nome);
							printAtribuicao(auxiliar);
							printf("\n\033[0m[\033[1m\033[35maviso\033[0m] o valor \033[1m\033[31m%s\033[0m é incompatível\n", auxiliar -> destino);
						}
					}
				} else {
					erroVisita = true;
					printf("\033[0m[\033[1m\033[35maviso\033[0m] a variável \033[1m\033[31m%s\033[0m tem um índice desconhecido\n", auxiliar -> origem);
				}
			} else {
				erroVisita = true;
				printf("\033[0m[\033[1m\033[35maviso\033[0m] a variável \033[1m\033[31m%s\033[0m tem um índice desconhecido\n", auxiliar -> origem);						
			}
		} else {
			if(retornaCompativel(tipo, auxiliar -> destino, locais, parametros, globais) == false){
				erroVisita = true;
				printf("\033[0m[\033[1m\033[35maviso\033[0m] a variável \033[1m\033[31m%s\033[0m tem um valor incompatível\n", auxiliar -> origem);											
			}
		}
		auxiliar = auxiliar -> proximo;
	}
}

void preencheAtribuicao(Arvore *arvore, ListaInicializacao *lista_inicializacao){
	bool origemUnidimensional, origemBidimensional;
	bool destinoUnidimensional, destinoBidimensional;
	char origemValor1[MAX], origemValor2[MAX];
	char destinoValor1[MAX], destinoValor2[MAX];
	char nomeOrigem[MAX], nomeDestino[MAX];
	Arvore *auxiliar = arvore -> filho;
	while(auxiliar != NULL){
		strcpy(origemValor1, "NULL");
		strcpy(origemValor2, "NULL");
		strcpy(destinoValor1, "NULL");
		strcpy(destinoValor2, "NULL");
		//if(compareString(auxiliar -> string, "inicializacao_variaveis") == 0){
			Arvore *atribuicao = auxiliar;
			if(compareString(atribuicao -> string, "atribuicao") == 0){
				Arvore *var = atribuicao -> filho;
				if(compareString("var", var -> string) == 0){
					Arvore *nomeVariavel = var -> filho;
					strcpy(nomeOrigem, nomeVariavel -> string);
					if(nomeVariavel -> proximo != NULL){
						Arvore *indice = nomeVariavel -> proximo;
						if(compareString("indice", indice -> string) == 0){
							Arvore *valoresIndice = indice -> filho;
							strcpy(origemValor1, "NULL");
							strcpy(origemValor2, "NULL");
							while(valoresIndice != NULL){
								if(compareString(valoresIndice -> string, "expressao") == 0){
									if(compareString(origemValor1, "NULL") == 0){
										memset(folha, 0, sizeof(folha));
										procuraFilho(valoresIndice);
										strcpy(origemValor1, folha);
									} else {
										memset(folha, 0, sizeof(folha));
										procuraFilho(valoresIndice);
										strcpy(origemValor2, folha);										
									}
								}
								valoresIndice = valoresIndice -> proximo;
							}
						}
					}
				}
				Arvore *expressao = atribuicao -> filho -> proximo;
				if(compareString("expressao", expressao -> string) == 0){
					Arvore *var = NULL, *numero = NULL;
					Arvore *filhoExpressao = expressao;
					while(filhoExpressao != NULL){
						if(compareString(filhoExpressao -> string, "var") == 0){
							var = filhoExpressao;
							break;
						} else if(quantidadeFilho(filhoExpressao) > 1){
							memset(folha, 0, sizeof(folha));
							procuraFilho(filhoExpressao);
							break;
						} else if(compareString(filhoExpressao -> string, "numero") == 0){
							numero = filhoExpressao;
							break;
						}
						filhoExpressao = filhoExpressao -> filho;
					}
					if(var == NULL && numero == NULL){
						strcpy(nomeDestino, folha);
						//printf("numero %s\n", numero -> filho -> string);
					} else	if(var == NULL && numero != NULL){
						strcpy(nomeDestino, numero -> filho -> string);
						//printf("numero %s\n", numero -> filho -> string);
					} else if(var != NULL && numero == NULL){
						//printf("var %s\n", var -> filho);
						strcpy(nomeDestino, var -> filho -> string);
						if(var -> filho -> proximo != NULL){
							strcpy(destinoValor1, "NULL");
							strcpy(destinoValor2, "NULL");
							Arvore *indice = var -> filho -> proximo;
							if(compareString(indice -> string, "indice") == 0){
								Arvore *valoresIndice = indice -> filho;
								while(valoresIndice != NULL){
									if(compareString(valoresIndice -> string, "expressao") == 0){
										if(compareString(destinoValor1, "NULL") == 0){
											memset(folha, 0, sizeof(folha));
											procuraFilho(valoresIndice);
											strcpy(destinoValor1, folha);
										} else {
											memset(folha, 0, sizeof(folha));
											procuraFilho(valoresIndice);
											strcpy(destinoValor2, folha);										
										}
									}
									valoresIndice = valoresIndice -> proximo;
								}	
							}
						}
					}
				}
				if((compareString(origemValor1, "NULL") == 0) && (compareString(origemValor2, "NULL") == 0)){
					origemUnidimensional = origemBidimensional = false;
				} else if((compareString(origemValor1, "NULL") != 0) && (compareString(origemValor2, "NULL") != 0)){
					origemUnidimensional = false;
					origemBidimensional = true;
				//Se o primeiro for diferente de null
				} else if((compareString(origemValor1, "NULL") != 0) && (compareString(origemValor2, "NULL") == 0)){
					origemUnidimensional = true;
					origemBidimensional = false;
				}
				if((compareString(destinoValor1, "NULL") == 0) && (compareString(destinoValor2, "NULL") == 0)){
					destinoUnidimensional = destinoBidimensional = false;
				} else if((compareString(destinoValor1, "NULL") != 0) && (compareString(destinoValor2, "NULL") != 0)){
					destinoUnidimensional = false;
					destinoBidimensional = true;
				//Se o primeiro for diferente de null
				} else if((compareString(destinoValor1, "NULL") != 0) && (compareString(destinoValor2, "NULL") == 0)){
					destinoUnidimensional = true;
					destinoBidimensional = false;
				}
				insereListaInicializacao(lista_inicializacao, nomeOrigem, origemUnidimensional, origemBidimensional, origemValor1, origemValor2, nomeDestino, destinoUnidimensional, destinoBidimensional, destinoValor1, destinoValor2);
			}
		//}
		auxiliar = auxiliar -> proximo;
	}
}


void preencheParametro(Arvore *arvore, ListaVariaveis *variaveis){
	Arvore *auxiliar = arvore;
	bool indiceUnidimensional , indiceBidimensional;
	char tipo[MAX], nome[MAX];
	int indice;
	while(auxiliar != NULL){
		//Verifico se tem algum parametro tem o mesmo nome que a variável global
		if((compareString(auxiliar -> string, ",") != 0) && (compareString(auxiliar -> string, "!@#") != 0)){
			indiceUnidimensional = false;
			indiceBidimensional = false;
			strcpy(tipo, "NULL");
			strcpy(nome, "NULL");
			indice = 0;
			Arvore *parametro = auxiliar -> filho;
			while(parametro != NULL){
				if(compareString(parametro -> string, "inteiro") == 0 || compareString(parametro -> string, "flutuante") == 0){
					strcpy(tipo, parametro -> string);
				} else if(compareString(parametro -> string, "]")  == 0 || compareString(parametro -> string, "[")  == 0 ){
					indice++;					
				} else if(compareString(parametro -> string, ":") != 0){
					strcpy(nome, parametro -> string);
				}
				parametro = parametro -> proximo;
			}
			if(indice == 2){
				indiceUnidimensional = true;
			} else if(indice == 4){
				indiceBidimensional = true;				
			}
			insereListaVariaveis(variaveis, tipo, nome, indiceUnidimensional, indiceBidimensional, "NULL", "NULL", false, true);
		}
		auxiliar = auxiliar -> proximo;
	}
}

bool escrevaCompativel(char *valor){
	int i = 0, quantidadeLetras = 0, quantidadeNumeros = 0;
	while(valor[i] != '\0'){
		if(valor[i] >= 'A' && valor[i] <= 'Z'){
			quantidadeLetras++;
		} else if(valor[i] >= 'a' && valor[i] <= 'z'){
			quantidadeLetras++;
		} else if(valor[i] == '[' || valor[i] == ']'){
			quantidadeLetras++;
		} else if(valor[i] >= '0' && valor[i] <= '9'){
			quantidadeNumeros++;
		}
		i++;
	}
	if(quantidadeLetras + quantidadeNumeros == strlen(valor)){
		return true;
	}
	return false;
}

int ehInteiro(char *valor){
	int i = 0, quantidadeVirgula = 0, quantidadeNumeros = 0;
	while(valor[i] != '\0'){
		if(valor[i] == '.'){
			quantidadeVirgula++;
		} else if(valor[i] >= '0' && valor[i] <= '9'){
			quantidadeNumeros++;
		}
		i++;
	}
	if(quantidadeNumeros == strlen(valor)){
		return 1;
	} else if(quantidadeNumeros + quantidadeVirgula == strlen(valor)){
		return 2;
	}
	return 3;	
}

bool tipoVariavel(char *tipo, ListaVariaveis *locais, ListaVariaveis *parametros, ListaVariaveis *globais, char *valor){
	bool tipoCerto = false;
	char aux[MAX];
	int i = 0, j = 0, quantidadeLetras = 0, quantidadeNumeros = 0;
	while(valor[i] != '\0'){
		if(valor[i] >= 'A' && valor[i] <= 'Z'){
			aux[j] = valor[i];
			j++;
		} else if(valor[i] >= 'a' && valor[i] <= 'z'){
			aux[j] = valor[i];
			j++;
		} else if(valor[i] == '[' || valor[i] == ']'){
			aux[j] = valor[i];
			j++;
		} else if(valor[i] >= '0' && valor[i] <= '9'){
			aux[j] = valor[i];
			j++;
		} else if(valor[i] == '+' || valor[i] == '-' || valor[i] == '*' || valor[i] == '/'){
			aux[j] = '\0';
			if(compareString(tipo, retornaTipoVariavel(locais, aux)) == 0){
				tipoCerto = true;
			} else if(compareString(tipo, retornaTipoVariavel(globais, aux)) == 0){
				tipoCerto = true;
			} else if(compareString(tipo, retornaTipoVariavel(parametros, aux)) == 0){
				tipoCerto = true;
			}
			memset(aux, 0, sizeof(aux));
		}
		i++;
	}
	aux[j] = '\0';
	if(compareString(tipo, retornaTipoVariavel(locais, aux)) == 0){
		tipoCerto = true;
	} else if(compareString(tipo, retornaTipoVariavel(globais, aux)) == 0){
		tipoCerto = true;
	} else if(compareString(tipo, retornaTipoVariavel(parametros, aux)) == 0){
		tipoCerto = true;
	}
	return tipoCerto;
}			

bool retornaCompativel(char *tipoFuncao, char *valor, ListaVariaveis *locais, ListaVariaveis *parametros, ListaVariaveis *globais){
	int tipo;
	char auxiliar[MAX];
	int i = 0, j = 0, quantidadeLetras = 0, quantidadeNumeros = 0;
	memset(auxiliar, 0, sizeof(auxiliar));
	while(valor[i] != '\0'){
		if((valor[i] >= 'A' && valor[i] <= 'Z') || (valor[i] >= 'a' && valor[i] <= 'z') || (valor[i] >= '0' && valor[i] <= '9') || (valor[i] >= '.')){
			auxiliar[j] = valor[i];
			j++;
		} else if(valor[i] == '+' || valor[i] == '*' || valor[i] == '-' || valor[i] == '/'){
			auxiliar[j] = '\0';
			tipo = ehInteiro(auxiliar);
			if(tipo == 1){
				if(compareString(tipoFuncao, "inteiro") != 0)
					return false;
			} else if(tipo == 2){
				if(compareString(tipoFuncao, "flutuante") != 0)
					return false;
			} else {
				if(tipoVariavel(tipoFuncao, locais, parametros, globais, auxiliar) == false){
					return false;
				}
			}
			memset(auxiliar, 0, sizeof(auxiliar));
			j = 0;
		}
		i++;
	}
	auxiliar[j] = '\0';
	tipo = ehInteiro(auxiliar);
	if(tipo == 1){
		if(compareString(tipoFuncao, "inteiro") != 0)
		return false;
	} else if(tipo == 2){
		if(compareString(tipoFuncao, "flutuante") != 0)
		return false;
	} else {
		if(tipoVariavel(tipoFuncao, locais, parametros, globais, auxiliar) == false){
			return false;
		}
	}
	return true;
}

void verificaAcao(ListaVariaveis *parametros, ListaVariaveis *globais, ListaVariaveis *locais, char *tipo, char *nome, Arvore *corpo){
	char tipoAcao[MAX];
	Arvore *auxiliar = corpo -> filho;
	int nFilho;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> string, "acao") == 0){
			Arvore *acao = auxiliar -> filho;
			char resultado[MAX];
			strcpy(tipoAcao, acao -> string);
			while(acao != NULL){
				nFilho = quantidadeFilho(acao);
				if(nFilho > 1){
					memset(folha, 0, sizeof(folha));
					procuraFilho(acao);
					strcpy(resultado, folha);
					break;
				} else if(nFilho == 0){
					strcpy(resultado, acao -> string);
				}
				acao = acao -> filho;
			}
			if(compareString(tipoAcao, "RETORNA") == 0){
				if(compareString(tipo, "void") == 0){
					erroVisita = true;
					printf("\033[0m[\033[1m\033[35maviso\033[0m] a função %s é do tipo \033[1m\033[31mvoid\033[0m\n", nome);
				} else {
					//printf("::%s\n", resultado);
					if(retornaCompativel(tipo, resultado, locais, parametros, globais) == false){
						erroVisita = true;
						printf("\033[0m[\033[1m\033[35maviso\033[0m] a função %s é do tipo \033[1m\033[31m%s\033[0m e seu valor de retorno é incompatível\n", nome, tipo);												
					}
				}
			} else if(compareString(tipoAcao, "ESCREVA") == 0){
				if(escrevaCompativel(resultado) == false){
					erroVisita = true;
					printf("\033[0m[\033[1m\033[35maviso\033[0m] na função %s no escreva temos \033[1m\033[31m%s\033[0m é o tipo é incompatível\n", nome, resultado);
				}
			}
		}
		auxiliar = auxiliar -> proximo;
	}
}

void imprimeUsada(ListaFuncao *funcoes){
	NoFuncao *auxiliar = funcoes -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, "principal") != 0){
			if(auxiliar -> ehChamada == false){
				erroVisita = true;
				printf("\033[0m[\033[1m\033[35maviso\033[0m] na função \033[1m\033[31m%s\033[0m é inutilizada\n", auxiliar -> nome);
			}			
		}
		auxiliar = auxiliar -> proximo;
	}
}

void funcaoUsada(ListaFuncao *funcoes, char *nome){
	NoFuncao *auxiliar = funcoes -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, nome) == 0){
			auxiliar -> ehChamada = true;
		}
		auxiliar = auxiliar -> proximo;
	}
}

bool existeFuncao(ListaFuncao *funcoes, char *nome, int quantidadeArgumentos){
	NoFuncao *auxiliar = funcoes -> primeiro;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> nome, nome) == 0){
			if(auxiliar -> numeroArgumento == quantidadeArgumentos){
				return true;
			} else {
				return false;
			}
		}
		auxiliar = auxiliar -> proximo;
	}
	return false;
}

void verificaChamada(ListaFuncao *funcao, Arvore *corpo, char *nome){
	int quantidadeArgumentos = 0;
	Arvore *auxiliar = corpo -> filho;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> string, "chamada_funcao") == 0){
			char nomefuncao[MAX];
			Arvore *chamada = auxiliar -> filho;
			while(chamada != NULL){
				if(compareString(chamada -> string, "lista_argumentos") != 0){
					strcpy(nomefuncao, chamada -> string);
				} else if(compareString(chamada -> string, "lista_argumentos") == 0){
					Arvore *lista_argumentos = chamada -> filho;
					quantidadeArgumentos = 0;
					while(lista_argumentos != NULL){
						quantidadeArgumentos++;
						lista_argumentos = lista_argumentos -> proximo;
					}
				}
				chamada = chamada -> proximo;
			}
			if(compareString(nome, nomefuncao) == 0){
				erroVisita = true;
				printf("\033[0m[\033[1m\033[35maviso\033[0m] recursão não permitida da função \033[1m\033[31m%s\033[0m\n", nomefuncao);
			} else {
				if(existeFuncao(funcao, nomefuncao, quantidadeArgumentos) == false){
					erroVisita = true;
					printf("\033[0m[\033[1m\033[35maviso\033[0m] chamada função \033[1m\033[31m%s\033[0m ou quantidade de arugmentos errada\n", nomefuncao);
				} else {
					funcaoUsada(funcao, nomefuncao);
				}
			}
		}
		auxiliar = auxiliar -> proximo;
	}
}

void usadaGlobais(ListaVariaveis *globais, ListaInicializacao *inicializacao){
	NoVariaveis *auxiliar = globais -> primeiro;
	while(auxiliar != NULL){
		NoInicializacao *auxiliarInicializacao = inicializacao -> primeiro;
		while(auxiliarInicializacao != NULL){
			if(compareString(auxiliar -> nome, auxiliarInicializacao -> origem) == 0){
				auxiliar -> usada = true;
			}
			auxiliarInicializacao = auxiliarInicializacao -> proximo;
		}
		auxiliar = auxiliar -> proximo;
	}
}

void imprimeUsadaGlobais(ListaVariaveis *variaveis){
	NoVariaveis *auxiliar = variaveis -> primeiro;
	while(auxiliar != NULL){
		if(auxiliar -> usada == false){
			erroVisita = true;
			printf("\033[0m[\033[1m\033[35maviso\033[0m] a variável \033[1m\033[31m%s\033[0m é inutilizada\n", auxiliar -> nome);
		}
		auxiliar = auxiliar -> proximo;
	}
}

void pecorreTodasFuncao(LLVMContextRef context, LLVMModuleRef module, LLVMBuilderRef builder, ListaFuncao *funcoes, ListaVariaveis *globais){
	ListaVariaveis *variaveisLocais, *parametros;
	ListaInicializacao *inicializacaoLocais;
	NoFuncao *auxiliar = funcoes -> primeiro;
	while(auxiliar != NULL){
		variaveisLocais = (ListaVariaveis*) malloc (sizeof(ListaVariaveis*));
		parametros = (ListaVariaveis*) malloc (sizeof(ListaVariaveis*));
		inicializacaoLocais = (ListaInicializacao*) malloc (sizeof(ListaInicializacao*));
		inicializaListaVariaveis(parametros);		
		/* Paramêtros repetidos */
		preencheParametro(auxiliar -> parametros, parametros);
		comparaParametros(auxiliar -> nome, parametros);
		//Comparo os parâmetros com as variáves globais
		parametroRepetido(auxiliar -> nome, auxiliar -> parametros, globais, 1);
		//Pego todas as variáveis locais
		inicializaListaVariaveis(variaveisLocais);
		preencheVariaveis(auxiliar -> corpo, variaveisLocais, false);
		//Comparo as variáveis locais com os parâmetros
		parametroRepetido(auxiliar -> nome, auxiliar -> parametros, variaveisLocais, 2);		
		//Comparo as locais com as globais
		comparaLocalGlobal(auxiliar -> nome, variaveisLocais, globais);
		//Comparo as locais com local
		redefinicaoVariavel(auxiliar-> nome, variaveisLocais, false);

		inicializaListaInicializacao(inicializacaoLocais);
		//Preenchendo as atribuições
		preencheAtribuicao(auxiliar -> corpo, inicializacaoLocais);
		atribuicaoValida(variaveisLocais, parametros, globais, inicializacaoLocais, auxiliar -> nome);
		
		verificaAcao(parametros, globais, variaveisLocais, auxiliar -> tipo, auxiliar -> nome, auxiliar -> corpo);
		verificaChamada(funcoes, auxiliar -> corpo, auxiliar -> nome);

		usadaGlobais(globais, inicializacaoLocais);

		codigoIRFuncao(context, module, builder, auxiliar, variaveisLocais, parametros, inicializacaoLocais);

		limpaListaVariavel(variaveisLocais);		
		limpaListaVariavel(parametros);		
		limpaListaInicializacao(inicializacaoLocais);
		/* Verificar retorno */
		auxiliar = auxiliar -> proximo;
	}
}

void variaveisNaoUtilizadas(ListaVariaveis *v){
	NoVariaveis *auxiliar = v -> primeiro;
	while(auxiliar != NULL){
		auxiliar -> usada = false;
		auxiliar = auxiliar -> proximo;
	}
}

/* Verifica as árvore */
void visitaArvore(char *nomeArquivo, Arvore *arvore){
	LLVMContextRef context = LLVMGetGlobalContext();;
    LLVMModuleRef module = LLVMModuleCreateWithNameInContext("meu_modulo.bc", context);
    LLVMBuilderRef builder = LLVMCreateBuilderInContext(context);

	ListaVariaveis *variaveisGlobais = (ListaVariaveis*) malloc (sizeof(ListaVariaveis*));
	ListaInicializacao *inicializacaoGlobais = (ListaInicializacao*) malloc (sizeof(ListaInicializacao*));
	ListaFuncao *listaFuncao = (ListaFuncao*) malloc (sizeof(ListaFuncao*));
	inicializaListaVariaveis(variaveisGlobais);
	inicializaListaInicializacao(inicializacaoGlobais);
	inicializaListaFuncao(listaFuncao);
	preencheVariaveis(arvore, variaveisGlobais, true);
	preencheInicializacao(arvore, inicializacaoGlobais);
	variaveisNaoUtilizadas(variaveisGlobais);
	preencheFuncao(arvore, listaFuncao);
	/* Erro no escopo global */
	/* Variavel global redefinida */
	redefinicaoVariavel("NULL", variaveisGlobais, true);
	/* Verifica se os índices são válidos */
	indiceValido(variaveisGlobais, true);
	/* Se alguma atribuição é inválida */
	inicializacaoValida(variaveisGlobais, inicializacaoGlobais, true);
	/* Se tem alguma variável inutilizada */
	variavelInutilizada(variaveisGlobais, inicializacaoGlobais, true);
	/* Se tem função principal e se ela tiver se tem parâmetros */
	temFuncaoPrincipal(listaFuncao);
	/* Redefinição função */
	redefinicaoFuncao(listaFuncao);
	if(erroVisita == false){
		codigoIRGlobais(context, module, builder, variaveisGlobais, inicializacaoGlobais);
		//codigoIRInicializacaoGlobais(context, module, builder, inicializacaoGlobais);
		/* Erro nas funções */
		/* Percorre todas as funções */
		pecorreTodasFuncao(context, module, builder, listaFuncao, variaveisGlobais);
		imprimeUsada(listaFuncao);
		imprimeUsadaGlobais(variaveisGlobais);
		if(erroVisita == false){

			LLVMDumpModule(module);
		    // Escreve para um arquivo no formato bitcode.
		    if (LLVMWriteBitcodeToFile(module, "meu_modulo.bc") != 0) {
		        fprintf(stderr, "error writing bitcode to file, skipping\n");
		    }

		} else {
			printf("\033[0m[\033[1m\033[35maviso\033[0m] não conseguiu gerar o código intermediário\n");
			system("rm meu_modulo.bc");
		}
	} else {
		printf("\033[0m[\033[1m\033[35maviso\033[0m] não conseguiu gerar o código intermediário\n");
		system("rm meu_modulo.bc");
	}
}


void imprimeErro(char *nome, Arvore *final){
	erroVisita = false;
	if(erroSemantico == true){
		system("clear");
		system("cat semantico.txt");
		if(erroGrave == false)
			visitaArvore(nome, final);
	} else {
		visitaArvore(nome, final);
	}
	system("rm semantico.txt");
	system("rm auxiliar.txt");
	if(erroVisita){
		exit(1);
	} 
} 