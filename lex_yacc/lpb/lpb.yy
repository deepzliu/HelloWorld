%{
#include <stdio.h>
#include <string.h>

extern int yylex(void); //该函数是在lex.yy.c里定义的，yyparse()里要调用该函数，为了能编译和链接，必须用extern加以声明
extern int yyparse(void);

//char heater[64]; 
char *heater; 

int yywrap()
{
	return 1;
}

void yyerror(const char *s)
{
	printf("[error] %s\n", s);
}

int main()
{
	yyparse();
	return 0;
}
%}

%token TOKHEAT TOKTARGET TOKTEMPERATURE TOKHEATER
%union
{
	int number;
	char *string;
}
%token <number> STATE
%token <number> NUMBER
%token <string> WORD

%%

commands: 
| commands command SEMICOLON ;

command: 
package_set | import_set | enum_set | message_set | page_set ;

%%

