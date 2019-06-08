#include<stdio.h>
#include<string.h>
#include<ctype.h>

char result[20];
int m=0,n;
char a[10][10];
void first(char);
void follow(char);

int main()
{
	int i,r;
	char c,ch;
	printf("\nenter the no of production");
	scanf("%d",&n);
	printf("\nenter the productions");
	for(i=0;i<n;i++)
	{
		scanf("%s%c",a[i],&ch);
	}

	do
	{
		m= 0;
		printf("\nenter the Symbol whose first &follow you want to find");
		scanf("%c",&c);
		first(c);
		printf("\nthe First of %c is {",c);
		//printf("%s",result);
		printf("}\n");
		//printf("%d\n",m);
		m=0;
		strcpy(result,"");
		printf("%s",result);
		follow(c);
		printf("\nthe follow of %c is {",c);
		//printf("%s",result);
		printf("}\n");
		printf("do you want to continue?");
		scanf("%d%c",&r,&ch);

	}while(r==1);
	return 0;
}

void first(char c)
{
	int i,j,k;
	if(!isupper(c))
	{
		result[m++] = c;
		printf(" %c ",c);
		//printf("inside first if-else");
	}
	for(i=0;i<n;i++)
	{
		if(a[i][0]==c)
		{
			if(a[i][2]=='$')
			{
				result[m++]='$';
				printf(" $ ");
				//printf("\nin a[i][2]");
			}
			else if(islower(a[i][2]))
			{
				result[m++]=a[i][2];
				//printf("\nin islower\n");
				printf(" %c ",a[i][2]);
			}
			else
			{
				//printf("\nin first(a[i][2])\n");
				first(a[i][2]);

			}
		}
	}

}

void follow(char c)
{
	int i,j;
	if(a[0][0]==c)
	{
		result[m++]='$';
		printf(" $ ");
		//printf("\nin a[0][0]");
	}
	for(i=0;i<n;i++)
	{
		for(j=2;j<strlen(a[i]);j++)
		{
			if(a[i][j]==c)
			{
				if(a[i][j+1]!='\0')
				{
					first(a[i][j+1]);
					//printf("\nin a[i][j] ");
				}
				else if(a[i][j+1]=='\0' && c!=a[i][0])
				{
					follow(a[i][0]);
					//printf("\nin a[i][0]");
				}
			}
		}
	}


}
