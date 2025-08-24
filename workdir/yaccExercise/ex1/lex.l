%{
    #include "y.tab.h"
%}

letter      [a-zA-Z]
digit       [0-9]

%%

"if"                            { return IF ;}
"else"                          { return ELSE ;}
"("                             { return LPAREN ;}
")"                             { return RPAREN ;}
"{"                             { return LBRACE ;}
"}"                             { return RBRACE ;}
{letter}|({letter}|{digit})*    { return ID ;} 
[\t\n]+                         { }
.                               { return OTHER ;}

%%

int yywrap() {
    return 1;
}