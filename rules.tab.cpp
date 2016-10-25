/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C

      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "rules.y"

    #include "lexer.h"
    #include <string>

/* Line 371 of yacc.c  */
#line 73 "rules.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "rules.tab.h".  */
#ifndef YY_YY_RULES_TAB_H_INCLUDED
# define YY_YY_RULES_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OR = 258,
     AND = 259,
     NE = 260,
     EQ = 261,
     GE = 262,
     LE = 263,
     UPLUS = 264,
     UMINUS = 265,
     NUMERAL = 266,
     BOOL = 267,
     NAME = 268,
     STRING = 269,
     PUBLIC = 270,
     CLASS = 271,
     STATIC = 272,
     VOID = 273,
     INTTYPE = 274,
     BOOLTYPE = 275,
     IF = 276,
     ELSE = 277,
     WHILE = 278,
     RETURN = 279,
     READINT = 280,
     READBOOL = 281,
     WRITE = 282,
     MAIN = 283
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 6 "rules.y"

	Expression *expression;
    Statement *statement;
    StatementList *statementList;
    Method *method;
    Field *field;
    FieldMethodList *methodList;
    MethodBody *methodBody;
    Variables *variables;
    ExpressionList *passedArguments;

	int value;
	char* name;
	data_type type;


/* Line 387 of yacc.c  */
#line 161 "rules.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_RULES_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 189 "rules.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     5,     2,     2,     2,    16,     2,     2,
      39,    42,    14,    12,    44,    13,    46,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       6,    45,     7,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
       8,     9,    10,    11,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    13,    27,    30,    33,    34,    39,
      41,    43,    45,    55,    57,    58,    62,    64,    67,    70,
      73,    74,    78,    81,    82,    84,    86,    88,    90,    92,
      97,   106,   111,   112,   120,   123,   127,   134,   139,   144,
     149,   154,   156,   157,   161,   163,   165,   167,   169,   173,
     175,   177,   179,   181,   183,   186,   189,   192,   196,   200,
     204,   208,   212,   216,   220,   224,   228,   232,   236,   240
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    23,    24,    21,    37,    49,    38,    -1,
      50,    51,    -1,    23,    25,    26,    36,    39,    22,    40,
      41,    21,    42,    37,    58,    38,    -1,    52,    51,    -1,
      54,    51,    -1,    -1,    25,    53,    21,    43,    -1,    28,
      -1,    27,    -1,    26,    -1,    25,    53,    21,    39,    55,
      42,    37,    58,    38,    -1,    56,    -1,    -1,    57,    44,
      56,    -1,    57,    -1,    53,    21,    -1,    59,    61,    -1,
      60,    59,    -1,    -1,    53,    21,    43,    -1,    62,    61,
      -1,    -1,    63,    -1,    64,    -1,    66,    -1,    67,    -1,
      68,    -1,    21,    45,    72,    43,    -1,    29,    39,    72,
      42,    37,    61,    38,    65,    -1,    30,    37,    61,    38,
      -1,    -1,    31,    39,    72,    42,    37,    61,    38,    -1,
      69,    43,    -1,    32,    72,    43,    -1,    21,    46,    21,
      39,    70,    42,    -1,    21,    39,    70,    42,    -1,    35,
      39,    70,    42,    -1,    33,    39,    70,    42,    -1,    34,
      39,    70,    42,    -1,    71,    -1,    -1,    72,    44,    71,
      -1,    72,    -1,    69,    -1,    73,    -1,    74,    -1,    39,
      72,    42,    -1,    75,    -1,    76,    -1,    20,    -1,    19,
      -1,    21,    -1,    13,    72,    -1,    12,    72,    -1,     5,
      72,    -1,    72,    12,    72,    -1,    72,    13,    72,    -1,
      72,    15,    72,    -1,    72,    14,    72,    -1,    72,    16,
      72,    -1,    72,     4,    72,    -1,    72,     3,    72,    -1,
      72,     9,    72,    -1,    72,     8,    72,    -1,    72,    11,
      72,    -1,    72,     6,    72,    -1,    72,    10,    72,    -1,
      72,     7,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    68,    71,    74,    75,    76,    79,    82,
      83,    84,    87,    90,    91,    94,    95,    98,   101,   104,
     105,   108,   111,   112,   115,   116,   117,   118,   119,   122,
     125,   128,   129,   132,   135,   138,   141,   142,   143,   144,
     145,   148,   149,   152,   153,   156,   157,   158,   159,   160,
     161,   164,   165,   168,   171,   172,   173,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OR", "AND", "'!'", "'<'", "'>'", "NE",
  "EQ", "GE", "LE", "'+'", "'-'", "'*'", "'/'", "'%'", "UPLUS", "UMINUS",
  "NUMERAL", "BOOL", "NAME", "STRING", "PUBLIC", "CLASS", "STATIC", "VOID",
  "INTTYPE", "BOOLTYPE", "IF", "ELSE", "WHILE", "RETURN", "READINT",
  "READBOOL", "WRITE", "MAIN", "'{'", "'}'", "'('", "'['", "']'", "')'",
  "';'", "','", "'='", "'.'", "$accept", "class", "field_method_list_init",
  "main_method", "field_method_list", "field_declaration", "typename",
  "method_declaration", "arguments_or_empty", "arguments", "argument",
  "method_body", "localvars", "localvar", "statement_list", "statement",
  "assign_statement", "if_statement", "else_block", "while_statement",
  "invoke_statement", "return_statement", "invoke_expression",
  "passed_arguments_or_empty", "passed_arguments", "expression",
  "literal_expression", "variable_expression", "unary_expression",
  "binary_expression", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,    33,    60,    62,   260,   261,
     262,   263,    43,    45,    42,    47,    37,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   123,   125,    40,
      91,    93,    41,    59,    44,    61,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    51,    52,    53,
      53,    53,    54,    55,    55,    56,    56,    57,    58,    59,
      59,    60,    61,    61,    62,    62,    62,    62,    62,    63,
      64,    65,    65,    66,    67,    68,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    73,    73,    74,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,    13,     2,     2,     0,     4,     1,
       1,     1,     9,     1,     0,     3,     1,     2,     2,     2,
       0,     3,     2,     0,     1,     1,     1,     1,     1,     4,
       8,     4,     0,     7,     2,     3,     6,     4,     4,     4,
       4,     1,     0,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     7,
       0,     2,     0,     3,     7,     7,     0,    11,    10,     9,
       0,     5,     6,     0,     0,     0,    14,     8,     0,     0,
       0,    13,    16,     0,    17,     0,     0,     0,    20,    15,
       0,     0,     0,    23,    20,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,    18,    23,    24,    25,    26,
      27,    28,     0,    19,    20,    21,    42,     0,     0,     0,
       0,     0,     0,     0,    52,    51,    53,     0,    45,     0,
      46,    47,    49,    50,    42,    42,    42,    22,    34,     0,
       0,    41,    44,     0,     0,     0,     0,    56,    55,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,     0,     0,     0,     4,    37,
       0,    29,    42,     0,     0,    48,    63,    62,    67,    69,
      65,    64,    68,    66,    57,    58,    60,    59,    61,    39,
      40,    38,    43,     0,    23,    23,    36,     0,     0,    32,
      33,     0,    30,    23,     0,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    13,    14,    41,    15,    30,    31,
      32,    42,    43,    44,    55,    56,    57,    58,   152,    59,
      60,    61,    78,    90,    91,    92,    80,    81,    82,    83
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -82
static const yytype_int16 yypact[] =
{
     -16,    -7,    19,     4,   -82,     3,    27,    26,    45,    59,
      60,   -82,    21,   -82,    59,    59,    49,   -82,   -82,   -82,
      70,   -82,   -82,    48,   -33,    72,    21,   -82,    52,    74,
      46,   -82,    53,    55,   -82,    63,    21,    78,    21,   -82,
      64,    83,    69,   165,    21,    87,    93,   -82,   -31,    98,
      99,   171,   100,   101,   102,   -82,   165,   -82,   -82,   -82,
     -82,   -82,   117,   -82,    21,   -82,   171,   171,   121,   171,
     171,   171,   171,   171,   -82,   -82,   -30,   171,   -82,    62,
     -82,   -82,   -82,   -82,   171,   171,   171,   -82,   -82,   106,
     103,   -82,    23,   105,   104,   119,   143,   205,   -82,   -82,
     159,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   -82,   122,   135,   136,   -82,   -82,
     171,   -82,   171,   142,   144,   -82,   205,   205,    30,    30,
      30,    30,    30,    30,    66,    66,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   138,   165,   165,   -82,   149,   150,   152,
     -82,   156,   -82,   165,   151,   -82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   -82,    -3,   -82,    67,   -82,   -82,   166,
     -82,   131,   163,   -82,   -55,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -43,   -81,    88,   -49,   -82,   -82,   -82,   -82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      62,    87,    79,   115,   116,   117,    26,     1,    66,    66,
      27,    21,    22,    62,    67,    68,    68,     3,    93,     4,
      95,    96,    97,    98,    99,     5,   101,   102,   100,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       6,   143,   109,   110,   111,   112,   113,    17,    18,    19,
       7,    10,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   101,   102,   120,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    20,
     111,   112,   113,    11,    12,    23,    16,    25,    35,   147,
     148,    24,    33,    29,    28,    34,    37,    36,   154,    40,
      38,    62,    62,    29,    46,   114,    45,    47,   101,   102,
      62,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   101,   102,    64,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    65,    69,    70,    84,
      85,    86,    94,   122,   118,   119,   101,   102,   121,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      88,   123,   101,   102,   139,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    71,   140,   141,   144,
     146,   145,   151,    72,    73,   124,    48,   149,   150,   155,
      74,    75,    76,   153,    49,    89,    50,    51,    52,    53,
      54,   125,    39,     0,    52,    53,    54,    63,   142,     0,
      77,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      43,    56,    51,    84,    85,    86,    39,    23,    39,    39,
      43,    14,    15,    56,    45,    46,    46,    24,    67,     0,
      69,    70,    71,    72,    73,    21,     3,     4,    77,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      37,   122,    12,    13,    14,    15,    16,    26,    27,    28,
      23,    25,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,     3,     4,    44,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    12,
      14,    15,    16,    38,    25,    36,    26,    39,    42,   144,
     145,    21,    40,    26,    22,    21,    41,    44,   153,    21,
      37,   144,   145,    36,    21,    43,    42,    38,     3,     4,
     153,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     3,     4,    37,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    43,    39,    39,    39,
      39,    39,    21,    39,    38,    42,     3,     4,    43,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      43,    42,     3,     4,    42,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     5,    42,    42,    37,
      42,    37,    30,    12,    13,    42,    21,    38,    38,    38,
      19,    20,    21,    37,    29,    64,    31,    32,    33,    34,
      35,    42,    36,    -1,    33,    34,    35,    44,   120,    -1,
      39,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    48,    24,     0,    21,    37,    23,    49,    50,
      25,    38,    25,    51,    52,    54,    26,    26,    27,    28,
      53,    51,    51,    36,    21,    39,    39,    43,    22,    53,
      55,    56,    57,    40,    21,    42,    44,    41,    37,    56,
      21,    53,    58,    59,    60,    42,    21,    38,    21,    29,
      31,    32,    33,    34,    35,    61,    62,    63,    64,    66,
      67,    68,    69,    59,    37,    43,    39,    45,    46,    39,
      39,     5,    12,    13,    19,    20,    21,    39,    69,    72,
      73,    74,    75,    76,    39,    39,    39,    61,    43,    58,
      70,    71,    72,    72,    21,    72,    72,    72,    72,    72,
      72,     3,     4,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    43,    70,    70,    70,    38,    42,
      44,    43,    39,    42,    42,    42,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    42,
      42,    42,    71,    70,    37,    37,    42,    61,    61,    38,
      38,    30,    65,    37,    61,    38
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 65 "rules.y"
    {executable = new Executable((yyvsp[(5) - (6)].methodList), (yyvsp[(3) - (6)].name));}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 68 "rules.y"
    {(yyvsp[(2) - (2)].methodList)->addMethod((yyvsp[(1) - (2)].method)); (yyval.methodList) = (yyvsp[(2) - (2)].methodList); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 71 "rules.y"
    {(yyval.method) = new Method("main", new Variables(), (yyvsp[(12) - (13)].methodBody), data_type::NONE);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 74 "rules.y"
    {(yyvsp[(2) - (2)].methodList)->addField((yyvsp[(1) - (2)].field)); (yyval.methodList) = (yyvsp[(2) - (2)].methodList);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 75 "rules.y"
    {(yyvsp[(2) - (2)].methodList)->addMethod((yyvsp[(1) - (2)].method)); (yyval.methodList) = (yyvsp[(2) - (2)].methodList);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 76 "rules.y"
    {(yyval.methodList) = new FieldMethodList();}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 79 "rules.y"
    { (yyval.field) = new Field((yyvsp[(2) - (4)].type), (yyvsp[(3) - (4)].name));}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 82 "rules.y"
    {(yyval.type) = data_type::BOOLEAN;}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 83 "rules.y"
    {(yyval.type) = data_type::INTEGER;}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 84 "rules.y"
    {(yyval.type) = data_type::NONE;}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 87 "rules.y"
    {(yyval.method) = new Method((yyvsp[(3) - (9)].name), (yyvsp[(5) - (9)].variables), (yyvsp[(8) - (9)].methodBody), (yyvsp[(2) - (9)].type));}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 90 "rules.y"
    { (yyval.variables) = (yyvsp[(1) - (1)].variables);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 91 "rules.y"
    { (yyval.variables) = new Variables(); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 94 "rules.y"
    { (yyvsp[(3) - (3)].variables)->addField((yyvsp[(1) - (3)].field)); (yyval.variables) = (yyvsp[(3) - (3)].variables); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 95 "rules.y"
    { (yyval.variables) = new Variables(); (yyval.variables) -> addField((yyvsp[(1) - (1)].field)); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 98 "rules.y"
    {(yyval.field) = new Field((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].name));}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 101 "rules.y"
    { (yyval.methodBody) = new MethodBody((yyvsp[(1) - (2)].variables), (yyvsp[(2) - (2)].statementList)); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 104 "rules.y"
    {(yyvsp[(2) - (2)].variables) -> addField((yyvsp[(1) - (2)].field)); (yyval.variables) = (yyvsp[(2) - (2)].variables);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 105 "rules.y"
    {(yyval.variables) = new Variables();}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 108 "rules.y"
    {(yyval.field) = new Field((yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].name));}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 111 "rules.y"
    {(yyvsp[(2) - (2)].statementList) -> addStatement((yyvsp[(1) - (2)].statement)); (yyval.statementList) = (yyvsp[(2) - (2)].statementList);}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 112 "rules.y"
    {(yyval.statementList) = new StatementList();}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 115 "rules.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 116 "rules.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 117 "rules.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 118 "rules.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 119 "rules.y"
    {(yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 122 "rules.y"
    {(yyval.statement) = new AssignStatement((yyvsp[(1) - (4)].name), (yyvsp[(3) - (4)].expression));}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 125 "rules.y"
    {(yyval.statement) = new IfStatement((yyvsp[(3) - (8)].expression), (yyvsp[(6) - (8)].statementList), (yyvsp[(8) - (8)].statementList));}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 128 "rules.y"
    {(yyval.statementList) = (yyvsp[(3) - (4)].statementList);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 129 "rules.y"
    {(yyval.statementList) = new StatementList();}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 132 "rules.y"
    {(yyval.statement) = new WhileStatement((yyvsp[(3) - (7)].expression), (yyvsp[(6) - (7)].statementList));}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 135 "rules.y"
    {(yyval.statement) = new InvokeStatement((yyvsp[(1) - (2)].expression));}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 138 "rules.y"
    {(yyval.statement) = new ReturnStatement((yyvsp[(2) - (3)].expression));}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 141 "rules.y"
    {(yyval.expression) = new InvokeExpression((yyvsp[(3) - (6)].name), (yyvsp[(5) - (6)].passedArguments), (yyvsp[(1) - (6)].name));}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 142 "rules.y"
    {(yyval.expression) = new InvokeExpression((yyvsp[(1) - (4)].name), (yyvsp[(3) - (4)].passedArguments), "");}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 143 "rules.y"
    {(yyval.expression) = new InvokeExpression("write", (yyvsp[(3) - (4)].passedArguments), "");}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 144 "rules.y"
    {(yyval.expression) = new InvokeExpression("readInt", (yyvsp[(3) - (4)].passedArguments), "");}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 145 "rules.y"
    {(yyval.expression) = new InvokeExpression("readBool", (yyvsp[(3) - (4)].passedArguments), "");}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 148 "rules.y"
    {(yyval.passedArguments) = (yyvsp[(1) - (1)].passedArguments);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 149 "rules.y"
    {(yyval.passedArguments) = new ExpressionList();}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 152 "rules.y"
    {(yyvsp[(3) - (3)].passedArguments) -> addExpression((yyvsp[(1) - (3)].expression)); (yyval.passedArguments) = (yyvsp[(3) - (3)].passedArguments);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 153 "rules.y"
    {(yyval.passedArguments) = new ExpressionList(); (yyval.passedArguments) -> addExpression((yyvsp[(1) - (1)].expression));}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 156 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 157 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 158 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 159 "rules.y"
    {(yyval.expression) = (yyvsp[(2) - (3)].expression);}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 160 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 161 "rules.y"
    {(yyval.expression) = (yyvsp[(1) - (1)].expression);}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 164 "rules.y"
    {(yyval.expression) = new LiteralExpression(data_type::BOOLEAN, (yyvsp[(1) - (1)].value));}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 165 "rules.y"
    {(yyval.expression) = new LiteralExpression(data_type::INTEGER, (yyvsp[(1) - (1)].value));}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 168 "rules.y"
    {(yyval.expression) = new VariableExpression((yyvsp[(1) - (1)].name));}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 171 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::OPPOSITE, (yyvsp[(2) - (2)].expression), NULL);}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 172 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::IDLE, (yyvsp[(2) - (2)].expression), NULL);}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 173 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::NOT, (yyvsp[(2) - (2)].expression), NULL);}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 176 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::ADD, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 177 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::SUBTRACT, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 178 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::DIVIDE, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 179 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::MULTIPLY, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 180 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::MODULE, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 181 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::OPAND, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 182 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::OPOR, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 183 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 184 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::NOT_EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 185 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::LESS_EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 186 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::LESS, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 187 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::GREATER_EQUAL, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 188 "rules.y"
    {(yyval.expression) = new OperatorExpression(operation_type::GREATER, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));}
    break;


/* Line 1792 of yacc.c  */
#line 1932 "rules.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 189 "rules.y"

