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
	char nomeArquivo[MAX];
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
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

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
      72,    76,    80,    94,    98,    99,   103,   105,   115,   116,
     120,   121,   125,   144,   148,   162,   177,   181,   183,   185,
     187,   189,   191,   193,   195,   197,   199,   201,   204,   205,
     206,   207,   208,   210,   212,   214,   216,   218,   220,   222,
     223,   224,   225,   226,   228,   230,   232,   234,   236,   238,
     242,   243,   256,   257,   270,   271,   287,   288,   289,   290,
     291,   292,   296,   297,   301,   305,   309,   310,   314,   315,
     319,   320,   324,   325,   329,   330,   356,   357,   383,   384,
     410,   411,   432,   433,   434,   435,   436,   437,   441,   442,
     446,   447,   451,   452,   453,   454,   458,   463,   468,   476,
     477,   481,   494
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

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     133,   -55,   -55,   -15,     1,    20,   133,   -55,   -55,   -55,
       6,    25,   -55,   -55,   -55,    19,   125,   -55,    17,    35,
     -55,   -55,   -55,   125,     1,    35,   -55,    66,   216,    39,
      45,   -55,   -10,   -55,   -55,   -55,   125,   -55,   -55,     6,
     -55,    38,   215,   -19,    44,   -55,   107,   -55,   -55,   -55,
       1,   -55,    35,     7,   125,   216,    74,    80,    84,   -55,
      47,   169,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
      46,    99,   216,    36,   -55,   100,    91,   108,   -55,   -55,
     -55,   -55,   -55,   -55,   125,   125,   -55,   -55,   125,   -55,
     -55,   -55,    51,    54,   147,   183,   125,   139,   125,   -55,
     -55,   -55,   -55,    56,    60,    67,   194,   -55,   -55,   -55,
       5,   -55,   125,   -19,    44,   -55,   119,    94,   130,   -55,
     216,   125,   146,   155,   157,   162,   101,   173,   -55,   113,
     123,   -55,   -55,   125,   184,   -55,   185,   -55,   -55,   158,
     -55,   -55,   -55,   -55,   -55,   193,   -55,   -55,   195,   151,
     196,   -55,   -55,   -55,   -55,   216,   -55,   -55,   -55,   198,
     -55,   -55,   205,   -55,   -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    19,    14,     0,     0,     2,     4,     5,     6,
       0,     0,     7,    21,    11,     0,     0,    15,    14,    10,
      13,     1,     3,     0,     0,     9,    20,     0,     0,     0,
       0,    26,    14,   106,   107,   108,     0,    98,    99,   103,
      82,     0,    83,    84,    86,    88,     0,    90,   105,   104,
       0,    75,     8,    49,     0,     0,     0,     0,     0,    66,
       0,     0,    60,    67,    68,    62,    69,    70,    71,    64,
      38,     0,     0,     0,    25,     0,     0,    17,    94,    92,
      96,    93,    97,    95,     0,     0,   100,   101,     0,   103,
      91,    12,    51,    52,     0,     0,     0,     0,     0,    23,
      61,    63,    65,    40,    41,    27,     0,    24,   110,   112,
       0,   102,     0,    85,    87,    89,    57,    50,     0,    55,
       0,     0,    81,    77,    79,    46,    39,     0,    44,    29,
      30,    22,   109,     0,     0,    58,    59,    56,    54,     0,
      74,    80,    76,    78,    47,    48,    45,    43,    35,    28,
       0,    33,   111,    16,    53,     0,    72,    42,    36,    37,
      34,    32,     0,    31,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   -55,   236,     9,   -55,    -1,    14,   -55,     4,
     -55,   232,   -55,   -22,   -50,   -54,   -55,   -55,     0,   -55,
     -55,   -55,   -12,   -55,   160,   161,   159,   -55,   -42,   -55,
     199,   -55,   -26,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    59,     9,    25,    10,    17,    60,
      12,    13,    30,    31,    61,    62,    63,    64,    40,    66,
      67,    68,    41,    42,    43,    44,    45,    84,    46,    88,
      47,    48,    49,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      14,    85,    69,    19,    11,    95,    14,   100,    74,     8,
      11,    51,    15,    37,    38,     8,    18,    75,    20,    29,
      21,    16,   106,    52,    76,    20,    16,    23,    65,    69,
      39,     1,     2,   132,    29,   102,   133,    39,    20,    27,
       3,   100,    94,    92,    93,    24,    69,    28,     1,     2,
      39,   107,   100,    16,    70,    65,    27,     1,     2,    71,
      89,   101,    18,   109,    91,    27,    50,    24,    39,   102,
     139,    85,    65,    72,    20,    77,    73,    29,    86,    87,
     102,    53,   103,   104,   122,   100,   124,   116,   117,    39,
     118,   119,   125,   126,    69,   101,   127,   128,    89,    89,
     134,    96,    89,   129,   130,   162,   101,    97,   100,   140,
      39,    98,    39,   102,   105,    32,    33,    34,    35,   111,
      65,   152,    32,    33,    34,    35,    39,    36,   108,    69,
     136,   137,    37,    38,    36,    39,   102,   145,   146,   101,
      32,    33,    34,    35,   112,     1,     2,    39,     3,   148,
     149,   120,    36,     4,   123,    65,   135,    37,    38,   150,
     151,    54,   101,   155,   156,    55,    56,   138,    57,    58,
       1,     2,    54,    32,   141,    99,    55,    56,     4,    57,
      58,     1,     2,   142,    32,   143,    54,   159,   160,     4,
      55,    56,   121,    57,    58,     1,     2,    54,    32,   144,
     131,    55,    56,     4,    57,    58,     1,     2,    54,    32,
     147,   164,    55,    56,     4,    57,    58,     1,     2,    54,
      32,   153,   154,    55,    56,     4,    57,    58,     1,     2,
     157,    32,   158,   161,    78,   163,     4,    79,    80,    81,
      82,    83,    22,    26,   113,    90,   114,   115
};

static const yytype_uint8 yycheck[] =
{
       0,    43,    28,     4,     0,    55,     6,    61,    30,     0,
       6,    23,    27,    32,    33,     6,    15,    27,     4,    15,
       0,    36,    72,    24,    36,    11,    36,    21,    28,    55,
      16,    12,    13,    28,    30,    61,    31,    23,    24,    20,
      15,    95,    54,    36,    37,    20,    72,    28,    12,    13,
      36,    73,   106,    36,    15,    55,    20,    12,    13,    20,
      46,    61,    15,    75,    50,    20,    31,    20,    54,    95,
     120,   113,    72,    28,    60,    37,    31,    73,    34,    35,
     106,    15,    36,    37,    96,   139,    98,    36,    37,    75,
      36,    37,    36,    37,   120,    95,    36,    37,    84,    85,
     112,    27,    88,    36,    37,   155,   106,    27,   162,   121,
      96,    27,    98,   139,    15,    15,    16,    17,    18,    28,
     120,   133,    15,    16,    17,    18,   112,    27,    28,   155,
      36,    37,    32,    33,    27,   121,   162,    36,    37,   139,
      15,    16,    17,    18,    36,    12,    13,   133,    15,    36,
      37,     4,    27,    20,    15,   155,    37,    32,    33,    36,
      37,     3,   162,     5,     6,     7,     8,    37,    10,    11,
      12,    13,     3,    15,    28,     6,     7,     8,    20,    10,
      11,    12,    13,    28,    15,    28,     3,    36,    37,    20,
       7,     8,     9,    10,    11,    12,    13,     3,    15,    37,
       6,     7,     8,    20,    10,    11,    12,    13,     3,    15,
      37,     6,     7,     8,    20,    10,    11,    12,    13,     3,
      15,    37,    37,     7,     8,    20,    10,    11,    12,    13,
      37,    15,    37,    37,    19,    37,    20,    22,    23,    24,
      25,    26,     6,    11,    84,    46,    85,    88
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    15,    20,    40,    41,    42,    43,    44,
      46,    48,    49,    50,    57,    27,    36,    47,    15,    45,
      46,     0,    42,    21,    20,    45,    50,    20,    28,    48,
      51,    52,    15,    16,    17,    18,    27,    32,    33,    46,
      57,    61,    62,    63,    64,    65,    67,    69,    70,    71,
      31,    61,    45,    15,     3,     7,     8,    10,    11,    43,
      48,    53,    54,    55,    56,    57,    58,    59,    60,    71,
      15,    20,    28,    31,    52,    27,    61,    37,    19,    22,
      23,    24,    25,    26,    66,    67,    34,    35,    68,    46,
      69,    46,    36,    37,    61,    53,    27,    27,    27,     6,
      54,    57,    71,    36,    37,    15,    53,    52,    28,    61,
      72,    28,    36,    63,    64,    65,    36,    37,    36,    37,
       4,     9,    61,    15,    61,    36,    37,    36,    37,    36,
      37,     6,    28,    31,    61,    37,    36,    37,    37,    53,
      61,    28,    28,    28,    37,    36,    37,    37,    36,    37,
      36,    37,    61,    37,    37,     5,     6,    37,    37,    36,
      37,    37,    53,    37,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    43,    43,
      43,    44,    45,    45,    46,    46,    47,    47,    48,    48,
      49,    49,    50,    50,    51,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    55,    55,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    71,
      71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     2,
       2,     1,     3,     1,     1,     2,     6,     3,     1,     1,
       2,     1,     6,     5,     3,     2,     1,     3,     5,     4,
       4,     7,     6,     5,     6,     5,     6,     6,     2,     4,
       3,     3,     6,     5,     4,     5,     4,     5,     5,     2,
       4,     3,     3,     6,     5,     4,     5,     4,     5,     5,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     5,     7,     4,     3,     4,     3,     4,     3,
       4,     3,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       3,     3,     1
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
#line 1446 "parser.tab.c" /* yacc.c:1646  */
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
					fprintf(arquivoSemantico, "lista_declaracoes\n");
					(yyval.a) = criaNo("lista_declaracoes", 1, (yyvsp[0].a));
				}
			}
#line 1463 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 55 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("lista_declaracoes", 1, (yyvsp[0].a)); }
#line 1469 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1475 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 60 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 66 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("declaracao_variaveis", 2, (yyvsp[-2].a), (yyvsp[0].a));
			if((yyvsp[-1].pgm)[0] == '\0'){
				printf("falta dois pontos (:) na declaração de variável\n");
			}
		}
#line 1497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 71 "parser.y" /* yacc.c:1646  */
    { erroSemantico = true; (yyval.a) = criaNo("declaracao_variaveis", 1, (yyvsp[0].a)); erroDeclaraVariavel((yyvsp[-1].a), (yyvsp[0].a), 1); }
#line 1503 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 72 "parser.y" /* yacc.c:1646  */
    { erroSemantico = true; (yyval.a) = criaNo("declaracao_variaveis", 1, (yyvsp[0].a)); erroDeclaraVariavel(NULL, (yyvsp[0].a), 2); }
#line 1509 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 76 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("inicializacao_variaveis", 1, (yyvsp[0].a)); }
#line 1515 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "parser.y" /* yacc.c:1646  */
    { 
			if((yyvsp[-2].a) != NULL){
				if(pertenceArvore((yyval.a), "lista_variaveis")){
					adicionaFilho((yyval.a), criaNo(",", 0));
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("lista_variaveis", 2, (yyvsp[0].a), criaNo(",", 0));
				}
			} else {
				fprintf(arquivoSemantico, "lista_variaveis\n");
				(yyval.a) = criaNo("lista_variaveis", 2, (yyvsp[0].a), criaNo(",", 0));
			}
		}
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("lista_variaveis", 1, (yyvsp[0].a)); }
#line 1539 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("var", 1, criaNo((yyvsp[0].pgm), 0));	}
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("var", 2, criaNo((yyvsp[-1].pgm), 0), (yyvsp[0].a)); }
#line 1551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 104 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("indice", 6, criaNo("[", 0), (yyvsp[-4].a), criaNo("]", 0), criaNo("[", 0), (yyvsp[-1].a), criaNo("]", 0)); }
#line 1557 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 106 "parser.y" /* yacc.c:1646  */
    {
			(yyval.a) = criaNo("indice", 3, criaNo("[", 0), (yyvsp[-1].a), criaNo("]", 0)); 
			if(indiceEhInteiro((yyvsp[-1].a)) == false){
				erroSemantico = true;
			}
		}
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("declaracao_funcao", 2, (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("declaracao_funcao", 1, (yyvsp[0].a)); }
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 126 "parser.y" /* yacc.c:1646  */
    {
			(yyval.a) = criaNo("cabecalho", 3, criaNo((yyvsp[-5].pgm), 0), (yyvsp[-3].a), (yyvsp[-1].a));
			if(erroParametro || erroIndiceParametro || erroDoisIndiceParametro || erroTipoIndiceParametro){
				erroSemantico = true;
				erroFuncao((yyvsp[-5].pgm));
				erroListaParametros((yyvsp[-3].a));
			}
			erroParametro = false;
			erroIndiceParametro = false;
			erroDoisIndiceParametro = false;
			if(erroCorpo){
				erroSemantico = true;
				erroFuncao((yyvsp[-5].pgm));
				erroCorpoFuncao((yyvsp[-1].a));
			}
			erroCorpo = false;
			erroLeia = false;
		}
#line 1615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("cabecalho", 2, criaNo((yyvsp[-4].pgm), 0), (yyvsp[-1].a)); }
#line 1621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 149 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-2].a) != NULL){
				if(pertenceArvore((yyval.a), "lista_parametros")){
					adicionaFilho((yyval.a), criaNo(",", 0));
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("lista_parametros", 2, (yyvsp[0].a), criaNo(",", 0));
				}
			} else {
				fprintf(arquivoSemantico, "lista_parametros\n");
				(yyval.a) = criaNo("lista_parametros", 2, (yyvsp[0].a), criaNo(",", 0));
			}
		}
#line 1639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 163 "parser.y" /* yacc.c:1646  */
    {
			erroParametro = true;
			if((yyvsp[-1].a) != NULL){
				if(pertenceArvore((yyval.a), "lista_parametros")){
					adicionaFilho((yyval.a), criaNo("!@#", 0));
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("lista_parametros", 2, (yyvsp[0].a), criaNo(",", 0));
				}
			} else {
				fprintf(arquivoSemantico, "lista_parametros\n");
				(yyval.a) = criaNo("lista_parametros", 2, (yyvsp[0].a), criaNo(",", 0));
			}
		}
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("lista_parametros", 1, (yyvsp[0].a)); }
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 181 "parser.y" /* yacc.c:1646  */
    {	(yyval.a) = criaNo("parametro", 3, (yyvsp[-2].a), criaNo(":", 0), criaNo((yyvsp[0].pgm), 0)); }
#line 1670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("parametro", 5, (yyvsp[-4].a), criaNo(":", 0), criaNo((yyvsp[-2].pgm), 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 185 "parser.y" /* yacc.c:1646  */
    { erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 4, (yyvsp[-3].a), criaNo(":", 0), criaNo((yyvsp[-1].pgm), 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 187 "parser.y" /* yacc.c:1646  */
    { erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 4, (yyvsp[-3].a), criaNo(":", 0), criaNo((yyvsp[-1].pgm), 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("parametro", 7, (yyvsp[-6].a), criaNo(":", 0), criaNo((yyvsp[-4].pgm), 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 191 "parser.y" /* yacc.c:1646  */
    { erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-5].a), criaNo(":", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 193 "parser.y" /* yacc.c:1646  */
    { erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-4].a), criaNo(":", 0), criaNo((yyvsp[-2].pgm), 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 195 "parser.y" /* yacc.c:1646  */
    { erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-5].a), criaNo(":", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("[", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 197 "parser.y" /* yacc.c:1646  */
    { erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-4].a), criaNo(":", 0), criaNo((yyvsp[-2].pgm), 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 199 "parser.y" /* yacc.c:1646  */
    { erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-5].a), criaNo(":", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 201 "parser.y" /* yacc.c:1646  */
    { erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-5].a), criaNo(":", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 204 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; (yyval.a) = criaNo("parametro", 3, (yyvsp[-1].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[0].pgm), 0));}
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 205 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; (yyval.a) = criaNo("parametro", 5, (yyvsp[-3].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[-2].pgm), 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 206 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 5, (yyvsp[-2].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[-1].pgm), 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 207 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 5, (yyvsp[-2].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[-1].pgm), 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 208 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-5].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[-4].pgm), 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 210 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-4].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 212 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-3].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[-2].pgm), 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 214 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-4].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("[", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 216 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-3].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[-2].pgm), 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 218 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-4].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 220 "parser.y" /* yacc.c:1646  */
    { erroDoisIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 7, (yyvsp[-4].a), criaNo("\033[1m\033[31m:\033[0m", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 222 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; (yyval.a) = criaNo("parametro", 2, criaNo(":", 0), criaNo((yyvsp[0].pgm), 0)); }
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 223 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; (yyval.a) = criaNo("parametro", 4, criaNo(":", 0), criaNo((yyvsp[-2].pgm), 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 224 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 4, criaNo(":", 0), criaNo((yyvsp[-1].pgm), 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 225 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 4, criaNo(":", 0), criaNo((yyvsp[-1].pgm), 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 226 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; (yyval.a) = criaNo("parametro", 6, criaNo(":", 0), criaNo((yyvsp[-4].pgm), 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 228 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 6, criaNo(":", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 230 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 6, criaNo(":", 0), criaNo((yyvsp[-2].pgm), 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 232 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 6, criaNo(":", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("[", 0), criaNo("]", 0), criaNo("\033[1m\033[31m[\033[0m", 0), criaNo("]", 0)); }
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 234 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 6, criaNo(":", 0), criaNo((yyvsp[-2].pgm), 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 236 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 6, criaNo(":", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0), criaNo("[", 0), criaNo("]", 0)); }
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 238 "parser.y" /* yacc.c:1646  */
    { erroTipoIndiceParametro = true; erroIndiceParametro = true; (yyval.a) = criaNo("parametro", 6, criaNo(":", 0), criaNo((yyvsp[-3].pgm), 0), criaNo("[", 0), criaNo("]", 0), criaNo("[", 0), criaNo("\033[1m\033[31m]\033[0m", 0)); }
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("corpo", 1, (yyvsp[0].a)); }
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 244 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].a) != NULL){
				if(pertenceArvore((yyval.a), "corpo")){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
				}
			} else {
				fprintf(arquivoSemantico, "corpo\n");
				(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
			}
		}
#line 1885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("corpo", 1, (yyvsp[0].a)); }
#line 1891 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 258 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].a) != NULL){
				if(pertenceArvore((yyval.a), "corpo")){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
				}
			} else {
				fprintf(arquivoSemantico, "corpo\n");
				(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
			}
		}
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("corpo", 1, (yyvsp[0].a)); }
#line 1914 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 272 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[-1].a) != NULL){
				if(pertenceArvore((yyval.a), "corpo")){
					adicionaFilho((yyval.a), (yyvsp[0].a));
				} else {
					(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
				}
			} else {
				fprintf(arquivoSemantico, "corpo\n");
				(yyval.a) = criaNo("corpo", 1, (yyvsp[0].a));
			}
		}
#line 1931 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("acao", 1, (yyvsp[0].a)); }
#line 1943 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("acao", 1, (yyvsp[0].a)); }
#line 1949 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 290 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("acao", 1, (yyvsp[0].a)); }
#line 1955 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 291 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("acao", 1, (yyvsp[0].a)); }
#line 1961 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 292 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("acao", 1, (yyvsp[0].a)); }
#line 1967 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 296 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("se", 2, (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 1973 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 297 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("se", 3, (yyvsp[-5].a), (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 1979 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 301 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("repita", 2, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("atribuicao", 2, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 1991 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 309 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("LEIA", 1, criaNo((yyvsp[-1].pgm), 0)); }
#line 1997 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 310 "parser.y" /* yacc.c:1646  */
    { erroCorpo = true; erroLeia = true; (yyval.a) = criaNo("LEIA", 3, criaNo("(", 0), criaNo((yyvsp[0].pgm), 0), criaNo("\033[1m\033[31m)\033[0m", 0)); }
#line 2003 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 314 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("ESCREVA", 1, (yyvsp[-1].a)); }
#line 2009 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 315 "parser.y" /* yacc.c:1646  */
    { erroCorpo = true; erroEscreva = true; (yyval.a) = criaNo("ESCREVA", 3, criaNo("(", 0), (yyvsp[0].a), criaNo("\033[1m\033[31m)\033[0m", 0)); }
#line 2015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 319 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("RETORNA", 1, (yyvsp[-1].a)); }
#line 2021 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 320 "parser.y" /* yacc.c:1646  */
    { erroCorpo = true; erroRetorna = true; (yyval.a) = criaNo("RETORNA", 3, criaNo("(", 0), (yyvsp[0].a), criaNo("\033[1m\033[31m)\033[0m", 0)); }
#line 2027 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 324 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao", 1, (yyvsp[0].a)); }
#line 2033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 325 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao", 1, (yyvsp[0].a)); }
#line 2039 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 329 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao_simples", 1, (yyvsp[0].a)); }
#line 2045 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 331 "parser.y" /* yacc.c:1646  */
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
				fprintf(arquivoSemantico, "expressao_simples\n");
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
#line 2072 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 356 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao_aditiva", 1, (yyvsp[0].a)); }
#line 2078 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 358 "parser.y" /* yacc.c:1646  */
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
				fprintf(arquivoSemantico, "expressao_aditiva\n");
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
#line 2105 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 383 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao_multiplicativa", 1, (yyvsp[0].a)); }
#line 2111 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 385 "parser.y" /* yacc.c:1646  */
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
				fprintf(arquivoSemantico, "expressao_multiplicativa\n");
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
#line 2138 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 410 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("expressao_unaria", 1, (yyvsp[0].a)); }
#line 2144 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 412 "parser.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].a) != NULL){
				if(pertenceArvore((yyval.a), "expressao_unaria")){
					if((yyvsp[-1].a) != NULL){
						adicionaFilho((yyval.a), (yyvsp[-1].a));
					}
				}
			} else {
				fprintf(arquivoSemantico, "expressao_unaria\n");
				//ver se em algum teste cai aqui
				(yyval.a) = criaNo("expressao_unaria", 0);
				if((yyvsp[-1].a) != NULL){
					adicionaFilho((yyval.a), (yyvsp[-1].a));
				}
			}
			
		}
#line 2166 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 432 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2172 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 433 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2178 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 434 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2184 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 435 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2190 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 436 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2196 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 437 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2202 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 441 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2208 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 442 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2214 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 446 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2220 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 447 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo((yyvsp[0].pgm), 0); }
#line 2226 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 451 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("fator", 1, (yyvsp[-1].a)); }
#line 2232 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 452 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("fator", 1, (yyvsp[0].a)); }
#line 2238 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 453 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("fator", 1, (yyvsp[0].a)); }
#line 2244 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 454 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("fator", 1, (yyvsp[0].a)); }
#line 2250 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 459 "parser.y" /* yacc.c:1646  */
    {
			auxiliar = criaNo((yyvsp[0].pgm), 0);
			(yyval.a) = criaNo("numero", 1, auxiliar);
		}
#line 2259 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 464 "parser.y" /* yacc.c:1646  */
    {
			auxiliar = criaNo((yyvsp[0].pgm), 0);
			(yyval.a) = criaNo("numero", 1, auxiliar);
		}
#line 2268 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 469 "parser.y" /* yacc.c:1646  */
    {
			auxiliar = criaNo((yyvsp[0].pgm), 0);
			(yyval.a) = criaNo("numero", 1, auxiliar);
		}
#line 2277 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 476 "parser.y" /* yacc.c:1646  */
    {	(yyval.a) = criaNo("chamada_funcao", 2, criaNo((yyvsp[-3].pgm), 0), (yyvsp[-1].a)); }
#line 2283 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 477 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("chamada_funcao", 1, criaNo((yyvsp[-2].pgm), 0)); }
#line 2289 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 482 "parser.y" /* yacc.c:1646  */
    {	
			if((yyvsp[-2].a) != NULL){
				if(pertenceArvore((yyval.a), "lista_argumentos")){
					adicionaFilho((yyval.a), (yyvsp[0].a));					
				} else {
					(yyval.a) = criaNo("lista_argumentos", 1, (yyvsp[0].a));					
				}
			} else {
				fprintf(arquivoSemantico, "chamada_funcao\n");
				(yyval.a) = criaNo("lista_argumentos", 1, (yyvsp[0].a));					
			}
		}
#line 2306 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 494 "parser.y" /* yacc.c:1646  */
    { (yyval.a) = criaNo("lista_argumentos", 1, (yyvsp[0].a)); }
#line 2312 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2316 "parser.tab.c" /* yacc.c:1646  */
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
#line 498 "parser.y" /* yacc.c:1906  */

void yyerror(char *s) {
	if(compareString(s, "syntax error") == 0){
		erroSemantico = true;
		erroGrave = true;
		fprintf(arquivoSemantico, "\033[0m[\033[1m\033[31merro\033[0m] erro inesperado na linha %d\n", erroLinha);
		fclose(arquivoSemantico);
		imprimeErro(nomeArquivo, aFinal);
		exit(1);
	} else {
		fprintf(stdout, "%s\n", s);
	}
}

int main(int argc, char *argv[]){
	strcpy(nomeArquivo, argv[1]);
	erroGrave = false;
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
	system("reset");
	imprimeErro(argv[1], aFinal);
	return 0;
}

