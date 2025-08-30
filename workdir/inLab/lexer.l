%{
    #include "y.tab.h"
%}

digit   [0-9]
%%


{digit}*    { return NUM ;}
[a-zA-Z]    { return ID ;}
"+="        { return ADDASSIGN;}
"+"         { return *yytext ;}
"="         { return *yytext ;}
"\n"        { return *yytext ;}
[ \t]       { }
.           { }
%%

int yywrap() {
    return 1;
}