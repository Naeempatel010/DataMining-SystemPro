%{
#include<stdio.h>

int idn=0;
struct word{
	char iden;
	int no;
}w[20];

int lookup(char wr)
{

	for(int i=0;i<idn;i++)
	{
		if(wr==w[i].iden)
		{
			return i;
		}


	}

	return -1;
}

void add(char identifier)
{
	int flag=lookup(identifier);
	if(flag==-1)
	{
		w[idn].iden= identifier;
		w[idn].no=idn;
		printf("\nidentifier %c added as identifier %d",identifier,idn);
		idn++;

	}
	else
	{
		printf("\n%c identifier identified as identifier %d",identifier,flag);
	}
}
%}


%%
(void|main|int) {yytext;}
[{|}|(|)] {yytext;} 
[;]  {yytext;}
[,] {yytext;}
[+|=] {yytext;}
[\n] {yytext;}
	([a-z]|[A-Z])([a-z]|[A-Z]|[0-9])* { add(yytext[0]); }



%%


int main()
{

	yyin=fopen("input.txt","r");
	yylex();

}

int yywrap(void)
{
	return 1;
}