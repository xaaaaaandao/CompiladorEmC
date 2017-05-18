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

	//printTree(bnf);
	initializeTree(outTree);
	copyOutput(outTree);	
	printStepTree(outTree);
}

