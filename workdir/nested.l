//Auxillary Declarations followed by Regular definitions start here and

%{
#include <stdio.h>
#include <stdlib.h>

%}

digit [0-9]             
number {digit}+


//Regex Rules i.e pattern and action start here
%%
[a-zA-Z_][a-zA-Z0-9_]+          {return ID ;}       //({letter})({letter}|{digit})*
"if"                            {return IF ;}
"else"                          {return ELSE ;}
.                               {return yytext[0];}
({letter})({letter}|{digit})*   {return ID ;}
[\t\n]                          {/* Ignore whitespace*/}


%%





int yywrap() {
    return 1;
}

