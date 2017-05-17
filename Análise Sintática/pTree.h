#ifndef PTREE_H
#define	PTREE_H

#define SIZE 32768

typedef struct node{
	char input[SIZE];
	struct node *next;
}Node;

typedef struct{
	Node *first, *last;
	int size;
}pTree;

void initializeTree(pTree*);
int emptyTree(pTree*);
void insertTree(pTree*, char*);
int sizeTree(pTree*);
void printTree(pTree*);

#endif /* FILES_H */
