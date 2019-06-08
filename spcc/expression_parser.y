%{

#include<stdio.h>
#include<stdlib.h>
	
%}
%token IF
%token ELSE
%start s
%token ID
%% 

s 			:IF'('condition')''{'block'}'ELSE'{'block'}'  		{printf("valid expression");} ;
condition 	:ID'>'ID|ID'<'ID ;
block 		:statement';'|statement';'block;
statement	:ID'='exp;
exp    		:ID|ID'+'ID;

%%



int main()
{
	
yyparse();
return 0;

}


yyerror()
{
printf("in valid statement");	

}

