#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "files.h"

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
				insertTree(bnf, father, children);
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

void copyOutput(pTree *outTree){
	FILE *out = fopen(outputprogram, "r");
	char line[SIZE];
	while(fgets(line, sizeof(line), out) != NULL){
		insertFirstTree(outTree, line);
		//printf("%s\n", line);
	}
	insertFirstTree(outTree, "programa");
	fclose(out);
}

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

bool checkWords(pTree *finalTree, pTree *bnf, char *step1, char *step2){
	char word[SIZE];
	int i = 0, j = 0;
	while(step1[i] != '\0'){
		if(step1[i] ==  ' '){
			word[j] = '\0';
			if(hasFather(bnf, word)){
				if(hasRule(bnf, word, step2)){
					//printf("w: %s\n", word);
					//printf("s: %s\n", step2);
					insertTree(finalTree, word, step2);
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
		//	printf("w: %s\n", word);
		//	printf("s: %s\n", step2);
			insertTree(finalTree, word, step2);
			return true;
		}
	}
	return false;
}

bool backTree(pTree *bnf, pTree *finalTree, char *step){
	Node *auxiliar = finalTree -> last;
	while(auxiliar != NULL){
		if(checkWords(finalTree, bnf, auxiliar -> children, step)){
			finalTree -> last -> id = auxiliar -> id;					
			return true;
		}
		auxiliar = auxiliar -> previous;
	}
	return false;
}

void buildTree(pTree *bnf, pTree *outTree){
	char step1[SIZE], step2[SIZE], father[SIZE];
	Node *auxiliar = outTree -> first;
	pTree *finalTree = (pTree*) malloc (sizeof(pTree));
	initializeTree(finalTree); 
	while(auxiliar != NULL){
		if(auxiliar -> next == NULL){
			break;
		}
		strcpy(step1, auxiliar -> step);
		strcpy(step2, auxiliar -> next -> step);
		printf("%s\n", step1);
		printf("%s\n", step2);
		printf("===========\n");
		memset(step1, 0, sizeof(step1));
		memset(step2, 0, sizeof(step2));
		auxiliar = auxiliar -> next;
	}
	idNode = 1;
	auxiliar = outTree -> first;
	while(auxiliar != NULL){
		if(auxiliar -> next == NULL){
			break;
		}
		strcpy(step1, auxiliar -> step);
		strcpy(step2, auxiliar -> next -> step);
		if(hasRule(bnf, step1, step2)){
			if(compareString(step1, "programa") == 0){
				insertTree(finalTree, "NULL", step1);	
			} else {
				insertTree(finalTree, step1, step2);					
			}
		} else {
			if(checkWords(finalTree, bnf, step1, step2) == false){
				if(backTree(bnf, finalTree, step2) == false){
					printf("err\n");
				}
					//printf("dsaadsdsa\n");
					//printf("%s\n", step1);
					///printf("%s\n", step2);
					//printf("===========\n");
					//break;
			}
		}
		memset(step1, 0, sizeof(step1));
		memset(step2, 0, sizeof(step2));
		//printf("%s\n", step1);
		//printf("%s\n", step2);
		//printf("===========\n");
		auxiliar = auxiliar -> next;
	}
	printTree(finalTree);
}

void printTreeSyntactic(){
	//system("clear");
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

//	printTree(bnf);
	initializeTree(outTree);
	copyOutput(outTree);

	buildTree(bnf, outTree);
	//printStepTree(outTree);
}

