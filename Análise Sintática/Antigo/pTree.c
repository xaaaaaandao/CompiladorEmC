#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pTree.h"
#include "files.h"

/**
* Esta função inicializa a pseudo-árvore;
@param tree, a estrutura da pseudo-árvore;
@return void, retorna nada.
*/
void initializeTree(pTree *tree){
	tree -> first = NULL;
	tree -> last = NULL;
	tree -> size = 0;
}

/**
* Esta função verifica se a pseudo-árvore está vazia;
@param tree, a estrutura da pseudo-árvore;
@return inteiro, retorna verdade ou não caso esteja vazio a pseudo-árvore.
*/
int emptyTree(pTree *tree){
	return (tree -> first == NULL);
}  

/**
* Esta função insere no final da pseudo-árvore;
@param tree, a estrutura da pseudo-árvore;
@param father, a sequência de caracetere que será inserido;
@param children, a sequência de caracetere que será inserido;
@param value, a sequência de caracetere que será inserido;
@return void, retorna nada.
*/
void insertTree(pTree *tree, char* father, char* children, char *value){
	Node *newNode = (Node *) malloc(sizeof(Node));
	strcpy(newNode -> father, father);
	strcpy(newNode -> children, children);	
	strcpy(newNode -> value, value);	

	newNode -> id = idNode;
	newNode -> previous = NULL;
	newNode -> next = NULL;

	if (emptyTree(tree)){
		tree -> first = newNode;
		tree -> last = newNode;
	} else {
		newNode -> previous = tree -> last;
		tree -> last -> next = newNode;
		tree -> last = newNode;

	}
	idNode++;	
	tree -> size++;
}
 
/**
* Esta função insere no começo da pseudo-árvore;
@param tree, a estrutura da pseudo-árvore;
@param step, a sequência de caracetere que será inserido;
@param value, a sequência de caracetere que será inserido;
@return void, retorna nada.
*/
void insertFirstTree(pTree *tree, char* step, char *value){
	Node *newNode = (Node *) malloc(sizeof(Node));
	Node *auxiliar = tree -> first;
	newNode -> next = NULL;
	newNode -> previous = NULL;
	strcpy(newNode -> step, step);
	strcpy(newNode -> value, value);
	
	if(emptyTree(tree)){
		tree -> first = newNode;
		tree -> last = newNode;
	} else {
		auxiliar ->  previous = newNode;
		newNode -> next = auxiliar;
		tree -> first = newNode;
	}

	tree -> size++;
}

/**
* Esta função retorna o tamanho da pseudo-árvore;
@param tree, a estrutura da pseudo-árvore;
@return inteiro, retorna o tamanho da pseudo-árvore.
*/
int sizeTree(pTree *tree){
	return (tree -> size);
}

/**
* Esta função imprime a pseudo-árvore;
@param tree, a estrutura da pseudo-árvore;
@return void, retorna nada.
*/
void printTree(pTree *tree){
	if (emptyTree(tree)){
		printf("Empty tree!");
	} else {
		Node *printNode;
		printNode = tree -> first;
		while (printNode != NULL){
			printf("ID: %d \n", printNode -> id);
			printf("Pai: %s \n", printNode -> father);
			printf("Filho: %s \n", printNode -> children);
			if(compareString(printNode -> value, "NULL") != 0){
				printf("Valor: %s\n", printNode -> value);
			} 
			printf("\n");
			printNode = printNode -> next;
		}
	}    
}

/**
* Esta função imprime o caminho percorrido da pseudo-árvore;
@param tree, a estrutura da pseudo-árvore;
@return void, retorna nada.
*/
void printStepTree(pTree *tree){
	if (emptyTree(tree)){
		printf("Empty tree!");
	} else {
		Node *printNode;
		printNode = tree -> first;
		while (printNode != NULL){
			if(compareString(printNode -> value, "NULL") == 0){
				printf("%s\n", printNode -> step);	
			} else {
				printf("%s (%s)\n", printNode -> step, printNode -> value);					
			}
			printNode = printNode -> next;
		}
	}    
}

/**
* Esta função retira quebras de linhas de caractere dos nós da pseudo-árvore;
@param tree, a estrutura da pseudo-árvore;
@return void, retorna nada.
*/
void cleanTree(pTree *tree){
	char father[SIZE], children[SIZE], newChildren[SIZE];
	Node *auxiliar = tree -> first;
	int i = 0, j = 0, fim = -1;
	while(auxiliar != NULL){
		strcpy(father, auxiliar -> father);
		strcpy(children, auxiliar -> children);
		i = 0;
		j = 0;
		fim = -1;
		while(children[i] != '\0'){
			if(children[i] == ' '){
				newChildren[j] = '\0';
				if(compareString(newChildren, father) == 0){
					fim = i;
					break;
				}
			} else {
				newChildren[j] = children[i];
				j++;
			}
			i++;
		}
		if(fim > -1){
			fim++;
			i = 0;
			memset(newChildren, 0, sizeof(newChildren));
			while(children[fim] != '\0'){
				newChildren[i] = children[fim];
				i++;
				fim++;
			}
			newChildren[i] = '\0';
			//printf("newChildren: %s\n", newChildren);
			strcpy(auxiliar -> children, newChildren);
		}
		auxiliar = auxiliar -> next;
	}
	auxiliar = tree -> first;
	while(auxiliar != NULL){
		i = 0;
		while(auxiliar -> father[i] != '\0'){
			if(auxiliar -> father[i] == '\n'){
				auxiliar -> father[i] = '\0';
				break;
			}
			i++;
		}
		i = 0;
		while(auxiliar -> children[i] != '\0'){
			if(auxiliar -> children[i] == '\n'){
				auxiliar -> children[i] = '\0';
				break;
			}
			i++;
		}
		auxiliar = auxiliar -> next;
	}
}
