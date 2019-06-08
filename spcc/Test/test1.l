%{
#include<stdio.h>
#include"y.tab.h"
%}

%%

if 		{return IF;}
else	{return ELSE;}
([a-z]|[A-Z])([a-z]|[A-Z]|[0-9])* {return ID;}
\t  ;
. {return yytext[0];}

%%



int yywrap()
{
	return 1;
}

