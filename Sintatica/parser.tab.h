/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END_OF_FILE = 258,
    NUMEROINTEIRO = 259,
    NUMEROFLUTUANTE = 260,
    IDENTIFICADOR = 261,
    RESERVADA = 262,
    IGUAL = 263,
    DOISPONTOS = 264,
    ATRIBUICAO = 265,
    MENOR = 266,
    MENORIGUAL = 267,
    MAIOR = 268,
    MAIORIGUAL = 269,
    DIFERENTE = 270,
    ABREPARENTESES = 271,
    FECHAPARENTESES = 272,
    ABRECHAVE = 273,
    FECHACHAVE = 274,
    VIRGULA = 275,
    MAIS = 276,
    MENOS = 277,
    MULTIPLICACAO = 278,
    DIVISAO = 279,
    COMENTARIO_NAO_FINALIZADO = 280,
    SE = 281,
    ENTAO = 282,
    SENAO = 283,
    FIM = 284,
    REPITA = 285,
    INTEIRO = 286,
    RETORNA = 287,
    ATE = 288,
    LEIA = 289,
    ESCREVA = 290,
    FLUTUANTE = 291,
    EXPONENCIAL = 292,
    COMENTARIO = 293,
    ABRECOLCHETE = 294,
    FECHACOLCHETE = 295
  };
#endif
/* Tokens.  */
#define END_OF_FILE 258
#define NUMEROINTEIRO 259
#define NUMEROFLUTUANTE 260
#define IDENTIFICADOR 261
#define RESERVADA 262
#define IGUAL 263
#define DOISPONTOS 264
#define ATRIBUICAO 265
#define MENOR 266
#define MENORIGUAL 267
#define MAIOR 268
#define MAIORIGUAL 269
#define DIFERENTE 270
#define ABREPARENTESES 271
#define FECHAPARENTESES 272
#define ABRECHAVE 273
#define FECHACHAVE 274
#define VIRGULA 275
#define MAIS 276
#define MENOS 277
#define MULTIPLICACAO 278
#define DIVISAO 279
#define COMENTARIO_NAO_FINALIZADO 280
#define SE 281
#define ENTAO 282
#define SENAO 283
#define FIM 284
#define REPITA 285
#define INTEIRO 286
#define RETORNA 287
#define ATE 288
#define LEIA 289
#define ESCREVA 290
#define FLUTUANTE 291
#define EXPONENCIAL 292
#define COMENTARIO 293
#define ABRECOLCHETE 294
#define FECHACOLCHETE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "parser.y" /* yacc.c:1909  */

	int iValue;		/* Valor inteiro. */
	char sIndex;	/*Indice da Tabela de Símbolos. */
	nodeType *nPtr;	/* Node Pointer. */

#line 140 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
