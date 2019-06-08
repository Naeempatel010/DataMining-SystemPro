#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main()
{
	char ch,temp[40],a[10][10];
	int n,k,flag=0,c=0,i,left_r[10];	
	printf("Enter the number of productions \n");
	scanf("%d",&n);
	for(k=0;k<n;k++)
		scanf("%s",a[k]);

	for(k=0;k<n;k++)
	{
		if(a[k][0]==a[k][2])
		{
			printf("left recursion exist");
			flag=1;
		}		
	}
	if(flag==0)
	{
		printf("No left recursion exiting!! %c %c",a[0][0],a[0][2]);
		exit(0);
	}
	for(k=0;k<n;k++)
	{
		if(a[k][0]==a[k][2])
		{
			left_r[c++]=k;
		}
	}
	for(k=0;k<c;k++)
	{
		for(i=0;i<n;i++)
		{
			if(a[left_r[k]][0]==a[i][0] && a[i][0]!=a[i][2])
			{
				printf("\n%c%c%c%c'\n%c'%c%c\n",a[i][0],a[i][1],a[i][2],a[i][0],a[i][0],a[i][1],a[left_r[k]][3]);
			}
		}
	}




	return 0;
}