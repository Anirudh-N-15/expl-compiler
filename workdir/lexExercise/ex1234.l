%{
#include <stdio.h>
int line_count = 0;
int word_count = 0;
int char_count = 0;
int num_count = 0;
int float_count = 0;
int three_char_word = 0;
int single_comment = 0 ;
int multi_comment = 0;
%}

/*Auxiliary declarations end & Regular definitions start here*/

digit [0-9]             
number {digit}+
float {digit}+"."{digit}+
word [a-zA-Z]+            
three_ch_w [A][a-zA-Z]{2}
single_line "//".*
multi_line "/*"([^*]|\*+[^/])*\*+"/"

%%

\n              {line_count++ ;}
[ \t]+          {char_count += yyleng ;}
{float}         {float_count++ ; char_count += yyleng ;}
{number}        {num_count++ ; char_count += yyleng ;}
{three_ch_w}    {three_char_word++ ; word_count++ ; char_count += yyleng ;}
{word}          {word_count++ ; char_count += yyleng ;}
.               {char_count++ ;}
{single_line}   {single_comment++ ; printf("%s\n",yytext);}
{multi_line}    {multi_comment++ ; printf("%s\n",yytext);}

%%


int main(int argc, char ** argv) {
    if(argc > 1) {
        yyin = fopen(argv[1],"r");

        if(!yyin) {
            perror("File not opening");
            return 1;
        }
    }

    yylex();
    printf("Lines = %d\n",line_count);
    printf("Words = %d\n",word_count);
    printf("Chars = %d\n",char_count);
    printf("Numbers = %d\n",num_count);
    printf("Floats = %d\n",float_count);
    printf("Three_letter_word = %d\n",three_char_word);
    printf("Single Comments = %d\n",single_comment);
    printf("Multi Comments = %d\n",multi_comment);
    return 0;
}

int yywrap() {
    return 1;
}
