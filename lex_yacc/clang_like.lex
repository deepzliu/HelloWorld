%{
	/*

	类C语法示例:

		logging{
		category lame-servers { null; };
		category cname { null; };
		};
		
		zone "." {
		type hint;
		file "/etc/bind/db.root";
		}
	
	token分析：

		WORD: 如'zone'和'type'
		FILENAME：如"/etc/bind/db.root"
		QUOTE: 如包含文件名的引号
		OBRACE：{
		EBRACE: }
		SEMICOLON: ;

	*/

#include <stdio.h>
%}

%%
[a-zA-Z][a-zA-Z0-9]* printf("WORD ");
[a-zA-Z0-9\/.-]+ printf("FILENAME ");
\" printf("QUOTE ");
\{ printf("OBRACE ");
\} printf("EBRACE ");
; printf("SEMICOLON ");
\n printf("\n");
[ \t]+ /* ignore whitespace */;
%%
