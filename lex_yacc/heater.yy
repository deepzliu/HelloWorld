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
commands: /* empty */
| commands command
;

command: heat_switch | target_set | heater_select;

heat_switch:
TOKHEAT STATE
{
	if ($2)
		printf("\tHeat turned on\n");
	else
		printf("\tHeat turned off\n");
}

target_set:
TOKTARGET TOKTEMPERATURE NUMBER
{
	//printf("\tTemperature set to %d\n", $3);
	printf("\tHeater '%s' temperature set to %d\n", heater, $3);

};

heater_select:
TOKHEATER WORD
{
	printf("\tSelected heater '%s'\n", $2);
	heater = $2;
};

%%


