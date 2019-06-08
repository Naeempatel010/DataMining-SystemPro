%{

#include<stdio.h>
#include<string.h>
#include "y.tab.h"
%}

%%

([A-Z]|[a-z])([a-z]|[A-Z]|[0-9])* {strcpy(yylval.str,yytext); return Var;}
[0-9]+ {strcpy(yylval.str,yytext);return Num;}
\t ;
\n {return 0;}
. {return yytext[0];}

%%

int yywrap()
{

	return 1;
}

