%{
#include <stdio.h>
//#define YYSTYPE char *
//extern YYSTYPE yylval; // 必须放在#include "y.tab.h"前面
#include "y.tab.h"
%}
%%
package return PACKAGE;
import return IMPORT;
enum return ENUM;
message return MESSAGE;
page return PAGE;

[a-zA-Z][a-zA-Z0-9]* yylval = strdup(yytext); return WORD; // _ 下划线？
[0-9\.]+ yylval = strdup(yytext); return NUMBER; // 小数据点(FLOAT)？

required return REQUIRED;
optional return OPTIONAL;
assisted return ASSISTED;
if return IF;
else return ELSE;

bool return BOOL;
char return CHAR;
int8 return INT8;
int16 return INT16;
int24 return INT24;
int32 return INT32;
int48 return INT48;
int64 return INT64;
uint8 return UINT8;
uint16 return UINT16;
uint24 return UINT24;
uint32 return UINT32;
uint48 return UINT48;
uint64 return UINT64;
long\ long return LONG_LONG;
string return VSTRING;
lstring return LSTRING;
estring return ESTRING;
vector return VECTOR;
lvector return LVECTOR;
bitset return BITSET;
lbitset return LBITSET;
map return MAP;
lmap return LMAP;

( return L_BRACKET;
) return R_BRACKET;
\[ return L_S_BRACKET;
\] return R_S_BRACKET;
\{ return OBRACE;
\} return EBRACE;
< return L_ANGLE;
> return R_ANGLE;

= return ASSIGN;
& return AND_OP;

== return EQUAL;
&& return AND;
|| return OR;
! return NOT

\" return QUOTE;
, return COMMA;
; return SEMICOLON;
:: return DOUBLECOLON;
* return STAR;
\n return LINE_BREAK;

// return line_COMMENT;
/* return L_COMMENT;
*/ return R_COMMENT;

\r /* ignore */;
[ \t]+ /* ignore whitespace */;

%%
