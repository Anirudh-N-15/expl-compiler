%{
  #include  "y.tab.h"
  #include "tree.h"
  void yyerror(char *);

%}

alpha [a-zA-Z]

%%

{alpha}+    {yylval.p = createTree(yytext, NULL, NULL); return ID ;}
"+"         {return PLUS ;}
"*"         {return MUL ;}
"/"         {return DIV ;}
[()]        {return *yytext ;}
[\t\n]      {}
.           {yyerror("invalid character") ;}

%%

int yywrap(void) {
  return 1;
}