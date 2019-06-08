%{
#include"y.tab.h"
%}

%%

([A-Z]|[a-z])([a-z]|[A-Z]|[0-9])*	{return ID;}
[0-9]* {return NUMBER;}
[+-/%*]	{return OP;}
\t ;
.	{return yytext[0];}	
\n 	{return 0;}

%%
int yywrap()
{
	return 1;
}