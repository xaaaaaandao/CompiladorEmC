%{
void yyerror(char *);


#ifndef  YYTOKENTYPE
#define YYTOKENTYPE
enum yytokentype{
	END_OF_FILE = 258,
	NUMEROINTEIRO = 259,
	NUMEROFLUTUANTE = 260,
	IDENTIFICADOR = 270,
	RESERVADA = 280,
	IGUAL = 290,
	DOISPONTOS = 291,
	ATRIBUICAO = 292,
	MENOR = 293,
	MENORIGUAL = 294,
	MAIOR = 295,
	MAIORIGUAL = 296,
	DIFERENTE = 297,
	ABREPARENTESES = 298,
	FECHAPARENTESES = 299,
	ABRECHAVE = 300,
	FECHACHAVE = 301,
	VIRGULA = 302,
	MAIS = 303,
	MENOS = 304,
	MULTIPLICACAO = 305,
	DIVISAO = 306,
	COMENTARIO_NAO_FINALIZADO = 307,
	SE = 1,
	ENTAO = 2,
	SENAO = 3,
	FIM = 4,
	REPITA = 5,
	INTEIRO = 6,
	RETORNA = 7,
	ATE = 8,
	LEIA = 9,
	ESCREVA = 10,
	FLUTUANTE = 11,
	EXPONENCIAL = 12,
	COMENTARIO = 13,
	ABRECOLCHETE = 14,
	FECHACOLCHETE = 15
};
#endif

int yylval;
int line_num = 1;
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
"se" return SE;
"então" return ENTAO;
"senão" return SENAO;
"fim" return FIM;
"repita" return REPITA;
"flutuante" return FLUTUANTE;
"retorna" return RETORNA;
"até" return ATE;
"leia" return LEIA;
"escreve" return ESCREVA;
"inteiro" return INTEIRO;

{IDENTIFICADOR} { return IDENTIFICADOR;} 
{INTEIRO} { return NUMEROINTEIRO; }
{FLUTUANTE} { return NUMEROFLUTUANTE; } 
{EXPONENCIAL} {	return EXPONENCIAL; }
{COMENTARIO} {	return COMENTARIO; }

"=" return IGUAL;
":" return DOISPONTOS;
":=" return ATRIBUICAO;
"<" return MENOR;
"<=" return MENORIGUAL;
">" return MAIOR;
">=" return MAIORIGUAL;
"<>" return DIFERENTE;
"(" return ABREPARENTESES;
")" return FECHAPARENTESES;
"{" return ABRECHAVE;	
"}" return FECHACHAVE;
"," return VIRGULA;
"+" return MAIS;
"-" return MENOS;
"*" return MULTIPLICACAO;
"/" return DIVISAO;
"[" return ABRECOLCHETE;
"]" return FECHACOLCHETE;	

{ESPACO} {
	//descarta espaço em branco
}

\{(.*?)\} {

}

<<EOF>> return END_OF_FILE;

%%
int yywrap(void){
	return 1;
}

extern int yy_flex_debug;
int main(int argc, char *argv[]){
/*	yyin = fopen(argv[1], "r");
	int token = 0;
	while((token = yylex()) != END_OF_FILE){
	}
	fclose(yyin);
	return 0;*/
}
