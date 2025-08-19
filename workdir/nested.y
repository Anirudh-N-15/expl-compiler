%{
#include <stdio.h>
#include <stdlib.h>

int nesting = 0;
%}
/*** YACC Declarations section ***/


%%

/*** Rules Section ***/



%%

/*** Auxiliary functions section ***/

yerror(const char *s) {
    printf("yerror %s",s);
}

yylex() {

}

int main() {
    yyparse();
    return 1;
}