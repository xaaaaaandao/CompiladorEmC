/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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
	bool seNao;
	static Arvore *aFinal;	
	Arvore *auxiliar;

#line 87 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
    SE = 258,
    ENTAO = 259,
    SENAO = 260,
    FIM = 261,
    REPITA = 262,
    RETORNA = 263,
    ATE = 264,
    LEIA = 265,
    ESCREVA = 266,
    TIPOINTEIRO = 267,
    TIPOFLUTUANTE = 268,
    TIPOVOID = 269,
    IDENTIFICADOR = 270,
    NUMEROINTEIRO = 271,
    NUMEROFLUTUANTE = 272,
    EXPONENCIAL = 273,
    IGUAL = 274,
    DOISPONTOS = 275,
    ATRIBUICAO = 276,
    MENOR = 277,
    MENORIGUAL = 278,
    MAIOR = 279,
    MAIORIGUAL = 280,
    DIFERENTE = 281,
    ABREPARENTESES = 282,
    FECHAPARENTESES = 283,
    ABRECHAVE = 284,
    FECHACHAVE = 285,
    VIRGULA = 286,
    ADICAO = 287,
    SUBTRACAO = 288,
    MULTIPLICACAO = 289,
    DIVISAO = 290,
    ABRECOLCHETE = 291,
    FECHACOLCHETE = 292,
    END_OF_FILE = 293
  };
#endif
/* Tokens.  */
#define SE 258
#define ENTAO 259
#define SENAO 260
#define FIM 261
#define REPITA 262
#define RETORNA 263
#define ATE 264
#define LEIA 265
#define ESCREVA 266
#define TIPOINTEIRO 267
#define TIPOFLUTUANTE 268
#define TIPOVOID 269
#define IDENTIFICADOR 270
#define NUMEROINTEIRO 271
#define NUMEROFLUTUANTE 272
#define EXPONENCIAL 273
#define IGUAL 274
#define DOISPONTOS 275
#define ATRIBUICAO 276
#define MENOR 277
#define MENORIGUAL 278
#define MAIOR 279
#define MAIORIGUAL 280
#define DIFERENTE 281
#define ABREPARENTESES 282
#define FECHAPARENTESES 283
#define ABRECHAVE 284
#define FECHACHAVE 285
#define VIRGULA 286
#define ADICAO 287
#define SUBTRACAO 288
#define MULTIPLICACAO 289
#define DIVISAO 290
#define ABRECOLCHETE 291
#define FECHACOLCHETE 292
#define END_OF_FILE 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "parser.y" /* yacc.c:355  */

	Arvore *a;
	char pgm[32768];

#line 208 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 225 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    42,    55,    59,    60,    61,    65,    71,
      73,    75,    80,    84,    98,   112,   116,   117,   120,   121,
     122,   123,   124,   125,   129,   130,   131,   135,   136,   140,
     145,   149,   163,   167,   172,   191,   192,   205,   206,   219,
     220,   236,   237,   238,   239,   240,   241,   245,   246,   250,
     254,   258,   266,   270,   274,   275,   279,   280,   306,   307,
     333,   334,   360,   361,   382,   383,   384,   385,   386,   387,
     391,   392,   396,   397,   401,   402,   403,   404,   408,   413,
     418,   426,   427,   430,   443
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SE", "ENTAO", "SENAO", "FIM", "REPITA",
  "RETORNA", "ATE", "LEIA", "ESCREVA", "TIPOINTEIRO", "TIPOFLUTUANTE",
  "TIPOVOID", "IDENTIFICADOR", "NUMEROINTEIRO", "NUMEROFLUTUANTE",
  "EXPONENCIAL", "IGUAL", "DOISPONTOS", "ATRIBUICAO", "MENOR",
  "MENORIGUAL", "MAIOR", "MAIORIGUAL", "DIFERENTE", "ABREPARENTESES",
  "FECHAPARENTESES", "ABRECHAVE", "FECHACHAVE", "VIRGULA", "ADICAO",
  "SUBTRACAO", "MULTIPLICACAO", "DIVISAO", "ABRECOLCHETE", "FECHACOLCHETE",
  "END_OF_FILE", "$accept", "programa", "lista_declaracoes", "declaracao",
  "declaracao_variaveis", "inicializacao_variaveis", "lista_variaveis",
  "var", "indice", "tipo", "declaracao_funcao", "cabecalho",
  "lista_parametros", "parametro", "corpo", "acao", "se", "repita",
  "atribuicao", "leia", "escreva", "retorna", "expressao",
  "expressao_simples", "expressao_aditiva", "expressao_multiplicativa",
  "expressao_unaria", "operador_relacional", "operador_soma",
  "operador_multiplicacao", "fator", "numero", "chamada_funcao",
  "lista_argumentos", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     215,   -53,   -53,   -20,    -7,    43,   215,   -53,   -53,   -53,
     -10,    16,   -53,   -53,   -53,    25,   122,   -53,    10,   -11,
     -53,   -53,   -53,   122,    -7,   -11,   -53,   211,   -53,    30,
     -16,    24,    20,   -53,   -53,   -53,   122,   -53,   -53,   -10,
     -53,    27,   214,    36,    50,   -53,    94,   -53,   -53,   -53,
      -7,   -53,   -53,   -11,   122,   211,    38,    48,    53,   -53,
      34,   164,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
      62,   211,   112,    52,   118,    63,   122,    59,   -53,   -53,
     -53,   -53,   -53,   -53,   122,   122,   -53,   -53,   122,   -53,
     -53,   -53,    96,   178,   122,    83,   122,   -53,   -53,   -53,
     -53,   -53,   189,    24,   -53,   -53,   -53,    11,   -53,   -53,
     122,    36,    50,   -53,   211,   122,    75,    77,    79,   -53,
     -53,   122,    80,   153,   -53,   -53,   -53,   -53,   -53,   -53,
     211,   -53,   200,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,    25,    16,     0,     0,     2,     4,     5,     6,
      26,     0,     7,    28,    12,     0,     0,    17,    16,    11,
      15,     1,     3,     0,     9,    10,    27,     0,    26,     0,
       0,    32,    16,    78,    79,    80,     0,    70,    71,    75,
      54,    23,    55,    56,    58,    60,     0,    62,    77,    76,
       0,    14,    50,     8,     0,     0,     0,     0,     0,    41,
       0,     0,    35,    42,    43,    37,    44,    45,    46,    39,
       0,     0,     0,     0,     0,     0,     0,    22,    66,    64,
      68,    65,    69,    67,     0,     0,    72,    73,     0,    75,
      63,    13,     0,     0,     0,     0,     0,    30,    36,    38,
      40,    33,     0,    31,    34,    82,    84,     0,    74,    21,
       0,    57,    59,    61,     0,     0,     0,     0,     0,    29,
      81,     0,    20,     0,    49,    53,    51,    52,    83,    19,
       0,    47,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,   110,    26,   -53,     6,    -2,   -53,    18,
     -53,   107,   -53,    56,   -52,   -36,   -53,   -53,     0,   -53,
     -53,   -53,     5,   -53,    45,    37,    54,   -53,   -38,   -53,
      85,   -53,   -26,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    59,     9,    25,    10,    17,    60,
      12,    13,    30,    31,    61,    62,    63,    64,    40,    66,
      67,    68,    41,    42,    43,    44,    45,    84,    46,    88,
      47,    48,    49,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      14,    69,    20,    93,    18,    85,    14,    15,    18,    20,
      19,    23,    71,    28,    39,    72,    16,    51,    11,   102,
      50,    39,    20,    51,    11,    98,     8,    65,    52,    69,
      53,     3,     8,    29,    39,   100,    24,     1,     2,   120,
      18,    75,   121,    21,    89,    69,    16,    74,    91,    18,
      70,    51,    39,    27,    24,    65,    16,    98,    20,    92,
      73,    99,   123,    76,    77,    94,    98,   100,    37,    38,
      28,    65,    39,    85,    39,    95,   100,   101,   132,   106,
      96,   109,    89,    89,    86,    87,    89,    98,    69,   104,
      29,   108,    39,    99,    39,   110,    98,   100,   117,   116,
     114,   118,    99,   125,    69,   126,   100,   127,    39,    32,
      33,    34,    35,    39,    65,   122,    22,   129,    26,    39,
     124,    36,   112,    99,     1,     2,   128,    18,   103,   111,
      65,    90,    99,    32,    33,    34,    35,    32,    33,    34,
      35,     0,   113,     0,     0,    36,   105,     0,     0,    36,
      37,    38,     0,     0,    37,    38,    54,     0,   130,   131,
      55,    56,     0,    57,    58,     1,     2,    54,    32,     0,
      97,    55,    56,     4,    57,    58,     1,     2,     0,    32,
       0,    54,     0,     0,     4,    55,    56,   115,    57,    58,
       1,     2,    54,    32,     0,   119,    55,    56,     4,    57,
      58,     1,     2,    54,    32,     0,   133,    55,    56,     4,
      57,    58,     1,     2,    54,    32,     0,     0,    55,    56,
       4,    57,    58,     1,     2,     0,    32,     1,     2,     0,
       3,     4,     0,    78,     0,     4,    79,    80,    81,    82,
      83
};

static const yytype_int16 yycheck[] =
{
       0,    27,     4,    55,    15,    43,     6,    27,    15,    11,
       4,    21,    28,    15,    16,    31,    36,    19,     0,    71,
      31,    23,    24,    25,     6,    61,     0,    27,    23,    55,
      24,    15,     6,    15,    36,    61,    20,    12,    13,    28,
      15,    36,    31,     0,    46,    71,    36,    27,    50,    15,
      20,    53,    54,    28,    20,    55,    36,    93,    60,    54,
      36,    61,   114,    36,    37,    27,   102,    93,    32,    33,
      72,    71,    74,   111,    76,    27,   102,    15,   130,    74,
      27,    76,    84,    85,    34,    35,    88,   123,   114,    37,
      72,    28,    94,    93,    96,    36,   132,   123,    15,    94,
       4,    96,   102,    28,   130,    28,   132,    28,   110,    15,
      16,    17,    18,   115,   114,   110,     6,    37,    11,   121,
     115,    27,    85,   123,    12,    13,   121,    15,    72,    84,
     130,    46,   132,    15,    16,    17,    18,    15,    16,    17,
      18,    -1,    88,    -1,    -1,    27,    28,    -1,    -1,    27,
      32,    33,    -1,    -1,    32,    33,     3,    -1,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,     3,    15,    -1,
       6,     7,     8,    20,    10,    11,    12,    13,    -1,    15,
      -1,     3,    -1,    -1,    20,     7,     8,     9,    10,    11,
      12,    13,     3,    15,    -1,     6,     7,     8,    20,    10,
      11,    12,    13,     3,    15,    -1,     6,     7,     8,    20,
      10,    11,    12,    13,     3,    15,    -1,    -1,     7,     8,
      20,    10,    11,    12,    13,    -1,    15,    12,    13,    -1,
      15,    20,    -1,    19,    -1,    20,    22,    23,    24,    25,
      26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    15,    20,    40,    41,    42,    43,    44,
      46,    48,    49,    50,    57,    27,    36,    47,    15,    45,
      46,     0,    42,    21,    20,    45,    50,    28,    46,    48,
      51,    52,    15,    16,    17,    18,    27,    32,    33,    46,
      57,    61,    62,    63,    64,    65,    67,    69,    70,    71,
      31,    46,    61,    45,     3,     7,     8,    10,    11,    43,
      48,    53,    54,    55,    56,    57,    58,    59,    60,    71,
      20,    28,    31,    36,    27,    61,    36,    37,    19,    22,
      23,    24,    25,    26,    66,    67,    34,    35,    68,    46,
      69,    46,    61,    53,    27,    27,    27,     6,    54,    57,
      71,    15,    53,    52,    37,    28,    61,    72,    28,    61,
      36,    63,    64,    65,     4,     9,    61,    15,    61,     6,
      28,    31,    61,    53,    61,    28,    28,    28,    61,    37,
       5,     6,    53,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    43,    43,
      43,    43,    44,    45,    45,    45,    46,    46,    47,    47,
      47,    47,    47,    47,    48,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    54,    54,    54,    55,    55,    56,
      57,    58,    59,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     2,
       2,     2,     1,     3,     2,     1,     1,     2,     0,     6,
       5,     4,     3,     2,     1,     1,     1,     2,     1,     6,
       5,     3,     1,     3,     3,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     5,     7,     4,
       3,     4,     4,     4,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     4,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 38 "parser.y" /* yacc.c:1646  */
    { aFinal = criaNo("programa", 1, (yyvsp[0].a)); }
#line 1428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 43 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1].a) != NULL){
					if(pertenceArvore((yyval.a), "lista_declaracoes")){
						adicionaFilho((yyval.a), (yyvsp[0].a));
					} else {
						(yyval.a) = criaNo("lista_declaracoes", 1, (yyvsp[0].a));
					}
				} else {
					fprintf(arquivoLog, "lista_declaracoes\n");
					(yyval.a) = criaNo("lista_declaracoes", 1, (yyvsp[0].a));
				}
			}
#line 1445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 55 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("lista_declaracoes", 1, (yyvsp[0].a)); }
#line 1451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 60 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1463 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1469 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 66 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("declaracao_variaveis", 2, (yyvsp[-2].a), (yyvsp[0].a));
			if((yyvsp[-1].pgm)[0] == '\0'){
				printf("falta dois pontos (:) na declaração de variável\n");
			}
		}
#line 1479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 72 "parser.y" /* yacc.c:1646  */
    { /* Tratar aqui */ (yyval.a) = criaNo("declaracao_variaveis", 1, (yyvsp[-1].a)); }
#line 1485 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 74 "parser.y" /* yacc.c:1646  */
    { /* Tratar aqui */ (yyval.a) = criaNo("declaracao_variaveis", 2, (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1491 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 76 "parser.y" /* yacc.c:1646  */
    { /* Tratar aqui */ (yyval.a) = criaNo("declaracao_variaveis", 1, (yyvsp[0].a)); }
#line 1497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 80 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("inicializacao_variaives", 1, (yyvsp[0].a)); }
#line 1503 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 85 "parser.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-2].a) != NULL){
				if(pertenceArvore((yyval.a), "lista_variaveis")){
					adicionaFilho((yyval.a), criaNo(",", 0));
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("lista_variaveis", 2, (yyvsp[0].a), criaNo(",", 0));
				}
			} else {
				fprintf(arquivoLog, "lista_variaveis\n");
				(yyval.a) = criaNo("lista_variaveis", 2, (yyvsp[0].a), criaNo(",", 0));
			}
		}
#line 1521 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 99 "parser.y" /* yacc.c:1646  */
    { 
			/* Tratar aqui */ 
			if((yyvsp[-1].a) != NULL){
				if(pertenceArvore((yyval.a), "lista_variaveis")){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("lista_variaveis", 1, (yyvsp[0].a));
				}
			} else {
				fprintf(arquivoLog, "lista_variaveis\n");
				(yyval.a) = criaNo("lista_variaveis", 1, (yyvsp[0].a));
			}
		}
#line 1539 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("lista_variaveis", 1, (yyvsp[0].a)); }
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("var", 1, criaNo((yyvsp[0].pgm), 0)); }
#line 1551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("var", 2, criaNo((yyvsp[-1].pgm), 0), (yyvsp[0].a)); }
#line 1557 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("indice", 6, criaNo("[", 0), (yyvsp[-4].a), criaNo("]", 0), criaNo("[", 0), (yyvsp[-1].a), criaNo("]", 0)); }
#line 1563 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 122 "parser.y" /* yacc.c:1646  */
    { /* Tratar aqui */ (yyval.a) = criaNo("indice", 5, criaNo("[", 0), (yyvsp[-3].a), criaNo("]", 0), criaNo("[", 0), (yyvsp[0].a)); }
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 123 "parser.y" /* yacc.c:1646  */
    { /* Tratar aqui */ (yyval.a) = criaNo("indice", 4, criaNo("[", 0), (yyvsp[-2].a), criaNo("[", 0), (yyvsp[0].a)); }
#line 1575 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("indice", 3, criaNo("[", 0), (yyvsp[-1].a), criaNo("]", 0)); }
#line 1581 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 125 "parser.y" /* yacc.c:1646  */
    { /* Tratar aqui */ (yyval.a) = criaNo("indice", 2, criaNo("[", 0), (yyvsp[0].a)); }
#line 1587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 1593 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 1599 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 131 "parser.y" /* yacc.c:1646  */
    { /* Tratar aqui */ (yyval.a) = criaNo("nada", 0); }
#line 1605 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("declaracao_funcao", 2, (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1611 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("declaracao_funcao", 1, (yyvsp[0].a)); }
#line 1617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 141 "parser.y" /* yacc.c:1646  */
    {
			auxiliar = criaNo((yyvsp[-5].pgm), 0);
			(yyval.a) = criaNo("cabecalho", 3, auxiliar, (yyvsp[-3].a), (yyvsp[-1].a)); 
		}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("cabecalho", 2, criaNo((yyvsp[-4].pgm), 0), (yyvsp[-1].a)); }
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 150 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].a) != NULL){
				if(pertenceArvore((yyval.a), "lista_parametros")){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("lista_parametros", 1, (yyvsp[0].a));
				}
			} else {
				fprintf(arquivoLog, "lista_parametros\n");
				(yyval.a) = criaNo("lista_parametros", 1, (yyvsp[0].a));
			}	

		}
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("lista_parametros", 1, (yyvsp[0].a)); }
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 168 "parser.y" /* yacc.c:1646  */
    {
			auxiliar = criaNo((yyvsp[0].pgm), 0);
			(yyval.a) = criaNo("parametro", 2, (yyvsp[-2].a), auxiliar);
		}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 173 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].a) != NULL){
				if(pertenceArvore((yyval.a), "parametro")){
					auxiliar = criaNo("[", 0);
					adicionaFilho((yyval.a), auxiliar);
					auxiliar = criaNo("]", 0);
					adicionaFilho((yyval.a), auxiliar);					
				} else {
					(yyval.a) = criaNo("parametro", 2, criaNo("[", 0), criaNo("]", 0));					
				}
			} else {
				fprintf(arquivoLog, "parametro\n");
				(yyval.a) = criaNo("parametro", 2, criaNo("[", 0), criaNo("]", 0));					
			}
		}
#line 1685 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("corpo", 1, (yyvsp[0].a)); }
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 193 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].a) != NULL){
				if(pertenceArvore((yyval.a), "corpo")){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
				}
			} else {
				fprintf(arquivoLog, "corpo\n");
				(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
			}
		}
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("corpo", 1, (yyvsp[0].a)); }
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 207 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].a) != NULL){
				if(pertenceArvore((yyval.a), "corpo")){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
				}
			} else {
				fprintf(arquivoLog, "corpo\n");
				(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
			}
		}
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("corpo", 1, (yyvsp[0].a)); }
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 221 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].a) != NULL){
				if(pertenceArvore((yyval.a), "corpo")){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
				}
			} else {
				fprintf(arquivoLog, "corpo\n");
				(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
			}
		}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("acao", 1, (yyvsp[0].a)); }
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 238 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("acao", 1, (yyvsp[0].a)); }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("acao", 1, (yyvsp[0].a)); }
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("acao", 1, (yyvsp[0].a)); }
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 241 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("acao", 1, (yyvsp[0].a)); }
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("se", 2, (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("se", 3, (yyvsp[-5].a), (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("repita", 2, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("atribuicao", 2, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 259 "parser.y" /* yacc.c:1646  */
    {	
			auxiliar = criaNo((yyvsp[-1].pgm), 0);
			(yyval.a) = criaNo("LEIA", 1, auxiliar);
		}
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("ESCREVA", 1, (yyvsp[-1].a)); }
#line 1829 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("RETORNA", 1, (yyvsp[-1].a)); }
#line 1835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao", 1, (yyvsp[0].a)); }
#line 1841 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao", 1, (yyvsp[0].a)); }
#line 1847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao_simples", 1, (yyvsp[0].a)); }
#line 1853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 281 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].a) != NULL){
				if(pertenceArvore((yyval.a), "expressao_simples")){
					if((yyvsp[-1].a) != NULL){
						adicionaFilho((yyval.a), (yyvsp[-1].a));
					}
					if((yyvsp[0].a) != NULL){
						adicionaFilho((yyval.a), (yyvsp[0].a));
					}
				}
			} else {
				fprintf(arquivoLog, "expressao_simples\n");
				//ver se em algum teste cai aqui
				(yyval.a) = criaNo("expressao_simples", 0);
				if((yyvsp[-1].a) != NULL){
					adicionaFilho((yyval.a), (yyvsp[-1].a));
				}
				if((yyvsp[0].a) != NULL){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				}
			}
		}
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao_aditiva", 1, (yyvsp[0].a)); }
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 308 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].a) != NULL){
				if(pertenceArvore((yyval.a), "expressao_aditiva")){
					if((yyvsp[-1].a) != NULL){
						adicionaFilho((yyval.a), (yyvsp[-1].a));
					}
					if((yyvsp[0].a) != NULL){
						adicionaFilho((yyval.a), (yyvsp[0].a));
					}
				}
			} else {
				fprintf(arquivoLog, "expressao_aditiva\n");
				//ver se em algum teste cai aqui
				(yyval.a) = criaNo("expressao_aditiva", 0);
				if((yyvsp[-1].a) != NULL){
					adicionaFilho((yyval.a), (yyvsp[-1].a));
				}
				if((yyvsp[0].a) != NULL){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				}
			}
		}
#line 1913 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao_multiplicativa", 1, (yyvsp[0].a)); }
#line 1919 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 335 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].a) != NULL){
				if(pertenceArvore((yyval.a), "expressao_multiplicativa")){
					if((yyvsp[-1].a) != NULL){
						adicionaFilho((yyval.a), (yyvsp[-1].a));
					}
					if((yyvsp[0].a) != NULL){
						adicionaFilho((yyval.a), (yyvsp[0].a));
					}
				}
			} else {
				fprintf(arquivoLog, "expressao_multiplicativa\n");
				//ver se em algum teste cai aqui
				(yyval.a) = criaNo("expressao_multiplicativa", 0);
				if((yyvsp[-1].a) != NULL){
					adicionaFilho((yyval.a), (yyvsp[-1].a));
				}
				if((yyvsp[0].a) != NULL){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				}
			}
		}
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 360 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao_unaria", 1, (yyvsp[0].a)); }
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 362 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].a) != NULL){
				if(pertenceArvore((yyval.a), "expressao_unaria")){
					if((yyvsp[-1].a) != NULL){
						adicionaFilho((yyval.a), (yyvsp[-1].a));
					}
				}
			} else {
				fprintf(arquivoLog, "expressao_unaria\n");
				//ver se em algum teste cai aqui
				(yyval.a) = criaNo("expressao_unaria", 0);
				if((yyvsp[-1].a) != NULL){
					adicionaFilho((yyval.a), (yyvsp[-1].a));
				}
			}
			
		}
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 382 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 1980 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 383 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 1986 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 384 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 1992 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 385 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 386 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2004 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 387 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 391 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2016 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 392 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 396 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 397 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2034 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 401 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("fator", 1, (yyvsp[-1].a)); }
#line 2040 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 402 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("fator", 1, (yyvsp[0].a)); }
#line 2046 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 403 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("fator", 1, (yyvsp[0].a)); }
#line 2052 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 404 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("fator", 1, (yyvsp[0].a)); }
#line 2058 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 409 "parser.y" /* yacc.c:1646  */
    {
			auxiliar = criaNo((yyvsp[0].pgm), 0);
			(yyval.a) = criaNo("numero", 1, auxiliar);
		}
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 414 "parser.y" /* yacc.c:1646  */
    {
			auxiliar = criaNo((yyvsp[0].pgm), 0);
			(yyval.a) = criaNo("numero", 1, auxiliar);
		}
#line 2076 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 419 "parser.y" /* yacc.c:1646  */
    {
			auxiliar = criaNo((yyvsp[0].pgm), 0);
			(yyval.a) = criaNo("numero", 1, auxiliar);
		}
#line 2085 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 426 "parser.y" /* yacc.c:1646  */
    {	(yyval.a) = criaNo("chamada_funcao", 2, criaNo((yyvsp[-3].pgm), 0), (yyvsp[-1].a)); }
#line 2091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 427 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("chamada_funcao", 1, criaNo((yyvsp[-2].pgm), 0)); }
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 431 "parser.y" /* yacc.c:1646  */
    {	
			if((yyvsp[-2].a) != NULL){
				if(pertenceArvore((yyval.a), "lista_argumentos")){
					adicionaFilho((yyval.a), (yyvsp[0].a));					
				} else {
					(yyval.a) = criaNo("lista_argumentos", 1, (yyvsp[0].a));					
				}
			} else {
				fprintf(arquivoLog, "chamada_funcao\n");
				(yyval.a) = criaNo("lista_argumentos", 1, (yyvsp[0].a));					
			}
		}
#line 2114 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 443 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("lista_argumentos", 1, (yyvsp[0].a)); }
#line 2120 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2124 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 447 "parser.y" /* yacc.c:1906  */

void yyerror(char *s) {
	if(compareString(s, "syntax error") == 0){
		printf("\033[0m[\033[1m\033[31merro\033[0m] erro inesperado na linha %d\n", linha);
		exit(1);
	} else {
		fprintf(stdout, "%s\n", s);
	}
}

int main(int argc, char *argv[]){
	erroSemantico = false;
	arquivoSemantico = fopen("semantico.txt", "w");
	arquivoLog = fopen("log.txt", "w");
	yyin = fopen(argv[1], "r");
	yyparse();	
	fclose(yyin);
	imprimeArvore(aFinal);
	fclose(arquivoSemantico);
	fclose(arquivoLog);
	verificarLog();
	gerandoDot(aFinal);
	return 0;
}
