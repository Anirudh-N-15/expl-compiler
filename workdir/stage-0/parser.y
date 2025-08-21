%{
    #include <stdio.h>
    #include<stdlib.h>
    int yylex(void);
    void yyerror(const char *s);
%}

%union {
    char c;
}

%token NEWLINE
%token DIGIT

%left '+' '-'
%left '*' '/'

%%

start   : expr NEWLINE  {
                        printf("\nComplete\n");
                        exit(1);
                      }
        ;

expr:  expr '+' expr        {printf("+ ");}
    |  expr '*' expr        {printf("* ");}
    | expr '-' expr         {printf("- ");}
    | '(' expr ')'          { }
    | DIGIT                 {printf("%c ",$<c>1);}
    ;

%%

void yyerror(char const *s) {
    printf("yyerror %s/n",s);
    return ;
}

int main() {
    yyparse();
    return 1;
}