%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    void yyerror(const char *s);

%}

%token ID INVALID

%%

program : ID    { printf("Valid Variable\n"); }
        | INVALID { printf("Invalid Variable\n"); }
        ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    return ;
}

