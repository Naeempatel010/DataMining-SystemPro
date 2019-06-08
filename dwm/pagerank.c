#include<stdio.h>
int cal_outward(int);
int link[10][10],n;

void main()
{
	
	int i,j,k,iter,outward_links,l;
	float pagerank[10][10],outward;
	printf("enter the number of pages");
	scanf("%d",&n);

	printf("enter the links between web pages");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&link[i][j]);

		}
	}
	printf("enter the number of iterations");
	scanf("%d",&iter);
	//printf("%d %d %d %d",cal_outward(0),cal_outward(1),cal_outward(2),cal_outward(3));

	for(i=0;i<n;i++)
	{
		pagerank[i][0] = (float)1/4; 
	}
	
	//printf("\niteration 1");
	for(i=0;i<n;i++)
	{
		printf("%f \t",pagerank[i][0]); 
	}	
	
	for(i=1;i<=iter;i++)
	{
		for(j=0;j<n;j++)
		{
			outward=0;
			for(k=0;k<n;k++)
			{
				if(link[k][j]==1 && k!=j)
				{
					outward_links = cal_outward(k);
					outward=outward + pagerank[k][i-1]/outward_links ;
				}
			}
			pagerank[j][i] = outward;
		}
		printf("\n ITERATION :%d ",i);
		for(l=0;l<n;l++)
			printf("%f \t ",pagerank[l][i]);
	}
	/*

	for(i=0;i<n;i++)
	{
		printf("\n%f",pagerank[i][iter]);
	}
	*/

}


int cal_outward(int node)
{
	int count=0,i;

	for(i=0;i<n;i++)
	{
		if(link[node][i]==1 && node!=i)
		{
			count++;
		}

	}
	return count;
}
