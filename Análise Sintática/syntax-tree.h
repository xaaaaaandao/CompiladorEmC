#define MAX 3276

struct arvore {
    char string[MAX];
    struct arvore *proximo;
    struct arvore *filho;
};

typedef struct arvore Arvore;
