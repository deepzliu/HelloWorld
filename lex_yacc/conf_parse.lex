%{
#include <stdio.h>
#define YYSTYPE char *
extern YYSTYPE yylval; // 必须放在#include "y.tab.h"前面
#include "y.tab.h"
%}
%%
zone return ZONETOK;
file return FILETOK;
[a-zA-Z][a-zA-Z0-9]* yylval = strdup(yytext); return WORD;
[a-zA-Z0-9\/.-]+ yylval = strdup(yytext); return FILENAME;
\" return QUOTE;
\{ return OBRACE;
\} return EBRACE;
; return SEMICOLON;
[ \t]+ /* ignore whitespace */;
\n /* ignore EOL */;
%%



