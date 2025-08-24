%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int yylex();
    void yyerror(const char *c);
%}

%union {
    char *c ;
};

%token <c> STR 
%type <c> expr
%left '+' '-'
%left '*' '/'

%%

start   : expr '\n' { printf("%s\n", $1); }
        ;

expr    : expr '+' expr { 
                            char buff[128];
                            sprintf(buff, "+ %s %s",$1, $3);
                            $$ = strdup(buff);
                        }

        | expr '-' expr { 
                            char buff[128];
                            sprintf(buff, "- %s %s",$1, $3);
                            $$ = strdup(buff);
                        }

        | expr '*' expr { 
                            char buff[128];
                            sprintf(buff, "* %s %s",$1, $3);
                            $$ = strdup(buff);
                        }

        | expr '/' expr { 
                            char buff[128];
                            sprintf(buff, "/ %s %s",$1, $3);
                            $$ = strdup(buff);
                        }

        | '(' expr ')'  { $$ = $2 ;}

        | STR           { $$ = $1 ;}
        ;
%%

void yyerror(const char *c) {
    printf("yyerror : %s\n",c);
    return ;
}

int main() {
    yyparse();
    return 0;
}

