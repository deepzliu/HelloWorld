%{
#include <stdio.h>
#include <string.h>

#define YYSTYPE char *
extern YYSTYPE yylval;
//int yydebug = 1;

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
{
	printf("zonecontent\n");
};

quotedname:
QUOTE FILENAME QUOTE
{
	$$ = $2;
	printf("filename: %s\n", $2);
};

zonestatements:
| zonestatements zonestatement SEMICOLON
{
	printf("zonestatements\n");
};

zonestatement:
statements | FILETOK quotedname
{
	printf("A zonefile name '%s' was encountered\n", $2);
};

block:
OBRACE zonestatements EBRACE SEMICOLON
{
	printf("block\n");
};

statements:
| statements statement
{
	printf("statements\n");
};

statement:
WORD | block | quotedname 
{
	printf("statement, word: %s\n", $1);
};

%%
