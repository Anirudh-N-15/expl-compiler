/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 156 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
