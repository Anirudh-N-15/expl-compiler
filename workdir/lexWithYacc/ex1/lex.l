%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
%}

%%

[a-zA-Z]      {
                yylval.c = *yytext;
                return CHAR ;
            }
"+"             return *yytext ;
"*"             return *yytext ;
"-"             return *yytext;
"/"             return *yytext;
[()]            return *yytext;
[\n]            return NEWLINE;

%%

int yywrap() {
    return 1;
}
