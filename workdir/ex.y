%{
/*** Auxiliary declarations section ***/

#include<stdio.h>
#include<stdlib.h>

%}

 /*** YACC Declarations section ***/
%token ID DIGIT
%left '+'
%left '='
%%


/*** Rules Section ***/
start: ID '=' expr        {printf("accept\n");}
    ;

expr: ID '=' expr       {printf("accept\n");}         
    | expr '+' expr     {printf("accept\n");}  
    | expr '+' DIGIT    {printf("accept\n");}
    | DIGIT
    | ID
    ;
%%

/*** Auxiliary functions section ***/

yyerror(char const *s)
{
    printf("reject");
}

yylex(){
    char c;
    c = getchar();
    if(c == 'x' || c == 'y' || c == 'z') {
        return ID ;
    } else if(isdigit(c)) {
        return DIGIT ;
    } else if(c == ' ') {
        yylex();
    }
    return c ;
}

main()
{
 yyparse();
 return 1;
}