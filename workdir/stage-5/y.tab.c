/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include "exptree.h"
    #include "symbolTable.h"
    #include "codeGen.h"

    int yylex(void);
    int yyerror(const char *s);

    FILE * output;
    extern int localBinding ;
    int currentType ;
    int paramType ;
    int currLocalType ;
    int flabel = 1;
    struct Gsymbol * Ghead  = NULL ;
    struct Lsymbol * Lhead  = NULL ; 
    struct ParamStruct * paramHead = NULL ;
    struct Gsymbol * currentFunc = NULL ;  //Current function for return type checking 

#line 92 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PLUS = 258,
    MINUS = 259,
    STAR = 260,
    DIV = 261,
    LE = 262,
    LT = 263,
    GT = 264,
    GE = 265,
    EQ = 266,
    NE = 267,
    IF = 268,
    ELSE = 269,
    WHILE = 270,
    REPEAT = 271,
    UNTIL = 272,
    DO = 273,
    BREAK = 274,
    CONTINUE = 275,
    ENDIF = 276,
    ENDWHILE = 277,
    DECL = 278,
    ENDDECL = 279,
    BEG = 280,
    END = 281,
    INT = 282,
    STR = 283,
    SEMICOLON = 284,
    THEN = 285,
    READ = 286,
    WRITE = 287,
    EXIT_PR = 288,
    MAIN = 289,
    RETURN = 290,
    NUM = 291,
    STR_LITERAL = 292,
    ID = 293,
    ASSIGN = 294
  };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define STAR 260
#define DIV 261
#define LE 262
#define LT 263
#define GT 264
#define GE 265
#define EQ 266
#define NE 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define REPEAT 271
#define UNTIL 272
#define DO 273
#define BREAK 274
#define CONTINUE 275
#define ENDIF 276
#define ENDWHILE 277
#define DECL 278
#define ENDDECL 279
#define BEG 280
#define END 281
#define INT 282
#define STR 283
#define SEMICOLON 284
#define THEN 285
#define READ 286
#define WRITE 287
#define EXIT_PR 288
#define MAIN 289
#define RETURN 290
#define NUM 291
#define STR_LITERAL 292
#define ID 293
#define ASSIGN 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

    struct ParamStruct * paramList ;
    struct tnode * node;
    int number ;
    char * string ;

#line 229 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

#define YYUNDEFTOK  2
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    55,    56,    59,    59,    80,    81,    84,
      85,    88,    91,    92,    95,    96,    97,   103,   104,   107,
     111,   116,   117,   118,   121,   124,   129,   130,   133,   134,
     137,   140,   141,   144,   145,   148,   149,   152,   153,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   174,   177,   180,   186,   187,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   202,
     202,   226,   229,   234,   239,   242,   245,   248,   251,   254,
     259
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "STAR", "DIV", "LE",
  "LT", "GT", "GE", "EQ", "NE", "IF", "ELSE", "WHILE", "REPEAT", "UNTIL",
  "DO", "BREAK", "CONTINUE", "ENDIF", "ENDWHILE", "DECL", "ENDDECL", "BEG",
  "END", "INT", "STR", "SEMICOLON", "THEN", "READ", "WRITE", "EXIT_PR",
  "MAIN", "RETURN", "NUM", "STR_LITERAL", "ID", "ASSIGN", "'('", "')'",
  "'{'", "'}'", "','", "'['", "']'", "$accept", "program", "MainBlock",
  "$@1", "GDeclBlock", "GDeclList", "GDecl", "GidList", "Gid", "FDefBlock",
  "Body", "ParamList", "Param", "Ret", "LdeclBlock", "LDeclList", "LDecl",
  "IdList", "GType", "ParType", "LType", "EXPR", "ArgList", "stmtList",
  "stmt", "Fdef", "$@2", "ifStmt", "whileStmt", "doWhileStmt",
  "repeatStmt", "ipStmt", "opStmt", "assignStmt", "IDENTIFIERS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      40,    41,   123,   125,    44,    91,    93
};
# endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,    32,   -23,    24,   -80,    36,   -80,   -80,   -80,    63,
     -80,   -12,    -2,   -80,   -23,   -80,    36,     2,   -80,   -80,
     -80,   -33,   -26,   -80,    52,   -80,   -80,    18,    58,    64,
     -80,   -12,   111,    58,   -80,   -80,    68,   -80,   114,   109,
     -80,   -80,    75,   -80,    58,   -80,   -80,   133,   115,   -80,
      77,   135,   -80,   -80,   -80,   -80,    90,   -80,   120,   248,
     119,   133,   -80,   -80,   -80,   -21,   121,   123,   306,   306,
     136,   137,   124,   127,   139,    17,   125,   145,   248,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   134,   -80,   135,
     -80,   140,    17,    17,   256,   314,   -80,   -80,   172,    17,
     -80,   -80,   -80,    -3,    17,   197,   -80,    17,   143,   148,
     -80,    17,   132,   -80,    72,   118,   171,   173,   174,   128,
      -7,   138,    17,    17,    17,    17,    17,    17,    17,    17,
      17,    17,   -80,    62,   -80,   147,   226,   -80,   182,   159,
      17,    17,   185,   188,   -80,   350,   110,   -80,    93,    93,
     -80,   -80,   360,   360,   360,   360,   360,   360,   -80,   -80,
     -80,   306,   306,   177,   187,   -80,   -80,   -80,    17,   227,
     277,   190,   -14,   350,   306,   191,   192,   -80,   -80,   285,
     -80,   -80,   193,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     8,    33,    34,     0,
      10,     0,     0,     1,    33,     3,     0,     0,    18,     7,
       9,    14,     0,    13,     0,     2,    17,     0,    23,     0,
      11,     0,     0,    23,    35,    36,     0,    22,     0,     0,
      12,     5,     0,    16,     0,    24,    15,     0,     0,    21,
       0,     0,    69,    27,    37,    38,     0,    29,     0,     0,
       0,     0,    26,    28,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,    58,
      62,    63,    64,    65,    59,    60,    61,     0,     6,     0,
      30,     0,     0,     0,     0,     0,    66,    67,     0,     0,
      68,    50,    51,    79,     0,     0,    52,     0,     0,     0,
      57,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,    20,     0,     0,    70,     0,     0,
       0,     0,     0,     0,    53,    56,     0,    49,    40,    39,
      41,    42,    43,    44,    45,    46,    47,    48,    80,    19,
      78,     0,     0,     0,     0,    76,    77,    54,     0,     0,
       0,     0,     0,    55,     0,     0,     0,    75,    74,     0,
      72,    73,     0,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,     1,   -80,   -80,   -80,   207,   -80,   194,   -80,
     150,   211,   179,   146,   166,   -80,   195,   -80,    11,   -80,
     -80,   -79,   -80,   -67,   -73,   233,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    47,     5,     9,    10,    22,    23,    16,
      60,    36,    37,    77,    51,    56,    57,    65,    11,    38,
      58,   105,   146,    78,    79,    18,    61,    80,    81,    82,
      83,    84,    85,    86,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,    94,    95,    30,   162,   110,    15,    28,    90,    87,
      87,    12,    29,   114,   115,   178,    17,    25,    31,    87,
     119,   110,   110,    91,    13,   121,    21,    17,   133,   101,
     102,   103,   136,   104,   144,    87,    87,   120,    24,   118,
      27,   145,   107,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   101,   102,   103,     6,   104,    33,     7,
       8,   163,   164,    14,     8,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    34,    35,    19,     1,   173,
       7,     8,     2,    32,   169,   170,   110,   110,   124,   125,
      39,    53,    87,    87,    54,    55,   110,   179,   158,    43,
      87,    87,    44,   138,    62,    87,    48,    54,    55,    44,
      87,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   167,    45,    41,   168,    46,    50,    52,    64,   139,
      59,    92,    88,    93,    98,    96,    97,    99,   100,   143,
     107,   108,   134,   111,   135,   137,   159,   162,   113,   147,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      76,   140,   161,   141,   165,   142,    20,   166,   171,   177,
     180,   181,   183,    49,   109,    40,   132,    89,   172,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   112,
      66,   174,    67,    68,    42,    69,    70,    71,   175,    26,
       0,    63,     0,     0,     0,   160,     0,     0,    72,    73,
      74,    66,     0,    67,    68,    76,    69,    70,    71,    66,
       0,    67,    68,   116,    69,    70,    71,     0,     0,    72,
      73,    74,     0,    75,     0,     0,    76,    72,    73,    74,
      66,     0,    67,    68,    76,    69,    70,    71,    66,   176,
      67,    68,     0,    69,    70,    71,   182,     0,    72,    73,
      74,     0,     0,     0,     0,    76,    72,    73,    74,    66,
       0,    67,    68,    76,    69,    70,    71,    66,     0,   117,
      68,     0,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,     0,     0,    76,    72,    73,    74,     0,     0,
       0,     0,    76,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      59,    68,    69,    29,    18,    78,     5,    40,    29,    68,
      69,    34,    45,    92,    93,    29,     5,    16,    44,    78,
      99,    94,    95,    44,     0,   104,    38,    16,   107,    36,
      37,    38,   111,    40,    41,    94,    95,    40,    40,    98,
      38,   120,    45,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    36,    37,    38,    24,    40,    40,    27,
      28,   140,   141,    27,    28,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    27,    28,    24,    23,   168,
      27,    28,    27,    41,   161,   162,   169,   170,     5,     6,
      36,    24,   161,   162,    27,    28,   179,   174,    46,    41,
     169,   170,    44,    41,    24,   174,    41,    27,    28,    44,
     179,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    41,    38,    42,    44,    46,    23,    42,    38,    41,
      25,    40,    43,    40,    40,    29,    29,    40,    29,    41,
      45,    26,    29,    39,    26,    43,    29,    18,    38,    41,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      38,    40,    30,    40,    29,    41,     9,    29,    41,    29,
      29,    29,    29,    44,    78,    31,    29,    61,    41,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    89,
      13,    14,    15,    16,    33,    18,    19,    20,    21,    16,
      -1,    56,    -1,    -1,    -1,    29,    -1,    -1,    31,    32,
      33,    13,    -1,    15,    16,    38,    18,    19,    20,    13,
      -1,    15,    16,    17,    18,    19,    20,    -1,    -1,    31,
      32,    33,    -1,    35,    -1,    -1,    38,    31,    32,    33,
      13,    -1,    15,    16,    38,    18,    19,    20,    13,    22,
      15,    16,    -1,    18,    19,    20,    21,    -1,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    31,    32,    33,    13,
      -1,    15,    16,    38,    18,    19,    20,    13,    -1,    15,
      16,    -1,    18,    19,    20,    -1,    -1,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    27,    48,    49,    51,    24,    27,    28,    52,
      53,    65,    34,     0,    27,    49,    56,    65,    72,    24,
      53,    38,    54,    55,    40,    49,    72,    38,    40,    45,
      29,    44,    41,    40,    27,    28,    58,    59,    66,    36,
      55,    42,    58,    41,    44,    38,    46,    50,    41,    59,
      23,    61,    42,    24,    27,    28,    62,    63,    67,    25,
      57,    73,    24,    63,    38,    64,    13,    15,    16,    18,
      19,    20,    31,    32,    33,    35,    38,    60,    70,    71,
      74,    75,    76,    77,    78,    79,    80,    81,    43,    61,
      29,    44,    40,    40,    70,    70,    29,    29,    40,    40,
      29,    36,    37,    38,    40,    68,    81,    45,    26,    60,
      71,    39,    57,    38,    68,    68,    17,    15,    81,    68,
      40,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    29,    68,    29,    26,    68,    43,    41,    41,
      40,    40,    41,    41,    41,    68,    69,    41,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    46,    29,
      29,    30,    18,    68,    68,    29,    29,    41,    44,    70,
      70,    41,    41,    68,    14,    21,    22,    29,    29,    70,
      29,    29,    21,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    48,    50,    49,    51,    51,    52,
      52,    53,    54,    54,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    58,    59,    60,    61,    61,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    73,
      72,    74,    74,    75,    76,    77,    78,    79,    80,    81,
      81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     0,     9,     3,     2,     2,
       1,     3,     3,     1,     1,     4,     4,     2,     1,     5,
       4,     3,     1,     0,     2,     3,     3,     2,     2,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     3,     4,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     0,
      10,    10,     8,     8,     7,     7,     5,     5,     4,     1,
       4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 54 "parser.y"
                                                {}
#line 1566 "y.tab.c"
    break;

  case 3:
#line 55 "parser.y"
                                                {}
#line 1572 "y.tab.c"
    break;

  case 4:
#line 56 "parser.y"
                                                {}
#line 1578 "y.tab.c"
    break;

  case 5:
#line 59 "parser.y"
                                                {   
                                                    Ghead = insertTable(Ghead,"F0",INT_TYPE,0,0); 
                                                    currentFunc = find(Ghead, "F0");
                                                    if(currentFunc == NULL) {
                                                        printf("Error: Function '%s' not found in symbol table\n", "main");
                                                        exit(1);
                                                    }
                                                }
#line 1591 "y.tab.c"
    break;

  case 6:
#line 67 "parser.y"
                                                {
                                                   

                                                    currentFunc->bodyAST = (yyvsp[-1].node) ;
                                                    currentFunc->Lentry = Lhead ;
                                                    
                                                    funcCodeGen(currentFunc,output); 
                                                    currentFunc = NULL ;
                                                    Lhead = NULL ;
                                                    
                                                }
#line 1607 "y.tab.c"
    break;

  case 7:
#line 80 "parser.y"
                                            {}
#line 1613 "y.tab.c"
    break;

  case 8:
#line 81 "parser.y"
                                            {}
#line 1619 "y.tab.c"
    break;

  case 9:
#line 84 "parser.y"
                                            {}
#line 1625 "y.tab.c"
    break;

  case 10:
#line 85 "parser.y"
                                            {}
#line 1631 "y.tab.c"
    break;

  case 11:
#line 88 "parser.y"
                                            {}
#line 1637 "y.tab.c"
    break;

  case 12:
#line 91 "parser.y"
                                            {}
#line 1643 "y.tab.c"
    break;

  case 13:
#line 92 "parser.y"
                                            {}
#line 1649 "y.tab.c"
    break;

  case 14:
#line 95 "parser.y"
                                            {   Ghead = insertTable(Ghead,((yyvsp[0].node))->varname,currentType,1,-1); }
#line 1655 "y.tab.c"
    break;

  case 15:
#line 96 "parser.y"
                                            {   Ghead = insertTable(Ghead,((yyvsp[-3].node))->varname,currentType,(yyvsp[-1].number),-1);}
#line 1661 "y.tab.c"
    break;

  case 16:
#line 97 "parser.y"
                                            {   
                                                Ghead = insertTable(Ghead,((yyvsp[-3].node))->varname,currentType,0,flabel++);
                                                insertParamListToGST(Ghead,((yyvsp[-3].node))->varname,(yyvsp[-1].paramList));
                                            }
#line 1670 "y.tab.c"
    break;

  case 17:
#line 103 "parser.y"
                                            {}
#line 1676 "y.tab.c"
    break;

  case 18:
#line 104 "parser.y"
                                            {}
#line 1682 "y.tab.c"
    break;

  case 19:
#line 107 "parser.y"
                                                {  
                                                    (yyval.node) = connectNode((yyvsp[-3].node),(yyvsp[-2].node)); 
                                                    //inorder($$);
                                                }
#line 1691 "y.tab.c"
    break;

  case 20:
#line 111 "parser.y"
                                                { 
                                                    (yyval.node) = (yyvsp[-2].node) ;
                                                }
#line 1699 "y.tab.c"
    break;

  case 21:
#line 116 "parser.y"
                                            {   (yyval.paramList) = insertToParamList((yyvsp[-2].paramList),((yyvsp[0].paramList))->name,((yyvsp[0].paramList))->type) ; }
#line 1705 "y.tab.c"
    break;

  case 22:
#line 117 "parser.y"
                                            {   (yyval.paramList) = insertToParamList(NULL,((yyvsp[0].paramList))->name,((yyvsp[0].paramList))->type) ;}
#line 1711 "y.tab.c"
    break;

  case 23:
#line 118 "parser.y"
                                            {   (yyval.paramList) = NULL ;}
#line 1717 "y.tab.c"
    break;

  case 24:
#line 121 "parser.y"
                                            {   (yyval.paramList) = createParamStructNode(strdup((yyvsp[0].node)->varname),paramType); }
#line 1723 "y.tab.c"
    break;

  case 25:
#line 124 "parser.y"
                                            {   
                                                (yyval.node) = returnNode(currentFunc,RETURN_NODE,(yyvsp[-1].node)); 
                                                //printf("%s\n",$$->left->varname);
                                            }
#line 1732 "y.tab.c"
    break;

  case 26:
#line 129 "parser.y"
                                            {   localBinding = 1; }
#line 1738 "y.tab.c"
    break;

  case 27:
#line 130 "parser.y"
                                            {}
#line 1744 "y.tab.c"
    break;

  case 28:
#line 133 "parser.y"
                                            {}
#line 1750 "y.tab.c"
    break;

  case 29:
#line 134 "parser.y"
                                            {}
#line 1756 "y.tab.c"
    break;

  case 30:
#line 137 "parser.y"
                                            {}
#line 1762 "y.tab.c"
    break;

  case 31:
#line 140 "parser.y"
                                            {   Lhead = insertToLocalTable(Lhead,((yyvsp[0].node))->varname,currLocalType);}
#line 1768 "y.tab.c"
    break;

  case 32:
#line 141 "parser.y"
                                            {   Lhead = insertToLocalTable(Lhead,((yyvsp[0].node))->varname,currLocalType);}
#line 1774 "y.tab.c"
    break;

  case 33:
#line 144 "parser.y"
                                            {   currentType = INT_TYPE ;}
#line 1780 "y.tab.c"
    break;

  case 34:
#line 145 "parser.y"
                                            {   currentType = STR_TYPE ;}
#line 1786 "y.tab.c"
    break;

  case 35:
#line 148 "parser.y"
                                            {   paramType = INT_TYPE ;}
#line 1792 "y.tab.c"
    break;

  case 36:
#line 149 "parser.y"
                                            {   paramType = STR_TYPE ;}
#line 1798 "y.tab.c"
    break;

  case 37:
#line 152 "parser.y"
                                            {   currLocalType = INT_TYPE ;}
#line 1804 "y.tab.c"
    break;

  case 38:
#line 153 "parser.y"
                                            {   currLocalType = STR_TYPE ;}
#line 1810 "y.tab.c"
    break;

  case 39:
#line 157 "parser.y"
                                            {   (yyval.node) = exprNode(MINUS_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1816 "y.tab.c"
    break;

  case 40:
#line 158 "parser.y"
                                            {   (yyval.node) = exprNode(ADD_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1822 "y.tab.c"
    break;

  case 41:
#line 159 "parser.y"
                                            {   (yyval.node) = exprNode(MUL_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1828 "y.tab.c"
    break;

  case 42:
#line 160 "parser.y"
                                            {   (yyval.node) = exprNode(DIV_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1834 "y.tab.c"
    break;

  case 43:
#line 161 "parser.y"
                                            {   (yyval.node) = exprNode(LE_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1840 "y.tab.c"
    break;

  case 44:
#line 162 "parser.y"
                                            {   (yyval.node) = exprNode(LT_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1846 "y.tab.c"
    break;

  case 45:
#line 163 "parser.y"
                                            {   (yyval.node) = exprNode(GT_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1852 "y.tab.c"
    break;

  case 46:
#line 164 "parser.y"
                                            {   (yyval.node) = exprNode(GE_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1858 "y.tab.c"
    break;

  case 47:
#line 165 "parser.y"
                                            {   (yyval.node) = exprNode(EQ_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1864 "y.tab.c"
    break;

  case 48:
#line 166 "parser.y"
                                            {   (yyval.node) = exprNode(NE_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1870 "y.tab.c"
    break;

  case 49:
#line 167 "parser.y"
                                            {   (yyval.node) = (yyvsp[-1].node) ;}
#line 1876 "y.tab.c"
    break;

  case 50:
#line 168 "parser.y"
                                            {   (yyval.node) = createTreeNode((yyvsp[0].number),INT_TYPE,NULL,NUM_NODE,NULL,NULL,NULL,NULL); }
#line 1882 "y.tab.c"
    break;

  case 51:
#line 169 "parser.y"
                                            {   (yyval.node) = createTreeNode(NO_VAL,STR_TYPE,(yyvsp[0].string),STR_NODE,NULL,NULL,NULL,NULL); }
#line 1888 "y.tab.c"
    break;

  case 52:
#line 170 "parser.y"
                                            {   (yyval.node) = (yyvsp[0].node) ; }
#line 1894 "y.tab.c"
    break;

  case 53:
#line 171 "parser.y"
                                            {   
                                                (yyval.node) = funcNode(Ghead,(yyvsp[-2].node),NULL);
                                            }
#line 1902 "y.tab.c"
    break;

  case 54:
#line 174 "parser.y"
                                            {   (yyval.node) = funcNode(Ghead,(yyvsp[-3].node),(yyvsp[-1].node));}
#line 1908 "y.tab.c"
    break;

  case 55:
#line 177 "parser.y"
                                            {
                                                (yyval.node) = appendArg((yyvsp[-2].node),(yyvsp[0].node));
                                            }
#line 1916 "y.tab.c"
    break;

  case 56:
#line 180 "parser.y"
                                            {   
                                                (yyval.node) = (yyvsp[0].node);
                                                (yyval.node)->argList = NULL ;
                                            }
#line 1925 "y.tab.c"
    break;

  case 57:
#line 186 "parser.y"
                                                {   (yyval.node) = connectNode((yyvsp[-1].node),(yyvsp[0].node)); }
#line 1931 "y.tab.c"
    break;

  case 58:
#line 187 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 1937 "y.tab.c"
    break;

  case 59:
#line 190 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 1943 "y.tab.c"
    break;

  case 60:
#line 191 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 1949 "y.tab.c"
    break;

  case 61:
#line 192 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 1955 "y.tab.c"
    break;

  case 62:
#line 193 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 1961 "y.tab.c"
    break;

  case 63:
#line 194 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 1967 "y.tab.c"
    break;

  case 64:
#line 195 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 1973 "y.tab.c"
    break;

  case 65:
#line 196 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 1979 "y.tab.c"
    break;

  case 66:
#line 197 "parser.y"
                                                {   (yyval.node) = flowControlNode(BREAK_NODE); }
#line 1985 "y.tab.c"
    break;

  case 67:
#line 198 "parser.y"
                                                {   (yyval.node) = flowControlNode(CONTINUE_NODE); }
#line 1991 "y.tab.c"
    break;

  case 68:
#line 199 "parser.y"
                                                {   (yyval.node) = exitNode(EXIT_NODE); }
#line 1997 "y.tab.c"
    break;

  case 69:
#line 202 "parser.y"
                                                {   
                                                    
                                                    currentFunc = find(Ghead, (yyvsp[-4].node)->varname);
                                                    checkDeclAndDefn(currentFunc,currentType);
                                                    if(currentFunc == NULL) {
                                                        printf("Error: Function '%s' not found in symbol table\n", (yyvsp[-4].node)->varname);
                                                        exit(1);
                                                    }
                                                    compareParamList(currentFunc,(yyvsp[-2].paramList)) ;
                                                    Lhead = createLSTFromParams((yyvsp[-2].paramList));
                                                }
#line 2013 "y.tab.c"
    break;

  case 70:
#line 213 "parser.y"
                                                {
                                                    currentFunc->bodyAST = (yyvsp[-1].node) ;
                                                    currentFunc->Lentry = Lhead ;
                                                    //printLocalSymbolTable(Lhead);
                                                    
                                                    funcCodeGen(currentFunc,output);                                       
                                                    currentFunc = NULL ;
                                                    Lhead = NULL ;
                                                }
#line 2027 "y.tab.c"
    break;

  case 71:
#line 226 "parser.y"
                                                                                {   
                                                                                    (yyval.node) = ifelseNode(IF_NODE,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));
                                                                                }
#line 2035 "y.tab.c"
    break;

  case 72:
#line 229 "parser.y"
                                                                                {
                                                                                    (yyval.node) = ifelseNode(IF_NODE,(yyvsp[-5].node),(yyvsp[-2].node),NULL);
                                                                                }
#line 2043 "y.tab.c"
    break;

  case 73:
#line 234 "parser.y"
                                                                                {
                                                                                    (yyval.node) = loopNode(WHILE_NODE,(yyvsp[-5].node),(yyvsp[-2].node));
                                                                                }
#line 2051 "y.tab.c"
    break;

  case 74:
#line 239 "parser.y"
                                                                                {   (yyval.node) = loopNode(DOWHILE_NODE,(yyvsp[-2].node),(yyvsp[-5].node)); }
#line 2057 "y.tab.c"
    break;

  case 75:
#line 242 "parser.y"
                                                                                {   (yyval.node) = loopNode(REPEAT_NODE,(yyvsp[-2].node),(yyvsp[-5].node)); }
#line 2063 "y.tab.c"
    break;

  case 76:
#line 245 "parser.y"
                                                                                {   (yyval.node) = ipOpNode(READ_NODE,(yyvsp[-2].node)); }
#line 2069 "y.tab.c"
    break;

  case 77:
#line 248 "parser.y"
                                                                                {   (yyval.node) = ipOpNode(WRITE_NODE,(yyvsp[-2].node)); }
#line 2075 "y.tab.c"
    break;

  case 78:
#line 251 "parser.y"
                                                                                {   (yyval.node) = assignNode((yyvsp[-3].node),(yyvsp[-1].node)); }
#line 2081 "y.tab.c"
    break;

  case 79:
#line 254 "parser.y"
                                                                                {   
                                                                                    struct tnode * node = setTypeId(Ghead,Lhead,(yyvsp[0].node),NULL,NULL);
                                                                                    node->nodetype = ID_NODE ;
                                                                                    (yyval.node) = node;
                                                                                }
#line 2091 "y.tab.c"
    break;

  case 80:
#line 259 "parser.y"
                                                                                {   
                                                                                    struct tnode * node = setTypeId(Ghead,Lhead,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
                                                                                    node->nodetype = ARR_NODE ;
                                                                                    (yyval.node) = node;
                                                                                }
#line 2101 "y.tab.c"
    break;


#line 2105 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 266 "parser.y"


int yyerror(const char *s) {
    printf("Erorr: %s/n",s);
    return 1;
}

extern FILE* yyin;

int main(int argc, char** argv) {

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("Error opening file\n");
            return 1;
        }
    }

    output = fopen("output.xsm", "w");

    auxFunctions(output,ENTRY_CODE,-1,-1);
    fprintf(output,"CALL F0\n");
    yyparse();
    auxFunctions(output,EXIT_CODE,-1,-1);

    fclose(output);
    return 0;
}
