%{
#include <stdio.h>
#include <string.h>

#define YYSTYPE char *
extern YYSTYPE yylval;
//int yydebug = 1; // debug

extern int yylex(void);
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

%token SEMICOLON ZONETOK OBRACE EBRACE QUOTE FILENAME WORD FILETOK

%%
commands: 
| commands command SEMICOLON 
;

command: 
zone_set
;

zone_set:
ZONETOK quotedname zonecontent
{
	printf("Complete zone for '%s' found\n", $2);
};

zonecontent:
OBRACE zonestatements EBRACE 
;

quotedname:
QUOTE FILENAME QUOTE
{
	$$ = $2;
	//printf("filename: %s\n", $2);
};

zonestatements:
| zonestatements zonestatement SEMICOLON
{
	//printf("zonestatements: %s\n", $2);
};

zonestatement:
statements | FILETOK quotedname
{
	printf("A zonefile name '%s' was encountered\n", $2);
};

statements:
| WORD statement 
{
	$$ = $2; // seems unnecessary
	printf("statements, key: %s, value: %s\n", $1, $2);
};

statement:
WORD | quotedname 
{
	//printf("statement: %s\n", $1);
};

%%
