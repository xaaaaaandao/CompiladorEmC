%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include "syntax-tree.h"
	#include "parser.tab.h"
	void yyerror(char *);
%}

DIGITO [0-9]
LETRAS [a-zA-ZãáàÃÁÀõÕóÓéÉíÍúÚ_]
NATURAL {DIGITO}+
INTEIRO {NATURAL}
FLUTUANTE {INTEIRO}("."{NATURAL})
EXPONENCIAL ({INTEIRO}|{FLUTUANTE})("e"|"E")("+"|"-"){INTEIRO}
SIMBOLO ("+"|"-"|"*"|"/"|"="|","|":="|"<"|">"|"<="|">="|"<>"|"("|")"|":"|"["|"]"|"{"|"}")
IDENTIFICADOR {LETRAS}({LETRAS}|{DIGITO})*
ESPACO [ \n\r\t]+
COMENTARIO "{"[^\}]*"}"

%% /* Regras */
"se" {
	strcpy(yylval.pgm, yytext);
	return SE;
}

"então"  {
	strcpy(yylval.pgm, yytext);
	return ENTAO;
}

"senão" {
	strcpy(yylval.pgm, yytext);
	return SENAO;
}

"fim" {
	strcpy(yylval.pgm, yytext);
	return FIM;
}

"repita" {
	strcpy(yylval.pgm, yytext);
	return REPITA;
}
"retorna" {
	strcpy(yylval.pgm, yytext);
	return RETORNA;
}

"até" {
	strcpy(yylval.pgm, yytext);
	return ATE;
}

"leia" {
	strcpy(yylval.pgm, yytext);
	return LEIA;
}

"escreva" {
	strcpy(yylval.pgm, yytext);
	return ESCREVA;
}

"inteiro" {
	strcpy(yylval.pgm, yytext);
	return TIPOINTEIRO;
};

"flutuante" {
	strcpy(yylval.pgm, yytext);
	return TIPOFLUTUANTE;
};

"void" {
	strcpy(yylval.pgm, yytext);
	return TIPOVOID;
}

{IDENTIFICADOR} { 
	strcpy(yylval.pgm, yytext);
	return IDENTIFICADOR;
}
 
{INTEIRO} {
	strcpy(yylval.pgm, yytext);
	return NUMEROINTEIRO;
}

{FLUTUANTE} {
	strcpy(yylval.pgm, yytext);
	return NUMEROFLUTUANTE;
} 

{EXPONENCIAL} {	
//	printf("%s\n", yytext);
	char sinal = '!';	
	char eValor[3276];			
	double valor;
	double potencia;
	int i = 0, j = 0;	
	while(yytext[i] != '\0'){
		if(yytext[i] == 'e' || yytext[i] ==  'E'){
			eValor[j] = '\0';
			valor = atof(eValor);
			memset(eValor, 0, sizeof(eValor));
			i++;
			j = 0;
		} else if(yytext[i] == '+' || yytext[i] == '-'){
			sinal = yytext[i];
			i++;
		} else {
			eValor[j] = yytext[i];
			i++;
			j++;
		}
	}
	eValor[j] = '\0';
	potencia = atof(eValor);				
	if(sinal == '-'){
		potencia = atof(eValor);				
		potencia = potencia * -1;
	}
	strcpy(yylval.pgm, yytext);
	return EXPONENCIAL;
}

{COMENTARIO} {
	strcpy(yylval.pgm, yytext);
}

"=" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return IGUAL;
}

":" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return DOISPONTOS;
};

":=" {
	strcpy(yylval.pgm, yytext);
	return ATRIBUICAO;
}

"<" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return MENOR;
}

"<=" {
	strcpy(yylval.pgm, yytext);
	return MENORIGUAL;

}

">" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return MAIOR;
}

">=" {
	strcpy(yylval.pgm, yytext);
	return MAIORIGUAL;
}

"<>" {
	strcpy(yylval.pgm, yytext);
	return DIFERENTE;
}

"(" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return ABREPARENTESES;
}

")" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return FECHAPARENTESES;
}

"{" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return ABRECHAVE;
}	

"}" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return FECHACHAVE;
}	

"," {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return VIRGULA;
}	

"+"  {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return ADICAO;
}	

"-" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return SUBTRACAO;
}	

"*" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return MULTIPLICACAO;
}	

"/" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return DIVISAO;
}	

"[" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return ABRECOLCHETE;
}	

"]" {
	yylval.pgm[0] = yytext[0];
	yylval.pgm[1] = '\0';
	return FECHACOLCHETE;
}		

{ESPACO} {
	//descarta espaço em branco
}

\{(.*?)\} {

}

<<EOF>> {
	static int once = 0; 
	if(once == 0)
		return once++;
	else 
		return '\n';
}

%%
int yywrap(void){
	return 1;
}

extern int yy_flex_debug;

