#ifndef FILES_H
#define	FILES_H

#define BLACK_TEXT(x) "\033[30;1m" x "\033[0m"
#define RED_TEXT(x) "\033[31;1m" x "\033[0m"
#define GREEN_TEXT(x) "\033[32;1m" x "\033[0m"
#define YELLOW_TEXT(x) "\033[33;1m" x "\033[0m"
#define BLUE_TEXT(x) "\033[34;1m" x "\033[0m"
#define MAGENTA_TEXT(x) "\033[35;1m" x "\033[0m"
#define CYAN_TEXT(x) "\033[36;1m" x "\033[0m"
#define WHITE_TEXT(x) "\033[37;1m" x "\033[0m"
#define BOLD_BLACK_TEXT(x) "\033[1m\033[30m" x "\033[0m"
#define BOLD_RED_TEXT(x) "\033[1m\033[31m" x "\033[0m"
#define BOLD_GREEN_TEXT(x) "\033[1m\033[32m" x "\033[0m"
#define BOLD_YELLOW_TEXT(x) "\033[1m\033[33m" x "\033[0m"
#define BOLD_BLUE_TEXT(x) "\033[1m\033[34m" x "\033[0m"
#define BOLD_MAGENTA_TEXT(x) "\033[1m\033[35m" x "\033[0m"
#define BOLD_CYAN_TEXT(x) "\033[1m\033[36m" x "\033[0m"
#define BOLD_WHITE_TEXT(x) "\033[1m\033[37m" x "\033[0m"

#define bnftplusplus "parser.y"
#define startbnftplusplus "//start"
#define endbnftplusplus "//end"
#define outputprogram "output.txt"

#include "pTree.h"

int compareString(char[], char[]);
void printTreeSyntactic();

typedef struct{
	int color;
	int id;
}colorOutput;

#endif /* FILES_H */

