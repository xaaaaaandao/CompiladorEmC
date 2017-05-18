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
	newNode -> next = NULL;

	if (emptyTree(tree)){
		tree -> first = newNode;
		tree -> last = newNode;
	} else {
		tree -> last -> next = newNode;
		tree -> last = newNode;
	}
	
	tree -> size++;
}
 
void insertFirstTree(pTree *tree, char* step){
	Node *newNode = (Node *) malloc(sizeof(Node));
	Node *auxiliar = tree -> first;
	strcpy(newNode -> step, step);
	
	tree -> first = newNode;
	newNode -> next = auxiliar;
	tree -> size++;
}

int sizeTree(pTree *tree){
	return (tree -> size);
}

void printTree(pTree *tree){
	if (emptyTree(tree)){
		printf("Empty pTree!");
	} else {
		Node *printNode;
		printNode = tree -> first;
		while (printNode != NULL){ 
			printf("Pai: %s \n", printNode -> father);
			printf("Filho: %s \n", printNode -> children);
			printNode = printNode -> next;
		}
	}    
}

void printStepTree(pTree *tree){
	if (emptyTree(tree)){
		printf("Empty pTree!");
	} else {
		Node *printNode;
		printNode = tree -> first;
		while (printNode != NULL){ 
			printf("Passo: %s \n", printNode -> step);
			printNode = printNode -> next;
		}
	}    
}