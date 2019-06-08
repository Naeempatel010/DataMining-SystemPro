%{
#include<stdio.h>
int count_header=0,count_identifier=0;
}%

%%

#include<conio.h> { count_heaader++;}
%%
int main()

{
yylex();

printf("%d",count_header);	

return 0;
}

int yywrap()
{

return 1;

}

