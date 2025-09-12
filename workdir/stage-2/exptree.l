%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "exptree.h"
    #include "execute.h"

    int number;
%}

numbers  [0-9]+
id      [a-z]

%%

{numbers}    {   
                int number = atoi(yytext); 
                yylval.node = createLeafNode(INT_TYPE, NULL, number);
                return NUM ;
            }
            
{id}        {
                yylval.node = createLeafNode(ID_TYPE, strdup(yytext), 0);
                return ID ;
            }
"begin"     return T_BEGIN ;
"end"       return T_END ;
"read"      return READ ; 
"write"     return WRITE ;
";"         return SEMICOLON ;
"="         return ASSIGN ;
"+"         return PLUS ;
"-"         return MINUS ;
"*"         return MUL ;
"/"         return DIV ;
[ \t]       {}
[()]        return *yytext ;
[\n]        {}
.           {}

%%

int yywrap() {
    return 1;
}