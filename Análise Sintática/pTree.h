#ifndef PTREE_H
#define	PTREE_H

#define SIZE 32768

typedef struct node{
	char father[SIZE];
	char children[SIZE];
	char step[SIZE];
	struct node *previous;
	struct node *next;
}Node;

typedef struct{
	Node *first, *last;
	int size;
}pTree;

void initializeTree(pTree*);
int emptyTree(pTree*);
void insertTree(pTree*, char*, char*);
void insertFirstTree(pTree*, char*);
int sizeTree(pTree*);
void printTree(pTree*);
void printStepTree(pTree*);

#endif /* FILES_H */
