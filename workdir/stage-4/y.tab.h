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
    AMPERSAND = 268,
    IF = 269,
    ELSE = 270,
    WHILE = 271,
    REPEAT = 272,
    UNTIL = 273,
    DO = 274,
    BREAK = 275,
    CONTINUE = 276,
    ENDIF = 277,
    ENDWHILE = 278,
    DECL = 279,
    ENDDECL = 280,
    BEG = 281,
    END = 282,
    INT = 283,
    STR = 284,
    SEMICOLON = 285,
    THEN = 286,
    READ = 287,
    WRITE = 288,
    EXIT_PR = 289,
    NUM = 290,
    STR_LITERAL = 291,
    ID = 292,
    MOD = 293,
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
#define AMPERSAND 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define REPEAT 272
#define UNTIL 273
#define DO 274
#define BREAK 275
#define CONTINUE 276
#define ENDIF 277
#define ENDWHILE 278
#define DECL 279
#define ENDDECL 280
#define BEG 281
#define END 282
#define INT 283
#define STR 284
#define SEMICOLON 285
#define THEN 286
#define READ 287
#define WRITE 288
#define EXIT_PR 289
#define NUM 290
#define STR_LITERAL 291
#define ID 292
#define MOD 293
#define ASSIGN 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "exptree.y"

    struct tnode * node;
    int number ;
    char * string ;

#line 141 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
