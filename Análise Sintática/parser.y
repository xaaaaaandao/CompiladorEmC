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

%type <pgm> programa lista_declaracoes declaracao declaracao_variaveis inicializacao_variaveis lista_variaveis var indice tipo declaracao_funcao cabecalho lista_parametros parametro corpo acao se repita escreva retorna expressao expressao_simples expressao_aditiva expressao_multiplicativa expressao_unaria operador_relacional operador_soma operador_multiplicacao fator numero chamada_funcao lista_argumentos leia atribuicao

%% 
programa:
	lista_declaracoes;

lista_declaracoes:
	lista_declaracoes declaracao
	| declaracao;

declaracao:
	declaracao_variaveis
	| inicializacao_variaveis
	| declaracao_funcao;

declaracao_variaveis:
	tipo DOISPONTOS lista_variaveis;

inicializacao_variaveis:
	atribuicao;

lista_variaveis:
	lista_variaveis VIRGULA var
	| var;

var:
	IDENTIFICADOR
	| IDENTIFICADOR indice;

indice:
	indice ABRECOLCHETE expressao FECHACOLCHETE
	| ABRECOLCHETE expressao FECHACOLCHETE;

tipo:
	TIPOINTEIRO
	| TIPOFLUTUANTE;

declaracao_funcao:
	tipo cabecalho
	| cabecalho;

cabecalho:
	IDENTIFICADOR ABREPARENTESES lista_parametros FECHAPARENTESES corpo FIM;

lista_parametros:
	lista_parametros VIRGULA parametro
	| parametro;

parametro:
	tipo DOISPONTOS IDENTIFICADOR
	| parametro ABRECOLCHETE FECHACOLCHETE;

corpo:
	corpo acao;

acao:
	expressao | declaracao_variaveis
	| se | repita | leia | escreva | retorna;

se:
	SE expressao ENTAO corpo FIM
	| SE expressao ENTAO corpo SENAO corpo FIM;

repita:
	REPITA corpo ATE expressao;

atribuicao:
	var ATRIBUICAO expressao;

leia:
	LEIA ABREPARENTESES IDENTIFICADOR FECHAPARENTESES;

escreva:
	ESCREVA ABREPARENTESES expressao FECHAPARENTESES;

retorna:
	RETORNA ABREPARENTESES "expressao" FECHAPARENTESES;

expressao:
	expressao_simples
	| "atribuicao";

expressao_simples:
	expressao_aditiva
	| expressao_simples operador_relacional expressao_aditiva;

expressao_aditiva:
	expressao_multiplicativa
	| expressao_aditiva operador_soma expressao_multiplicativa;

expressao_multiplicativa:
	expressao_unaria
	| expressao_multiplicativa operador_multiplicacao expressao_unaria;

expressao_unaria:
	fator
	| operador_soma fator;

operador_relacional:
	MENOR | MAIOR | IGUAL | DIFERENTE | MENORIGUAL | MAIORIGUAL;

operador_soma:
	ADICAO | SUBTRACAO;

operador_multiplicacao:
	MULTIPLICACAO | DIVISAO;

fator:
	ABREPARENTESES expressao FECHAPARENTESES
	| var
	| chamada_funcao
	| numero;

numero:
	NUMEROINTEIRO
	| NUMEROFLUTUANTE
	| EXPONENCIAL;

chamada_funcao:
	IDENTIFICADOR ABREPARENTESES lista_argumentos FECHAPARENTESES;

lista_argumentos:
	lista_argumentos VIRGULA expressao
	| expressao;
%%
void yyerror(char *s) {
	fprintf(stdout, "%s\n", s);
}

int main(int argc, char *argv[]){
	/*
		-> precisar ter uma expressão para o comentário?
		-> como fazer com a expressão vazio?
	*/
	yyin = fopen(argv[1], "r");
	yyparse();	
	fclose(yyin);
	return 0;
}

