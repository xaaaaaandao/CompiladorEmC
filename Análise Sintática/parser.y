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
	char pgm[32768];
};
%start programa

%token <pgm> SE ENTAO SENAO FIM REPITA RETORNA ATE LEIA ESCREVA TIPOINTEIRO TIPOFLUTUANTE TIPOVOID IDENTIFICADOR NUMEROINTEIRO NUMEROFLUTUANTE EXPONENCIAL COMENTARIO IGUAL DOISPONTOS ATRIBUICAO MENOR MENORIGUAL MAIOR MAIORIGUAL DIFERENTE ABREPARENTESES FECHAPARENTESES ABRECHAVE FECHACHAVE VIRGULA ADICAO SUBTRACAO MULTIPLICACAO DIVISAO ABRECOLCHETE FECHACOLCHETE END_OF_FILE

%% 
programa:
	lista_declaracoes {printf("programa\n");}
	;

lista_declaracoes:
	lista_declaracoes declaracao {printf("lista_declaracoes declaracao\n");}
	| declaracao {printf("declaracao\n");}
	;

declaracao:
	declaracao_variaveis {printf("declaracao_variaveis\n");}
	| inicializacao_variaveis {printf("inicializacao_variaveis\n");}
	| declaracao_funcao {printf("declaracao_funcao\n");}
	;

declaracao_variaveis:
	tipo DOISPONTOS lista_variaveis {printf("tipo DOISPONTOS lista_variaveis\n");}
	;

inicializacao_variaveis:
	atribuicao {printf("atribuicao\n");}
	;

lista_variaveis:
	lista_variaveis VIRGULA var {printf("lista_variaveis VIRGULA var\n");}
	| var {printf("var\n");}
	;

var:
	IDENTIFICADOR {printf("IDENTIFICADOR\n");}
	| IDENTIFICADOR indice {printf("IDENTIFICADOR indice\n");}
	;

indice:
	indice ABRECOLCHETE expressao FECHACOLCHETE {printf("indice ABRECOLCHETE expressao FECHACOLCHETE\n");}
	| ABRECOLCHETE expressao FECHACOLCHETE {printf("ABRECOLCHETE expressao FECHACOLCHETE\n");}
	;

tipo:
	TIPOINTEIRO {printf("TIPOINTEIRO\n");}
	| TIPOFLUTUANTE {printf("flutuante\n");}
	;

declaracao_funcao:
	tipo cabecalho {printf("tipo cabecalho\n");}
	| cabecalho {printf("cabecalho\n");}
	;

cabecalho:
	IDENTIFICADOR ABREPARENTESES lista_parametros FECHAPARENTESES corpo FIM {printf("IDENTIFICADOR ABREPARENTESES lista_parametros FECHAPARENTESES corpo FIM\n"); }
	| 	IDENTIFICADOR ABREPARENTESES FECHAPARENTESES corpo FIM {printf("IDENTIFICADOR ABREPARENTESES FECHAPARENTESES corpo FIM\n"); }
	;

lista_parametros:
	lista_parametros VIRGULA parametro {printf("lista_parametros VIRGULA parametro\n");}
	| parametro {printf("parametro\n");}
	;

parametro:
	tipo DOISPONTOS IDENTIFICADOR {printf("tipo DOISPONTOS IDENTIFICADOR\n");}
	| parametro ABRECOLCHETE FECHACOLCHETE{printf("parametro ABRECOLCHETE FECHACOLCHETE\n");}
	;

corpo:
	acao {printf("acao\n");}
	| corpo acao {printf("corpo acao\n");};

acao:
	expressao {printf("expressao\n");}
	| declaracao_variaveis {printf("declaracao_variaveis\n");}
	| se {printf("se\n");}
	| repita {printf("repita\n");}
	| leia {printf("leia\n");}
	| escreva {printf("escreva\n");}
	| retorna {printf("retorna\n");};

se:
	SE expressao ENTAO corpo FIM {printf("SE expressao ENTAO corpo FIM\n");}
	| SE expressao ENTAO corpo SENAO corpo FIM {printf("SE expressao ENTAO corpo SENAO corpo FIM\n");}
	;

repita:
	REPITA corpo ATE expressao {printf("REPITA corpo ATE expressao\n");}
	;

atribuicao:
	var ATRIBUICAO expressao{printf("var ATRIBUICAO expressao\n");}
	;

leia:
	LEIA ABREPARENTESES IDENTIFICADOR FECHAPARENTESES{printf("LEIA ABREPARENTESES IDENTIFICADOR FECHAPARENTESES\n");}
	;

escreva:
	ESCREVA ABREPARENTESES expressao FECHAPARENTESES{printf("ESCREVA ABREPARENTESES expressao FECHAPARENTESES\n");}
	;

retorna:
	RETORNA ABREPARENTESES expressao FECHAPARENTESES{printf("RETORNA ABREPARENTESES expressao FECHAPARENTESES\n");}
	;

expressao:
	atribuicao {printf("atribuicao\n");}
	| expressao_simples {printf("expressao_simples\n");}
	;

expressao_simples:
	expressao_aditiva {printf("expressao_aditiva\n");}
	| expressao_simples operador_relacional expressao_aditiva {printf("expressao_simples operador_relacional expressao_aditiva\n");}
	; 

expressao_aditiva:
	expressao_multiplicativa {printf("expressao_multiplicativa\n");}
	| expressao_aditiva operador_soma expressao_multiplicativa {printf("expressao_aditiva operador_soma expressao_multiplicativa\n");}
	;

expressao_multiplicativa:
	expressao_unaria {printf("expressao_unaria\n");}
	| expressao_multiplicativa operador_multiplicacao expressao_unaria{printf("expressao_multiplicativa operador_multiplicacao expressao_unaria\n");}
	;

expressao_unaria:
	fator {printf("fator \n");}
	| operador_soma fator {printf("operador_soma fator\n");}
	;

operador_relacional:
	MENOR {printf("MENOR\n");}
	| MAIOR {printf("MAIOR\n");}
	| IGUAL {printf("IGUAL\n");}
	| DIFERENTE {printf("DIFERENTE\n");}
	| MENORIGUAL {printf("MENORIGUAL\n");}
	| MAIORIGUAL{printf("MAIORIGUAL\n");}
	; 

operador_soma:
	ADICAO {printf("ADICAO\n");}
	| SUBTRACAO {printf("SUBTRACAO\n");}
	;

operador_multiplicacao:
	MULTIPLICACAO {printf("MULTIPLICACAO\n");}
	| DIVISAO {printf("DIVISAO\n");}
	;

fator:
	ABREPARENTESES expressao FECHAPARENTESES {printf("ABREPARENTESES expressao FECHAPARENTESES\n");}
	| var {printf("var\n");}
	| chamada_funcao {printf("chamada_funcao\n");}
	| numero {printf("numero\n");}
	;

numero:
	NUMEROINTEIRO {printf("NUMEROINTEIRO\n");}
	| NUMEROFLUTUANTE {printf("NUMEROFLUTUANTE\n");}
	| EXPONENCIAL {printf("EXPONENCIAL\n");}
	;

chamada_funcao:
	IDENTIFICADOR ABREPARENTESES lista_argumentos FECHAPARENTESES {printf("IDENTIFICADOR ABREPARENTESES lista_argumentos FECHAPARENTESES\n");}
	;

lista_argumentos:
	lista_argumentos VIRGULA expressao {printf("lista_argumentos VIRGULA expressao\n");}
	| expressao {printf("expressao\n");}
	;

%%
void yyerror(char *s) {
	fprintf(stdout, "%s\n", s);
}

int main(int argc, char *argv[]){
	/*
		-> precisar ter uma expressão para o comentário?
		-> como fazer com a expressão vazio & erro?
	*/
	yyin = fopen(argv[1], "r");
	yyparse();	
	fclose(yyin);
	return 0;
}

