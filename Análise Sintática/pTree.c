#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pTree.h"

void initializeTree(pTree *tree){
	tree -> first = NULL;
	tree -> last = NULL;
	tree -> size = 0;
}

int emptyTree(pTree *tree){
	return (tree -> first == NULL);
}  

void insertTree(pTree *tree, char* father, char* children){
	Node *newNode = (Node *) malloc(sizeof(Node));
	strcpy(newNode -> father, father);
	strcpy(newNode -> children, children);	
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
 
void insertFirstTree(pTree *tree, char* step){
	Node *newNode = (Node *) malloc(sizeof(Node));
	Node *auxiliar = tree -> first;
	newNode -> next = NULL;
	newNode -> previous = NULL;
	strcpy(newNode -> step, step);
	
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

int sizeTree(pTree *tree){
	return (tree -> size);
}

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
			printNode = printNode -> next;
		}
	}    
}

void printStepTree(pTree *tree){
	if (emptyTree(tree)){
		printf("Empty tree!");
	} else {
		Node *printNode;
		printNode = tree -> first;
		while (printNode != NULL){ 
			printf("Passo: %s \n", printNode -> step);
			printNode = printNode -> next;
		}
	}    
}