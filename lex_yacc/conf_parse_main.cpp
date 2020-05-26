#include <iostream>
//#include "y.tab.c"

extern int yyparse(void);

int main()
{
	yyparse();
	return 0;
}

