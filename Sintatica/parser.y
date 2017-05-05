%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdarg.h>
  #include "syntax-tree.h"

  /* Protótipos */
  nodeType *opr(int oper, int nops, ...);
  nodeType *id(int i);
  nodeType *con(int value);
  void freeNode(nodeType *p);
  int ex(nodeType *p);

  int yylex(void);
  void yyerror(char *s);
  int sym[26];	/* Tabela de Símbolos. */

  extern FILE *yyin;
	extern FILE *yyout;
%}

%union	{
	int iValue;		/* Valor inteiro. */
	char sIndex;	/*Indice da Tabela de Símbolos. */
	nodeType *nPtr;	/* Node Pointer. */
};

%token  END_OF_FILE NUMEROINTEIRO NUMEROFLUTUANTE IDENTIFICADOR RESERVADA IGUAL DOISPONTOS ATRIBUICAO MENOR MENORIGUAL MAIOR MAIORIGUAL DIFERENTE ABREPARENTESES FECHAPARENTESES ABRECHAVE FECHACHAVE VIRGULA MAIS MENOS MULTIPLICACAO DIVISAO COMENTARIO_NAO_FINALIZADO SE ENTAO SENAO FIM REPITA INTEIRO RETORNA ATE LEIA ESCREVA FLUTUANTE EXPONENCIAL COMENTARIO ABRECOLCHETE FECHACOLCHETE

%left '+' '-' 
%left '*' '/'

%% 
programa:
	lista_declaracoes;

lista_declaracoes:
	lista_declaracoes declaracao | declaracao;

declaracao:
	declaracao_variavel declaracao_funcao | variavel;

declaracao_variavel:
	declaracao_variavel "variavel" | "variavel";

variavel:
	tipo DOISPONTOS var;

var:
	var ',' IDENTIFICADOR
	| IDENTIFICADOR '[' NUMEROINTEIRO ']'
	| IDENTIFICADOR '[' NUMEROINTEIRO ']' '[' NUMEROINTEIRO ']'
	| IDENTIFICADOR;

tipo:
	INTEIRO | FLUTUANTE;

declaracao_funcao:
	"declaracao_funcao" funcao
	| funcao;

funcao: tipo IDENTIFICADOR "(" declaracao_parametros ")" declaracao_composta FIM
	| tipo IDENTIFICADOR "(" declaracao_parametros ")" FIM;

declaracao_parametros:
	lista_parametros;

lista_parametros:
	lista_parametros ',' parametro | parametro;

parametro: 
	tipo DOISPONTOS IDENTIFICADOR '[' NUMEROINTEIRO ']'
	| tipo DOISPONTOS IDENTIFICADOR '[' NUMEROINTEIRO ']' '[' NUMEROINTEIRO ']'
	| tipo DOISPONTOS IDENTIFICADOR;

declaracao_composta:
	declaracoes_locais
	| lista_statements;

declaracoes_locais:
	"declaracoes_locais" declaracao_variavel;

lista_statements:
	"lista_statements" statement | statement;

statement:
 	declaracao_selecao
	| declaracao_iteracao
	| declaracao_atribuicao
	| declaracao_leitura
	| declaracao_escrita
	| declaracao_retorno;

declaracao_selecao:
	SE ENTAO lista_statements FIM
	| SE ENTAO lista_statements SENAO lista_statements FIM;

declaracao_iteracao:
	REPITA lista_statements ATE;

declaracao_atribuicao:
	var ":=" expressao;

declaracao_leitura:
	LEIA '(' IDENTIFICADOR ')';

declaracao_escrita:
	ESCREVA '(' expressao ')';

declaracao_retorno:
	RETORNA '(' expressao ')';

expressao:
	expressao_simples | chamada_funcao;

expressao_simples:
	unario expressao_soma operador_relacional expressao_soma | expressao_soma;

unario:
	operador_soma expressao;

operador_relacional:
	MAIOR | MENOR | MAIORIGUAL | MENORIGUAL | DIFERENTE;

expressao_soma:
	expressao_soma operador_soma termo | termo;

operador_soma:
	MAIS | MENOS;

termo:
	termo operador_multiplicacao fator | fator;

operador_multiplicacao:
	'*' | '/';

fator:
	'(' expressao ')' | numero | IDENTIFICADOR;

numero:
	NUMEROINTEIRO | NUMEROFLUTUANTE | EXPONENCIAL;

chamada_funcao:
	"IDENTIFICADOR" '(' lista_argumentos ')';

lista_argumentos:
	lista_argumentos ',' expressao | expressao;

%%
//fazer comentario!!
//como fazer com o vazio?
//como fazer com os main?

#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)

/* Constante. */
nodeType *con(int value) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeCon;
	p->con.value = value;
	return p;
}

/* Identificador. */
nodeType *id(int i) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeId;
	p->id.i = i;
	return p;
}

nodeType *opr(int oper, int nops, ...) {
	va_list ap;
	nodeType *p;
	int i;
	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, nodeType*);
	va_end(ap);
	return p;
}

void freeNode(nodeType *p) {
	int i;
	if (!p) return;
	if (p->type == typeOpr) {
		for (i = 0; i < p->opr.nops; i++)
			freeNode(p->opr.op[i]);
	}
	free (p);
}

void yyerror(char *s) {
	fprintf(stdout, "%s\n", s);
}

/*int main(void) {
	yyparse();
	return 0;
}*/

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	
	yyparse();
	
	fclose(yyin);

	return 0;
}
