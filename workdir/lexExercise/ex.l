%{
#include <stdio.h>
#include <stdlib.h>
%}

digit [0-9]             
number {digit}+
ID [a-zA-Z_][a-zA-Z0-9_]+   
ch [a-z]+

%%
[a-zA-Z_][a-zA-Z0-9_]+          {return ID ;}       
[0-9]+                          {return DIGIT ;}
{ch}+                           {return expr ;}

%%


int yywrap() {
    return 1;
}