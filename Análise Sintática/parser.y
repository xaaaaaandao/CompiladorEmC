%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include "syntax-tree.h"

	/* Protótipos */
	int yylex(void);
	void yyerror(char *s);
	extern FILE *yyin;
	extern FILE *yyout;
%}

%union	{
	char pgm[100];
	char simbolo[3];
	char tipo[10];
	char identificador[3276];	
	char reservada[3276];
	char comentario[3276];
};
%start programa

%token <pgm> SE ENTAO SENAO FIM REPITA RETORNA ATE LEIA ESCREVA TIPOINTEIRO TIPOFLUTUANTE TIPOVOID IDENTIFICADOR NUMEROINTEIRO NUMEROFLUTUANTE EXPONENCIAL COMENTARIO IGUAL DOISPONTOS ATRIBUICAO MENOR MENORIGUAL MAIOR MAIORIGUAL DIFERENTE ABREPARENTESES FECHAPARENTESES ABRECHAVE FECHACHAVE VIRGULA ADICAO SUBTRACAO MULTIPLICACAO DIVISAO ABRECOLCHETE FECHACOLCHETE END_OF_FILE

%type <pgm> programa comentario declaracao_funcao tipo_funcao

%% 
programa:
	/* empty */
	comentario
	| programa comentario
	| declaracao_funcao
	| programa declaracao_funcao;

comentario: COMENTARIO {strcpy($$, $1);};

declaracao_funcao:
	tipo_funcao DOISPONTOS { printf("%s %s\n", $1, $2); };

tipo_funcao:
	TIPOINTEIRO {strcpy($$, $1);}
	| TIPOFLUTUANTE {strcpy($$, $1);}
	| TIPOVOID {strcpy($$, $1);};

%%
void yyerror(char *s) {
	fprintf(stdout, "%s\n", s);
}

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	yyparse();	
	fclose(yyin);
	return 0;
}

