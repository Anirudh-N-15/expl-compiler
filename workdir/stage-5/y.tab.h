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
    LE = 262,
    LT = 263,
    GT = 264,
    GE = 265,
    EQ = 266,
    NE = 267,
    AND = 268,
    ASSIGN = 269,
    IF = 270,
    ELSE = 271,
    WHILE = 272,
    REPEAT = 273,
    UNTIL = 274,
    DO = 275,
    BREAK = 276,
    CONTINUE = 277,
    ENDIF = 278,
    ENDWHILE = 279,
    DECL = 280,
    ENDDECL = 281,
    BEG = 282,
    END = 283,
    INT = 284,
    STR = 285,
    SEMICOLON = 286,
    THEN = 287,
    READ = 288,
    WRITE = 289,
    EXIT_PR = 290,
    MAIN = 291,
    RETURN = 292,
    NUM = 293,
    STR_LITERAL = 294,
    ID = 295
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
#define AND 268
#define ASSIGN 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define REPEAT 273
#define UNTIL 274
#define DO 275
#define BREAK 276
#define CONTINUE 277
#define ENDIF 278
#define ENDWHILE 279
#define DECL 280
#define ENDDECL 281
#define BEG 282
#define END 283
#define INT 284
#define STR 285
#define SEMICOLON 286
#define THEN 287
#define READ 288
#define WRITE 289
#define EXIT_PR 290
#define MAIN 291
#define RETURN 292
#define NUM 293
#define STR_LITERAL 294
#define ID 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

    struct ParamStruct * paramList ;
    struct tnode * node;
    int number ;
    char * string ;

#line 144 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
