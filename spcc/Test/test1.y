%{
#include<stdio.h>	

%}

%token IF
%token ELSE
%token ID
%start s

%%

s			:IF'('condition')''{'block'}'ELSE'{'block'}'  {printf("Valid IF-ELSE Expression");} ;
condition 	:ID'<'ID|ID'>'ID ;
block 		:statement';'|statement';'block	;
statement	:ID'='ID ;


%%


int main()
{
	
	printf("Enter the Expression");
	yyparse();
	return 0;
}


yyerror()
{
	printf("Invalid expression");
}
