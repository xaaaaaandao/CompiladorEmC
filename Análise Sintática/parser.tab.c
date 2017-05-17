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
	#include <string.h>
	#include "syntax-tree.h"

	/* Protótipos */
	int yylex(void);
	void yyerror(char *s);
	extern FILE *yyin;
	extern FILE *yyout;

#line 80 "parser.tab.c" /* yacc.c:339  */

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
    COMENTARIO = 274,
    IGUAL = 275,
    DOISPONTOS = 276,
    ATRIBUICAO = 277,
    MENOR = 278,
    MENORIGUAL = 279,
    MAIOR = 280,
    MAIORIGUAL = 281,
    DIFERENTE = 282,
    ABREPARENTESES = 283,
    FECHAPARENTESES = 284,
    ABRECHAVE = 285,
    FECHACHAVE = 286,
    VIRGULA = 287,
    ADICAO = 288,
    SUBTRACAO = 289,
    MULTIPLICACAO = 290,
    DIVISAO = 291,
    ABRECOLCHETE = 292,
    FECHACOLCHETE = 293,
    END_OF_FILE = 294
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
#define COMENTARIO 274
#define IGUAL 275
#define DOISPONTOS 276
#define ATRIBUICAO 277
#define MENOR 278
#define MENORIGUAL 279
#define MAIOR 280
#define MAIORIGUAL 281
#define DIFERENTE 282
#define ABREPARENTESES 283
#define FECHAPARENTESES 284
#define ABRECHAVE 285
#define FECHACHAVE 286
#define VIRGULA 287
#define ADICAO 288
#define SUBTRACAO 289
#define MULTIPLICACAO 290
#define DIVISAO 291
#define ABRECOLCHETE 292
#define FECHACOLCHETE 293
#define END_OF_FILE 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "parser.y" /* yacc.c:355  */

	char pgm[32768];

#line 202 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 219 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    24,    24,    28,    29,    33,    34,    35,    39,    43,
      47,    48,    52,    53,    57,    58,    62,    63,    67,    68,
      72,    73,    77,    78,    82,    83,    87,    88,    89,    90,
      93,    94,    95,    96,    97,    98,   101,   102,   106,   110,
     114,   118,   122,   126,   127,   131,   132,   136,   137,   141,
     142,   146,   147,   151,   152,   153,   154,   155,   156,   160,
     161,   165,   166,   170,   171,   172,   173,   177,   178,   179,
     183,   187,   188
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
  "EXPONENCIAL", "COMENTARIO", "IGUAL", "DOISPONTOS", "ATRIBUICAO",
  "MENOR", "MENORIGUAL", "MAIOR", "MAIORIGUAL", "DIFERENTE",
  "ABREPARENTESES", "FECHAPARENTESES", "ABRECHAVE", "FECHACHAVE",
  "VIRGULA", "ADICAO", "SUBTRACAO", "MULTIPLICACAO", "DIVISAO",
  "ABRECOLCHETE", "FECHACOLCHETE", "END_OF_FILE", "$accept", "programa",
  "lista_declaracoes", "declaracao", "declaracao_variaveis",
  "inicializacao_variaveis", "lista_variaveis", "var", "indice", "tipo",
  "declaracao_funcao", "cabecalho", "lista_parametros", "parametro",
  "corpo", "acao", "se", "repita", "atribuicao", "leia", "escreva",
  "retorna", "expressao", "expressao_simples", "expressao_aditiva",
  "expressao_multiplicativa", "expressao_unaria", "operador_relacional",
  "operador_soma", "operador_multiplicacao", "fator", "numero",
  "chamada_funcao", "lista_argumentos", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -52

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      37,   -52,   -52,     1,    25,    37,   -52,   -52,   -52,     5,
      32,   -52,   -52,   -52,    -1,    -2,    11,   -52,   -52,    -2,
       8,    45,   -52,    98,    48,    41,    39,    18,   -52,   -52,
     -52,    -2,   -52,   -52,     5,   -52,    24,    67,   -31,   -18,
     -52,    26,   -52,   -52,   -52,    -2,   -52,    52,    42,   -52,
      -2,    98,    72,    74,    84,   -52,    78,   130,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,    80,    98,    71,    76,    -2,
      87,   -52,   -52,   -52,   -52,   -52,   -52,   -52,    -2,    -2,
     -52,   -52,    -2,   -52,   -52,    79,    45,   114,   141,    -2,
     104,    -2,   -52,   -52,   -52,   -52,   152,    39,   -52,   -52,
      53,   -52,   -31,   -18,   -52,   -52,   -52,    98,    -2,    91,
      99,   106,   -52,   -52,    -2,   119,   -52,   -52,   -52,   -52,
     -52,    98,   -52,   163,   -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    17,    12,     0,     2,     4,     5,     6,     0,
       0,     7,    19,     9,     0,     0,    13,     1,     3,     0,
       0,     0,    18,     0,     0,     0,    23,    12,    67,    68,
      69,     0,    59,    60,    64,    43,     0,    44,    45,    47,
      49,     0,    51,    66,    65,     0,    39,    12,     8,    11,
       0,     0,     0,     0,     0,    30,     0,     0,    26,    31,
      32,    28,    33,    34,    35,     0,     0,     0,     0,     0,
       0,    15,    55,    53,    57,    54,    58,    56,     0,     0,
      61,    62,     0,    64,    52,     0,     0,     0,     0,     0,
       0,     0,    21,    27,    29,    24,     0,    22,    25,    72,
       0,    63,    46,    48,    50,    14,    10,     0,     0,     0,
       0,     0,    20,    70,     0,     0,    38,    42,    40,    41,
      71,     0,    36,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   -52,   134,    56,   -52,   -52,   -11,   -52,    19,
     -52,   136,   -52,    90,   -44,   -51,   -52,   -52,     0,   -52,
     -52,   -52,   -10,   -52,    69,    82,    86,   -52,   -37,   -52,
     131,   -52,   -52,   -52
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    55,     8,    48,     9,    16,    56,
      11,    12,    25,    26,    57,    58,    59,    60,    35,    62,
      63,    64,    36,    37,    38,    39,    40,    78,    41,    82,
      42,    43,    44,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    79,    32,    33,    34,    13,    93,    88,    34,    46,
      49,     1,     2,    27,    28,    29,    30,    80,    81,    10,
      34,    70,    96,    61,    10,    17,    31,    19,    23,    14,
      83,    32,    33,    24,    34,    85,    14,    93,    15,    34,
      87,    27,    28,    29,    30,    93,    69,    20,    45,     1,
       2,    61,     3,    21,    31,    15,     7,    94,    34,    99,
      47,     7,    71,   115,    93,    79,    61,    83,    83,    65,
      66,    83,    93,    67,    86,   106,    68,   123,    34,   109,
      34,   111,   113,     1,     2,   114,    24,    72,    94,    15,
      73,    74,    75,    76,    77,    95,    94,    34,   116,    21,
      89,    50,    90,    34,   120,    51,    52,    61,    53,    54,
       1,     2,    91,    47,    98,    94,   101,   105,   107,   110,
     117,    61,    50,    94,   121,   122,    51,    52,   118,    53,
      54,     1,     2,    50,    47,   119,    92,    51,    52,    18,
      53,    54,     1,     2,    50,    47,    22,   102,    51,    52,
     108,    53,    54,     1,     2,    50,    47,    97,   112,    51,
      52,   103,    53,    54,     1,     2,    50,    47,   104,   124,
      51,    52,    84,    53,    54,     1,     2,     0,    47
};

static const yytype_int8 yycheck[] =
{
       0,    38,    33,    34,    15,     5,    57,    51,    19,    19,
      21,    12,    13,    15,    16,    17,    18,    35,    36,     0,
      31,    31,    66,    23,     5,     0,    28,    22,    29,    28,
      41,    33,    34,    14,    45,    45,    28,    88,    37,    50,
      50,    15,    16,    17,    18,    96,    28,    15,    37,    12,
      13,    51,    15,    21,    28,    37,     0,    57,    69,    69,
      15,     5,    38,   107,   115,   102,    66,    78,    79,    21,
      29,    82,   123,    32,    32,    86,    37,   121,    89,    89,
      91,    91,    29,    12,    13,    32,    67,    20,    88,    37,
      23,    24,    25,    26,    27,    15,    96,   108,   108,    21,
      28,     3,    28,   114,   114,     7,     8,   107,    10,    11,
      12,    13,    28,    15,    38,   115,    29,    38,     4,    15,
      29,   121,     3,   123,     5,     6,     7,     8,    29,    10,
      11,    12,    13,     3,    15,    29,     6,     7,     8,     5,
      10,    11,    12,    13,     3,    15,    10,    78,     7,     8,
       9,    10,    11,    12,    13,     3,    15,    67,     6,     7,
       8,    79,    10,    11,    12,    13,     3,    15,    82,     6,
       7,     8,    41,    10,    11,    12,    13,    -1,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    15,    41,    42,    43,    44,    45,    47,
      49,    50,    51,    58,    28,    37,    48,     0,    43,    22,
      15,    21,    51,    29,    49,    52,    53,    15,    16,    17,
      18,    28,    33,    34,    47,    58,    62,    63,    64,    65,
      66,    68,    70,    71,    72,    37,    62,    15,    46,    47,
       3,     7,     8,    10,    11,    44,    49,    54,    55,    56,
      57,    58,    59,    60,    61,    21,    29,    32,    37,    28,
      62,    38,    20,    23,    24,    25,    26,    27,    67,    68,
      35,    36,    69,    47,    70,    62,    32,    62,    54,    28,
      28,    28,     6,    55,    58,    15,    54,    53,    38,    62,
      73,    29,    64,    65,    66,    38,    47,     4,     9,    62,
      15,    62,     6,    29,    32,    54,    62,    29,    29,    29,
      62,     5,     6,    54,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    45,
      46,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      55,    55,    55,    55,    55,    55,    56,    56,    57,    58,
      59,    60,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    71,    71,    71,
      72,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     2,     4,     3,     1,     1,     2,     1,
       6,     5,     3,     1,     3,     3,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     5,     7,     4,     3,
       4,     4,     4,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       4,     3,     1
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
#line 24 "parser.y" /* yacc.c:1646  */
    {printf("programa\n");}
#line 1402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 28 "parser.y" /* yacc.c:1646  */
    {printf("lista_declaracoes declaracao\n");}
#line 1408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 29 "parser.y" /* yacc.c:1646  */
    {printf("declaracao\n");}
#line 1414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 33 "parser.y" /* yacc.c:1646  */
    {printf("declaracao_variaveis\n");}
#line 1420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 34 "parser.y" /* yacc.c:1646  */
    {printf("inicializacao_variaveis\n");}
#line 1426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 35 "parser.y" /* yacc.c:1646  */
    {printf("declaracao_funcao\n");}
#line 1432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 39 "parser.y" /* yacc.c:1646  */
    {printf("tipo DOISPONTOS lista_variaveis\n");}
#line 1438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 43 "parser.y" /* yacc.c:1646  */
    {printf("atribuicao\n");}
#line 1444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 47 "parser.y" /* yacc.c:1646  */
    {printf("lista_variaveis VIRGULA var\n");}
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 48 "parser.y" /* yacc.c:1646  */
    {printf("var\n");}
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 52 "parser.y" /* yacc.c:1646  */
    {printf("IDENTIFICADOR\n");}
#line 1462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 53 "parser.y" /* yacc.c:1646  */
    {printf("IDENTIFICADOR indice\n");}
#line 1468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 57 "parser.y" /* yacc.c:1646  */
    {printf("indice ABRECOLCHETE expressao FECHACOLCHETE\n");}
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 58 "parser.y" /* yacc.c:1646  */
    {printf("ABRECOLCHETE expressao FECHACOLCHETE\n");}
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 62 "parser.y" /* yacc.c:1646  */
    {printf("TIPOINTEIRO\n");}
#line 1486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 63 "parser.y" /* yacc.c:1646  */
    {printf("TIPOFLUTUANTE\n");}
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 67 "parser.y" /* yacc.c:1646  */
    {printf("tipo cabecalho\n");}
#line 1498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 68 "parser.y" /* yacc.c:1646  */
    {printf("cabecalho\n");}
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 72 "parser.y" /* yacc.c:1646  */
    {printf("IDENTIFICADOR ABREPARENTESES lista_parametros FECHAPARENTESES corpo FIM\n"); }
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 73 "parser.y" /* yacc.c:1646  */
    {printf("IDENTIFICADOR ABREPARENTESES FECHAPARENTESES corpo FIM\n"); }
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 77 "parser.y" /* yacc.c:1646  */
    {printf("lista_parametros VIRGULA parametro\n");}
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 78 "parser.y" /* yacc.c:1646  */
    {printf("parametro\n");}
#line 1528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 82 "parser.y" /* yacc.c:1646  */
    {printf("tipo DOISPONTOS IDENTIFICADOR\n");}
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 83 "parser.y" /* yacc.c:1646  */
    {printf("parametro ABRECOLCHETE FECHACOLCHETE\n");}
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 87 "parser.y" /* yacc.c:1646  */
    {printf("acao\n");}
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 88 "parser.y" /* yacc.c:1646  */
    {printf("corpo acao\n");}
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "parser.y" /* yacc.c:1646  */
    {printf("declaracao_variaveis\n");}
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 94 "parser.y" /* yacc.c:1646  */
    {printf("se\n");}
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 95 "parser.y" /* yacc.c:1646  */
    {printf("repita\n");}
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 96 "parser.y" /* yacc.c:1646  */
    {printf("leia\n");}
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 97 "parser.y" /* yacc.c:1646  */
    {printf("escreva\n");}
#line 1582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 98 "parser.y" /* yacc.c:1646  */
    {printf("retorna\n");}
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 101 "parser.y" /* yacc.c:1646  */
    {printf("SE expressao ENTAO corpo FIM\n");}
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 102 "parser.y" /* yacc.c:1646  */
    {printf("SE expressao ENTAO corpo SENAO corpo FIM\n");}
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 106 "parser.y" /* yacc.c:1646  */
    {printf("REPITA corpo ATE expressao\n");}
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 110 "parser.y" /* yacc.c:1646  */
    {printf("var ATRIBUICAO expressao\n");}
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 114 "parser.y" /* yacc.c:1646  */
    {printf("LEIA ABREPARENTESES IDENTIFICADOR FECHAPARENTESES\n");}
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 118 "parser.y" /* yacc.c:1646  */
    {printf("ESCREVA ABREPARENTESES expressao FECHAPARENTESES\n");}
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 122 "parser.y" /* yacc.c:1646  */
    {printf("RETORNA ABREPARENTESES expressao FECHAPARENTESES\n");}
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 126 "parser.y" /* yacc.c:1646  */
    {printf("atribuicao\n");}
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 127 "parser.y" /* yacc.c:1646  */
    {printf("expressao_simples\n");}
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 131 "parser.y" /* yacc.c:1646  */
    {printf("expressao_aditiva\n");}
#line 1648 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 132 "parser.y" /* yacc.c:1646  */
    {printf("expressao_simples operador_relacional expressao_aditiva\n");}
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 136 "parser.y" /* yacc.c:1646  */
    {printf("expressao_multiplicativa\n");}
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 137 "parser.y" /* yacc.c:1646  */
    {printf("expressao_aditiva operador_soma expressao_multiplicativa\n");}
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 141 "parser.y" /* yacc.c:1646  */
    {printf("expressao_unaria\n");}
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 142 "parser.y" /* yacc.c:1646  */
    {printf("expressao_multiplicativa operador_multiplicacao expressao_unaria\n");}
#line 1678 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 146 "parser.y" /* yacc.c:1646  */
    {printf("fator \n");}
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 147 "parser.y" /* yacc.c:1646  */
    {printf("operador_soma fator\n");}
#line 1690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 151 "parser.y" /* yacc.c:1646  */
    {printf("MENOR\n");}
#line 1696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 152 "parser.y" /* yacc.c:1646  */
    {printf("MAIOR\n");}
#line 1702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 153 "parser.y" /* yacc.c:1646  */
    {printf("IGUAL\n");}
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 154 "parser.y" /* yacc.c:1646  */
    {printf("DIFERENTE\n");}
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 155 "parser.y" /* yacc.c:1646  */
    {printf("MENORIGUAL\n");}
#line 1720 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 156 "parser.y" /* yacc.c:1646  */
    {printf("MAIORIGUAL\n");}
#line 1726 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 160 "parser.y" /* yacc.c:1646  */
    {printf("ADICAO\n");}
#line 1732 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 161 "parser.y" /* yacc.c:1646  */
    {printf("SUBTRACAO\n");}
#line 1738 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 165 "parser.y" /* yacc.c:1646  */
    {printf("MULTIPLICACAO\n");}
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 166 "parser.y" /* yacc.c:1646  */
    {printf("DIVISAO\n");}
#line 1750 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 170 "parser.y" /* yacc.c:1646  */
    {printf("ABREPARENTESES expressao FECHAPARENTESES\n");}
#line 1756 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 171 "parser.y" /* yacc.c:1646  */
    {printf("var\n");}
#line 1762 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 172 "parser.y" /* yacc.c:1646  */
    {printf("chamada_funcao\n");}
#line 1768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 173 "parser.y" /* yacc.c:1646  */
    {printf("numero\n");}
#line 1774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 177 "parser.y" /* yacc.c:1646  */
    {printf("NUMEROINTEIRO\n");}
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 178 "parser.y" /* yacc.c:1646  */
    {printf("NUMEROFLUTUANTE\n");}
#line 1786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 179 "parser.y" /* yacc.c:1646  */
    {printf("EXPONENCIAL\n");}
#line 1792 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 183 "parser.y" /* yacc.c:1646  */
    {printf("IDENTIFICADOR ABREPARENTESES lista_argumentos FECHAPARENTESES\n");}
#line 1798 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 187 "parser.y" /* yacc.c:1646  */
    {printf("lista_argumentos VIRGULA expressao\n");}
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 188 "parser.y" /* yacc.c:1646  */
    {printf("expressao\n");}
#line 1810 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1814 "parser.tab.c" /* yacc.c:1646  */
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
#line 191 "parser.y" /* yacc.c:1906  */

void yyerror(char *s) {
	fprintf(stdout, "%s\n", s);
}

int main(int argc, char *argv[]){
	/*
		-> precisar ter uma expressão para o comentário?
		-> como fazer com a expressão vazio & erro?
	*/
	yyin = fopen(argv[1], "r");
	yyparse();	
	fclose(yyin);
	return 0;
}

