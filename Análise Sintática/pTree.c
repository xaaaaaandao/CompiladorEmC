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

void insertTree(pTree *tree, char* input){
	Node *newNode = (Node *) malloc(sizeof(Node));
	strcpy(newNode -> input, input);
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
			printf("File: %s \n", printNode -> input);
			printNode = printNode -> next;
		}
	}    
}
