%{
#include"y.tab.h"
#include <stdio.h>

extern int lex_custom_input(char* buf, unsigned long *num_read,int max_read);
#undef YY_INPUT
#define YY_INPUT(b,r,s) lex_custom_input(b,&r,s)

void yyerror(char* s) 
{
	printf("[error] %s\n", s);
}

int yywrap() 
{
	return -1;
}
%}

DIGIT [0-9]

%%

\+ { yylval.op = "+"; printf("got plus\n"); return OP_PLUS; }
\- { yylval.op = "-"; printf("got minus\n"); return OP_MINUS; }
{DIGIT}+ { yylval.num = atoi(yytext); printf("got number: %d\n", yylval.num); return NUMBER; }
\n /* ignore end of line */
[ \t]+ /* ignore whitespace */

%%
