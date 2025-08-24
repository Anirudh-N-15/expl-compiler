%{
    #include "y.tab.h"
%}

letter      [a-zA-Z]
digit       [0-9]

%%

{letter}({letter}|{digit})*        { return ID ;} 
{digit}+({letter}|{digit})*        { return INVALID; }
.|\n                               { return INVALID; }

%%

int yywrap() {
    return 1;
}