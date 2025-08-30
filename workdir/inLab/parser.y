%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    void yyerror(const char *s);
%}

%token ID NUM ADDASSIGN;

%left '=' '+'

%%

start   : ID '=' E '\n'         { printf("Accept\n"); exit(1); }
        | ID ADDASSIGN E '\n'   { printf("Accept\n"); exit(1); }   
        ;

E       : E '+' E
        | ID
        | NUM
        ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Reject");
}
