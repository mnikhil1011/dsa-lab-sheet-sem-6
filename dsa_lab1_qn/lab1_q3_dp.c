#include<stdio.h>


int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	int i=1;
	for(;i<=n;i++)
		scanf("%d",a+i);
	int sum;
	scanf("%d",&sum);
	
	int b[n+1][sum+1];
	for(i=1;i<=sum;i++)
		b[0][i]=0;
	for(i=0;i<=n;i++)
		b[i][0]=1;
		
	for(i=1;i<=n;i++)
	{
		int j;
		for(j=1;j<=sum;j++)
		{
			if(a[i]>j)
				b[i][j]=b[i-1][j];
			else
				b[i][j]=b[i-1][j]|| b[i-1][j-a[i]];	
				
		}	
	}	
	if(b[n][sum]==1)
	{
		printf("yes");
		int j=sum;
		for(i=n;i>=0;i--)
		{
			if(b[n-1][j-a[i]])
			{
				printf("%d ",i-1);
				j=j-a[i];
			}
				
		}
			
	
	}
	

	else
		printf("no");
		
		
}