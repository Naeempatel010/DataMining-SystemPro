%{

#include "y.tab.h"


%}


%%

[0-9]+		{yylval.num=atof(yytext);return number;}

[-+*/]		{return yytext[0];}

cos 		{return cos1;}
sin			{return sin1;}
tan			{return tan1;}
pow			{return power;}
root		{return root;}


%%

int yywrap()
{
	return 1;
}
