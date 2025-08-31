%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "exptree.h"
    void yyerror(const char *s);
%}

number [0-9]+

%%

{number}  {   
            int number = atoi(yytext); 
            yylval.node = createLeafNode(number);
            return NUM ;
        }
"+"         return PLUS ;
"-"         return MINUS ;
"*"         return MUL ;
"/"         return DIV ;
[ \t]       {}
[()]        return *yytext ;
[\n]        return *yytext ;
.           {}

%%

int yywrap() {
    return 1;
}