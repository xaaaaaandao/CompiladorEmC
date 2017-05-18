%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include "syntax-tree.h"
	#include "pTree.h"
	#include "files.h"

	/* Protótipos */
	FILE *output;
	int yylex(void);
	void yyerror(char *s);
	extern FILE *yyin;
	extern FILE *yyout;
%}

%union	{
	char pgm[32768];
};
%start programa

%token <pgm> SE ENTAO SENAO FIM REPITA RETORNA ATE LEIA ESCREVA TIPOINTEIRO TIPOFLUTUANTE TIPOVOID IDENTIFICADOR NUMEROINTEIRO NUMEROFLUTUANTE EXPONENCIAL IGUAL DOISPONTOS ATRIBUICAO MENOR MENORIGUAL MAIOR MAIORIGUAL DIFERENTE ABREPARENTESES FECHAPARENTESES ABRECHAVE FECHACHAVE VIRGULA ADICAO SUBTRACAO MULTIPLICACAO DIVISAO ABRECOLCHETE FECHACOLCHETE END_OF_FILE

%% 
//start
programa:
	lista_declaracoes {fprintf(output, "lista_declaracoes\n");}
	;

lista_declaracoes:
	lista_declaracoes declaracao {fprintf(output, "lista_declaracoes declaracao\n");}
	| declaracao {fprintf(output, "declaracao\n");}
	;

declaracao:
	declaracao_variaveis {fprintf(output, "declaracao_variaveis\n");}
	| inicializacao_variaveis {fprintf(output, "inicializacao_variaveis\n");}
	| declaracao_funcao {fprintf(output, "declaracao_funcao\n");}
	;

declaracao_variaveis:
	tipo DOISPONTOS lista_variaveis {fprintf(output, "tipo DOISPONTOS lista_variaveis\n");}
	;

inicializacao_variaveis:
	atribuicao {fprintf(output, "atribuicao\n");}
	;

lista_variaveis:
	lista_variaveis VIRGULA var {fprintf(output, "lista_variaveis VIRGULA var\n");}
	| var {fprintf(output, "var\n");}
	;

var:
	IDENTIFICADOR {fprintf(output, "IDENTIFICADOR\n");}
	| IDENTIFICADOR indice {fprintf(output, "IDENTIFICADOR indice\n");}
	;

indice:
	indice ABRECOLCHETE expressao FECHACOLCHETE {fprintf(output, "indice ABRECOLCHETE expressao FECHACOLCHETE\n");}
	| ABRECOLCHETE expressao FECHACOLCHETE {fprintf(output, "ABRECOLCHETE expressao FECHACOLCHETE\n");}
	;

tipo:
	TIPOINTEIRO {fprintf(output, "TIPOINTEIRO\n");}
	| TIPOFLUTUANTE {fprintf(output, "TIPOFLUTUANTE\n");}
	;

declaracao_funcao:
	tipo cabecalho {fprintf(output, "tipo cabecalho\n");}
	| cabecalho {fprintf(output, "cabecalho\n");}
	;

cabecalho:
	IDENTIFICADOR ABREPARENTESES lista_parametros FECHAPARENTESES corpo FIM {fprintf(output, "IDENTIFICADOR ABREPARENTESES lista_parametros FECHAPARENTESES corpo FIM\n");}
	| IDENTIFICADOR ABREPARENTESES FECHAPARENTESES corpo FIM {fprintf(output, "IDENTIFICADOR ABREPARENTESES FECHAPARENTESES corpo FIM\n");}
	;

lista_parametros:
	lista_parametros VIRGULA parametro {fprintf(output, "lista_parametros VIRGULA parametro\n");}
	| parametro {fprintf(output, "parametro\n");}
	;

parametro:
	tipo DOISPONTOS IDENTIFICADOR {fprintf(output, "tipo DOISPONTOS IDENTIFICADOR\n");}
	| parametro ABRECOLCHETE FECHACOLCHETE{fprintf(output, "parametro ABRECOLCHETE FECHACOLCHETE\n");}
	;

corpo:
	acao {fprintf(output, "acao\n");}
	| corpo acao {fprintf(output, "corpo acao\n");}
	| atribuicao {fprintf(output, "atribuicao\n");}
	| corpo atribuicao {fprintf(output, "corpo atribuicao\n");};

acao:
	declaracao_variaveis {fprintf(output, "declaracao_variaveis\n");}
	| se {fprintf(output, "se\n");}
	| repita {fprintf(output, "repita\n");}
	| leia {fprintf(output, "leia\n");}
	| escreva {fprintf(output, "escreva\n");}
	| retorna {fprintf(output, "retorna\n");};

se:
	SE expressao ENTAO corpo FIM {fprintf(output, "SE expressao ENTAO corpo FIM\n");}
	| SE expressao ENTAO corpo SENAO corpo FIM {fprintf(output, "SE expressao ENTAO corpo SENAO corpo FIM\n");}
	;

repita:
	REPITA corpo ATE expressao {fprintf(output, "REPITA corpo ATE expressao\n");}
	;

atribuicao:
	var ATRIBUICAO expressao{fprintf(output, "var ATRIBUICAO expressao\n");}
	;

leia:
	LEIA ABREPARENTESES IDENTIFICADOR FECHAPARENTESES{fprintf(output, "LEIA ABREPARENTESES IDENTIFICADOR FECHAPARENTESES\n");}
	;

escreva:
	ESCREVA ABREPARENTESES expressao FECHAPARENTESES{fprintf(output, "ESCREVA ABREPARENTESES expressao FECHAPARENTESES\n");}
	;

retorna:
	RETORNA ABREPARENTESES expressao FECHAPARENTESES{fprintf(output, "RETORNA ABREPARENTESES expressao FECHAPARENTESES\n");}
	;

expressao:
	atribuicao {fprintf(output, "atribuicao\n");}
	| expressao_simples {fprintf(output, "expressao_simples\n");}
	;

expressao_simples:
	expressao_aditiva {fprintf(output, "expressao_aditiva\n");}
	| expressao_simples operador_relacional expressao_aditiva {fprintf(output, "expressao_simples operador_relacional expressao_aditiva\n");}
	; 

expressao_aditiva:
	expressao_multiplicativa {fprintf(output, "expressao_multiplicativa\n");}
	| expressao_aditiva operador_soma expressao_multiplicativa {fprintf(output, "expressao_aditiva operador_soma expressao_multiplicativa\n");}
	;

expressao_multiplicativa:
	expressao_unaria {fprintf(output, "expressao_unaria\n");}
	| expressao_multiplicativa operador_multiplicacao expressao_unaria{fprintf(output, "expressao_multiplicativa operador_multiplicacao expressao_unaria\n");}
	;

expressao_unaria:
	fator {fprintf(output, "fator \n");}
	| operador_soma fator {fprintf(output, "operador_soma fator\n");}
	;

operador_relacional:
	MENOR {fprintf(output, "MENOR\n");}
	| MAIOR {fprintf(output, "MAIOR\n");}
	| IGUAL {fprintf(output, "IGUAL\n");}
	| DIFERENTE {fprintf(output, "DIFERENTE\n");}
	| MENORIGUAL {fprintf(output, "MENORIGUAL\n");}
	| MAIORIGUAL{fprintf(output, "MAIORIGUAL\n");}
	; 

operador_soma:
	ADICAO {fprintf(output, "ADICAO\n");}
	| SUBTRACAO {fprintf(output, "SUBTRACAO\n");}
	;

operador_multiplicacao:
	MULTIPLICACAO {fprintf(output, "MULTIPLICACAO\n");}
	| DIVISAO {fprintf(output, "DIVISAO\n");}
	;

fator:
	ABREPARENTESES expressao FECHAPARENTESES {fprintf(output, "ABREPARENTESES expressao FECHAPARENTESES\n");}
	| var {fprintf(output, "var\n");}
	| chamada_funcao {fprintf(output, "chamada_funcao\n");}
	| numero {fprintf(output, "numero\n");}
	;

numero:
	NUMEROINTEIRO {fprintf(output, "NUMEROINTEIRO\n");}
	| NUMEROFLUTUANTE {fprintf(output, "NUMEROFLUTUANTE\n");}
	| EXPONENCIAL {fprintf(output, "EXPONENCIAL\n");}
	;

chamada_funcao:
	IDENTIFICADOR ABREPARENTESES lista_argumentos FECHAPARENTESES {fprintf(output, "IDENTIFICADOR ABREPARENTESES lista_argumentos FECHAPARENTESES\n");}
	;

lista_argumentos:
	lista_argumentos VIRGULA expressao {fprintf(output, "lista_argumentos VIRGULA expressao\n");}
	| expressao {fprintf(output, "expressao\n");}
	;
//end

%%
void yyerror(char *s) {
	fprintf(stdout, "%s\n", s);
}

int main(int argc, char *argv[]){
	idNode = 0;
	output = fopen(outputprogram, "w");
	yyin = fopen(argv[1], "r");
	yyparse();	
	fclose(yyin);
	fclose(output);
	printTreeSyntactic();
	return 0;
}

