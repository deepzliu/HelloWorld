%{
#include <stdio.h>
#include <string.h>

extern int yylex(void); //该函数是在lex.yy.c里定义的，yyparse()里要调用该函数，为了能编译和链接，必须用extern加以声明
extern int yyparse(void);

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

%token NUMBER TOKHEAT STATE TOKTARGET TOKTEMPERATURE

%%
commands: /* empty */
| commands command
;

command: heat_switch | target_set ;

heat_switch:
TOKHEAT STATE
{
	printf("\tHeat turned on or off\n");
};

target_set:
TOKTARGET TOKTEMPERATURE NUMBER
{
	printf("\tTemperature set\n");
};
%%
