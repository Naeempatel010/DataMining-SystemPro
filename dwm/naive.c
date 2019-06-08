#include<stdio.h>
#include<stdlib.h>

struct row
{
	char chills;
	char runny_nose;
	char headache;
	char flu;
}data[20];



float calculate(char,struct row[],int,struct row);

void main()
{
	int n,i,r=1;
	char ch;
	printf("\nenter the number of tuples");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter the chills,runny_nose,headache,flu");
		scanf("%c%c%c%c",&data[i].chills,&data[i].runny_nose,&data[i].headache,&data[i].flu);		
	}
	while(r==1)
	{
		struct row unknown;
		printf("Enter the unknown sample");
		scanf("%c%c%c",&unknown.chills,&unknown.runny_nose,&unknown.headache);
		float y = calculate('1',data,n,unknown);
		float n = calculate('0',data,n,unknown);
		printf("y= %f \n n= %f \n",y,n);
		printf("\nDo you want to continue");
		scanf("%d",&r);
	}
}


float calculate(char class,struct row data[],int n,struct row unknown)
{
	int i;
	int c_1=0,c_2=0,c_3=0,class_counter=0;
	for(i=0;i<n;i++)
	{

		if(data[i].flu==class)
		{
			class_counter++;
			if(unknown.chills==data[i].chills)
			{
				c_1++;
			}
			if(unknown.runny_nose==data[i].runny_nose)
			{
				c_2++;
			}
			if(unknown.headache==data[i].headache)
			{
				c_3++;
			}
		}
		float ans = ((float)(c_1*c_2*c_3)/(class_counter*class_counter*class_counter*class_counter))*((float)class_counter/n);
		return ans;
	}
}