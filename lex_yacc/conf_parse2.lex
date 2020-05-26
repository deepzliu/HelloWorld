%{
#include <stdio.h>
%}

%%
zone printf("ZONETOK ");
file printf("FILETOK ");
[a-zA-Z][a-zA-Z0-9]* printf("WORD ");
[a-zA-Z0-9\/.-]+ printf("FILENAME ");
\" printf("QUOTE ");
\{ printf("OBRACE ");
\} printf("EBRACE ");
; printf("SEMICOLON ");
[ \t]+ /* ignore whitespace */;
\n printf("\n");
%%
