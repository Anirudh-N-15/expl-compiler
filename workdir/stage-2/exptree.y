%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "exptree.h"
    #include "execute.h"

    int yylex(void);
    int yyerror(const char *s);

    FILE * output;
%}

%union {
    struct tnode * node;
}

%token PLUS MINUS MUL DIV 
%token T_BEGIN T_END READ WRITE ASSIGN SEMICOLON

%token <node> NUM ID

%type <node> expr assignStmt opStmt ipStmt stmt stmtList

%left PLUS MINUS 
%left MUL DIV 

%%

program     :   T_BEGIN stmtList T_END SEMICOLON    {
                                                        finalOutput($2, output);
                                                        evaluator($2);
                                                    }
            |   T_BEGIN T_END SEMICOLON             {
                                                    printf("\n");
                                                    exit(0);
                                                }
            ;

stmtList    :   stmtList stmt                   {   $$ = createConnecterNode($1, $2); }
            |   stmt                            {   $$ = $1 ;}
            ;

stmt        :   ipStmt                          {   $$ = $1 ;}
            |   opStmt                          {   $$ = $1 ;}
            |   assignStmt                      {   $$ = $1 ;}
            ;

ipStmt      :   READ '(' ID ')' SEMICOLON       {   $$ = createReadNode($3) ;}
            ;

opStmt      :   WRITE '(' expr ')' SEMICOLON    {   $$ = createWriteNode($3) ;}
            ;

assignStmt  :   ID ASSIGN expr SEMICOLON       {   $$ = createAssignNode($1, $3) ;}
            ;

expr        :   expr PLUS  expr                 {   $$ = createOperatorNode(ADD_NODE, $1, $3); }
            |   expr MINUS expr                 {   $$ = createOperatorNode(MINUS_NODE, $1, $3); }
            |   expr MUL   expr                 {   $$ = createOperatorNode(MUL_NODE, $1, $3); }
            |   expr DIV   expr                 {   $$ = createOperatorNode(DIV_NODE, $1, $3); }
            |   '(' expr ')'                    {   $$ = $2 ;}
            |   NUM                             {   $$ = $1 ;}
            |   ID                              {   $$ = $1 ;}
            ;
            
%%

extern FILE * yyin ;

int  yyerror(const char * s) {
    printf("Error : %s\n",s);
    return 1;
}

int main(int argc, char ** argv) {
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        if(!yyin) {
            printf("Error opening file\n");
            return 1;
        }
    }

    output = fopen("output.xsm", "w");
    yyparse();

    fclose(output);
    return 0;
}
