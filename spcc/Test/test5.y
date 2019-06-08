%{
#include<stdlib.h>	
#include<stdio.h>
#include<math.h>
%}

%union{
	
	float num;
}

%token sin1
%token tan1
%token cos1
%token <num> number
%type <num> s
%type <num> exp
%start s

%%

s 			:exp		{$$=$1;printf("Answer:-%f",$$);}
			;
exp			:exp'+'exp	{$$=$1+$3;}
			|exp'-'exp	{$$=$1-$3;}
			|exp'*'exp	{$$=$1-$3;}
			|exp'/'exp	{$$=$1-$3;}
			|sin1 exp {$$=sin($2*3.14/180.0);}
			|cos1 exp {$$=cos($2*3.14/180.0);}
			|tan1 exp {$$=tan($2*3.14/180.0);}
			|number
			;

%%


int main()
{
	
	printf("enter the expression");
	yyparse();
	return 0;
}

yyerror()
{
	printf("invalid");
	exit(0);
}