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
    NUM = 288,
    STR_LITERAL = 289,
    ID = 290,
    ASSIGN = 291,
    MOD = 292
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
#define NUM 288
#define STR_LITERAL 289
#define ID 290
#define ASSIGN 291
#define MOD 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "exptree.y"

    struct tnode * node;
    int number ;
    char * string ;

#line 137 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
