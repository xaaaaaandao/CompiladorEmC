#define MAX 3276

struct arvore {
    unsigned long int p;
    unsigned long int f;
    char string[MAX];
    struct arvore *proximo;
    struct arvore *filho;
};

typedef struct arvore Arvore;
