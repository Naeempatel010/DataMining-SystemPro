#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	double ele[10],m1,m2,pm1,pm2;
	int n,j,i,counter1=0;
	printf("enter the number of elements");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
		scanf("%lf",&ele[i]);
	
	m1=rand()%10+1;
	m2=rand()%10+1;
	//printf("%f %f ",m1,m2);
	while(pm1!=m1 && pm2!=m2 )
	{
		counter1++;
		int cluster[10]; 
		pm1=m1;
		pm2=m2;
		printf("%f %f",m1,m2);
		for(i=0;i<n;i++)
		{
			double d1 = sqrt(pow(m1-ele[i],2));
			//printf("\ndistance %f d1 of %f element from %f m1",d1,ele[i],m1);
			double d2 = sqrt(pow(m2-ele[i],2));
			//printf("\ndistance d2 of %f element from %f m2",d2,m2);
			if(d1>=d2)
			{
				cluster[i] = 1;
			}
			else
			{

				cluster[i] = 2;
			}
			
		}
		for(i=0;i<n;i++)
			printf("%d\t",cluster[i]);
		printf("\ncluster 1={");
		float sum = 0;
		int count = 0;
		for(j=0;j<n;j++)
		{
			if(cluster[j]==1)
			{
				printf(" %f ",ele[j]);
				sum=sum+ele[j];
				count++;
			}
		}
		printf("}\n");
		m1=sum/count;
		sum=0,count=0;
		printf("\n Cluster 2={");
		for(j=0;j<n;j++)
		{
			if(cluster[j]==2)
			{
				printf(" %f ",ele[j]);
				sum=sum+ele[j];
				count++;
			}
		}
		printf("}\n");
		m2=sum/count;

	}
	printf("Clustering completed");
}

