%{
#include "y.tab.h"
%}

%%

[0-9]+	{yylval.num = atof(yytext);return number;}
sin		{return sin1;}
tan		{return tan1;}
cos		{return cos1;}
\t ;
\n	 {return 0;}
.	{return yytext[0];}


%%



int yywrap()
{
	return 1;
}