#include <stdio.h>
#include <stdlib.h>
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

void copyBNF(int start, int end){
	char line[SIZE];
	FILE *parser = fopen(bnftplusplus, "r");
	int i = 0;
	end --;
	while(fgets(line, sizeof(line), parser) != NULL){
		if(i >= start && i < end){
			printf("%s\n", line);
			memset(line, 0, sizeof(line));
		} else if(i >= end){
			break;
		}
		i++;
	}
	fclose(parser);
}

void printTreeSyntactic(){
	int start, end;
	FILE *parser = fopen(bnftplusplus, "r");
	start = getStart(parser);
	fclose(parser);
	printf("%d\n", start);
	parser = fopen(bnftplusplus, "r");
	end = getEnd(parser);
	fclose(parser);
	printf("%d\n", end);
	copyBNF(start, end);
}

