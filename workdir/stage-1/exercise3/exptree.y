%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "exptree.h"

    int yylex(void);
    void yyerror(const char *s);

    FILE * output;
%}

%union {
    struct tnode * node ;
}

%type <node> expr start 
%token PLUS MINUS MUL DIV  
%token <node> NUM 

%left PLUS MINUS 
%left MUL DIV 

%%

start : expr '\n'   {
                        printf("Value : %d\n", evaluate($1));

                        prefix($1);
                        printf("\n");

                        postfix($1);
                        printf("\n");

                        execGen($1, output);
                        exit(0);
                    }
        ;

expr    : PLUS  expr expr   { $$ = createOperatorNode('+', $2, $3); } 
        | MUL expr expr     { $$ = createOperatorNode('*', $2, $3); }
        | DIV expr expr     { $$ = createOperatorNode('/', $2, $3); }       
        | '(' expr ')'      { $$ = $2 ;}
        | MINUS expr expr   { $$ = createOperatorNode('-', $2, $3); }
        | NUM               { $$ = $1 ;}
        ;

%%

extern FILE * yyin ;

void yyerror(const char *s) {
    printf("yyerror %s",s);
    return;
}

int main(int argc , char ** argv) {
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        if(!yyin) {
            printf("Error opening file");
        } else {
            yyin = stdin ;
        }
    }

    output = fopen("output.xsm", "w");
    yyparse();

    fclose(output);
    return 0;
}
