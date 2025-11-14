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
    #include "TypeTable.h"
    #include "codeGen.h"

    int yylex(void);
    int yyerror(const char *s);

    FILE * output;
    extern int yylineNum; 
    extern int localBinding ;
    int flabel = 1;

    struct Gsymbol * Ghead  = NULL ;
    struct Lsymbol * Lhead  = NULL ; 
    struct ParamStruct * paramHead = NULL ;
    struct Gsymbol * currentFunc = NULL ;  //Current function for return type checking 

    struct TypeTable * currentType ;
    struct TypeTable * paramType ;
    struct TypeTable * currLocalType ;

    struct TypeTable * TTableHead = NULL ;
    struct TypeTable * currTupleType = NULL ;

#line 99 "y.tab.c"

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
    AMPERSAND = 262,
    LE = 263,
    LT = 264,
    GT = 265,
    GE = 266,
    EQ = 267,
    NE = 268,
    AND = 269,
    OR = 270,
    NOT = 271,
    ASSIGN = 272,
    IF = 273,
    ELSE = 274,
    WHILE = 275,
    REPEAT = 276,
    UNTIL = 277,
    DO = 278,
    BREAK = 279,
    CONTINUE = 280,
    ENDIF = 281,
    ENDWHILE = 282,
    DECL = 283,
    ENDDECL = 284,
    BEG = 285,
    END = 286,
    INT = 287,
    STR = 288,
    SEMICOLON = 289,
    THEN = 290,
    READ = 291,
    WRITE = 292,
    EXIT_PR = 293,
    MAIN = 294,
    RETURN = 295,
    TUPLE = 296,
    DOT = 297,
    NUM = 298,
    STR_LITERAL = 299,
    ID = 300
  };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define STAR 260
#define DIV 261
#define AMPERSAND 262
#define LE 263
#define LT 264
#define GT 265
#define GE 266
#define EQ 267
#define NE 268
#define AND 269
#define OR 270
#define NOT 271
#define ASSIGN 272
#define IF 273
#define ELSE 274
#define WHILE 275
#define REPEAT 276
#define UNTIL 277
#define DO 278
#define BREAK 279
#define CONTINUE 280
#define ENDIF 281
#define ENDWHILE 282
#define DECL 283
#define ENDDECL 284
#define BEG 285
#define END 286
#define INT 287
#define STR 288
#define SEMICOLON 289
#define THEN 290
#define READ 291
#define WRITE 292
#define EXIT_PR 293
#define MAIN 294
#define RETURN 295
#define TUPLE 296
#define DOT 297
#define NUM 298
#define STR_LITERAL 299
#define ID 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"

    struct ParamStruct * paramList ;
    struct tnode * node;
    int number ;
    char * string ;
    struct Fieldlist * flist ;
    struct TypeTable * type ;

#line 250 "y.tab.c"

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


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
      46,    47,     2,     2,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    67,    68,    71,    71,    91,    92,    95,
      96,    99,   100,   103,   103,   121,   122,   125,   126,   129,
     138,   144,   147,   148,   151,   152,   153,   157,   160,   161,
     164,   168,   173,   174,   175,   178,   179,   182,   187,   188,
     191,   192,   195,   196,   199,   199,   216,   217,   220,   221,
     225,   226,   229,   230,   233,   234,   237,   238,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   262,   265,   268,   274,
     275,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   290,   290,   311,   315,   321,   326,   329,   332,   335,
     338,   341,   346,   351,   357,   362
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "STAR", "DIV",
  "AMPERSAND", "LE", "LT", "GT", "GE", "EQ", "NE", "AND", "OR", "NOT",
  "ASSIGN", "IF", "ELSE", "WHILE", "REPEAT", "UNTIL", "DO", "BREAK",
  "CONTINUE", "ENDIF", "ENDWHILE", "DECL", "ENDDECL", "BEG", "END", "INT",
  "STR", "SEMICOLON", "THEN", "READ", "WRITE", "EXIT_PR", "MAIN", "RETURN",
  "TUPLE", "DOT", "NUM", "STR_LITERAL", "ID", "'('", "')'", "'{'", "'}'",
  "','", "'['", "']'", "$accept", "program", "MainBlock", "$@1",
  "GDeclBlock", "GDeclList", "GDecl", "GTupleDecl", "$@2", "GTupleIdList",
  "GTupleId", "FieldDefList", "FieldDef", "GidList", "Gid", "FDefBlock",
  "Body", "ParamList", "Param", "Ret", "LdeclBlock", "LDeclList", "LDecl",
  "LTupleDecl", "$@3", "LTupleIdList", "LTupleId", "IdList", "GType",
  "ParType", "LType", "EXPR", "ArgList", "stmtList", "stmt", "Fdef", "$@4",
  "ifStmt", "whileStmt", "doWhileStmt", "repeatStmt", "ipStmt", "opStmt",
  "assignStmt", "IDENTIFIERS", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,    40,    41,   123,   125,
      44,    91,    93
};
# endif

#define YYPACT_NINF (-107)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      79,    41,   -26,    21,  -107,   106,  -107,  -107,  -107,    -8,
      89,  -107,    37,     2,    45,  -107,   -26,  -107,   106,    70,
    -107,    74,  -107,  -107,  -107,   116,   -10,   -17,  -107,   127,
    -107,  -107,   137,   186,  -107,   190,   168,  -107,     2,   172,
     190,   -36,  -107,   170,  -107,  -107,    -7,  -107,     3,   175,
    -107,  -107,    69,  -107,   186,  -107,  -107,   190,   187,  -107,
    -107,   203,   185,     5,  -107,  -107,  -107,   100,   204,  -107,
     191,  -107,   196,  -107,  -107,  -107,  -107,   202,   184,  -107,
     201,   208,   247,   209,   203,  -107,     5,   213,  -107,  -107,
    -107,  -107,   -16,   215,   216,   217,   220,   342,   342,   228,
     235,   227,   229,   240,   205,   225,   246,   247,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,   -12,  -107,   204,  -107,
     186,  -107,   234,  -107,  -107,   205,   205,   273,   365,  -107,
    -107,    -1,   205,  -107,   205,  -107,  -107,    26,   205,   403,
     239,   205,   248,   255,  -107,   205,   243,   241,    84,  -107,
      90,   141,   253,   254,    50,   154,   443,    22,   167,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,  -107,    75,  -107,   268,   416,  -107,  -107,  -107,   269,
     266,   205,   205,   271,   272,  -107,   430,    93,  -107,   224,
     224,  -107,  -107,   454,   454,   454,   454,   454,   454,   443,
     443,  -107,  -107,  -107,     7,   342,   342,   181,   194,  -107,
    -107,  -107,   205,   262,  -107,   258,  -107,   219,   296,   278,
       8,   430,  -107,     7,   342,   279,   281,  -107,  -107,  -107,
     319,  -107,  -107,   288,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     8,    52,    53,     0,
       0,    10,     0,     0,     0,     1,    52,     3,     0,     0,
      29,     0,     7,     9,    12,     0,    24,     0,    23,     0,
       2,    28,     0,     0,    27,    34,     0,    11,     0,     0,
      34,     0,    20,     0,    54,    55,     0,    33,     0,     0,
      22,     5,     0,    13,     0,    21,    26,     0,     0,    35,
      25,     0,     0,     0,    19,    32,    36,     0,     0,    91,
       0,    17,    14,    16,    39,    56,    57,     0,     0,    41,
       0,     0,     0,     0,     0,    18,     0,     0,    38,    40,
      43,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,     0,     0,    80,    84,
      85,    86,    87,    81,    82,    83,     0,     6,     0,    15,
       0,    42,     0,   103,   104,     0,     0,     0,     0,    88,
      89,     0,     0,    90,     0,    72,    73,   101,     0,     0,
      74,     0,     0,     0,    79,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    31,     0,     0,   105,    92,    44,     0,
       0,     0,     0,     0,     0,    75,    78,     0,    71,    59,
      58,    60,    61,    65,    66,    67,    68,    69,    70,    62,
      63,   102,    30,   100,     0,     0,     0,     0,     0,    98,
      99,    76,     0,     0,    48,    45,    47,     0,     0,     0,
       0,    77,    49,     0,     0,     0,     0,    97,    96,    46,
       0,    94,    95,     0,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,     4,  -107,  -107,  -107,   315,  -107,  -107,  -107,
     242,   207,   275,  -107,   292,  -107,   218,   291,   289,   231,
     251,  -107,   270,  -107,  -107,  -107,   128,  -107,   107,  -107,
    -107,  -106,  -107,   -96,  -104,   332,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    61,     5,    10,    11,    12,    63,    72,
      73,    41,    42,    27,    28,    18,    83,    46,    47,   106,
      68,    78,    79,    80,   204,   215,   216,    92,    43,    48,
      81,   139,   187,   107,   108,    20,    84,   109,   110,   111,
     112,   113,   114,   115,   140
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     116,   127,   128,   144,    93,   145,    94,    25,    58,    17,
      70,    53,   213,    14,    54,   116,   116,    37,   121,   150,
     151,    15,    30,   144,   144,   116,   155,    93,   156,    94,
     146,   206,   158,    38,   122,   172,    35,    21,   134,   175,
      56,    36,   228,    57,   105,   116,   116,    26,    59,   154,
      71,   186,   214,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   135,   136,   137,   138,   185,
       6,    24,   157,     7,     8,   207,   208,   141,   159,   160,
     161,   162,     9,   163,   164,   165,   166,   167,   168,   169,
     170,    29,   146,   159,   160,   161,   162,   183,   163,   164,
     165,   166,   167,   168,   169,   170,   221,     1,    13,   217,
     218,     2,    19,   144,   144,    32,    62,    13,    22,    57,
      33,     7,     8,   116,   116,    19,   144,   201,   230,    74,
       9,   178,    75,    76,    54,   116,   116,   179,    16,     8,
     211,    77,   116,   212,   159,   160,   161,   162,   116,   163,
     164,   165,   166,   167,   168,   169,   170,   159,   160,   161,
     162,    34,   163,   164,   165,   166,   167,   168,   169,   170,
     159,   160,   161,   162,    39,   163,   164,   165,   166,   167,
     168,   169,   170,    40,   159,   160,   161,   162,   180,   163,
     164,   165,   166,   167,   168,   169,   170,   159,   160,   161,
     162,   184,   163,   164,   165,   166,   167,   168,   169,   170,
      93,    49,    94,    88,   188,    55,    75,    76,     7,     8,
      51,   134,    44,    45,    93,    77,    94,    60,   219,   161,
     162,    67,    66,    69,    82,    90,    85,    95,   224,    96,
      97,   220,    98,    99,   100,   225,    86,    87,   135,   136,
     137,   138,    93,    91,    94,   101,   102,   103,   117,   120,
     123,   124,   129,   125,   105,    95,   126,    96,    97,   130,
      98,    99,   100,   131,   133,   132,   141,   142,    93,   149,
      94,   146,   173,   101,   102,   103,   174,   104,   176,   206,
     177,    95,   105,    96,    97,   152,    98,    99,   100,   181,
     182,    93,   202,    94,   205,   209,   210,   222,   223,   101,
     102,   103,   227,   231,    95,   232,    96,    97,   105,    98,
      99,   100,   234,   226,    93,    23,    94,   148,   119,    64,
      50,    52,   101,   102,   103,   118,   147,    95,   143,    96,
      97,   105,    98,    99,   100,   233,    65,    93,    89,    94,
      31,   229,     0,     0,     0,   101,   102,   103,     0,     0,
      95,     0,    96,    97,   105,    98,    99,   100,     0,     0,
      93,     0,    94,     0,     0,     0,     0,     0,   101,   102,
     103,     0,     0,    95,     0,   153,    97,   105,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,     0,   159,   160,   161,   162,
     105,   163,   164,   165,   166,   167,   168,   169,   170,   159,
     160,   161,   162,     0,   163,   164,   165,   166,   167,   168,
     169,   170,     0,   159,   160,   161,   162,   171,   163,   164,
     165,   166,   167,   168,   169,   170,   159,   160,   161,   162,
     203,   163,   164,   165,   166,   167,   168,   159,   160,   161,
     162,     0,    -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      82,    97,    98,   107,     5,    17,     7,     5,     5,     5,
       5,    47,     5,    39,    50,    97,    98,    34,    34,   125,
     126,     0,    18,   127,   128,   107,   132,     5,   134,     7,
      42,    23,   138,    50,    50,   141,    46,    45,    16,   145,
      47,    51,    34,    50,    45,   127,   128,    45,    45,   131,
      45,   157,    45,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,    43,    44,    45,    46,    47,
      29,    34,    46,    32,    33,   181,   182,    51,     3,     4,
       5,     6,    41,     8,     9,    10,    11,    12,    13,    14,
      15,    46,    42,     3,     4,     5,     6,    47,     8,     9,
      10,    11,    12,    13,    14,    15,   212,    28,     1,   205,
     206,    32,     5,   217,   218,    45,    47,    10,    29,    50,
      46,    32,    33,   205,   206,    18,   230,    52,   224,    29,
      41,    47,    32,    33,    50,   217,   218,    47,    32,    33,
      47,    41,   224,    50,     3,     4,     5,     6,   230,     8,
       9,    10,    11,    12,    13,    14,    15,     3,     4,     5,
       6,    45,     8,     9,    10,    11,    12,    13,    14,    15,
       3,     4,     5,     6,    47,     8,     9,    10,    11,    12,
      13,    14,    15,    46,     3,     4,     5,     6,    47,     8,
       9,    10,    11,    12,    13,    14,    15,     3,     4,     5,
       6,    47,     8,     9,    10,    11,    12,    13,    14,    15,
       5,    43,     7,    29,    47,    45,    32,    33,    32,    33,
      48,    16,    32,    33,     5,    41,     7,    52,    47,     5,
       6,    28,    45,    48,    30,    34,    45,    18,    19,    20,
      21,    47,    23,    24,    25,    26,    50,    45,    43,    44,
      45,    46,     5,    45,     7,    36,    37,    38,    49,    46,
      45,    45,    34,    46,    45,    18,    46,    20,    21,    34,
      23,    24,    25,    46,    34,    46,    51,    31,     5,    45,
       7,    42,    34,    36,    37,    38,    31,    40,    45,    23,
      49,    18,    45,    20,    21,    22,    23,    24,    25,    46,
      46,     5,    34,     7,    35,    34,    34,    45,    50,    36,
      37,    38,    34,    34,    18,    34,    20,    21,    45,    23,
      24,    25,    34,    27,     5,    10,     7,   120,    86,    54,
      38,    40,    36,    37,    38,    84,   118,    18,   107,    20,
      21,    45,    23,    24,    25,    26,    57,     5,    78,     7,
      18,   223,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,
      18,    -1,    20,    21,    45,    23,    24,    25,    -1,    -1,
       5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    -1,    18,    -1,    20,    21,    45,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    -1,     3,     4,     5,     6,
      45,     8,     9,    10,    11,    12,    13,    14,    15,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,     3,     4,     5,     6,    34,     8,     9,
      10,    11,    12,    13,    14,    15,     3,     4,     5,     6,
      34,     8,     9,    10,    11,    12,    13,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    12,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    32,    54,    55,    57,    29,    32,    33,    41,
      58,    59,    60,    81,    39,     0,    32,    55,    68,    81,
      88,    45,    29,    59,    34,     5,    45,    66,    67,    46,
      55,    88,    45,    46,    45,    46,    51,    34,    50,    47,
      46,    64,    65,    81,    32,    33,    70,    71,    82,    43,
      67,    48,    70,    47,    50,    45,    47,    50,     5,    45,
      52,    56,    47,    61,    65,    71,    45,    28,    73,    48,
       5,    45,    62,    63,    29,    32,    33,    41,    74,    75,
      76,    83,    30,    69,    89,    45,    50,    45,    29,    75,
      34,    45,    80,     5,     7,    18,    20,    21,    23,    24,
      25,    36,    37,    38,    40,    45,    72,    86,    87,    90,
      91,    92,    93,    94,    95,    96,    97,    49,    73,    63,
      46,    34,    50,    45,    45,    46,    46,    86,    86,    34,
      34,    46,    46,    34,    16,    43,    44,    45,    46,    84,
      97,    51,    31,    72,    87,    17,    42,    69,    64,    45,
      84,    84,    22,    20,    97,    84,    84,    46,    84,     3,
       4,     5,     6,     8,     9,    10,    11,    12,    13,    14,
      15,    34,    84,    34,    31,    84,    45,    49,    47,    47,
      47,    46,    46,    47,    47,    47,    84,    85,    47,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    52,    34,    34,    77,    35,    23,    84,    84,    34,
      34,    47,    50,     5,    45,    78,    79,    86,    86,    47,
      47,    84,    45,    50,    19,    26,    27,    34,    34,    79,
      86,    34,    34,    26,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    56,    55,    57,    57,    58,
      58,    59,    59,    61,    60,    62,    62,    63,    63,    64,
      64,    65,    66,    66,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    71,    71,    72,    73,    73,
      74,    74,    75,    75,    77,    76,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    86,
      86,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    89,    88,    90,    90,    91,    92,    93,    94,    95,
      96,    97,    97,    97,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     0,     9,     3,     2,     2,
       1,     3,     2,     0,     7,     3,     1,     1,     2,     3,
       1,     2,     3,     1,     1,     4,     4,     2,     2,     1,
       5,     4,     3,     1,     0,     2,     3,     3,     3,     2,
       2,     1,     3,     2,     0,     7,     3,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     4,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     0,    10,    10,     8,     8,     7,     7,     5,     5,
       4,     1,     4,     2,     2,     3
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
#line 66 "parser.y"
                                                {}
#line 1633 "y.tab.c"
    break;

  case 3:
#line 67 "parser.y"
                                                {}
#line 1639 "y.tab.c"
    break;

  case 4:
#line 68 "parser.y"
                                                {}
#line 1645 "y.tab.c"
    break;

  case 5:
#line 71 "parser.y"
                                                {   
                                                    Ghead = insertTable(Ghead,"F0",T_INT,0,0); 
                                                    currentFunc = find(Ghead, "F0");
                                                    if(currentFunc == NULL) {
                                                        printf("Error: Function '%s' not found in symbol table\n", "main");
                                                        exit(1);
                                                    }
                                                }
#line 1658 "y.tab.c"
    break;

  case 6:
#line 79 "parser.y"
                                                {

                                                    currentFunc->bodyAST = (yyvsp[-1].node) ;
                                                    currentFunc->Lentry = Lhead ;
                                                    
                                                    funcCodeGen(currentFunc,output); 
                                                    currentFunc = NULL ;
                                                    Lhead = NULL ;
                                                    
                                                }
#line 1673 "y.tab.c"
    break;

  case 7:
#line 91 "parser.y"
                                            {}
#line 1679 "y.tab.c"
    break;

  case 8:
#line 92 "parser.y"
                                            {}
#line 1685 "y.tab.c"
    break;

  case 9:
#line 95 "parser.y"
                                            {}
#line 1691 "y.tab.c"
    break;

  case 10:
#line 96 "parser.y"
                                            {}
#line 1697 "y.tab.c"
    break;

  case 11:
#line 99 "parser.y"
                                            {}
#line 1703 "y.tab.c"
    break;

  case 12:
#line 100 "parser.y"
                                            {}
#line 1709 "y.tab.c"
    break;

  case 13:
#line 103 "parser.y"
                                                {
                                                    int size = 0;
                                                    struct Fieldlist * temp = (yyvsp[-1].flist) ;
                                                    while(temp) {
                                                        size += GetSize(temp->type);
                                                        temp = temp->next ;
                                                    }
                                                    TTableHead = TInstall(TTableHead,(yyvsp[-3].node)->varname,size,(yyvsp[-1].flist));
                                                    currTupleType = TLookup(TTableHead, (yyvsp[-3].node)->varname);

                                                    if(currTupleType == NULL) {
                                                        printf("Tuple Type installation failed\n");
                                                        exit(1);
                                                    }
                                                }
#line 1729 "y.tab.c"
    break;

  case 14:
#line 118 "parser.y"
                                                {   currTupleType = NULL ;}
#line 1735 "y.tab.c"
    break;

  case 15:
#line 121 "parser.y"
                                               {}
#line 1741 "y.tab.c"
    break;

  case 16:
#line 122 "parser.y"
                                               {}
#line 1747 "y.tab.c"
    break;

  case 17:
#line 125 "parser.y"
                                            {    Ghead = insertTable(Ghead, ((yyvsp[0].node))->varname, currTupleType, currTupleType->size, -1);}
#line 1753 "y.tab.c"
    break;

  case 18:
#line 126 "parser.y"
                                            {    /*Ghead = insertTable(Ghead, ($2)->varname, currTupleType, currTupleType->size, -1);*/}
#line 1759 "y.tab.c"
    break;

  case 19:
#line 129 "parser.y"
                                            {   
                                                struct Fieldlist * temp = (yyvsp[-2].flist) ;
                                                while(temp->next) {
                                                    temp = temp->next ;
                                                }
                                                (yyvsp[0].flist)->fieldIndex = temp->fieldIndex + 1;
                                                temp->next = (yyvsp[0].flist) ;
                                                (yyval.flist) = (yyvsp[-2].flist) ;
                                            }
#line 1773 "y.tab.c"
    break;

  case 20:
#line 138 "parser.y"
                                            {   
                                                (yyvsp[0].flist)->fieldIndex = 0; 
                                                (yyval.flist) = (yyvsp[0].flist) ;
                                            }
#line 1782 "y.tab.c"
    break;

  case 21:
#line 144 "parser.y"
                                            {   (yyval.flist) = createFieldlistNode(((yyvsp[0].node))->varname,currentType,0); }
#line 1788 "y.tab.c"
    break;

  case 22:
#line 147 "parser.y"
                                            {}
#line 1794 "y.tab.c"
    break;

  case 23:
#line 148 "parser.y"
                                            {}
#line 1800 "y.tab.c"
    break;

  case 24:
#line 151 "parser.y"
                                            {   Ghead = insertTable(Ghead,((yyvsp[0].node))->varname,currentType,1,-1); }
#line 1806 "y.tab.c"
    break;

  case 25:
#line 152 "parser.y"
                                            {   Ghead = insertTable(Ghead,((yyvsp[-3].node))->varname,currentType,(yyvsp[-1].number),-1);}
#line 1812 "y.tab.c"
    break;

  case 26:
#line 153 "parser.y"
                                            {   
                                                Ghead = insertTable(Ghead,((yyvsp[-3].node))->varname,currentType,0,flabel++);
                                                insertParamListToGST(Ghead,((yyvsp[-3].node))->varname,(yyvsp[-1].paramList));
                                            }
#line 1821 "y.tab.c"
    break;

  case 27:
#line 157 "parser.y"
                                            {   Ghead = insertTable(Ghead,((yyvsp[0].node))->varname,currentType == T_INT ? T_INT_PTR : T_STR_PTR,1,-1); }
#line 1827 "y.tab.c"
    break;

  case 28:
#line 160 "parser.y"
                                            {}
#line 1833 "y.tab.c"
    break;

  case 29:
#line 161 "parser.y"
                                            {}
#line 1839 "y.tab.c"
    break;

  case 30:
#line 164 "parser.y"
                                                {  
                                                    (yyval.node) = connectNode((yyvsp[-3].node),(yyvsp[-2].node)); 
                                                    //inorder($$);
                                                }
#line 1848 "y.tab.c"
    break;

  case 31:
#line 168 "parser.y"
                                                { 
                                                    (yyval.node) = (yyvsp[-2].node) ;
                                                }
#line 1856 "y.tab.c"
    break;

  case 32:
#line 173 "parser.y"
                                            {   (yyval.paramList) = insertToParamList((yyvsp[-2].paramList),((yyvsp[0].paramList))->name,((yyvsp[0].paramList))->type) ; }
#line 1862 "y.tab.c"
    break;

  case 33:
#line 174 "parser.y"
                                            {   (yyval.paramList) = insertToParamList(NULL,((yyvsp[0].paramList))->name,((yyvsp[0].paramList))->type) ;}
#line 1868 "y.tab.c"
    break;

  case 34:
#line 175 "parser.y"
                                            {   (yyval.paramList) = NULL ;}
#line 1874 "y.tab.c"
    break;

  case 35:
#line 178 "parser.y"
                                            {   (yyval.paramList) = createParamStructNode(strdup((yyvsp[0].node)->varname),paramType); }
#line 1880 "y.tab.c"
    break;

  case 36:
#line 179 "parser.y"
                                            {   (yyval.paramList) = createParamStructNode(strdup((yyvsp[0].node)->varname),paramType == T_INT ? T_INT_PTR : T_STR_PTR); }
#line 1886 "y.tab.c"
    break;

  case 37:
#line 182 "parser.y"
                                            {   
                                                (yyval.node) = returnNode(currentFunc,RETURN_NODE,(yyvsp[-1].node)); 
                                                //printf("%s\n",$$->left->varname);
                                            }
#line 1895 "y.tab.c"
    break;

  case 38:
#line 187 "parser.y"
                                            {   localBinding = 1; }
#line 1901 "y.tab.c"
    break;

  case 39:
#line 188 "parser.y"
                                            {}
#line 1907 "y.tab.c"
    break;

  case 40:
#line 191 "parser.y"
                                            {}
#line 1913 "y.tab.c"
    break;

  case 41:
#line 192 "parser.y"
                                            {}
#line 1919 "y.tab.c"
    break;

  case 42:
#line 195 "parser.y"
                                            {}
#line 1925 "y.tab.c"
    break;

  case 43:
#line 196 "parser.y"
                                            {}
#line 1931 "y.tab.c"
    break;

  case 44:
#line 199 "parser.y"
                                                {
                                                    int size = 0;
                                                    struct Fieldlist *temp = (yyvsp[-1].flist);
                                                    while(temp) {
                                                        size += GetSize(temp->type);
                                                        temp = temp->next;
                                                    }
                                                    TTableHead = TInstall(TTableHead, (yyvsp[-3].node)->varname, size, (yyvsp[-1].flist));
                                                    currTupleType = TLookup(TTableHead, (yyvsp[-3].node)->varname);
                                                    if (currTupleType == NULL) {
                                                        yyerror("Tuple type installation failed");
                                                        exit(1);
                                                    }
                                                }
#line 1950 "y.tab.c"
    break;

  case 45:
#line 213 "parser.y"
                                                {   currTupleType = NULL ;}
#line 1956 "y.tab.c"
    break;

  case 46:
#line 216 "parser.y"
                                                {}
#line 1962 "y.tab.c"
    break;

  case 47:
#line 217 "parser.y"
                                                {}
#line 1968 "y.tab.c"
    break;

  case 48:
#line 220 "parser.y"
                                            {    Lhead = insertToLocalTable(Lhead, ((yyvsp[0].node))->varname, currTupleType);}
#line 1974 "y.tab.c"
    break;

  case 49:
#line 221 "parser.y"
                                            {   }
#line 1980 "y.tab.c"
    break;

  case 50:
#line 225 "parser.y"
                                            {   Lhead = insertToLocalTable(Lhead,((yyvsp[0].node))->varname,currLocalType);}
#line 1986 "y.tab.c"
    break;

  case 51:
#line 226 "parser.y"
                                            {   Lhead = insertToLocalTable(Lhead,((yyvsp[0].node))->varname,currLocalType);}
#line 1992 "y.tab.c"
    break;

  case 52:
#line 229 "parser.y"
                                            {   currentType = T_INT ;}
#line 1998 "y.tab.c"
    break;

  case 53:
#line 230 "parser.y"
                                            {   currentType = T_STR ;}
#line 2004 "y.tab.c"
    break;

  case 54:
#line 233 "parser.y"
                                            {   paramType = T_INT ;}
#line 2010 "y.tab.c"
    break;

  case 55:
#line 234 "parser.y"
                                            {   paramType = T_STR ;}
#line 2016 "y.tab.c"
    break;

  case 56:
#line 237 "parser.y"
                                            {   currLocalType = T_INT ;}
#line 2022 "y.tab.c"
    break;

  case 57:
#line 238 "parser.y"
                                            {   currLocalType = T_STR ;}
#line 2028 "y.tab.c"
    break;

  case 58:
#line 242 "parser.y"
                                            {   (yyval.node) = exprNode(MINUS_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2034 "y.tab.c"
    break;

  case 59:
#line 243 "parser.y"
                                            {   (yyval.node) = exprNode(ADD_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2040 "y.tab.c"
    break;

  case 60:
#line 244 "parser.y"
                                            {   (yyval.node) = exprNode(MUL_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2046 "y.tab.c"
    break;

  case 61:
#line 245 "parser.y"
                                            {   (yyval.node) = exprNode(DIV_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2052 "y.tab.c"
    break;

  case 62:
#line 246 "parser.y"
                                            {   (yyval.node) = exprNode(AND_NODE,(yyvsp[-2].node), (yyvsp[0].node)); }
#line 2058 "y.tab.c"
    break;

  case 63:
#line 247 "parser.y"
                                            {   (yyval.node) = exprNode(OR_NODE,(yyvsp[-2].node), (yyvsp[0].node)); }
#line 2064 "y.tab.c"
    break;

  case 64:
#line 248 "parser.y"
                                            {   (yyval.node) = exprNode(NOT_NODE,(yyvsp[0].node), NULL);}
#line 2070 "y.tab.c"
    break;

  case 65:
#line 249 "parser.y"
                                            {   (yyval.node) = exprNode(LE_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2076 "y.tab.c"
    break;

  case 66:
#line 250 "parser.y"
                                            {   (yyval.node) = exprNode(LT_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2082 "y.tab.c"
    break;

  case 67:
#line 251 "parser.y"
                                            {   (yyval.node) = exprNode(GT_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2088 "y.tab.c"
    break;

  case 68:
#line 252 "parser.y"
                                            {   (yyval.node) = exprNode(GE_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2094 "y.tab.c"
    break;

  case 69:
#line 253 "parser.y"
                                            {   (yyval.node) = exprNode(EQ_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2100 "y.tab.c"
    break;

  case 70:
#line 254 "parser.y"
                                            {   (yyval.node) = exprNode(NE_NODE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2106 "y.tab.c"
    break;

  case 71:
#line 255 "parser.y"
                                            {   (yyval.node) = (yyvsp[-1].node) ;}
#line 2112 "y.tab.c"
    break;

  case 72:
#line 256 "parser.y"
                                            {   (yyval.node) = createTreeNode((yyvsp[0].number),T_INT,NULL,NUM_NODE,NULL,NULL,NULL,NULL); }
#line 2118 "y.tab.c"
    break;

  case 73:
#line 257 "parser.y"
                                            {   (yyval.node) = createTreeNode(NO_VAL,T_STR,(yyvsp[0].string),STR_NODE,NULL,NULL,NULL,NULL); }
#line 2124 "y.tab.c"
    break;

  case 74:
#line 258 "parser.y"
                                            {   (yyval.node) = (yyvsp[0].node) ; }
#line 2130 "y.tab.c"
    break;

  case 75:
#line 259 "parser.y"
                                            {   
                                                (yyval.node) = funcNode(Ghead,(yyvsp[-2].node),NULL);
                                            }
#line 2138 "y.tab.c"
    break;

  case 76:
#line 262 "parser.y"
                                            {   (yyval.node) = funcNode(Ghead,(yyvsp[-3].node),(yyvsp[-1].node));}
#line 2144 "y.tab.c"
    break;

  case 77:
#line 265 "parser.y"
                                            {
                                                (yyval.node) = appendArg((yyvsp[-2].node),(yyvsp[0].node));
                                            }
#line 2152 "y.tab.c"
    break;

  case 78:
#line 268 "parser.y"
                                            {   
                                                (yyval.node) = (yyvsp[0].node);
                                                (yyval.node)->argList = NULL ;
                                            }
#line 2161 "y.tab.c"
    break;

  case 79:
#line 274 "parser.y"
                                                {   (yyval.node) = connectNode((yyvsp[-1].node),(yyvsp[0].node)); }
#line 2167 "y.tab.c"
    break;

  case 80:
#line 275 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 2173 "y.tab.c"
    break;

  case 81:
#line 278 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 2179 "y.tab.c"
    break;

  case 82:
#line 279 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 2185 "y.tab.c"
    break;

  case 83:
#line 280 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 2191 "y.tab.c"
    break;

  case 84:
#line 281 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 2197 "y.tab.c"
    break;

  case 85:
#line 282 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 2203 "y.tab.c"
    break;

  case 86:
#line 283 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 2209 "y.tab.c"
    break;

  case 87:
#line 284 "parser.y"
                                                {   (yyval.node) = (yyvsp[0].node) ; }
#line 2215 "y.tab.c"
    break;

  case 88:
#line 285 "parser.y"
                                                {   (yyval.node) = flowControlNode(BREAK_NODE); }
#line 2221 "y.tab.c"
    break;

  case 89:
#line 286 "parser.y"
                                                {   (yyval.node) = flowControlNode(CONTINUE_NODE); }
#line 2227 "y.tab.c"
    break;

  case 90:
#line 287 "parser.y"
                                                {   (yyval.node) = exitNode(EXIT_NODE); }
#line 2233 "y.tab.c"
    break;

  case 91:
#line 290 "parser.y"
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
#line 2248 "y.tab.c"
    break;

  case 92:
#line 300 "parser.y"
                                                {
                                                    currentFunc->bodyAST = (yyvsp[-1].node) ;
                                                    currentFunc->Lentry = Lhead ;
                                                    //printLocalSymbolTable(Lhead);
                                                    
                                                    funcCodeGen(currentFunc,output);                                       
                                                    currentFunc = NULL ;
                                                    Lhead = NULL ;
                                                }
#line 2262 "y.tab.c"
    break;

  case 93:
#line 311 "parser.y"
                                                                                {   
                                                                                    
                                                                                    (yyval.node) = ifelseNode(IF_NODE,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));
                                                                                }
#line 2271 "y.tab.c"
    break;

  case 94:
#line 315 "parser.y"
                                                                                {
                                                                                    
                                                                                    (yyval.node) = ifelseNode(IF_NODE,(yyvsp[-5].node),(yyvsp[-2].node),NULL);
                                                                                }
#line 2280 "y.tab.c"
    break;

  case 95:
#line 321 "parser.y"
                                                                                {
                                                                                    (yyval.node) = loopNode(WHILE_NODE,(yyvsp[-5].node),(yyvsp[-2].node));
                                                                                }
#line 2288 "y.tab.c"
    break;

  case 96:
#line 326 "parser.y"
                                                                                {   (yyval.node) = loopNode(DOWHILE_NODE,(yyvsp[-2].node),(yyvsp[-5].node)); }
#line 2294 "y.tab.c"
    break;

  case 97:
#line 329 "parser.y"
                                                                                {   (yyval.node) = loopNode(REPEAT_NODE,(yyvsp[-2].node),(yyvsp[-5].node)); }
#line 2300 "y.tab.c"
    break;

  case 98:
#line 332 "parser.y"
                                                                                {   (yyval.node) = ipOpNode(READ_NODE,(yyvsp[-2].node)); }
#line 2306 "y.tab.c"
    break;

  case 99:
#line 335 "parser.y"
                                                                                {   (yyval.node) = ipOpNode(WRITE_NODE,(yyvsp[-2].node)); }
#line 2312 "y.tab.c"
    break;

  case 100:
#line 338 "parser.y"
                                                                                {   (yyval.node) = assignNode((yyvsp[-3].node),(yyvsp[-1].node)); }
#line 2318 "y.tab.c"
    break;

  case 101:
#line 341 "parser.y"
                                                                                {   
                                                                                    struct tnode * node = setTypeId(Ghead,Lhead,(yyvsp[0].node),NULL,NULL);
                                                                                    node->nodetype = ID_NODE ;
                                                                                    (yyval.node) = node;
                                                                                }
#line 2328 "y.tab.c"
    break;

  case 102:
#line 346 "parser.y"
                                                                                {   
                                                                                    struct tnode * node = setTypeId(Ghead,Lhead,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
                                                                                    node->nodetype = ARR_NODE ;
                                                                                    (yyval.node) = node;
                                                                                }
#line 2338 "y.tab.c"
    break;

  case 103:
#line 351 "parser.y"
                                                                                {
                                                                                    struct tnode * node = setTypeId(Ghead,Lhead,(yyvsp[0].node),NULL,NULL);
                                                                                    printf("%s\n",node->varname);
                                                                                    node->nodetype = ID_NODE;                              
                                                                                    (yyval.node) = pointerNode(Ghead,DEREF_NODE,node,NULL,NULL);
                                                                                }
#line 2349 "y.tab.c"
    break;

  case 104:
#line 357 "parser.y"
                                                                                {
                                                                                    struct tnode * node = setTypeId(Ghead,Lhead,(yyvsp[0].node),NULL,NULL);
                                                                                    node->nodetype = ID_NODE ;
                                                                                    (yyval.node) = pointerNode(Ghead,ADDR_NODE,node,NULL,NULL);
                                                                                }
#line 2359 "y.tab.c"
    break;

  case 105:
#line 362 "parser.y"
                                                                                {
                                                                                    if ((yyvsp[-2].node)->type->fields == NULL) {
                                                                                        yyerror("Field access ('.') on a non-tuple type");
                                                                                        exit(1);
                                                                                    }
                                                                                    struct Fieldlist *field = FLookup((yyvsp[-2].node)->type, (yyvsp[0].node)->varname);

                                                                                    if (field == NULL) {
                                                                                        printf("Field '%s' not found in tuple type '%s'", (yyvsp[0].node)->varname, (yyvsp[-2].node)->type->name);                                                                                   
                                                                                        exit(1);
                                                                                    }
                                                                                    (yyval.node) = createTreeNode(field->fieldIndex, field->type, field->name, FIELD_NODE, NULL, (yyvsp[-2].node), NULL, NULL);
                                                                                }
#line 2377 "y.tab.c"
    break;


#line 2381 "y.tab.c"

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
#line 377 "parser.y"


int yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineNum);
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

    TTableHead = createTypeTable(); // TInstall default types -> int, str, void, bool

    auxFunctions(output,ENTRY_CODE,-1,-1);
    fprintf(output,"CALL F0\n");
    yyparse();
    auxFunctions(output,EXIT_CODE,-1,-1);

    fclose(output);
    return 0;
}
