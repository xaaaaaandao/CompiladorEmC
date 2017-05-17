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
<<<<<<< HEAD
#define YYLAST   528
=======
#define YYLAST   236
>>>>>>> xandao

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
<<<<<<< HEAD
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135
=======
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121
>>>>>>> xandao

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
<<<<<<< HEAD
       0,    31,    31,    34,    35,    38,    39,    40,    43,    46,
      49,    50,    53,    54,    57,    58,    61,    62,    65,    66,
      69,    70,    71,    72,    75,    76,    79,    80,    83,    84,
      87,    87,    88,    88,    88,    88,    88,    88,    91,    92,
      95,    98,   101,   104,   107,   110,   110,   113,   114,   117,
     118,   121,   122,   125,   126,   127,   128,   131,   131,   131,
     131,   131,   131,   134,   134,   137,   137,   140,   141,   142,
     143,   146,   147,   148,   151,   154,   155
=======
       0,    24,    24,    28,    29,    33,    34,    35,    39,    43,
      47,    48,    52,    53,    57,    58,    62,    63,    67,    68,
      72,    76,    77,    81,    82,    86,    87,    90,    91,    92,
      93,    94,    95,    96,    99,   100,   104,   108,   112,   116,
     120,   124,   125,   129,   130,   134,   135,   139,   140,   144,
     145,   149,   150,   151,   152,   153,   154,   158,   159,   163,
     164,   168,   169,   170,   171,   175,   176,   177,   181,   185,
     186
>>>>>>> xandao
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

<<<<<<< HEAD
#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))
=======
#define YYPACT_NINF -71

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-71)))
>>>>>>> xandao

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
      31,   -65,   -65,   -24,    12,    31,   -65,   -65,   -65,    -6,
      -7,   -65,   -65,   -65,     5,   445,   -13,   -65,   -65,   445,
       7,    13,   -65,   170,    47,    18,    40,   491,   -65,   -65,
     -65,   445,   -65,   -65,   -65,   -65,    30,   -65,    96,    37,
      16,   -65,    36,   -65,   -65,   -65,   -65,    14,    14,   -65,
     -65,   -65,   445,   -65,    42,    48,   -65,   445,   -65,   416,
      54,    55,    56,   -65,    -6,    64,   211,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,    72,   252,    60,    51,   -65,
     -65,   -65,   -65,   -65,   -65,    14,    65,   445,    21,    75,
     474,   -65,   -65,   -65,    58,    13,    94,   293,   445,    84,
     445,   -65,   -65,   -65,   -65,   334,    40,   -65,   -65,   -65,
     -65,    33,   -65,   -65,   -65,   -65,   -65,   416,   445,    71,
      73,    78,   -65,   -65,   445,   129,   -65,   -65,   -65,   -65,
     -65,   416,   -65,   375,   -65
=======
      32,   -71,   -71,   -20,     5,    32,   -71,   -71,   -71,     4,
      12,   -71,   -71,   -71,    47,     3,    -2,   -71,   -71,     3,
      18,    35,   -71,    56,    19,    31,    -5,   -71,   -71,   -71,
       3,   -71,   -71,     4,   -71,    40,    49,    28,    30,   -71,
      -4,   -71,   -71,   -71,     3,   -71,    33,     8,   -71,    41,
     202,    47,    42,     3,    50,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,     3,     3,   -71,   -71,     3,   -71,   -71,    43,
      35,   -71,     3,   202,    54,    55,    57,   -71,    66,   117,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,    31,   -71,   -71,
      23,   -71,    28,    30,   -71,   -71,   -71,    84,   145,     3,
      74,     3,   -71,   -71,   -71,     3,   202,     3,    68,    73,
      78,   -71,    88,   -71,   -71,   -71,   -71,   202,   -71,   174,
     -71
>>>>>>> xandao
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    17,    12,     0,     2,     4,     5,     6,     0,
       0,     7,    19,     9,     0,     0,    13,     1,     3,     0,
<<<<<<< HEAD
       0,     0,    18,     0,     0,     0,    25,    12,    71,    72,
      73,     0,    63,    64,    65,    66,     0,    45,     0,     0,
       0,    68,     0,    46,    47,    49,    51,     0,     0,    53,
      70,    69,     0,    41,    12,     8,    11,     0,    23,     0,
       0,     0,     0,    31,    68,     0,     0,    28,    32,    33,
      34,    35,    36,    37,    30,     0,     0,     0,     0,    59,
      57,    61,    58,    62,    60,     0,     0,     0,     0,     0,
       0,    15,    56,    55,     0,     0,     0,     0,     0,     0,
       0,    22,    29,    26,    21,     0,    24,    27,    54,    67,
      76,     0,    48,    50,    52,    14,    10,     0,     0,     0,
       0,     0,    20,    74,     0,     0,    40,    44,    42,    43,
      75,     0,    38,     0,    39
=======
       0,     0,    18,     0,     0,    22,    12,    65,    66,    67,
       0,    57,    58,    62,    41,     0,    42,    43,    45,    47,
       0,    49,    64,    63,     0,    37,    12,     8,    11,     0,
       0,     0,     0,     0,     0,    15,    53,    51,    55,    52,
      56,    54,     0,     0,    59,    60,     0,    62,    50,     0,
       0,    23,     0,     0,     0,     0,     0,    28,     0,     0,
      25,    29,    30,    31,    32,    33,    27,    21,    24,    70,
       0,    61,    44,    46,    48,    14,    10,     0,     0,     0,
       0,     0,    20,    26,    68,     0,     0,     0,     0,     0,
       0,    69,     0,    36,    40,    38,    39,     0,    34,     0,
      35
>>>>>>> xandao
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
<<<<<<< HEAD
     -65,   -65,   -65,    99,    20,   -65,   -65,     0,   -65,     1,
     -65,    91,   -65,    38,   -50,   -64,   -65,   -65,    22,   -65,
     -65,   -65,   -12,   -65,    25,    35,    39,    88,    89,    87,
     -37,   -65,   -65,   -65
=======
     -71,   -71,   -71,   103,    25,   -71,   -71,     1,   -71,     2,
     -71,    99,   -71,    59,   -63,   -70,   -71,   -71,    34,   -71,
     -71,   -71,   -15,   -71,    51,    48,    46,   -71,   -34,   -71,
      75,   -71,   -71,   -71
>>>>>>> xandao
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
<<<<<<< HEAD
      -1,     4,     5,     6,    63,     8,    55,    41,    16,    65,
      11,    12,    25,    26,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    43,    44,    45,    46,    85,    47,    48,
      49,    50,    51,   111
=======
      -1,     4,     5,     6,    77,     8,    47,    33,    16,    78,
      11,    12,    24,    25,    79,    80,    81,    82,    34,    83,
      84,    85,    86,    36,    37,    38,    39,    62,    40,    66,
      41,    42,    43,    90
>>>>>>> xandao
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
<<<<<<< HEAD
       9,    10,   102,    42,    14,     9,    10,    53,    20,    97,
      92,    93,    17,    15,    21,    24,    19,     1,     2,    86,
       7,    56,    13,    64,    52,     7,   105,    13,    54,    54,
      28,    29,    30,   102,    23,    14,    27,    28,    29,    30,
      94,   102,    31,     1,     2,    96,     3,    76,   108,    31,
      77,    34,    35,    36,    32,    33,    34,    35,    87,    64,
      36,   102,   123,    39,    40,   124,    64,   125,    75,   102,
      32,    33,     1,     2,    91,   110,    64,    78,    24,    15,
      95,   133,    98,    99,   100,    21,   119,   103,   121,   107,
      27,    28,    29,    30,   109,   116,   115,    64,   117,   120,
     127,    22,   128,    31,    18,    64,   126,   129,    32,    33,
      34,    35,   130,   112,    36,   106,    79,    64,    40,    80,
      81,    82,    83,    84,   113,    64,    88,    90,    89,   114,
       0,    64,    57,    64,   131,   132,    59,    60,     0,    61,
      62,     1,     2,     0,    27,    28,    29,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,    32,    33,    34,    35,     0,     0,    36,    37,
      38,    39,    40,    57,     0,     0,    58,    59,    60,     0,
      61,    62,     1,     2,     0,    27,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,    32,    33,    34,    35,     0,     0,    36,
      37,    38,    39,    40,    57,     0,     0,   101,    59,    60,
       0,    61,    62,     1,     2,     0,    27,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,    32,    33,    34,    35,     0,     0,
      36,    37,    38,    39,    40,    57,     0,     0,   104,    59,
      60,     0,    61,    62,     1,     2,     0,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,    32,    33,    34,    35,     0,
       0,    36,    37,    38,    39,    40,    57,     0,     0,     0,
      59,    60,   118,    61,    62,     1,     2,     0,    27,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,    32,    33,    34,    35,
       0,     0,    36,    37,    38,    39,    40,    57,     0,     0,
     122,    59,    60,     0,    61,    62,     1,     2,     0,    27,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,    32,    33,    34,
      35,     0,     0,    36,    37,    38,    39,    40,    57,     0,
       0,   134,    59,    60,     0,    61,    62,     1,     2,     0,
      27,    28,    29,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,    32,    33,
      34,    35,     0,     0,    36,    37,    38,    39,    40,    57,
       0,     0,     0,    59,    60,     0,    61,    62,     1,     2,
       0,    27,    28,    29,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,    32,
      33,    34,    35,     0,     0,    36,    37,    38,    39,    40,
      27,    28,    29,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,    32,    33,
      34,    35,     0,     0,    36,    37,    38,    39,    40,    27,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,    32,    33,    34,
      35,    79,     0,    36,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15
=======
      35,     9,    10,    63,    45,    17,     9,    10,    14,   103,
      98,    26,    27,    28,    29,    54,    23,    15,    26,    27,
      28,    29,    48,    53,    30,     7,    19,    20,   103,    69,
       7,    30,    15,    21,    13,    44,    31,    32,    89,    13,
      70,    67,   103,   112,     1,     2,    14,     3,    50,   103,
      46,    51,   104,    23,   119,   105,    71,    97,    63,     1,
       2,    31,    32,    67,    67,    64,    65,    67,    52,    56,
      15,    96,    57,    58,    59,    60,    61,    49,    55,    91,
      88,    95,    99,   100,   108,   101,   110,    21,   106,   109,
     111,    72,   113,   117,   118,    73,    74,   114,    75,    76,
       1,     2,   115,    26,    27,    28,    29,   116,    18,    22,
      87,    93,    94,    92,     0,    68,    30,     0,     0,     0,
      72,    31,    32,   102,    73,    74,     0,    75,    76,     1,
       2,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,    72,     0,
      31,    32,    73,    74,   107,    75,    76,     1,     2,     0,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,    72,    31,    32,
     120,    73,    74,     0,    75,    76,     1,     2,     0,    26,
      27,    28,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,     0,    72,     0,    31,    32,    73,
      74,     0,    75,    76,     1,     2,     0,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,    31,    32
>>>>>>> xandao
};

static const yytype_int8 yycheck[] =
{
<<<<<<< HEAD
       0,     0,    66,    15,    28,     5,     5,    19,    15,    59,
      47,    48,     0,    37,    21,    14,    22,    12,    13,    31,
       0,    21,     0,    23,    37,     5,    76,     5,    15,    15,
      16,    17,    18,    97,    29,    28,    15,    16,    17,    18,
      52,   105,    28,    12,    13,    57,    15,    29,    85,    28,
      32,    35,    36,    39,    33,    34,    35,    36,    28,    59,
      39,   125,    29,    42,    43,    32,    66,   117,    21,   133,
      33,    34,    12,    13,    38,    87,    76,    37,    77,    37,
      32,   131,    28,    28,    28,    21,    98,    15,   100,    38,
      15,    16,    17,    18,    29,    95,    38,    97,     4,    15,
      29,    10,    29,    28,     5,   105,   118,    29,    33,    34,
      35,    36,   124,    88,    39,    77,    20,   117,    43,    23,
      24,    25,    26,    27,    89,   125,    38,    40,    39,    90,
      -1,   131,     3,   133,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    -1,    -1,    39,    40,
      41,    42,    43,     3,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    39,
      40,    41,    42,    43,     3,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,    -1,
      39,    40,    41,    42,    43,     3,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    39,    40,    41,    42,    43,     3,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      -1,    -1,    39,    40,    41,    42,    43,     3,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    39,    40,    41,    42,    43,     3,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    39,    40,    41,    42,    43,     3,
      -1,    -1,    -1,     7,     8,    -1,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    39,    40,    41,    42,    43,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    39,    40,    41,    42,    43,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    20,    -1,    39,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37
=======
      15,     0,     0,    37,    19,     0,     5,     5,    28,    79,
      73,    15,    16,    17,    18,    30,    14,    37,    15,    16,
      17,    18,    21,    28,    28,     0,    22,    15,    98,    44,
       5,    28,    37,    21,     0,    37,    33,    34,    53,     5,
      32,    40,   112,   106,    12,    13,    28,    15,    29,   119,
      15,    32,    29,    51,   117,    32,    15,    72,    92,    12,
      13,    33,    34,    62,    63,    35,    36,    66,    37,    20,
      37,    70,    23,    24,    25,    26,    27,    21,    38,    29,
      38,    38,    28,    28,    99,    28,   101,    21,     4,    15,
     105,     3,   107,     5,     6,     7,     8,    29,    10,    11,
      12,    13,    29,    15,    16,    17,    18,    29,     5,    10,
      51,    63,    66,    62,    -1,    40,    28,    -1,    -1,    -1,
       3,    33,    34,     6,     7,     8,    -1,    10,    11,    12,
      13,    -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,     3,    -1,
      33,    34,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,     3,    33,    34,
       6,     7,     8,    -1,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,     3,    -1,    33,    34,     7,
       8,    -1,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    33,    34
>>>>>>> xandao
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
<<<<<<< HEAD
       0,    12,    13,    15,    45,    46,    47,    48,    49,    51,
      53,    54,    55,    62,    28,    37,    52,     0,    47,    22,
      15,    21,    55,    29,    53,    56,    57,    15,    16,    17,
      18,    28,    33,    34,    35,    36,    39,    40,    41,    42,
      43,    51,    66,    67,    68,    69,    70,    72,    73,    74,
      75,    76,    37,    66,    15,    50,    51,     3,     6,     7,
       8,    10,    11,    48,    51,    53,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    21,    29,    32,    37,    20,
      23,    24,    25,    26,    27,    71,    66,    28,    71,    72,
      73,    38,    74,    74,    66,    32,    66,    58,    28,    28,
      28,     6,    59,    15,     6,    58,    57,    38,    74,    29,
      66,    77,    68,    69,    70,    38,    51,     4,     9,    66,
      15,    66,     6,    29,    32,    58,    66,    29,    29,    29,
      66,     5,     6,    58,     6
=======
       0,    12,    13,    15,    41,    42,    43,    44,    45,    47,
      49,    50,    51,    58,    28,    37,    48,     0,    43,    22,
      15,    21,    51,    49,    52,    53,    15,    16,    17,    18,
      28,    33,    34,    47,    58,    62,    63,    64,    65,    66,
      68,    70,    71,    72,    37,    62,    15,    46,    47,    21,
      29,    32,    37,    28,    62,    38,    20,    23,    24,    25,
      26,    27,    67,    68,    35,    36,    69,    47,    70,    62,
      32,    15,     3,     7,     8,    10,    11,    44,    49,    54,
      55,    56,    57,    59,    60,    61,    62,    53,    38,    62,
      73,    29,    64,    65,    66,    38,    47,    62,    54,    28,
      28,    28,     6,    55,    29,    32,     4,     9,    62,    15,
      62,    62,    54,    62,    29,    29,    29,     5,     6,    54,
       6
>>>>>>> xandao
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
<<<<<<< HEAD
       0,    44,    45,    46,    46,    47,    47,    47,    48,    49,
      50,    50,    51,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    55,    55,    56,    56,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    62,    63,    64,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    75,    75,    75,    76,    77,    77
=======
       0,    40,    41,    42,    42,    43,    43,    43,    44,    45,
      46,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    57,    58,    59,    60,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    71,    71,    71,    72,    73,
      73
>>>>>>> xandao
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     2,     4,     3,     1,     1,     2,     1,
<<<<<<< HEAD
       6,     5,     5,     4,     3,     1,     3,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     7,
       4,     3,     4,     4,     4,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     4,     3,     1
=======
       6,     3,     1,     3,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     4,     3,     4,     4,
       4,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     4,     3,
       1
>>>>>>> xandao
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
<<<<<<< HEAD
      
#line 1481 "parser.tab.c" /* yacc.c:1646  */
=======
        case 2:
#line 24 "parser.y" /* yacc.c:1646  */
    {printf("programa\n");}
#line 1414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 28 "parser.y" /* yacc.c:1646  */
    {printf("lista_declaracoes declaracao\n");}
#line 1420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 29 "parser.y" /* yacc.c:1646  */
    {printf("declaracao\n");}
#line 1426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 33 "parser.y" /* yacc.c:1646  */
    {printf("declaracao_variaveis\n");}
#line 1432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 34 "parser.y" /* yacc.c:1646  */
    {printf("inicializacao_variaveis\n");}
#line 1438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 35 "parser.y" /* yacc.c:1646  */
    {printf("declaracao_funcao\n");}
#line 1444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 39 "parser.y" /* yacc.c:1646  */
    {printf("tipo DOISPONTOS lista_variaveis\n");}
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 43 "parser.y" /* yacc.c:1646  */
    {printf("atribuicao\n");}
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 47 "parser.y" /* yacc.c:1646  */
    {printf("lista_variaveis VIRGULA var\n");}
#line 1462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 48 "parser.y" /* yacc.c:1646  */
    {printf("var\n");}
#line 1468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 52 "parser.y" /* yacc.c:1646  */
    {printf("IDENTIFICADOR\n");}
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 53 "parser.y" /* yacc.c:1646  */
    {printf("IDENTIFICADOR indice\n");}
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 57 "parser.y" /* yacc.c:1646  */
    {printf("indice ABRECOLCHETE expressao FECHACOLCHETE\n");}
#line 1486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 58 "parser.y" /* yacc.c:1646  */
    {printf("ABRECOLCHETE expressao FECHACOLCHETE\n");}
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 62 "parser.y" /* yacc.c:1646  */
    {printf("TIPOINTEIRO\n");}
#line 1498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 63 "parser.y" /* yacc.c:1646  */
    {printf("flutuante\n");}
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 67 "parser.y" /* yacc.c:1646  */
    {printf("tipo cabecalho\n");}
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 68 "parser.y" /* yacc.c:1646  */
    {printf("cabecalho\n");}
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 72 "parser.y" /* yacc.c:1646  */
    {printf("IDENTIFICADOR ABREPARENTESES lista_parametros FECHAPARENTESES corpo FIM\n"); }
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 76 "parser.y" /* yacc.c:1646  */
    {printf("lista_parametros VIRGULA parametro\n");}
#line 1528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 77 "parser.y" /* yacc.c:1646  */
    {printf("parametro\n");}
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 81 "parser.y" /* yacc.c:1646  */
    {printf("tipo DOISPONTOS IDENTIFICADOR\n");}
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 82 "parser.y" /* yacc.c:1646  */
    {printf("parametro ABRECOLCHETE FECHACOLCHETE\n");}
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 86 "parser.y" /* yacc.c:1646  */
    {printf("acao\n");}
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 87 "parser.y" /* yacc.c:1646  */
    {printf("corpo acao\n");}
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 90 "parser.y" /* yacc.c:1646  */
    {printf("expressao\n");}
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 91 "parser.y" /* yacc.c:1646  */
    {printf("declaracao_variaveis\n");}
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 92 "parser.y" /* yacc.c:1646  */
    {printf("se\n");}
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "parser.y" /* yacc.c:1646  */
    {printf("repita\n");}
#line 1582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 94 "parser.y" /* yacc.c:1646  */
    {printf("leia\n");}
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 95 "parser.y" /* yacc.c:1646  */
    {printf("escreva\n");}
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 96 "parser.y" /* yacc.c:1646  */
    {printf("retorna\n");}
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 99 "parser.y" /* yacc.c:1646  */
    {printf("SE expressao ENTAO corpo FIM\n");}
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 100 "parser.y" /* yacc.c:1646  */
    {printf("SE expressao ENTAO corpo SENAO corpo FIM\n");}
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 104 "parser.y" /* yacc.c:1646  */
    {printf("REPITA corpo ATE expressao\n");}
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 108 "parser.y" /* yacc.c:1646  */
    {printf("var ATRIBUICAO expressao\n");}
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 112 "parser.y" /* yacc.c:1646  */
    {printf("LEIA ABREPARENTESES IDENTIFICADOR FECHAPARENTESES\n");}
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 116 "parser.y" /* yacc.c:1646  */
    {printf("ESCREVA ABREPARENTESES expressao FECHAPARENTESES\n");}
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 120 "parser.y" /* yacc.c:1646  */
    {printf("RETORNA ABREPARENTESES expressao FECHAPARENTESES\n");}
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 124 "parser.y" /* yacc.c:1646  */
    {printf("atribuicao\n");}
#line 1648 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 125 "parser.y" /* yacc.c:1646  */
    {printf("expressao_simples\n");}
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 129 "parser.y" /* yacc.c:1646  */
    {printf("expressao_aditiva\n");}
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 130 "parser.y" /* yacc.c:1646  */
    {printf("expressao_simples operador_relacional expressao_aditiva\n");}
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 134 "parser.y" /* yacc.c:1646  */
    {printf("expressao_multiplicativa\n");}
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 135 "parser.y" /* yacc.c:1646  */
    {printf("expressao_aditiva operador_soma expressao_multiplicativa\n");}
#line 1678 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 139 "parser.y" /* yacc.c:1646  */
    {printf("expressao_unaria\n");}
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 140 "parser.y" /* yacc.c:1646  */
    {printf("expressao_multiplicativa operador_multiplicacao expressao_unaria\n");}
#line 1690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 144 "parser.y" /* yacc.c:1646  */
    {printf("fator \n");}
#line 1696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 145 "parser.y" /* yacc.c:1646  */
    {printf("operador_soma fator\n");}
#line 1702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 149 "parser.y" /* yacc.c:1646  */
    {printf("MENOR\n");}
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 150 "parser.y" /* yacc.c:1646  */
    {printf("MAIOR\n");}
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 151 "parser.y" /* yacc.c:1646  */
    {printf("IGUAL\n");}
#line 1720 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 152 "parser.y" /* yacc.c:1646  */
    {printf("DIFERENTE\n");}
#line 1726 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 153 "parser.y" /* yacc.c:1646  */
    {printf("MENORIGUAL\n");}
#line 1732 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 154 "parser.y" /* yacc.c:1646  */
    {printf("MAIORIGUAL\n");}
#line 1738 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 158 "parser.y" /* yacc.c:1646  */
    {printf("ADICAO\n");}
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 159 "parser.y" /* yacc.c:1646  */
    {printf("SUBTRACAO\n");}
#line 1750 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 163 "parser.y" /* yacc.c:1646  */
    {printf("MULTIPLICACAO\n");}
#line 1756 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 164 "parser.y" /* yacc.c:1646  */
    {printf("DIVISAO\n");}
#line 1762 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 168 "parser.y" /* yacc.c:1646  */
    {printf("ABREPARENTESES expressao FECHAPARENTESES\n");}
#line 1768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 169 "parser.y" /* yacc.c:1646  */
    {printf("var\n");}
#line 1774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 170 "parser.y" /* yacc.c:1646  */
    {printf("chamada_funcao\n");}
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 171 "parser.y" /* yacc.c:1646  */
    {printf("numero\n");}
#line 1786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 175 "parser.y" /* yacc.c:1646  */
    {printf("NUMEROINTEIRO\n");}
#line 1792 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 176 "parser.y" /* yacc.c:1646  */
    {printf("NUMEROFLUTUANTE\n");}
#line 1798 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 177 "parser.y" /* yacc.c:1646  */
    {printf("EXPONENCIAL\n");}
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 181 "parser.y" /* yacc.c:1646  */
    {printf("IDENTIFICADOR ABREPARENTESES lista_argumentos FECHAPARENTESES\n");}
#line 1810 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 185 "parser.y" /* yacc.c:1646  */
    {printf("lista_argumentos VIRGULA expressao\n");}
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 186 "parser.y" /* yacc.c:1646  */
    {printf("expressao\n");}
#line 1822 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1826 "parser.tab.c" /* yacc.c:1646  */
>>>>>>> xandao
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
<<<<<<< HEAD
#line 157 "parser.y" /* yacc.c:1906  */
=======
#line 189 "parser.y" /* yacc.c:1906  */
>>>>>>> xandao

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

