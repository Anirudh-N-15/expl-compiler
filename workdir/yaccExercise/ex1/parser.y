%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    int yyerror(const char *s);
    int max_depth = 0;
    int curr_depth = 0;
%}

%token ID IF ELSE LPAREN RPAREN LBRACE RBRACE OTHER

%right ELSE

%%

program : statement_list { printf("Maximum Nesting = %d\n",max_depth); };

statement_list  : 
                | statement_list statement
                ;

statement   : if_statement
            | block
            | OTHER
            ;

if_statement    :   IF LPAREN expr RPAREN {
                        curr_depth++ ;
                        if(curr_depth > max_depth) max_depth = curr_depth ;
                    }
                    statement
                    { curr_depth-- ;}
                |   IF LPAREN expr RPAREN {
                        curr_depth++ ;
                        if(curr_depth > max_depth) max_depth = curr_depth ;
                    }
                    statement ELSE statement
                    { curr_depth-- ;}
                ;
block   : LBRACE statement_list RBRACE

expr    : ID
        | OTHER
        | LPAREN expr RPAREN
        ;

%%

int main() {
    yyparse() ;
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n",s);
    return 0;
}