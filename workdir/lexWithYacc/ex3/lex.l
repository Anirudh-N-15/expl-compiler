%{
    #include "y.tab.h"
%}

%%

[a-zA-Z]+       {   yylval.c = strdup(yytext) ;
                    return STR ;
                }
"+"             return *yytext ;
"*"             return *yytext ;
"-"             return *yytext ;
"/"             return *yytext ;
[()]            return *yytext ;
[\n\t]          return *yytext ;
.               {}
%%

int yywrap() {
    return 1;
}