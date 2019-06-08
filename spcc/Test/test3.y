%{
#include<stdio.h>	
#include<stdlib.h>
#include<string.h>	
char* createaddress(void);
int count=0;
%}

%union{
	
	char str[30];
}
%token <str> Var
%token <str> Num
%type <str> s
%type <str> exp
%left '+' '-'
%left '*' '%' '/'
%left '^'



%%
s 				:Var'='exp  {printf("\n%s=%s",$1,$3);};
exp 			:'('exp')'	{strcpy($$,$2);};
				|exp'+'exp 	{strcpy($$,createaddress());printf("\n%s = %s + %s",$$,$1,$3);}
				|exp'-'exp  {strcpy($$,createaddress());printf("\n%s = %s - %s",$$,$1,$3);}
				|exp'*'exp  {strcpy($$,createaddress());printf("\n%s = %s * %s",$$,$1,$3);}
				|exp'/'exp 	{strcpy($$,createaddress());printf("\n%s = %s / %s",$$,$1,$3);}
				|Num
				|Var
				;	




%%

char* createaddress(void)
{
	char temp[30],*ptr;
	sprintf(temp,"t%d",count++);
	ptr=temp;
	return ptr;
}

int main()
{
	
	yyparse();
	return 0;
}

yyerror()
{
	
	printf("Invalid expression");
	exit(0);
}
