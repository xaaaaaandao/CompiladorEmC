%{
	#include <stdio.h>

	int yyerror(char *);
	int yylex(void);
	int sym[26]
%}

%token  END_OF_FILE T_INTEIRO T_FLUTUANTE T_IDENTIFICADOR T_RESERVADA T_IGUAL T_DOIS_PONTOS T_ATRIBUICAO T_MENOR T_MENOR_IGUAL T_MAIOR T_MAIOR_IGUAL T_DIFERENTE T_ABRE_PARENTESES T_FECHA_PARENTESES T_ABRE_CHAVE T_FECHA_CHAVE T_VIRGULA T_MAIS T_MENOS T_MULTIPLICACAO T_DIVISAO COMENTARIO_NAO_FINALIZADO T_SE T_ENTAO T_SENAO T_FIM T_REPITA T_RETORNA T_ATE T_LEIA T_ESCREVA T_EXPONENCIAL


%% 

programa:
	lista_declaracoes;

lista_declaracoes:
	lista_declaracoes declaracao | declaracao;

declaracao:
	declaracao_variavel variavel | variavel;

declaracao_variavel:
	declaracao_variavel variavel | variavel;

variavel:
	tipo T_DOIS_PONTOS var;

var:
	var ',' T_IDENTIFICADOR
	| T_IDENTIFICADOR '[' T_INTEIRO ']'
	| T_IDENTIFICADOR '[' T_INTEIRO ']' '[' T_INTEIRO ']'
	| T_IDENTIFICADOR;

tipo:
	T_INTEIRO | T_FLUTUANTE;

declaracao_funcao:
	declaracao_funcao funcao | funcao;

funcao:
	tipo T_IDENTIFICADOR T_ABRE_PARENTESES declaracao_parametros T_FECHA_PARENTESES declaracao_composta T_FIM
	| tipo T_IDENTIFICADOR T_ABRE_PARENTESES declaracao_parametros T_FECHA_PARENTESES T_FIM;

declaracao_parametros:
	lista_parametros | vazio;

lista_parametros:
	lista_parametros T_VIRGULA parametro
	| parametro;

parametro:
	tipo T_DOIS_PONTOS T_IDENTIFICADOR '[' T_INTEIRO ']'
	| tipo T_DOIS_PONTOS T_IDENTIFICADOR '[' T_INTEIRO ']' '[' T_INTEIRO ']'
	| tipo T_DOIS_PONTOS T_IDENTIFICADOR;

declaracao_composta:
	declaracoes_locais
	| lista_statements;

declaracoes_locais:
	declaracoes_locais declaracao_variavel
	| vazio;

lista_statements:
	lista_statements statement
	| vazio;

statement: 
	expressao
	| declaracao_composta
	| declaracao_selecao
	| declaracao_iteracao
	| declaracao_atribuicao
	| declaracao_leitura
	| declaracao_escrita
	| declaracao_retorno
	| erro;

declaracao_selecao:
	T_SE expressao T_ENTAO lista_statements T_FIM
	| T_SE expressao T_ENTAO lista_statements T_SENAO lista_statements T_FIM;

declaracao_iteracao:
	T_REPITA lista_statements T_ATE expressao;

declaracao_atribuicao:
	var T_ATRIBUICAO expressao;

declaracao_leitura:
	T_LEIA T_ABRE_PARENTESES T_IDENTIFICADOR T_FECHA_PARENTESES;

declaracao_escrita:
	T_ESCREVA T_ABRE_PARENTESES expressao T_FECHA_PARENTESES;

declaracao_retorno:
	T_RETORNA T_ABRE_PARENTESES expressao T_FECHA_PARENTESES;

expressao:
	expressao_simples
	| chamada_funcao;

expressao_simples:
	unario expressao_soma operador_relacional expressao_soma
	| expressao_soma;

unario:
	operador_soma expressao;

operador_relacional:
	T_MENOR | T_MAIOR | T_IGUAL | T_DIFERENTE | T_MENOR_IGUAL | T_MAIOR_IGUAL;

expressao_soma:
	expressao_soma operador_soma termo | termo;

operador_soma:
	T_MAIS | T_MENOS;

termo:
	termo operador_multiplicacao fator | fator;

operador_multiplicacao:
	T_MULTIPLICACAO	| T_DIVISAO;

fator:
	T_ABRE_PARENTESES expressao T_FECHA_PARENTESES
	| numero
	| T_IDENTIFICADOR;

numero:
	T_INTEIRO | T_FLUTUANTE | T_EXPONENCIAL;

chamada_funcao:
	T_IDENTIFICADOR T_ABRE_PARENTESES lista_argumentos T_FECHA_PARENTESES;

lista_argumentos:
	lista_argumentos T_VIRGULA expressao
	| expressao
	| vazio;
%%

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	
	yyparse();
	
	fclose(yyin);

	return 0;
}
