%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <stdbool.h>
	#include <string.h>
//	#include "syntax-tree.h"
	#include "nTree.h"

	/* Protótipos */
	int yylex(void);
	void yyerror(char *s);
	extern FILE *yyin;
	extern FILE *yyout;
	
	/* Global */
	bool seNao;
	static Arvore *aFinal;	
	Arvore *auxiliar;
%}

%union	{
	Arvore *a;
	char pgm[32768];
};
%start programa

%token <pgm> SE ENTAO SENAO FIM REPITA RETORNA ATE LEIA ESCREVA TIPOINTEIRO TIPOFLUTUANTE TIPOVOID IDENTIFICADOR NUMEROINTEIRO NUMEROFLUTUANTE EXPONENCIAL IGUAL DOISPONTOS ATRIBUICAO MENOR MENORIGUAL MAIOR MAIORIGUAL DIFERENTE ABREPARENTESES FECHAPARENTESES ABRECHAVE FECHACHAVE VIRGULA ADICAO SUBTRACAO MULTIPLICACAO DIVISAO ABRECOLCHETE FECHACOLCHETE END_OF_FILE

%type <a> programa lista_declaracoes declaracao declaracao_variaveis inicializacao_variaveis lista_variaveis var indice tipo declaracao_funcao cabecalho lista_parametros parametro corpo acao se repita atribuicao leia escreva retorna expressao expressao_simples expressao_aditiva expressao_multiplicativa expressao_unaria operador_relacional operador_soma operador_multiplicacao fator numero chamada_funcao lista_argumentos 

%left ADICAO SUBTRACAO
%left MULTIPLICACAO DIVISAO

%% 
//start
programa:
	lista_declaracoes { aFinal = criaNo("programa", 1, $1); }
	;

lista_declaracoes:
	lista_declaracoes declaracao
			{
				if($1 != NULL){
					if(pertenceArvore($$, "lista_declaracoes")){
						adicionaFilho($$, $2);
					} else {
						$$ = criaNo("lista_declaracoes", 1, $2);
					}
				} else {
					fprintf(fileLog, "lista_declaracoes\n");
					$$ = criaNo("lista_declaracoes", 1, $2);
				}
			}
	| declaracao { $$ = criaNo("lista_declaracoes", 1, $1); }
	;

declaracao:
	declaracao_variaveis { $$ = $1; }
	| inicializacao_variaveis { $$ = $1; }
	| declaracao_funcao { $$ = $1; }
	;

declaracao_variaveis:
	tipo DOISPONTOS lista_variaveis  { $$ = criaNo("declaracao_variaveis", 2, $1, $3); }
	;

inicializacao_variaveis:
	atribuicao { $$ = criaNo("inicializacao_variaives", 1, $1); }
	;

lista_variaveis:
	lista_variaveis VIRGULA var
		{ 
			if($1 != NULL){
				if(pertenceArvore($$, "lista_variaveis")){
					adicionaFilho($$, $3);
				} else {
					$$ = criaNo("lista_variaveis", 1, $3);
				}
			} else {
				fprintf(fileLog, "lista_variaveis\n");
				$$ = criaNo("lista_variaveis", 1, $3);
			}
		}
	| var { $$ = criaNo("lista_variaveis", 1, $1); }
	;

var:
	IDENTIFICADOR
		{ 
			auxiliar = criaNo($1, 0);		
			$$ = criaNo("var", 1, auxiliar);
		}
	| IDENTIFICADOR indice
		{			
			$$ = criaNo("var", 2, criaNo($1, 0), $2);
		}
	;

indice:
	indice ABRECOLCHETE expressao FECHACOLCHETE
		{
			if($1 != NULL){
				if(pertenceArvore($$, "indice")){
					adicionaFilho($$, $3);
				} else {
					$$ = criaNo("indice", 1, $3);
				}
			} else {
				fprintf(fileLog, "indice\n");
				$$ = criaNo("indice", 1, $3);
			}
		}
	| ABRECOLCHETE expressao FECHACOLCHETE { $$ = criaNo("indice", 1, $2); }
	;

tipo:
	TIPOINTEIRO { $$ = criaNo($1, 0); }
	| TIPOFLUTUANTE { $$ = criaNo($1, 0); }
	;

declaracao_funcao:
	tipo cabecalho { $$ = criaNo("declaracao_funcao", 2, $1, $2); }
	| cabecalho { $$ = criaNo("declaracao_funcao", 1, $1); }
	;

cabecalho:
	IDENTIFICADOR ABREPARENTESES lista_parametros FECHAPARENTESES corpo FIM
		{
			auxiliar = criaNo($1, 0);
			$$ = criaNo("cabecalho", 3, auxiliar, $3, $5); 
		}
	| IDENTIFICADOR ABREPARENTESES FECHAPARENTESES corpo FIM { $$ = criaNo("cabecalho", 2, criaNo($1, 0), $4); }
	;

lista_parametros:
	lista_parametros VIRGULA parametro
		{
			if($1 != NULL){
				if(pertenceArvore($$, "lista_parametros")){
					adicionaFilho($$, $3);
				} else {
					$$ = criaNo("lista_parametros", 1, $3);
				}
			} else {
				fprintf(fileLog, "lista_parametros\n");
				$$ = criaNo("lista_parametros", 1, $3);
			}	

		}
	| parametro { $$ = criaNo("lista_parametros", 1, $1); }
	;

parametro:
	tipo DOISPONTOS IDENTIFICADOR
		{
			auxiliar = criaNo($3, 0);
			$$ = criaNo("parametro", 2, $1, auxiliar);
		}
	| parametro ABRECOLCHETE FECHACOLCHETE
		{
			if($1 != NULL){
				if(pertenceArvore($$, "parametro")){
					auxiliar = criaNo("[", 0);
					adicionaFilho($$, auxiliar);
					auxiliar = criaNo("]", 0);
					adicionaFilho($$, auxiliar);					
				} else {
					$$ = criaNo("parametro", 2, criaNo("[", 0), criaNo("]", 0));					
				}
			} else {
				fprintf(fileLog, "parametro\n");
				$$ = criaNo("parametro", 2, criaNo("[", 0), criaNo("]", 0));					
			}
		}
	;

corpo:
	acao { $$ = criaNo("corpo", 1, $1); }
	| corpo acao
		{
			if($1 != NULL){
				if(pertenceArvore($$, "corpo")){
					adicionaFilho($$, $2);
				} else {
					$$ = criaNo("corpo", 1, $2);
				}
			} else {
				fprintf(fileLog, "corpo\n");
				$$ = criaNo("corpo", 1, $2);
			}
		}
	| atribuicao { $$ = criaNo("corpo", 1, $1); }
	| corpo atribuicao
		{
			if($1 != NULL){
				if(pertenceArvore($$, "corpo")){
					adicionaFilho($$, $2);
				} else {
					$$ = criaNo("corpo", 1, $2);
				}
			} else {
				fprintf(fileLog, "corpo\n");
				$$ = criaNo("corpo", 1, $2);
			}
		}
	| chamada_funcao { $$ = criaNo("corpo", 1, $1); }
	| corpo chamada_funcao
		{
			if($1 != NULL){
				if(pertenceArvore($$, "corpo")){
					adicionaFilho($$, $2);
				} else {
					$$ = criaNo("corpo", 1, $2);
				}
			} else {
				fprintf(fileLog, "corpo\n");
				$$ = criaNo("corpo", 1, $2);
			}
		}
	;

acao:
	declaracao_variaveis { $$ = $1; }
	| se { $$ = criaNo("acao", 1, $1); }
	| repita { $$ = criaNo("acao", 1, $1); }
	| leia { $$ = criaNo("acao", 1, $1); }
	| escreva { $$ = criaNo("acao", 1, $1); }
	| retorna { $$ = criaNo("acao", 1, $1); }
	;

se:
	SE expressao ENTAO corpo FIM { $$ = criaNo("se", 2, $2, $4); }
	| SE expressao ENTAO corpo SENAO corpo FIM { $$ = criaNo("se", 3, $2, $4, $6); }
	;

repita:
	REPITA corpo ATE expressao { $$ = criaNo("repita", 2, $2, $4); }
	;

atribuicao:
	var ATRIBUICAO expressao { $$ = criaNo("atribuicao", 2, $1, $3); }
	;

leia:
	LEIA ABREPARENTESES IDENTIFICADOR FECHAPARENTESES
		{	
			auxiliar = criaNo($3, 0);
			$$ = criaNo("LEIA", 1, auxiliar);
		}
	;

escreva:
	ESCREVA ABREPARENTESES expressao FECHAPARENTESES { $$ = criaNo("ESCREVA", 1, $3); }
	;

retorna:
	RETORNA ABREPARENTESES expressao FECHAPARENTESES { $$ = criaNo("RETORNA", 1, $3); }
	;

expressao:
	atribuicao { $$ = criaNo("expressao", 1, $1); }
	| expressao_simples { $$ = criaNo("expressao", 1, $1); }
	;

expressao_simples:
	expressao_aditiva { $$ = criaNo("expressao_simples", 1, $1); }
	| expressao_simples operador_relacional expressao_aditiva
		{
			if($1 != NULL){
				if(pertenceArvore($$, "expressao_simples")){
					if($2 != NULL){
						adicionaFilho($$, $2);
					}
					if($3 != NULL){
						adicionaFilho($$, $3);
					}
				}
			} else {
				fprintf(fileLog, "expressao_simples\n");
				//ver se em algum teste cai aqui
				$$ = criaNo("expressao_simples", 0);
				if($2 != NULL){
					adicionaFilho($$, $2);
				}
				if($3 != NULL){
					adicionaFilho($$, $3);
				}
			}
		}
	; 

expressao_aditiva:
	expressao_multiplicativa { $$ = criaNo("expressao_aditiva", 1, $1); }
	| expressao_aditiva operador_soma expressao_multiplicativa
		{
			if($1 != NULL){
				if(pertenceArvore($$, "expressao_aditiva")){
					if($2 != NULL){
						adicionaFilho($$, $2);
					}
					if($3 != NULL){
						adicionaFilho($$, $3);
					}
				}
			} else {
				fprintf(fileLog, "expressao_aditiva\n");
				//ver se em algum teste cai aqui
				$$ = criaNo("expressao_aditiva", 0);
				if($2 != NULL){
					adicionaFilho($$, $2);
				}
				if($3 != NULL){
					adicionaFilho($$, $3);
				}
			}
		}
	;

expressao_multiplicativa:
	expressao_unaria { $$ = criaNo("expressao_multiplicativa", 1, $1); }
	| expressao_multiplicativa operador_multiplicacao expressao_unaria
		{
			if($1 != NULL){
				if(pertenceArvore($$, "expressao_multiplicativa")){
					if($2 != NULL){
						adicionaFilho($$, $2);
					}
					if($3 != NULL){
						adicionaFilho($$, $3);
					}
				}
			} else {
				fprintf(fileLog, "expressao_multiplicativa\n");
				//ver se em algum teste cai aqui
				$$ = criaNo("expressao_multiplicativa", 0);
				if($2 != NULL){
					adicionaFilho($$, $2);
				}
				if($3 != NULL){
					adicionaFilho($$, $3);
				}
			}
		}
	;

expressao_unaria:
	fator { $$ = criaNo("expressao_unaria", 1, $1); }
	| operador_soma fator
		{
			if($2 != NULL){
				if(pertenceArvore($$, "expressao_unaria")){
					if($1 != NULL){
						adicionaFilho($$, $1);
					}
				}
			} else {
				fprintf(fileLog, "expressao_unaria\n");
				//ver se em algum teste cai aqui
				$$ = criaNo("expressao_unaria", 0);
				if($1 != NULL){
					adicionaFilho($$, $1);
				}
			}
			
		}
	;

operador_relacional:
	MENOR { $$ = criaNo($1, 0); }
	| MAIOR { $$ = criaNo($1, 0); }
	| IGUAL { $$ = criaNo($1, 0); }
	| DIFERENTE { $$ = criaNo($1, 0); }
	| MENORIGUAL { $$ = criaNo($1, 0); }
	| MAIORIGUAL { $$ = criaNo($1, 0); }
	; 

operador_soma:
	ADICAO { $$ = criaNo($1, 0); }
	| SUBTRACAO { $$ = criaNo($1, 0); }
	;

operador_multiplicacao:
	MULTIPLICACAO { $$ = criaNo($1, 0); }
	| DIVISAO { $$ = criaNo($1, 0); }
	;

fator:
	ABREPARENTESES expressao FECHAPARENTESES { $$ = criaNo("fator", 1, $2); }
	| var { $$ = criaNo("fator", 1, $1); }
	| chamada_funcao { $$ = criaNo("fator", 1, $1); }
	| numero { $$ = criaNo("fator", 1, $1); }
	;

numero:
	NUMEROINTEIRO
		{
			auxiliar = criaNo($1, 0);
			$$ = criaNo("numero", 1, auxiliar);
		}
	| NUMEROFLUTUANTE
		{
			auxiliar = criaNo($1, 0);
			$$ = criaNo("numero", 1, auxiliar);
		}
	| EXPONENCIAL
		{
			auxiliar = criaNo($1, 0);
			$$ = criaNo("numero", 1, auxiliar);
		}
	;

chamada_funcao:
	IDENTIFICADOR ABREPARENTESES lista_argumentos FECHAPARENTESES {	$$ = criaNo("chamada_funcao", 2, criaNo($1, 0), $3); }
	| IDENTIFICADOR ABREPARENTESES FECHAPARENTESES { $$ = criaNo("chamada_funcao", 1, criaNo($1, 0)); };

lista_argumentos:
	lista_argumentos VIRGULA expressao
		{	
			if($1 != NULL){
				if(pertenceArvore($$, "lista_argumentos")){
					adicionaFilho($$, $3);					
				} else {
					$$ = criaNo("lista_argumentos", 1, $3);					
				}
			} else {
				fprintf(fileLog, "chamada_funcao\n");
				$$ = criaNo("lista_argumentos", 1, $3);					
			}
		}
	| expressao { $$ = criaNo("lista_argumentos", 1, $1); }
	;
//end

%%
void yyerror(char *s) {
	if(compareString(s, "syntax error") == 0){
		system("reset");
		printf("\033[1m\033[31mSYNTAX ERROR\n");	
		exit(1);
	} else {
		fprintf(stdout, "%s\n", s);
	}
}

int main(int argc, char *argv[]){
	fileLog = fopen("log.txt", "w");
	yyin = fopen(argv[1], "r");
	yyparse();	
	fclose(yyin);
	system("reset");
	imprimeArvore(aFinal);
	fclose(fileLog);
	verificarLog();
	system("reset");
	gerandoDot(aFinal);
	return 0;
}
