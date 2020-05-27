%{
#include <stdio.h>
extern void yyerror(char* s);
extern FILE *yyget_out();
extern int yylex();
extern int simple_op(int n, int m, char *op);
char *op;
int result;
%}

%union
{
	int num;
	char *op;
}
%token <num> NUMBER
%token <op> OP_PLUS 
%token <op> OP_MINUS

%%

expr: NUMBER operation NUMBER
{
	printf("expr: %d %s %d = %d\n", $1, op, $3, simple_op($1, $3, op)); 
};

operation: plus | minus; 

plus: OP_PLUS
{
	op = $1;
	printf("operation: %s\n", $1); 
};

minus: OP_MINUS 
{
	op = $1;
	printf("operation: %s\n", $1); 
};

%%


