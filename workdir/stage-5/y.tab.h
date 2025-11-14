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
    OR = 269,
    NOT = 270,
    ASSIGN = 271,
    IF = 272,
    ELSE = 273,
    WHILE = 274,
    REPEAT = 275,
    UNTIL = 276,
    DO = 277,
    BREAK = 278,
    CONTINUE = 279,
    ENDIF = 280,
    ENDWHILE = 281,
    DECL = 282,
    ENDDECL = 283,
    BEG = 284,
    END = 285,
    INT = 286,
    STR = 287,
    SEMICOLON = 288,
    THEN = 289,
    READ = 290,
    WRITE = 291,
    EXIT_PR = 292,
    MAIN = 293,
    RETURN = 294,
    NUM = 295,
    STR_LITERAL = 296,
    ID = 297
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
#define OR 269
#define NOT 270
#define ASSIGN 271
#define IF 272
#define ELSE 273
#define WHILE 274
#define REPEAT 275
#define UNTIL 276
#define DO 277
#define BREAK 278
#define CONTINUE 279
#define ENDIF 280
#define ENDWHILE 281
#define DECL 282
#define ENDDECL 283
#define BEG 284
#define END 285
#define INT 286
#define STR 287
#define SEMICOLON 288
#define THEN 289
#define READ 290
#define WRITE 291
#define EXIT_PR 292
#define MAIN 293
#define RETURN 294
#define NUM 295
#define STR_LITERAL 296
#define ID 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

    struct ParamStruct * paramList ;
    struct tnode * node;
    int number ;
    char * string ;

#line 148 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
