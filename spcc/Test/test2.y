%{
#include<stdio.h>	
#include<stdlib.h>
#include<string.h>
%}

%token ID
%token NUMBER
%start s
%token OP

%%
s 					:e ;
e					:number_operator|number_operator OP e 	;
number_operator		:ID|NUMBER 		;

%%


int main()
{
	printf("enter expression");

	yyparse();
	printf("valid expression");
	return 0;
}


yyerror()
{
	printf("Invalid expression");
	exit(0);
}