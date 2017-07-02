%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <stdbool.h>
	#include <string.h>
	#include "syntaxtree.h"
	#include "semantic.h"

	/* Protótipos */
	int yylex(void);
	void yyerror(char *s);
	extern FILE *yyin;
	extern FILE *yyout;
	
	/* Global */
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
					fprintf(arquivoSemantico, "lista_declaracoes\n");
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
	tipo DOISPONTOS lista_variaveis
		{ $$ = criaNo("declaracao_variaveis", 2, $1, $3);
			if($2[0] == '\0'){
				printf("falta dois pontos (:) na declaração de variável\n");
			}
		}
	| tipo lista_variaveis { erroSemantico = true; $$ = criaNo("declaracao_variaveis", 1, $2); erroDeclaraVariavel($1, $2, 1); }
	| DOISPONTOS lista_variaveis { erroSemantico = true; $$ = criaNo("declaracao_variaveis", 1, $2); erroDeclaraVariavel(NULL, $2, 2); }
	;

inicializacao_variaveis:
	atribuicao { $$ = criaNo("inicializacao_variaives", 1, $1); }
	;

lista_variaveis:
	lista_variaveis VIRGULA var
		{ 
			if($1 != NULL){
				if(pertenceArvore($$, "lista_variaveis")){
					adicionaFilho($$, criaNo(",", 0));
					adicionaFilho($$, $3);
				} else {
					$$ = criaNo("lista_variaveis", 2, $3, criaNo(",", 0));
				}
			} else {
				fprintf(arquivoSemantico, "lista_variaveis\n");
				$$ = criaNo("lista_variaveis", 2, $3, criaNo(",", 0));
			}
		}
	| var { $$ = criaNo("lista_variaveis", 1, $1); }
	;

var:
	IDENTIFICADOR { $$ = criaNo("var", 1, criaNo($1, 0));	}
	| IDENTIFICADOR indice	{ $$ = criaNo("var", 2, criaNo($1, 0), $2); }
	;

indice:
	ABRECOLCHETE expressao FECHACOLCHETE ABRECOLCHETE expressao FECHACOLCHETE
	{ $$ = criaNo("indice", 6, criaNo("[", 0), $2, criaNo("]", 0), criaNo("[", 0), $5, criaNo("]", 0)); }
	| ABRECOLCHETE expressao FECHACOLCHETE { $$ = criaNo("indice", 3, criaNo("[", 0), $2, criaNo("]", 0)); }
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
			$$ = criaNo("cabecalho", 3, criaNo($1, 0), $3, $5);
			if(erroParametro || erroIndiceParametro || erroDoisIndiceParametro || erroTipoIndiceParametro){
				erroSemantico = true;
				erroFuncao($1);
				erroListaParametros($3);
			}
			erroParametro = false;
			erroIndiceParametro = false;
			erroDoisIndiceParametro = false;
		}
	| IDENTIFICADOR ABREPARENTESES FECHAPARENTESES corpo FIM { $$ = criaNo("cabecalho", 2, criaNo($1, 0), $4); }
	;

lista_parametros:
	lista_parametros VIRGULA parametro
		{
			if($1 != NULL){
				if(pertenceArvore($$, "lista_parametros")){
					adicionaFilho($$, criaNo(",", 0));
					adicionaFilho($$, $3);
				} else {
					$$ = criaNo("lista_parametros", 2, $3, criaNo(",", 0));
				}
			} else {
				fprintf(arquivoSemantico, "lista_parametros\n");
				$$ = criaNo("lista_parametros", 2, $3, criaNo(",", 0));
			}
		}
	| lista_parametros parametro
		{
			erroParametro = true;
			if($1 != NULL){
				if(pertenceArvore($$, "lista_parametros")){
					adicionaFilho($$, criaNo("!@#", 0));
					adicionaFilho($$, $2);
				} else {
					$$ = criaNo("lista_parametros", 2, $2, criaNo(",", 0));
				}
			} else {
				fprintf(arquivoSemantico, "lista_parametros\n");
				$$ = criaNo("lista_parametros", 2, $2, criaNo(",", 0));
			}
		}
	| parametro { $$ = criaNo("lista_parametros", 1, $1); }
	;

parametro:
	tipo DOISPONTOS IDENTIFICADOR {	$$ = criaNo("parametro", 3, $1, criaNo(":", 0), criaNo($3, 0)); }
	//[]
	| tipo DOISPONTOS IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE { $$ = criaNo("parametro", 5, $1, criaNo(":", 0), criaNo($3, 0), criaNo("[", 0), criaNo("]", 0)); }
	//]
	| tipo DOISPONTOS IDENTIFICADOR ABRECOLCHETE { erroIndiceParametro = true; $$ = criaNo("parametro", 4, $1, criaNo(":", 0), criaNo($3, 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
	//]
	| tipo DOISPONTOS IDENTIFICADOR FECHACOLCHETE { erroIndiceParametro = true; $$ = criaNo("parametro", 4, $1, criaNo(":", 0), criaNo($3, 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
	//[][]
	| tipo DOISPONTOS IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE ABRECOLCHETE FECHACOLCHETE { $$ = criaNo("parametro", 7, $1, criaNo(":", 0), criaNo($3, 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
	//][]
	| tipo DOISPONTOS IDENTIFICADOR FECHACOLCHETE ABRECOLCHETE FECHACOLCHETE { erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo(":", 0), criaNo($3, 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
	//]]
	| tipo DOISPONTOS IDENTIFICADOR FECHACOLCHETE FECHACOLCHETE { erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo(":", 0), criaNo($3, 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
	//[]]
	| tipo DOISPONTOS IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE FECHACOLCHETE { erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo(":", 0), criaNo($3, 0), criaNo("[", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
	//[[
	| tipo DOISPONTOS IDENTIFICADOR ABRECOLCHETE ABRECOLCHETE { erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo(":", 0), criaNo($3, 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
	//[[]
	| tipo DOISPONTOS IDENTIFICADOR ABRECOLCHETE ABRECOLCHETE FECHACOLCHETE { erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo(":", 0), criaNo($3, 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("]", 0)); }
	//[][
	| tipo DOISPONTOS IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE ABRECOLCHETE { erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo(":", 0), criaNo($3, 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }


	| tipo IDENTIFICADOR { erroDoisIndiceParametro = true; $$ = criaNo("parametro", 3, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0));}
	| tipo IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE { erroDoisIndiceParametro = true; $$ = criaNo("parametro", 5, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0), criaNo("[", 0), criaNo("]", 0)); }
	| tipo IDENTIFICADOR ABRECOLCHETE { erroDoisIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 5, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
	| tipo IDENTIFICADOR FECHACOLCHETE { erroDoisIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 5, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
	| tipo IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE ABRECOLCHETE FECHACOLCHETE { erroDoisIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
	//][]
	| tipo IDENTIFICADOR FECHACOLCHETE ABRECOLCHETE FECHACOLCHETE { erroDoisIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
	//]]
	| tipo IDENTIFICADOR FECHACOLCHETE FECHACOLCHETE { erroDoisIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
	//[]]
	| tipo IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE FECHACOLCHETE { erroDoisIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0), criaNo("[", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
	//[[
	| tipo IDENTIFICADOR ABRECOLCHETE ABRECOLCHETE { erroDoisIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
	//[[]
	| tipo IDENTIFICADOR ABRECOLCHETE ABRECOLCHETE FECHACOLCHETE { erroDoisIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
	//[][
	| tipo IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE ABRECOLCHETE { erroDoisIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 7, $1, criaNo("\033[1m\033[31m:\033[0m", 0), criaNo($2, 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }

	| DOISPONTOS IDENTIFICADOR { erroTipoIndiceParametro = true; $$ = criaNo("parametro", 2, criaNo(":", 0), criaNo($2, 0)); }
	| DOISPONTOS IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE { erroTipoIndiceParametro = true; $$ = criaNo("parametro", 4, criaNo(":", 0), criaNo($2, 0), criaNo("[", 0), criaNo("]", 0)); }
	| DOISPONTOS IDENTIFICADOR ABRECOLCHETE { erroTipoIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 4, criaNo(":", 0), criaNo($2, 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
	| DOISPONTOS IDENTIFICADOR FECHACOLCHETE { erroTipoIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 4, criaNo(":", 0), criaNo($2, 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
	| DOISPONTOS IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE ABRECOLCHETE FECHACOLCHETE { erroTipoIndiceParametro = true; $$ = criaNo("parametro", 6, criaNo(":", 0), criaNo($2, 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
	//][]
	| DOISPONTOS IDENTIFICADOR FECHACOLCHETE ABRECOLCHETE FECHACOLCHETE { erroTipoIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 6, criaNo(":", 0), criaNo($2, 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
	//]]
	| DOISPONTOS IDENTIFICADOR FECHACOLCHETE FECHACOLCHETE { erroTipoIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 6, criaNo(":", 0), criaNo($2, 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
	//[]]
	| DOISPONTOS IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE FECHACOLCHETE { erroTipoIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 6, criaNo(":", 0), criaNo($2, 0), criaNo("[", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
	//[[
	| DOISPONTOS IDENTIFICADOR ABRECOLCHETE ABRECOLCHETE { erroTipoIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 6, criaNo(":", 0), criaNo($2, 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
	//[[]
	| DOISPONTOS IDENTIFICADOR ABRECOLCHETE ABRECOLCHETE FECHACOLCHETE { erroTipoIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 6, criaNo(":", 0), criaNo($2, 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("]", 0)); }
	//[][
	| DOISPONTOS IDENTIFICADOR ABRECOLCHETE FECHACOLCHETE ABRECOLCHETE { erroTipoIndiceParametro = true; erroIndiceParametro = true; $$ = criaNo("parametro", 6, criaNo(":", 0), criaNo($2, 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
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
				fprintf(arquivoSemantico, "corpo\n");
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
				fprintf(arquivoSemantico, "corpo\n");
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
				fprintf(arquivoSemantico, "corpo\n");
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
				fprintf(arquivoSemantico, "expressao_simples\n");
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
				fprintf(arquivoSemantico, "expressao_aditiva\n");
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
				fprintf(arquivoSemantico, "expressao_multiplicativa\n");
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
				fprintf(arquivoSemantico, "expressao_unaria\n");
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
				fprintf(arquivoSemantico, "chamada_funcao\n");
				$$ = criaNo("lista_argumentos", 1, $3);					
			}
		}
	| expressao { $$ = criaNo("lista_argumentos", 1, $1); }
	;
//end

%%
void yyerror(char *s) {
	if(compareString(s, "syntax error") == 0){
		erroSemantico = true;
		fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] erro inesperado na linha %d\n", erroLinha);
		fclose(arquivoSemantico);
		imprimeErro();
		exit(1);
	} else {
		fprintf(stdout, "%s\n", s);
	}
}

int main(int argc, char *argv[]){
	erroSemantico = false;
	arquivoSemantico = fopen("semantico.txt", "w");
	auxiliarSemantico = fopen("auxiliar.txt", "w");
	arquivoLog = fopen("log.txt", "w");
	yyin = fopen(argv[1], "r");
	yyparse();	
	fclose(yyin);
	imprimeArvore(aFinal);
	fclose(arquivoSemantico);
	fclose(auxiliarSemantico);
	fclose(arquivoLog);
	verificarLog();
	gerandoDot(aFinal);
	imprimeErro();
	return 0;
}
