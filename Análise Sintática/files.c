#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "files.h"

/**
* Esta função compara duas strings, se forem iguais ela retorna zero,
* caso contrário reotrna um valor diferente de zero;
@param stringA, é uma sequência de char a ser comparada;
@param stringB, é uma sequência de char a ser comparada;
@return result, retorna um inteiro em que se for zero é igual e qualquer coisa se for diferente.
*/
int compareString(char stringA[], char stringB[]){
	int i = 0;
	int result;
	int equal = 1;
	while(equal && stringA[i] != '\0' && stringB[i] != '\0'){
		if(stringA[i] != stringB[i]){
			equal = 0;
		}
		i++;
	}
	if(stringA[i-1] == '\0' && stringB[i-1] == '\0'){
		result = 0;	
	} else {
		result = stringA[i-1] - stringB[i-1];	
	}
	return result;
}

/**
* Esta função verifica onde começa as BNF, no arquivo parser.y
* e retorna a linha que começa a BNF;
@param parser, é um arquivo onde temos a BNF definidas;
@return i, retorna i em que seria a posição da linha onde começa a BNF, caso
* não encontre retorna -1.
*/
int getStart(FILE *parser){
	char line[SIZE];
	int i = 0;
	while(fgets(line, sizeof(line), parser) != NULL){
		if(compareString(line, startbnftplusplus) == 0){
			return i + 1;
		}
		i++;
	}
	return -1;
}

/**
* Esta função verifica onde termina as BNF, no arquivo parser.y
* e retorna a linha que termina a BNF;
@param parser, é um arquivo onde temos a BNF definidas;
@return i, retorna i em que seria a posição da linha onde termina a BNF, caso
* não encontre retorna -1.
*/
int getEnd(FILE *parser){
	char line[SIZE];
	int i = 0;
	while(fgets(line, sizeof(line), parser) != NULL){
		if(compareString(line, endbnftplusplus) == 0){
			return i + 1;
		}
		i++;
	}
	return -1;
}

/**
* Esta função verifica se a linha contém o caracetere ':'
* se estiver presente retorna verdadeiro caso contrário retorna falso;
@param line, é um sequência de caractere onde vai ser procurado o caracetere;
@return true ou false, retorna verdadeiro caso ou falso caso não ache.
*/
bool hasTwoPoint(char *line){
	int i = 0;
	while(line[i] != '\0'){
		if(line[i] == ':'){
			return true;
		}
		i++;
	}
	return false;
}

/**
* Esta função verifica se a linha contém o caracetere '{'
* se estiver presente retorna verdadeiro caso contrário retorna falso;
@param line, é um sequência de caractere onde vai ser procurado o caracetere;
@return true ou false, retorna verdadeiro caso ou falso caso não ache.
*/
bool hasKey(char *line){
	int i = 0;
	while(line[i] != '\0'){
		if(line[i] == '{'){
			return true;
		}
		i++;
	}
	return false;
}

/**
* Esta função retorna o pai da BNF;
@param line, é um sequência de caractere onde vai ser pego o nome do pai;
@return father, retorna o pai.
*/
char *getFather(char *line){
	char *father = (char*) malloc (SIZE * sizeof(char));
	int i = 0, j = 0;
	while(line[i] != '\0'){
		if(line[i] == ':'){
			break;
		}
		father[j] = line[i];
		i++;
		j++;
	}
	father[j] = '\0';
	return father;
}

/**
* Esta função retorna o filho da BNF;
@param line, é um sequência de caractere onde vai ser pego o nome do filho;
@return children, retorna o filho.
*/
char *getChildren(char *line){
	char *children = (char*) malloc (SIZE * sizeof(char));
	int i = 0, j = 0;
	while(line[i] != '\0'){
		if((line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 123)){
			break;
		}
		i++;
	}
	while(line[i] != '\0'){
		if(line[i] == '{'){
			break;
		}
		children[j] = line[i];
		i++;
		j++;
	}
	children[j] = '\0';
	return children;
}

/**
* Esta função copia a BNF presente no parser.y presente
* para uma estrutura;
@param start, é um inteiro que seria a linha onde começa a BNF;
@param end, é um inteiro que seria a linha onde termina a BNF;
@param bnf, é a estrutura onde ser armazenada BNF;
@return void, retorna nada.
*/
void copyBNF(int start, int end, pTree *bnf){
	char line[SIZE], father[SIZE], children[SIZE];
	FILE *parser = fopen(bnftplusplus, "r");
	int i = 0;
	end--;
	while(fgets(line, sizeof(line), parser) != NULL){
		if(i >= start && i < end){
			if(hasTwoPoint(line)){
				strcpy(father, getFather(line));
			} else if(hasKey(line)){
				strcpy(children, getChildren(line));
				insertTree(bnf, father, children, "NULL");
				//printf("father: %s\n", father);
				//printf("children: %s\n", children);
			}
			memset(line, 0, sizeof(line));
		} else if(i >= end){
			break;
		}
		i++;
	}
	fclose(parser);
}

/**
* Esta função verifica tem parentêses, se tiver copia o valor que está dentro do parentêses;
@param line, é uma sequência de caractere onde será procurado o parentêses;
@return value, retorna uma sequência de caractere com o valor que estava dentro do parentêses.
*/
char* hasParentheses(char *line){
	char *value = (char*) malloc (SIZE * sizeof(char));
	bool startParentheses = false;
	bool endParentheses = false;
	int i = 0, j = 0, inicio;
	while(line[i] != '\0'){
		if(line[i] == '('){
			startParentheses = true;
			inicio = i + 1;
			break;
		}
		i++;
	}
	i = 0;
	while(line[i] != '\0'){
		if(line[i] == ')'){
			endParentheses = true;
			break;
		}
		i++;
	}
	if(startParentheses && endParentheses){
		i = inicio;
		while(line[i] != '\0'){
			if(line[i] == ')'){
				value[j] = '\0';
				return value;
			}
			value[j] = line[i];
			i++;
			j++;
		}
	} else {
		return "NULL";
	}
}

/**
* Esta função reduz uma linha que contenha uma espaço em branco em seguida um abre parentêses;
@param line, é uma sequência de caractere onde será removido os caracteres;
@return void, retorna nada.
*/
void cleanValue(char *line){
	int i = 0;
	while(line[i] != '\0'){
		if(line[i] == ' ' && line[i + 1] == '('){
			line[i] = '\0';
			return;
		}
		i++;
	}
}

/**
* Esta função copia o caminho percorrido pelo código-fonte de entrada para
* uma estrutura;
@param line, é uma sequência de caractere onde será removido os caracteres;
@return void, retorna nada.
*/
void copyOutput(pTree *outTree){
	FILE *out = fopen(outputprogram, "r");
	char line[SIZE], output[SIZE];
	while(fgets(line, sizeof(line), out) != NULL){
		strcpy(output, hasParentheses(line));
		if(compareString(output, "NULL") == 0){
			insertFirstTree(outTree, line, "NULL");
		} else {
			cleanValue(line);
			insertFirstTree(outTree, line, output);			
		}
		memset(line, 0, sizeof(line));
	}
	insertFirstTree(outTree, "programa", "NULL");
	fclose(out);
}

/**
* Esta função simplesmente acha o último caracetere da linha, e na posição seguinte
* coloca um marcador de fim de linha;
@param bnf, é a estrutura onde tem a bnf que será limpa;
@return void, retorna nada.
*/
void clearBNF(pTree *bnf){
	int i;
	Node *auxiliar = bnf -> first;
	while(auxiliar != NULL){
		i = strlen(auxiliar -> children);
		while(i > 0){
			if((auxiliar -> children[i] >= 65 && auxiliar -> children[i] <= 90) || (auxiliar -> children[i] >= 97 && auxiliar -> children[i] <= 123)){
				auxiliar -> children[i + 1] = '\0';
				break;
			}
			i--;
		}
		auxiliar = auxiliar -> next;
	}
}

/**
* Esta função verifica se a entrada contém aquela determinada regra;
@param bnf, é a estrutura onde tem a bnf que será procurada as regras;
@param father, é uma sequência de caractere que verifica se a notação existe na BNF;
@param children, é uma sequência de caractere que se existe;
@return true ou false, retorna verdadeiro caso exista ou falso caso não exista.
*/
bool hasRule(pTree *bnf, char *father, char *children){
	Node *auxiliar = bnf -> first;
	while(auxiliar != NULL){
		if((compareString(father, auxiliar -> father) == 0) && (compareString(children, auxiliar -> children) == 0)){
			return true;
		}
		auxiliar = auxiliar -> next;
	}
	return false;
}

/**
* Esta função verifica se existe determinada ação existe;
@param bnf, é a estrutura onde tem a bnf que será procurada as regras;
@param father, é uma sequência de caractere que verifica se a notação existe na BNF;
@return true ou false, retorna verdadeiro caso exista ou falso caso não exista.
*/
bool hasFather(pTree *bnf, char *father){
	Node *auxiliar = bnf -> first;
	while(auxiliar != NULL){
		if(compareString(auxiliar -> father, father) == 0){
			return true;
		}
		auxiliar = auxiliar -> next;
	}
	return false;
}

/**
* Esta função verifica se uma das palavras contém aquela regra;
@param finalTree, é a estrutura é montada a árvore sintática;
@param bnf, é a estrutura onde tem a bnf que será procurada as regras;
@param step1, é uma sequência de caractere que verifica se a notação existe na BNF;
@param step2, é uma sequência de caractere que verifica se no step1 tem o step2;
@param value, é uma sequência de caractere caso exista um valor associado;
@return true ou false, retorna verdadeiro caso exista ou falso caso não exista.
*/
bool checkWords(pTree *finalTree, pTree *bnf, char *step1, char *step2, char *value){
	char word[SIZE];
	int i = 0, j = 0;
	while(step1[i] != '\0'){
		if(step1[i] ==  ' '){
			word[j] = '\0';
			if(hasFather(bnf, word)){
				if(hasRule(bnf, word, step2)){
					insertTree(finalTree, word, step2, value);
					return true;
				}
			}
			j = 0;
			memset(word, 0, sizeof(word));
		} else {
			word[j] = step1[i];
			j++;
		}
		i++;
	}
	word[j] = '\0';
	if(hasFather(bnf, word)){
		if(hasRule(bnf, word, step2)){
			insertTree(finalTree, word, step2, value);
			return true;
		}
	}
	return false;
}

/**
* Esta função verifica se o pai e o filho combinam com a notação da BNF;
@param tree, é a estrutura que será procurado;
@param inicio, é uma inteiro onde será o início dá onde será procurado;
@param fim, é uma inteiro onde será o fim dá onde será procurado;
@param father, é uma sequência de caractere onde será comparado com a estrutura de combinado;
@param children, é uma sequência de caractere onde será comparado com a estrutura de combinado;
@return true ou false, retorna verdadeiro caso exista ou falso caso não exista.
*/
bool checkFather(pTree *tree, int inicio, int fim, char *father, char *children){
	Node *auxiliar = tree -> first;
	while(auxiliar != NULL){
		if(auxiliar -> id >= inicio && auxiliar -> id <= fim){
			if((compareString(auxiliar -> father, father) == 0) && (compareString(auxiliar -> children, children) == 0)){
				return true;
			}
		}
		auxiliar = auxiliar -> next;
	}
	return false;
}

/**
* Esta função verifica se aquela linha contém espaço em branco.
@param line, é uma sequência de caractere onde vai ser verificada se existe espaço em branco;
@return true ou false, retorna verdadeiro caso exista ou falso caso não exista.
*/
bool hasSpace(char *line){
	int i = 0;
	while(line[i] != '\0'){
		if(line[i] == ' '){
			return true;
		}
		i++;
	}
	return false;
}

/**
* Esta função verifica se foi achado o pai de determinado nó.
@param father, é uma sequência de caractere onde vai ser verificada a existência;
@param children, é uma sequência de caractere onde vai ser verificada a existência;
@return true ou false, retorna verdadeiro caso exista ou falso caso não exista.
*/
bool checkFatherChildren(char *father, char *children){
	char auxiliarFather[SIZE], auxiliarChildren[SIZE];
	int i = 0, j = 0;
	if((hasSpace(father) == false) &&  (hasSpace(children) == false)){
		if(compareString(father, children) == 0){
			return true;
		}
	} else {
		while(children[i] != '\0'){
			if(children[i] == ' '){
				auxiliarChildren[j] = '\0';
				if(compareString(auxiliarChildren, father) == 0){
					return true;
				} else {
					memset(auxiliarChildren, 0, sizeof(auxiliarChildren));
					j = 0;	
				}
			} else if(children[i + 1] == '\0'){
				auxiliarChildren[j] = children[i];
				auxiliarChildren[j + 1] = '\0';
				if(compareString(auxiliarChildren, father) == 0){
					return true;
				}
				return false;
			} else {
				auxiliarChildren[j] = children[i];
				j++;
			}
			i++;
		}
	}
	return false;
}

/**
* Esta função retrocede na árvore atrás do seu pai;
@param bnf, é a estrutura onde está guarada a BNF;
@param finalTree, é a estrutura onde está guarada a árvore sintática;
@param step, é uma sequência de caractere onde vai ser procurado o pai;
@param value, é uma sequência de caractere onde vai ser o valor que pode ou não ter;
@return true ou false, retorna verdadeiro caso exista ou falso caso não exista.
*/
bool backTree(pTree *bnf, pTree *finalTree, char *step, char *value){
	bool found = false;
	int copyID = idNode, start, end;
	Node *auxiliar = finalTree -> last;
	Node *check, *penultimate, *checkPrevious;
	while(auxiliar != NULL){
		if(checkWords(finalTree, bnf, auxiliar -> children, step, value)){
			penultimate = finalTree -> last;
			if(checkFather(finalTree, auxiliar -> id, penultimate -> previous -> id, finalTree -> last -> father, finalTree -> last -> children) == false){
				finalTree -> last -> id = auxiliar -> id;	
			} else {
				end = auxiliar -> id;
				while(1){
					check = finalTree -> first;
					while(check != NULL){
						if(check -> next -> id == end){
							checkPrevious = check;
							break;
						}
						check = check -> next;
					}
					while(checkPrevious != NULL){
						if(checkPrevious == finalTree -> first){
							finalTree -> last -> id = auxiliar -> id;	
							return true;
						}
						if(checkFatherChildren(finalTree -> last -> father, checkPrevious -> children)){
							start = checkPrevious -> id;
							break;
						}
						checkPrevious = checkPrevious -> previous;
					}
					if(checkFather(finalTree, start, end, finalTree -> last -> father, finalTree -> last -> children) == false){
						finalTree -> last -> id = checkPrevious -> id;
						return true;
					} else {
						end = start;
					}
				}
			}
			idNode = copyID;
			//printf("achou\n");
			return true;
		}
		auxiliar = auxiliar -> previous;
	}
	return false;
}

/**
* Esta função imprime na tela nós que ID iguais, com a mesma cor;
@param i, é um inteiro que indica a cor que será pintada;
@param id, é um inteiro que é o identificador daquele nó;
@param father, é uma sequência de caractere que é o pai daquele nó;
@param children, é uma sequência de caractere que é o filho daquele nó;
@param value, é uma sequência de caractere onde vai ser o valor que pode ou não ter;
@return void, retorna nada.
*/
void printRepeatColor(int i, int id, char *father, char *children, char *value){
	if (i == 1){
		printf(RED_TEXT("ID: %d\n"), id);
		printf(RED_TEXT("Pai: %s\n"), father);
		printf(RED_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(RED_TEXT("Valor: %s\n"), value);		
		}
	} else if (i == 2){
		printf(GREEN_TEXT("ID: %d\n"), id);
		printf(GREEN_TEXT("Pai: %s\n"), father);
		printf(GREEN_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(GREEN_TEXT("Valor: %s\n"), value);		
		}
	} else if (i == 3){
		printf(YELLOW_TEXT("ID: %d\n"), id);
		printf(YELLOW_TEXT("Pai: %s\n"), father);
		printf(YELLOW_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(YELLOW_TEXT("Valor: %s\n"), value);		
		}
	} else if (i == 4){
		printf(BLUE_TEXT("ID: %d\n"), id);
		printf(BLUE_TEXT("Pai: %s\n"), father);
		printf(BLUE_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(BLUE_TEXT("Valor: %s\n"), value);		
		}
	} else if (i == 5){
		printf(MAGENTA_TEXT("ID: %d\n"), id);
		printf(MAGENTA_TEXT("Pai: %s\n"), father);
		printf(MAGENTA_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(MAGENTA_TEXT("Valor: %s\n"), value);		
		}
	} else if (i == 6){
		printf(CYAN_TEXT("ID: %d\n"), id);
		printf(CYAN_TEXT("Pai: %s\n"), father);
		printf(CYAN_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(CYAN_TEXT("Valor: %s\n"), value);		
		}	
	} else if (i == 7){
		printf(BOLD_RED_TEXT("ID: %d\n"), id);
		printf(BOLD_RED_TEXT("Pai: %s\n"), father);
		printf(BOLD_RED_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(BOLD_RED_TEXT("Valor: %s\n"), value);		
		}	
	} else if (i == 8){
		printf(BOLD_GREEN_TEXT("ID: %d\n"), id);
		printf(BOLD_GREEN_TEXT("Pai: %s\n"), father);
		printf(BOLD_GREEN_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(BOLD_GREEN_TEXT("Valor: %s\n"), value);		
		}	
	} else if (i == 9){
		printf(BOLD_YELLOW_TEXT("ID: %d\n"), id);
		printf(BOLD_YELLOW_TEXT("Pai: %s\n"), father);
		printf(BOLD_YELLOW_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(BOLD_YELLOW_TEXT("Valor: %s\n"), value);		
		}		
	} else if (i == 10){
		printf(BOLD_BLUE_TEXT("ID: %d\n"), id);
		printf(BOLD_BLUE_TEXT("Pai: %s\n"), father);
		printf(BOLD_BLUE_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(BOLD_BLUE_TEXT("Valor: %s\n"), value);		
		}			
	} else if (i == 11){
		printf(BOLD_MAGENTA_TEXT("ID: %d\n"), id);
		printf(BOLD_MAGENTA_TEXT("Pai: %s\n"), father);
		printf(BOLD_MAGENTA_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(BOLD_MAGENTA_TEXT("Valor: %s\n"), value);		
		}				
	} else if (i == 12){
		printf(BOLD_CYAN_TEXT("ID: %d\n"), id);
		printf(BOLD_CYAN_TEXT("Pai: %s\n"), father);
		printf(BOLD_CYAN_TEXT("Filho: %s\n"), children);
		if(compareString(value, "NULL") != 0){
			printf(BOLD_CYAN_TEXT("Valor: %s\n"), value);		
		}			
	}
	printf("\n");
}

/**
* Esta função verifica se o número de elementos repetidos tem a mesma quantidade de cores;
@param finalTree, é a estrutura onde está sendo montada a árvore sintática;
@return void, retorna nada.
*/
void printColor(pTree *finalTree){
	bool ehBranco;
	int repeat[SIZE], equal, soma, i = 0, j = 0, k;
	Node *auxiliar, *auxiliarNode;
	auxiliar = finalTree -> first;
	while(auxiliar != NULL){
		soma = 0;
		auxiliarNode = finalTree -> first;
		while(auxiliarNode != NULL){
			if(auxiliar -> id == auxiliarNode -> id){
				soma++;
			}
			auxiliarNode = auxiliarNode -> next;
		}
		if(soma > 1){
			if(i == 0){
				repeat[i] = auxiliar -> id;
				i++;
			} else {
				equal = 0;	
				for(j = 0; j < i; j++){
					if(repeat[j] == auxiliar -> id){
						equal = 1;
						break;
					}
				}
				if(equal == 0){
					repeat[i] = auxiliar -> id;
					i++;
				}
			}
		}
		auxiliar = auxiliar -> next;
	}
	if(i < 13){
		colorOutput x[i];
		k = 1;
		for(j = 0; j < i; j++){
			x[j].id = repeat[j];
			x[j].color = k;
			k++;
		}
		auxiliar = finalTree -> first;
		while(auxiliar != NULL){
			ehBranco = true;
			for(j = 0; j < i; j++){
				if(auxiliar -> id == x[j].id){
					printRepeatColor(x[j].color, auxiliar -> id, auxiliar -> father, auxiliar -> children, auxiliar -> value);
					ehBranco = false;
					break;
				}
			}
			if(ehBranco){
				printf("ID: %d\n", auxiliar -> id);
				printf("Pai: %s\n", auxiliar -> father);
				printf("Filho: %s\n", auxiliar -> children);
				if(compareString(auxiliar -> value, "NULL") != 0){				
					printf("Valor: %s\n", auxiliar -> value);	
				}
				printf("\n");
			}
			auxiliar = auxiliar -> next;
		}
	} else {
		printTree(finalTree);	
	}
}

/**
* Esta função elimina o espaço em branco e a quebra de linha;
@param line, é a sequência de caractere onde será eliminado;
@return void, retorna nada.
*/
void eliminateSpace(char *line){
	int i = 0;
	while(line[i] != '\0'){
		if((line[i] == ' ' && line[i + 1] == '\0') || (line[i] == '\n' && line[i + 1] == '\0')){
			line[i] = '\0';
		}
		i++;
	}
}

/**
* Esta função elimina o espaço em branco e a quebra de linha em todos o nós da saída;
@param out, é a estrutura onde está armazenada a saída;
@return void, retorna nada.
*/
void cleanOut(pTree *out){
	Node *auxiliar = out -> first;
	while(auxiliar != NULL){
		eliminateSpace(auxiliar -> step);
		auxiliar = auxiliar -> next;
	}
}		

/**
* Esta função constrói a árvore sintática;
@param bnf, é a estrutura onde está armazenada a BNF;
@param outTree, é a estrutura onde está armazenada a saída;
@return void, retorna nada.
*/
void buildTree(pTree *bnf, pTree *outTree){
	char step1[SIZE], step2[SIZE], father[SIZE];
	Node *auxiliar = outTree -> first;
	pTree *finalTree = (pTree*) malloc (sizeof(pTree));
	initializeTree(finalTree); 
	idNode = 1;
	/*auxiliar = outTree -> first;
	while(auxiliar != NULL){
		eliminateSpace(auxiliar -> step);
	//	printf("-> %s\n", auxiliar -> step);
		auxiliar = auxiliar -> next;
	}*/
	auxiliar = outTree -> first;
	while(auxiliar != NULL){
		if(auxiliar -> next == NULL){
			break;
		}
		strcpy(step1, auxiliar -> step);
		strcpy(step2, auxiliar -> next -> step);
		if(hasRule(bnf, step1, step2)){
			if(compareString(step1, "programa") == 0){
				//printf("a: %d\n", idNode);
				insertTree(finalTree, "NULL", step1, auxiliar -> next -> value);
				insertTree(finalTree, step1, step2, auxiliar -> next -> value);	
			} else {
				//printf("b: %d\n", idNode);
				insertTree(finalTree, step1, step2, auxiliar -> next -> value);					
			}
		} else {
			if(checkWords(finalTree, bnf, step1, step2, auxiliar -> next -> value) == false){
				if(backTree(bnf, finalTree, step2, auxiliar -> next -> value) == false){
					printf(BOLD_RED_TEXT("ERROR"));
				}
			}
		}
		memset(step1, 0, sizeof(step1));
		memset(step2, 0, sizeof(step2));
		auxiliar = auxiliar -> next;
	}
	cleanTree(finalTree);
	printf(BOLD_GREEN_TEXT("╔══════════════════════════════════╗\n"));
	printf(BOLD_GREEN_TEXT("║              CAMINHO             ║\n"));
	printf(BOLD_GREEN_TEXT("╚══════════════════════════════════╝\n"));
	cleanOut(outTree);
	printStepTree(outTree);
	printf(BOLD_GREEN_TEXT("╔══════════════════════════════════╗\n"));
	printf(BOLD_GREEN_TEXT("║         ÁRVORE SINTÁTICA         ║\n"));
	printf(BOLD_GREEN_TEXT("╚══════════════════════════════════╝\n"));
	printColor(finalTree);
	system("rm *.txt");
}

/**
* Esta função chamada as demais funções com a de construir a árvore sintática, ler o 
* arquivo de saída;
@param nenhum, não recebe nenhum parâmetro;
@return void, retorna nada.
*/
void printTreeSyntactic(){
	system("reset");
	int start, end;
	FILE *parser = fopen(bnftplusplus, "r");
	pTree *bnf = (pTree*) malloc (sizeof(pTree));
	pTree *outTree = (pTree*) malloc (sizeof(pTree));
	start = getStart(parser);
	fclose(parser);

	parser = fopen(bnftplusplus, "r");
	end = getEnd(parser);
	fclose(parser);

	initializeTree(bnf);
	copyBNF(start, end, bnf);
	clearBNF(bnf);

	initializeTree(outTree);
	copyOutput(outTree);

	buildTree(bnf, outTree);
}


