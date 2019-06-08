%{
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
	
%}

%union
{
	float num;	
}

%token <num>number;
%type <num>exp;

%token cos1
%token sin1
%token tan1
%token power
%token root

%start s


%%
s  		:exp 				
exp		:number				{$$=$1;}
		|exp'+'number		{$$=$1+$3;printf("%f",$$);}
		|exp'-'number		{$$=$1-$3;printf("%f",$$);}
		|exp'*'number		{$$=$1*$3;printf("%f",$$);}
		|exp'/'number		{$$=$1/$3;printf("%f",$$);}
		|sin1 number		{$$=sin($2*3.14/180.0);printf("%f",$$);}
		|cos1 number		{$$=cos($2*3.14/180.0);printf("%f",$$);}
		|tan1 number		{$$=tan($2*3.14/180.0);printf("%f",$$);}
		|power number number {$$=pow($2,$3);printf("%f",$$);}
		|root number		{$$=sqrt($2);}
		;

%%


int main()
{
	
	yyparse();
	return 0;
}

yyerror()
{
	printf("invalid expression");
}



