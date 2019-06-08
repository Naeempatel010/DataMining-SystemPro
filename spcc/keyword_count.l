%{
#include<stdio.h>
int key_c=0,iden_c=0,oper_c=0,sp_c,br_c,num_c=0,header_c=0;
%}


%%
if|main|void { key_c++;}
#include<([a-z])*.h>  {header_c++;}
([A-Z]|[a-z]|[_])([a-z]|[A-Z]|[0-9])* {iden_c++;}
[-|+|*|/] { oper_c++;}
[,|.|?|!|@] { sp_c++;}
[(|)|{|}] {br_c++;}
[0-9]* {num_c++;}
%%
int main()

{
yyin=fopen("work.c","r");
yylex();	
printf("%d no of keywords",key_c);
printf("%d no of identifiers",iden_c);

return 0;
}

int yywrap(void)
{
	return 1;
}
