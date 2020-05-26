%{
	/*
	简单的温度控制器扩展:
		
		heat on
		Heater on!
		heat off
		Heater off!
		target temperature set!

	需要识别的标识符:

		heat
		on/off(STATE)
		target
		temperature
		NUMBER

	*/

#include <stdio.h>
//#include "temperature_controller.tab.h"
#include "y.tab.h"
%}

%%
[0-9]+ yylval = atoi(yytext); return NUMBER;
heat return TOKHEAT;
on|off yylval = !strcmp(yytext, "on"); return STATE;
target return TOKTARGET;
temperature return TOKTEMPERATURE;
\n /* ignore end of line */
[ \t]+ /* ignore whitespace */
%%
