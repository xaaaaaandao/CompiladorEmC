%{
void yyerror(char *);

#ifndef  YYTOKENTYPE
#define YYTOKENTYPE
enum yytokentype{
	END_OF_FILE = 258,
	T_INTEIRO = 259,
	T_FLUTUANTE = 260,
	T_IDENTIFICADOR = 270,
	T_RESERVADA = 280,
	T_IGUAL = 290,
	T_DOIS_PONTOS = 291,
	T_ATRIBUICAO = 292,
	T_MENOR = 293,
	T_MENOR_IGUAL = 294,
	T_MAIOR = 295,
	T_MAIOR_IGUAL = 296,
	T_DIFERENTE = 297,
	T_ABRE_PARENTESES = 298,
	T_FECHA_PARENTESES = 299,
	T_ABRE_CHAVE = 300,
	T_FECHA_CHAVE = 301,
	T_VIRGULA = 302,
	T_MAIS = 303,
	T_MENOS = 304,
	T_MULTIPLICACAO = 305,
	T_DIVISAO = 306,
	COMENTARIO_NAO_FINALIZADO = 307
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
EXPONENCIAL ({INTEIRO}|{FLUTUANTE})("e"|"E")[+-]?{INTEIRO}
RESERVADA ("se"|"então"|"senão"|"fim"|"repita"|"flutuante"|"retorna"|"até"|"leia"|"escreve"|"inteiro")
SIMBOLO ("+"|"-"|"*"|"/"|"="|","|":="|"<"|">"|"<="|">="|"<>"|"("|")"|":"|"["|"]"|"{"|"}")
IDENTIFICADOR {LETRAS}({LETRAS}|{DIGITO})*
ESPACO [ \n\r\t]+
COMENTARIO ("{")[^\}]*("}")

%% /* Regras */
{RESERVADA} {
	printf("<RESERVADA, %s>\n", yytext);
	return T_RESERVADA;
}

{IDENTIFICADOR} {
	printf("<IDENTIFICADOR, %s>\n", yytext);
	return T_IDENTIFICADOR;
}

{INTEIRO} {
	printf("<INTEIRO, %s>\n", yytext);
	return T_INTEIRO;
}

{FLUTUANTE} {
	printf("<FLUTUANTE, %s>\n", yytext);
	return T_FLUTUANTE;
}

{EXPONENCIAL} {
	printf("<EXPONENCIAL, %s>\n", yytext);
}

{COMENTARIO} {
	printf("<COMENTARIO, %s>\n", yytext);
}

"=" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_IGUAL;
}

":" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_DOIS_PONTOS;
}

":=" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_ATRIBUICAO;
}

"<" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_MENOR;
}

"<=" {
	return T_MENOR_IGUAL;
	printf("<SÍMBOLO, %s>\n", yytext);
}

">" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_MAIOR;
}

">=" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_MAIOR_IGUAL;
}

"<>" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_DIFERENTE;
}

"(" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_ABRE_PARENTESES;
}

")" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_FECHA_PARENTESES;
}

"{" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_ABRE_CHAVE;	
}

"}" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_FECHA_CHAVE;
}

"," {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_VIRGULA;
}

"+" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_MAIS;
}

"-" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_MENOS;
}

"*" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_MULTIPLICACAO;
}

"/" {
	printf("<SÍMBOLO, %s>\n", yytext);
	return T_DIVISAO;
}

"[" {
	printf("<SÍMBOLO, %s>\n", yytext);
}

"]" {
	printf("<SÍMBOLO, %s>\n", yytext);
}

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

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	int token = 0;
	while((token = yylex()) != END_OF_FILE){
	}
	fclose(yyin);
	return 0;
}
