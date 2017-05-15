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
	strcpy(yylval.reservada, yytext);
	return SE;
}

"então"  {
	strcpy(yylval.reservada, yytext);
	return ENTAO;
}

"senão" {
	strcpy(yylval.reservada, yytext);
	return SENAO;
}

"fim" {
	strcpy(yylval.reservada, yytext);
	return FIM;
}

"repita" {
	strcpy(yylval.reservada, yytext);
	return REPITA;
}
"retorna" {
	strcpy(yylval.reservada, yytext);
	return RETORNA;
}

"até" {
	strcpy(yylval.reservada, yytext);
	return ATE;
}

"leia" {
	strcpy(yylval.reservada, yytext);
	return LEIA;
}

"escreve" {
	strcpy(yylval.reservada, yytext);
	return ESCREVA;
}

"inteiro" {
	strcpy(yylval.tipo, yytext);
	return TIPOINTEIRO;
};

"flutuante" {
	strcpy(yylval.tipo, yytext);
	return TIPOFLUTUANTE;
};

"void" {
	strcpy(yylval.tipo, yytext);
	return TIPOVOID;
}

{IDENTIFICADOR} { 
	strcpy(yylval.identificador, yytext);
	return IDENTIFICADOR;
}
 
{INTEIRO} {
	/*yylval.nValor = atoi(yytext);*/
	return NUMEROINTEIRO;
}

{FLUTUANTE} {
	/*yylval.nValor = atof(yytext);*/
	return NUMEROFLUTUANTE;
} 

{EXPONENCIAL} {	
	printf("%s\n", yytext);
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
	//yylval.nValor = pow(valor, potencia);
	return EXPONENCIAL;
}

{COMENTARIO} {
	strcpy(yylval.comentario, yytext);
	return COMENTARIO;
}

"=" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return IGUAL;
}

":" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return DOISPONTOS;
};

":=" {
	strcpy(yylval.simbolo, yytext);
	return ATRIBUICAO;
}

"<" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return MENOR;
}

"<=" {
	strcpy(yylval.simbolo, yytext);
	return MENORIGUAL;

}

">" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return MAIOR;
}

">=" {
	strcpy(yylval.simbolo, yytext);
	return MAIORIGUAL;
}

"<>" {
	strcpy(yylval.simbolo, yytext);
	return DIFERENTE;
}

"(" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return ABREPARENTESES;
}

")" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return FECHAPARENTESES;
}

"{" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return ABRECHAVE;
}	

"}" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return FECHACHAVE;
}	

"," {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return VIRGULA;
}	

"+"  {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return ADICAO;
}	

"-" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return SUBTRACAO;
}	

"*" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return MULTIPLICACAO;
}	

"/" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return DIVISAO;
}	

"[" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
	return ABRECOLCHETE;
}	

"]" {
	yylval.simbolo[0] = yytext[0];
	yylval.simbolo[1] = '\0';
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

